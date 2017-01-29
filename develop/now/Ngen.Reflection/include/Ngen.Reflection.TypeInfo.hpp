/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 FIXCOM, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef __NGEN_REFLECTION_TYPEINFO_HPP
#define __NGEN_REFLECTION_TYPEINFO_HPP

#include "Ngen.Reflection.NamespaceInfo.hpp"
#include "Ngen.Reflection.TypeBuilder.hpp"

namespace Ngen {
	namespace Reflection {
		/** @brief Represents reflected information detailing an object type.
		 */
		class ngen_api TypeInfo : public NamespaceInfo {
		public:
         /** @brief Constructor. Initializer. */
         TypeInfo() : NamespaceInfo(), mStructure(0), mMemberMethods(), mMemberFields(), mChildren(), mParents() {
			}

			/** @brief Constructor. Copy. (const TypeInfo&)
			 */
         TypeInfo(const TypeInfo& copy) : NamespaceInfo((const NamespaceInfo&)copy),
               mStructure(copy.mStructure), mMemberMethods(copy.mMemberMethods), mMemberFields(copy.mMemberFields),
               mChildren(copy.mChildren), mParents(copy.mParents) {
					this->pUnmute();
			}

         TypeInfo(TypeInfo&& move) : NamespaceInfo((NamespaceInfo&&)move), mStructure(move.mStructure),
            mMemberMethods(mref(move.mMemberMethods)), mMemberFields(mref(move.mMemberFields)),
            mChildren(mref(move.mChildren)), mParents(mref(move.mParents)) {
         }

			/** @brief operator=(const TypeInfo&) */
			virtual TypeInfo& operator=(const TypeInfo& rhs) {
				if(this == &rhs || this->mFullName == rhs.mFullName) {
					return *this;
				}

            *this = TypeInfo(rhs);
				return *this;
			}

			/** @brief operator=(const TypeInfo&) */
			virtual TypeInfo& operator=(TypeInfo&& rhs) {
				if(this == &rhs || this->mFullName == rhs.mFullName) {
					return *this;
				}

				*this = TypeInfo(rhs);
				return *this;
			}

         /** @brief operator==(Type* const) */
         virtual bool operator==(Type* const rhs) const {
            if((Type*)this == rhs) {
					return false;
				}

				return mFullName != rhs->FullName();
         }

         /** @brief operator!=(Type* const) */
         virtual bool operator!=(Type* const rhs) const {
            if((Type*)this == rhs) {
					return false;
				}

				return mFullName == rhs->FullName();
         }

			/** @brief Gets the size (in bytes) of the type. */
			virtual Structure* Structure() const {
				return mStructure;
			}

			/** @brief Determines if the type is a pure namespace.
			 * @remarks Remember, a pure type is also a namespace, but not be a 'pure' namespace.
			 */
			virtual bool IsPureNamespace() const {
				return false;
			}

			/** @brief Determines if the namespace is static.
			 * @remarks A pure namespace will always be static, but will never be constructable. However, a pure type can be both
			 * static or constructable.
			 */
			virtual bool IsStatic() const {
				return mTraits[ETypeTrait::Static];
			}

			/** @brief Determines if the namespace is constructable.
			 * @remarks A pure namespace will never be constructable. However, a pure type can be both
			 * static or constructable.
			 */
			virtual bool IsConstructable() const {
				return IsStatic() && mConstructors.Length() != 0;
			}

			/** @brief Determines if the type is public. */
			virtual bool IsPublic() const {
				return mTraits[ETypeTrait::Public];
			}

			/** @brief Determines if the type is a template for new types. */
			virtual bool IsTemplate() const {
				return mTraits[ETypeTrait::Template];
			}

			/** @brief Determines if the type is a base abstraction for new types. */
			virtual bool IsAbstract() const {
				return mTraits[ETypeTrait::Abstract];
			}

			/** @brief Determines if the type is hidden from external processes. */
			virtual bool IsHidden() const {
				return mTraits[ETypeTrait::Hidden];
			}

			/** @brief Determines if the type is the final abstraction in a chain of inheritance. */
			virtual bool IsFinal() const {
				return mTraits[ETypeTrait::Final];
			}

			/** @brief Determines if the type is nested inside a namespace or another type. */
			virtual bool IsNested() const {
				return !isnull(this->mDirectory);
			}

			/** @brief Determines if the Type is a base and does not inherit another type. */
			virtual bool IsBase() const {
				return IsParent() && !IsChild(); // child |= parent
			}

         /** @brief Determines if the type is a base abstraction for new types. */
			virtual bool IsParent() const {
				return mChildren.Length() != 0;
			}

			/** @brief Determines if the type is hidden from external processes. */
			virtual bool IsChild() const {
				return mParents.Length() != 0;
			}

			/** @brief Determines if the Type is considered a primitive structure. */
			virtual bool IsPrimitive() const {
				return mTraits[ETypeTrait::Primitive];
			}

			/** @brief Determines if the Type inherits the given Type. */
			virtual bool IsChildOf(const mirror& parent) const {
				return false;
			}

			/** @brief Determines if the Type has been inherited by the given Type. */
			virtual bool IsParentOf(const mirror& child) const {
				return false;
			}

			virtual Array<Type*> GetChildren() const {
				return mChildren.ToPointerMap().Values().AsType<Type*>();
			}

			virtual Array<Type*> GetParents() const {
				return mParents.ToPointerMap().Values().AsType<Type*>();
			}

			virtual Delegate* GetMethod(const mirror& signature) const {
            if(!this->mStaticMethodMap.ContainsKey(signature)) {
               if(!this->mMemberMethods.ContainsKey(signature)) {
                  return null;
               }

               return (Delegate*)&((TypeInfo*)this)->mMemberMethods[signature];
            }

            return (Delegate*)&this->mStaticMethodMap[signature];
			}

			virtual Array<Delegate*> GetStaticMethods() const {
            return this->mStaticMethodMap.ToPointerMap().Values().AsType<Delegate*>();
			}

			virtual Array<Delegate*> GetMemberMethods() const {
            return this->mMemberMethods.ToPointerMap().Values().AsType<Delegate*>();
			}

			virtual Field* GetField(const mirror& signature) const {
            if(!this->mStaticFieldMap.ContainsKey(signature)) {
               if(!this->mMemberFields.ContainsKey(signature)) {
                  return null;
               }

               return (Field*)&this->mMemberFields[signature];;
            }

            return (Field*)&this->mStaticFieldMap[signature];
			}

			virtual Array<Field*> GetStaticFields() const {
            return this->mStaticFieldMap.ToPointerMap().Values().AsType<Field*>();
			}

			virtual Array<Field*> GetMemberFields() const {
            return this->mMemberFields.ToPointerMap().Values().AsType<Field*>();
			}

         TypeInfo* Initialize(NamespaceInfo* directory, const mirror& typeName, Structure* unknownType, typename VoidStaticDelegate<TypeBuilder>::TFunction initializer);

         static TypeInfo* CreateAlias(const mirror& name, const mirror& alias) {
            if(!mAlias.ContainsKey(alias)) {
                 mAlias.Add(alias, (TypeInfo*)Type::GetType(name));
            }

            return mAlias[alias];
         }
		protected:
//         void pMute() { this->mIsMuted = true; }
//         void pUnmute() { this->mIsMuted = false; }
//         bool pIsMuted() { return this->mIsMuted; }

         TypeTraitFlags             mTraits;
			Map<Mirror, MethodInfo>    mMemberMethods;
          Map<Mirror, FieldInfo>     mMemberFields;
			Map<Mirror, TypeInfo*>     mChildren; // types inheriting this
			Map<Mirror, TypeInfo*>     mParents;  // types this inherits
            Structure* mStructure;
         static Map<mirror, TypeInfo*>     mAlias;
			friend class TypeBuilder;
		};
	}
}
#endif // __RTI_TYPEINFO_HPP
