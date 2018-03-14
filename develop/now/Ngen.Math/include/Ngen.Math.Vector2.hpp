/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2017 FIXCOM, LLC

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
#ifndef _NGEN_MATH_VECTOR2
#define _NGEN_MATH_VECTOR2

#include "Ngen.Math.Typedefs.hpp"

namespace Ngen {
	namespace Math {

		class Vector2 {
		public:
			real X;
			real Y;

			Vector2() : X(0), Y(0) {}
			Vector2(real xy) : X(xy), Y(xy) {}
			Vector2(real x, real y) : X(x), Y(y) {}
			Vector2(const Vector2& copy) : X(copy.X), Y(copy.Y) {}

			bool operator==(const Vector2& rhs) const {
            return X == rhs.X && Y == rhs.Y;
         }
         bool operator!=(const Vector2& rhs) const {
            return X != rhs.X || Y != rhs.Y;
         }
         Vector2 operator-(const Vector2& rhs) const {
            return Vector2(X-rhs.X, Y-rhs.Y);
         }
         Vector2 operator+(const Vector2& rhs) const {
            return Vector2(X+rhs.X, Y+rhs.Y);
         }

         static Vector2 Zero() { return Vector2(); }
		};

		typedef Vector2 vec2;
	}
}
#endif
