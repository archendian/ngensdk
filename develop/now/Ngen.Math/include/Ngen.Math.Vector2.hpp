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

         Vector2() : X(0.f), Y(0.f) {}
         Vector2(real x, real y) : X(x), Y(y) {}
         Vector2(const Vector2& copy) : X(copy.X), Y(copy.Y) {}

         Vector2& operator=(const Vector2& copy) {
            X = copy.X;
            Y = copy.Y;
            return *this;
         }

         bool operator==(const Vector2& rhs) const {
            return X == rhs.X && Y == rhs.Y;
         }

         bool operator!=(const Vector2& rhs) const {
            return X != rhs.X && Y != rhs.Y;
         }

         Vector2 operator+(const Vector2& rhs) const {
            return Vector2(X + rhs.X, Y + rhs.Y);
         }

         Vector2& operator+=(const Vector2& rhs) {
            X += rhs.X;
            Y += rhs.Y;
            return *this;
         }

         Vector2 operator-(const Vector2& rhs) const {
            return Vector2(X - rhs.X, Y - rhs.Y);
         }

         Vector2& operator-=(const Vector2& rhs) {
            X -= rhs.X;
            Y -= rhs.Y;
            return *this;
         }

         Vector2 operator*(const Vector2& rhs) const {
            return Vector2(X * rhs.X, Y * rhs.Y);
         }

         Vector2& operator*=(const Vector2& rhs) {
            X *= rhs.X;
            Y *= rhs.Y;
            return *this;
         }

         Vector2 operator/(const Vector2& rhs) const {
            return Vector2(X / rhs.X, Y / rhs.Y);
         }

         Vector2& operator/=(const Vector2& rhs) {
            X /= rhs.X;
            Y /= rhs.Y;
            return *this;
         }

         Vector2 operator+(real rhs) const {
            return Vector2(X + rhs, Y + rhs);
         }

         Vector2& operator+=(real rhs) {
            X += rhs;
            Y += rhs;
            return *this;
         }

         Vector2 operator-(real rhs) const {
            return Vector2(X - rhs, Y - rhs);
         }

         Vector2& operator-=(real rhs) {
            X -= rhs;
            Y -= rhs;
            return *this;
         }

         Vector2 operator*(real rhs) const {
            return Vector2(X * rhs, Y * rhs);
         }

         Vector2& operator*=(real rhs) {
            X *= rhs;
            Y *= rhs;
            return *this;
         }

         Vector2 operator/(real rhs) const {
            return Vector2(X / rhs, Y / rhs);
         }

         Vector2& operator/=(real rhs) {
            X /= rhs;
            Y /= rhs;
            return *this;
         }

         real& operator[](uword index) {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            default: THROW(InvalidParameterException());
            }
         }

         const real& operator[](uword index) const {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            default: THROW(InvalidParameterException());
            }
         }


         static Vector2 Zero();
         static Vector2 Up();
         static Vector2 Down();
         static Vector2 Left();
         static Vector2 Right();
      };
	}
}
#endif
