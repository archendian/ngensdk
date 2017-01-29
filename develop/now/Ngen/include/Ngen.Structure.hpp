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
#ifndef __NGEN_STRUCTURE_HPP
#define __NGEN_STRUCTURE_HPP

#include "Ngen.Mirror.hpp"
#include "Ngen.Map.hpp"
#include "Ngen.StaticDelegate.hpp"

namespace Ngen {

	// NOTE: Type definitions for static delegates.
   using NewStructureDelegate      = VoidStaticDelegate<unknown&, uword>;
   using DeleteStructureDelegate   = VoidStaticDelegate<unknown&>;
   using CopyStructureDelegate     = VoidStaticDelegate<unknown, unknown&, uword>;
   using CopyNewStructureDelegate  = VoidStaticDelegate<unknown, unknown&, uword>;
   using CompareStructureDelegate  = VoidStaticDelegate<unknown, unknown>;
   using NextStructureDelegate     = VoidStaticDelegate<unknown&>;
   using PreviousStructureDelegate = VoidStaticDelegate<unknown&>;
   using StructureMap = Map<mirror, Structure>;
   using StructurePtrMap = Map<mirror, Structure*>;

   template<typename T> struct Alias {
           T Member;
           mirror Alias;
    };

   class ngen_api Structure {
   public:
        typedef Alias<Structure*> TAliasPtr;
        typedef Alias<Structure> TAlias;
        typedef Map<mirror, TAliasPtr> TAliasPtrMap;

      Structure() : mNew(), mDelete(), mCopy(), mNext(), mPrevious(), mByteSize(), mName() {}

      static Structure* Get(const Mirror& name){
         Structure* result = null;

         if(mStructures.ContainsKey(name)) {
            result = &mStructures[name];
         } else if (mAliases.ContainsKey(name)) {
            result = mAliases[name];
         }

         return result;
      }

      template<typename T> static Structure* Create(const mirror& typeName) {
         Structure* result = Structure::Get(typeName);
         if(isnull(result)) {
            mStructures.Add(typeName, Structure::Structure<T>(typeName));
            result = &mStructures[typeName];
         } else {
            result = CreateAlias(typeName, typeName);
         }

         return result;
      }

      void New(unknown& pointer, uword length=1) {
         unknown args[2] { pointer, Cast<uword>::To(length) };
         mNew(null, args);
      }

      void Delete(unknown& pointer) {
         unknown args[1] { pointer };
         mDelete(null, args);
      }

      void Copy(unknown from, unknown& to, uword length=1) {
         unknown args[3] { from, to, Cast<uword>::To(length) };
         mCopy(null, args);
      }

      void CopyNew(unknown from, unknown& to, uword length=1) {
         unknown args[3] { from, to, Cast<uword>::To(length) };
         mCopyNew(null, args);
      }

      void Previous(unknown& pointer) const {
         unknown args[1] { pointer };
         mPrevious(null, args);
      }

      void Next(unknown& pointer) const {
         unknown args[1] { pointer };
         mNext(null, args);
      }

      bool Compare(unknown lhs, unknown rhs, uword length=1) const {
         unknown args[3] { lhs, rhs, Cast<uword>::To(length) };
         return Cast<bool>::From(mCompare(null, args));
      }
      const Mirror& Name() const { return mName; }
      uword Size() const { return mByteSize; }
   protected:
      template<typename T> Structure(const mirror& name) :
         mNew(Memory::UnknownNew<T>),
         mDelete(Memory::UnknownDelete<T>),
         mCopy(Memory::UnknownCopy<T>),
         mNext([] (unknown& pointer) { ((T*)pointer)++; }),
         mPrevious([] (unknown& pointer) { ((T*)pointer)--; }),
         mCopyNew([] (unknown from, unknown& to, uword length) { Memory::UnknownNew<T>(to, length); Memory::UnknownCopy<T>(from, to, length); }),
         mCompare([] (unknown l, unknown r, uword length) { return Memory::UnknownCompare<T>(l, r, length); }),
         mByteSize(sizeof(T)), mName(name) {
      }

      static Structure* CreateAlias(const Mirror& name, const Mirror& alias) {
         Structure* result = null;

         if(mAliases.ContainsKey(alias)) {
            result = mAliases[alias];
         } else if(mStructures.ContainsKey(name)) {
            result = &mStructures[name];
            mAliases.Add(alias, result);
         }

         return result;
      }

      NewStructureDelegate        mNew;
      DeleteStructureDelegate     mDelete;
      CopyStructureDelegate       mCopy;
      NextStructureDelegate       mNext;
      PreviousStructureDelegate   mPrevious;
      CopyNewStructureDelegate  mCopyNew;
      CompareStructureDelegate  mCompare;
      uword                     mByteSize;
      mirror                    mName;

      static StructureMap       mStructures;
      static StructurePtrMap    mAliases;
   };

   ngen_api Structure* structureof(const mirror& typeName);
   template<typename T> Structure* structureof() { return structureof(typename_mirror<T>()); }

}

#endif // __NGEN_UNKNOWNTYPE_HPP
