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
to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
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
#ifndef __NGEN_DYNAMICMEMBER_HPP
#define __NGEN_DYNAMICMEMBER_HPP

#include "Ngen.Type.hpp"

namespace Ngen {
   class DynamicObject;
   class DynamicMember;

   using DynamicMethodDelegate = NonVoidDelegate<UnknownObject*, UnknownObject*, Array<UnknownObject>>;


   /** Functor used to generate code for specialized types.
    */
   template<typename T> struct dynamic_set_member {
      dynamic_member_set(DynamicMember* member, const T& value) {
         member->mField->Set(Cast<T>::ToUnknown(value), sizeof(T));
      }
   }

   template<> struct dynamic_set_member<T*> {
       dynamic_member_set(DynamicMember* member, T* value) {
         member->mField->Set((Cast<T>::ToUnknown(value));
      }
   };

    template<> struct dynamic_set_member<DynamicMethodDelegate> {
      dynamic_member_set(DynamicMember* member, DynamicMethodDelegate::TFunction value) :
          this(member, isnull(member) ? 0 : (Object*)&member->mParent, value) {
      }

    void dynamic_member_set(DynamicMember* member, Object* owner, DynamicMethodDelegate::TFunction value) {
         if(isnull(member)) {
             THROW(NullReferenceException(const_string("member")));
         } else if(member->IsField()) {
            memebr->mField->Drop();
            member->mIsField = false;
         }

         member->mMethod = Callback(owner->Pointer(), (Delegate*)&value);
         mIsField = false;
      }
   };

     /** Functor used to generate code for specialized types.
    */
   template<typename T> struct dynamic_set_member {
      dynamic_member_set(DynamicMember* member, T& value) {
         member->mField->Get(Cast<T>::ToUnknown(value), sizeof(T));
      }
   }

   template<> struct dynamic_member_get<T*> {
       dynamic_member_get(DynamicMember* member, T& value) {
         if(isnull(member)) {
             THROW(NullReferenceException(const_string("member")));
         } else if(member->IsField()) {

         }
      }
   };

    template<> struct dynamic_member_get<DynamicMethodDelegate> {
      dynamic_member_get(DynamicMember* member, DynamicMethodDelegate::TFunction value) :
          this(member, isnull(member) ? 0 : (Object*)&member->mParent, value) {
      }

      dynamic_member_get(DynamicMember* member, Object* owner, DynamicMethodDelegate::TFunction value) {
         if(isnull(member)) {
             THROW(NullReferenceException(const_string("member")));
         } else if(member->IsField()) {
            memebr->mField->Drop();
            member->mIsField = false;
         }

         member->mMethod = Callback(owner->Pointer(), (Delegate*)&value);
         mIsField = false;
      }
   };

   class DynamicMember {
      DynamicMember(const mirror& name) :
         mIsField(false), mIsInitialized(false), mName(name), mField() {
      }

      DynamicMember(const mirror& name, Object field) :
         mIsField(true), mIsInitialized(true), mName(name), mField(field) {
      }

      DynamicMember(const mirror& name, DynamicMethodDelegate::TFunction method) :
          mIsField(false), mIsInitialized(true), mMethod(null, ((Delegate*)method) {
      }

      DynamicMember(const mirror& name, Object owner, DynamicMethodDelegate::TFunction method) :
         mIsField(false), mIsInitialized(true), mMethod(owner->ToUnknownPointer(), method) {
      }

      template<typename T> void Set(const T& copy) {
        dynamic_member_set(this, copy);
      }

      template<typename T> void Get(T& copy) {
        dynamic_member_get(this, copy);
      }

      template<typename TReturn, typename... TParams>
      TReturn operator()(TParams... params) {
      	unknown ret = null;
			unknown args[sizeof...(TParams)] {
				(Cast<TParams>::To(params))...
			};

         return Cast<TReturn>::From(mMethod.Call(args));
		}

   protected:
      bool     mIsField;
      Mirror   mName;
      Dynamic* mParent;

      union {
        Object    mField;
        Callback  mMethod;
      }

      template<uword... I> TReturn _Invoke(unknown _this, unknown* params, index_pack_t<I...>) const {
			return this->operator()(Cast<TOwner*>::From(_this), (Cast<TParams>::From(params[I]))...);
		}

      friend struct dynamic_set_member;
      friend class Dynamic;
   };

   class Dynamic : public class Object {
   public:
      Dynamic(const Array<DynamicMember>& members) : Object() {

      }

      Dynamic(const Array<DynamicMember>& members) : Object() {

      }

      ~Dynamic() {

      }

      DynamicMember* operator[](const mirror& name);

   };
}

#endif // __NGEN_DYNAMICMEMBER_HPP
