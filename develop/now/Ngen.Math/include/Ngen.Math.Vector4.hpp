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
#ifndef __NGEN_MATH_VECTOR4_HPP
#define __NGEN_MATH_VECTOR4_HPP

#include "Ngen.Math.Typedefs.hpp"

namespace Ngen {
	namespace Math {

		class Vector4 {
		public:
			real X;
			real Y;
			real Z;
			real W;

			Vector4() : X(0), Y(0), Z(0), W(0) {}
			Vector4(real xyzw) : X(xyzw), Y(xyzw), Z(xyzw), W(xyzw) {}
			Vector4(real x, real y, real z, real w) : X(x), Y(y), Z(z), W(w) {}
			Vector4(const Vector4& copy) : X(copy.X), Y(copy.Y), Z(copy.Z), W(copy.W) {}

			bool operator==(const Vector4 rhs) const {
            return X == rhs.X && Y == rhs.Y && Z == rhs.Z && W == rhs.W;
			}

			bool operator!=(const Vector4 rhs) const {
            return X != rhs.X || Y != rhs.Y || Z != rhs.Z || W != rhs.W;
			}

			Vector4& operator=(const Vector4& rhs) {
            X = rhs.X;
            Y = rhs.Y;
            Z = rhs.Z;
            W = rhs.W;
            return *this;
         }

         Vector4 operator-() {
            return Vector4(-X, -Y, -Z, -W);
         }

         Vector4 operator-(const Vector4& rhs) const {
            return Vector4(X-rhs.X, Y-rhs.Y, Z-rhs.Z, W-rhs.W);
         }

         Vector4& operator-=(const Vector4& rhs) {
            X -= rhs.X;
            Y -= rhs.Y;
            Z -= rhs.Z;
            W -= rhs.W;
            return *this;
         }

         Vector4 operator+(const Vector4& rhs) const {
            return Vector4(X+rhs.X, Y+rhs.Y, Z+rhs.Z, W+rhs.W);
         }

         Vector4& operator+=(const Vector4& rhs) {
            X += rhs.X;
            Y += rhs.Y;
            Z += rhs.Z;
            Z += rhs.W;
            return *this;
         }

         Vector4 operator*(const Vector4& rhs) const {
            return Vector4(X*rhs.X, Y*rhs.Y, Z*rhs.Z, W*rhs.W);
         }

         Vector4& operator*=(const Vector4& rhs) {
            X *= rhs.X;
            Y *= rhs.Y;
            Z *= rhs.Z;
            Z *= rhs.Z;
            return *this;
         }

         Vector4 operator/(const Vector4& rhs) const {
            return Vector4(X/rhs.X, Y/rhs.Y, Z/rhs.Z, W/rhs.W);
         }

         Vector4& operator/=(const Vector4& rhs) {
            X /= rhs.X;
            Y /= rhs.Y;
            Z /= rhs.Z;
            W /= rhs.W;
            return *this;
         }

         Vector4 operator/(real rhs) const {
            return Vector4(X/rhs, Y/rhs, Z/rhs, W/rhs);
         }

         Vector4& operator/=(real rhs) {
            X /= rhs;
            Y /= rhs;
            Z /= rhs;
            W /= rhs;
            return *this;
         }

         Vector4 operator*(real rhs) const {
            return Vector4(X*rhs, Y*rhs, Z*rhs, W*rhs);
         }

         Vector4 &operator*=(real rhs) {
            X *= rhs;
            Y *= rhs;
            Z *= rhs;
            W *= rhs;
            return *this;
         }

         real& operator[](uword index) {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            case 2: return Z;
            case 3: return W;
            default: THROW(InvalidParameterException());
            }
         }

         const real& operator[](uword index) const {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            case 2: return Z;
            case 3: return W;
            default: THROW(InvalidParameterException());
            }
         }

         real Dot(const Vector4& rhs) const {
            return X*rhs.X+Y*rhs.Y+Z*rhs.Z+W*rhs.W;
         }

         real MagnitudeSq() const {
            return (X*X)+(Y*Y)+(Z*Z)+(W*W);
         }

         real Magnitude() const {
            return t_calc::Sqrt((X*X)+(Y*Y)+(Z*Z)+(W*W));
         }

         Vector4& Normalize() {
            auto mag = Magnitude();
            X /= mag;
            Y /= mag;
            Z /= mag;
            W /= mag;
            return *this;
         }
		};

		typedef Vector4 vec4;
	}
}
#endif
