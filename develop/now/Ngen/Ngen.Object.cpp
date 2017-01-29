/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2014 NGENWARE

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

#include "Ngen.Type.hpp"

namespace Ngen {
	Object __nullObject = Object();

	const Object& Object::Null() {
		return __nullObject;
	}

   Object::Object(Type* type) : mType(type), mPointer(0), mReference(new Reference(1)), mIsReadonly(false) {
      if(!IsUnknown()) {
          type->Struct()->New(mPointer);
      }
   }
   Object::Object(unknown pointer, Type* type, bool readOnly) :
      mType(type), mPointer(pointer), mReference(null), mIsReadonly(readOnly) {
      if(!readOnly) {
          mType->Struct()->CopyNew(pointer, mPointer);
          mReference = new Reference(1);
      }
   }

   bool Object::operator==(const Object& rhs) const {
      bool result = false;
      if(IsNull() || rhs.IsNull()) {
          if(IsNull() && rhs.IsNull()) {
              result = true;
          }
      } else if(isnull(rhs.mType) || isnull(mType)) {
          return rhs.mPointer == mPointer;
      } else if(rhs.mType == mType || mType->IsRelated(rhs.mType)) {
          result = mType->Struct()->Compare(rhs.mPointer, mPointer);
      }

      return result;
   }

   bool Object::Drop() {
      if(IsManaged() && !IsReadonly()) {
          if(mReference->Drop()) {
              delete mReference;
              mType->Struct()->Delete(mPointer);
              mReference = null;
              mPointer = null;
              return true;
          }
      }

      return false;
   }

   Object Object::As(Type* type) const {
      auto result = Object::Null();
      if(isnull(mType) || mType->IsRelated(type)) {
          result = Object(mPointer, type, true);
      }

      return result;
   }
}
