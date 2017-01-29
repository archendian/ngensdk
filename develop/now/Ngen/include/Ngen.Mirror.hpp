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
#ifndef __NGEN_MIRROR_HPP
#define __NGEN_MIRROR_HPP

#include "Ngen.string.hpp"

namespace Ngen {
	/** @brief A structure used as a hash-code that represents a unique identity.
	 */
	class ngen_api Mirror {
	public:
		/** @brief Constructor. Default.
		 */
		Mirror() : mLongName(string::Empty()), mHashcode(0) {}

		/** @brief Constructor. (const string&).
		 * @param longName The unique identity being representing in the mirror.
		 */
		Mirror(const string& longName) : mLongName(const_string(longName)), mHashcode(longName.ToHashcode()) {}

		/** @brief Constructor. Copy. (const Mirror&).
		 * @param copy The unique identity being representing in the mirror.
		 */
		Mirror(const Mirror& copy) : mLongName(copy.mLongName), mHashcode(copy.mHashcode) {}

		/** @brief Constructor. Copy. (const Mirror&).
		 * @param copy The unique identity being representing in the mirror.
		 */
		Mirror(Mirror&& move) : mLongName((string&&)move.mLongName), mHashcode(move.mHashcode) {}


		/** @brief operator=(const Mirror&). */
		Mirror& operator=(const Mirror& rhs) {
			mHashcode = rhs.mHashcode;
			mLongName = rhs.mLongName;

			return *this;
		}

		/** @brief operator==(const Mirror&). */
		bool operator==(const Mirror& rhs) const {
			return rhs.mHashcode == mHashcode;
		}

		/** @brief operator!=(const Mirror&). */
		bool operator!=(const Mirror& rhs) const {
			return rhs.mHashcode != mHashcode;
		}

		/** @brief Gets the mirror represented as a hash-code. */
		uword ToHashcode() const {
			return mHashcode;
		}

		/** @brief Gets the unique name that generated the hash-code for the mirror. */
		string ToLongName() const {
			return mLongName;
		}

	protected:
		string mLongName;
		uword mHashcode;
	};


	typedef Mirror mirror;

#	define const_mirror(s) mirror(string(s, true))

    template<typename T> struct __typename {
        static string text() { return const_string(code_string(T)); }
        static mirror mirror() { return const_mirror(code_string(T)); }
    };

    #define rti_typename_set(TYPENAME, NAME)\
        template<> struct __typename<TYPENAME> {\
            static Ngen::string text() { return const_string(NAME); }\
            static Ngen::mirror mirror() { return const_mirror(__typename<TYPENAME>::text()); }\
        };

    template<typename T> string typename_text() { return __typename<T>::text(); }
    template<typename T> mirror typename_mirror() { return __typename<T>::mirror(); }
}


#endif // __NGEN_MIRROR_HPP
