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
#ifndef __NGEN_OBJECT_HPP
#define __NGEN_OBJECT_HPP

#include "Ngen.Mirror.hpp"
#include "Ngen.Callback.hpp"
#include "Ngen.Field.hpp"
#include "Ngen.Map.hpp"
#include "Ngen.Reference.hpp"

//TODO:  Use an internal ObjectHeader structure to track IsReadOnly, Type, and Reference of an Object
// This is a trade-off for 5 bytes per object

namespace Ngen {
  class ngen_api Object {
    public:
        Object(unknown pointer=null) : mType(null), mPointer(pointer), mReference(null), mIsReadonly(false) {}
        Object(const mirror& typeName);
        Object(Type* type);
        Object(unknown pointer, Type* type, bool readOnly=false);
        Object(Object&& move) : mType(move.mType), mPointer(move.mPointer),
            mReference(move.mReference), mIsReadonly(move.mIsReadonly) {
            move.mReference = null;
            move.mPointer = null;
        }
        Object(const Object& copy, bool readOnly=false) : Object(copy.mPointer, copy.mType, readOnly) {};
        ~Object() { Drop(); }

        bool operator==(const Object& rhs) const;
        bool operator!=(const Object& rhs) const { return !this->operator==(rhs); }
        Object operator=(const Object& rhs) const {
            return Object(rhs.mPointer, rhs.mType, rhs.mIsReadonly);
        }
        bool Drop();
        bool IsReadonly() const { return mIsReadonly; }
        bool IsManaged() const { return mReference != null; }
        bool IsNull() const { return isnull(mPointer); }
        bool IsUnknown() const { return isnull(mType); }
        uword ReferenceCount() const { return IsManaged() ? mReference->Current() : 0; }
        unknown& Pointer() { return mPointer; }
        template<typename T> T*& Instance() { return Cast<T*&>::From(mPointer); }
        Object As(Type* type) const;
        Type* GetType() const { return mType; }
        static const Object& Null();

    protected:
        Type* mType;
        unknown mPointer;
        Reference* mReference;
        bool mIsReadonly;

        friend class Type;
    };

	typedef Object object;

#  define const_object(value) object(value, true)
#  define copy_object(value) object(value, false)
}

#endif // __NGEN_OBJECT_HPP
