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
#ifndef __NGEN_REFERENCECOUNT_HPP
#define __NGEN_REFERENCECOUNT_HPP

#include "Ngen.BitField.hpp"

namespace Ngen {
   class Reference {
   public:
      Reference(const Reference& copy) : mCount(copy.mCount) {}
      Reference(uword count=0) : mCount(count) {}


      bool operator==(const Reference& rhs) const { return rhs.mCount == this->mCount; }
      bool operator!=(const Reference& rhs) const { return rhs.mCount != this->mCount; }

      /** @brief Decrements the reference count by one. */
      uword Drop() { return --mCount; }

      /** @brief Increments the reference count by one. */
      uword Grab() { return ++mCount; }

      /** @brief Gets the current reference count. */
      uword Current() const { return mCount; }

	protected:
        uword                 mCount;
   };
}
#endif // __NGEN_REFERENCECOUNT_HPP
