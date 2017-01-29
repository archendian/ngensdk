/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 NGENWARE STUDIOS, LLC

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
#ifndef __NGEN_BITFIELD_HPP
#define __NGEN_BITFIELD_HPP

#include "Ngen.Typedefs.hpp"

namespace Ngen {

   template<typename TEnum> class BitField {
   public:
	   typedef BitField<TEnum> TSelf;

		/** @brief Default. ()
		 */
		BitField() : mField(0) {
		}

		/** @brief Turns off all bits in the flag.
		 */
		TSelf& Clear(uword to=0) {
		   mField = 0;
		   return *this;
		}

		/** @brief Sets the bit-flag of a given enumeration.
		 * @param target The enumeration representing the bit-flag being set.
		 * @param value If true, the bit-flag will be turned on, and if false, the
		 * bit-flag will be turned off.
		 */
		TSelf& Set(TEnum target, bool value) {
		    if(value) {
                mField |= (uword)target;
		    } else {
                mField &= ~(uword)target;
		    }

			return *this;
		}

		/** @brief Toggles the bit-flag of a given enumeration.
		 * @param target The enumeration representing the bit-flag being toggled.
		 */
		TSelf& Toggle(TEnum target) {
			mField ^= (uword)target;
			return *this;
		}

		/** @brief Turns on the bit-flag of a given enumeration.
		 * @param target The enumeration representing the bit-flag being toggled.
		 */
		TSelf& On(TEnum target) {
			mField |= (uword)target;
			return *this;
		}

		/** @brief Turns off the bit-flag of a given enumeration.
		 * @param target The enumeration representing the bit-flag being toggled.
		 */
		TSelf& Off(TEnum target) {
			mField &= ~(uword)target;
			return *this;
		}

      /** @brief Gets a value that determines if a specific bit-flag has been set.
       */
      bool operator[](TEnum e) const {
         return (mField & (uword)e == (uword)e);
      }

      /** @brief Gets a value that determines if a specific bit-flag has been set.
       */
      bool operator[](uword e) const {
         return (mField & e == e);
      }

      bool operator==(const TSelf& lhs) const {
         return mField == lhs.mField;
      }

      bool operator!=(const TSelf& lhs) const {
         return mField != lhs.mField;
      }

      bool operator==(TEnum lhs) const {
         return (mField & lhs == lhs);
      }

      bool operator!=(TEnum lhs) const {
         return (mField & lhs != lhs);
      }

      TSelf& operator+=(TEnum lhs) {
         mField |= lhs;
         return *this;
      }

      TSelf& operator-=(TEnum lhs) {
         mField &= ~lhs;
         return *this;
      }

	protected:
      uword mField;
   };
}

#endif // __NGEN_BITFLAGS_HPP
