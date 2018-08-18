/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2018 FIXCOM, LLC

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
#ifndef __NGEN_MATH_VECTOR3_HPP
#define __NGEN_MATH_VECTOR3_HPP

#include "Ngen.Math.Typedefs.hpp"

namespace Ngen {
	namespace Math {

		class Vector3 {
		public:
			real X;
			real Y;
			real Z;

			Vector3() : X(0), Y(0), Z(0) {}
			Vector3(real xyz) : X(xyz), Y(xyz), Z(xyz) {}
			Vector3(real x, real y, real z) : X(x), Y(y), Z(z) {}
			Vector3(const Vector3& copy) : X(copy.X), Y(copy.Y), Z(copy.Z) {}

			bool operator==(const Vector3& rhs) const {
            return X == rhs.X && Y == rhs.Y && Z == rhs.Z;
			}

			bool operator!=(const Vector3& rhs) const {
            return X != rhs.X || Y != rhs.Y || Z != rhs.Z;
			}

         Vector3& operator=(const Vector3& rhs) {
            X = rhs.X;
            Y = rhs.Y;
            Z = rhs.Z;
            return *this;
         }

         Vector3 operator-() {
            return Vector3(-X, -Y, -Z);
         }

         Vector3 operator-(const Vector3& rhs) const {
            return rhsector3(X - rhs.X, Y - rhs.Y, Z - rhs.Z);
         }

         Vector3& operator-=(const Vector3& rhs) {
            X -= rhs.X;
            Y -= rhs.Y;
            Z -= rhs.Z;
            return *this;
         }

         Vector3 operator+(const Vector3& rhs) const {
            return Vector3(X+rhs.X, Y+rhs.Y, Z+rhs.Z);
         }

         Vector3& operator+=(const Vector3& rhs) {
            X += rhs.X;
            Y += rhs.Y;
            Z += rhs.Z;
            return *this;
         }

         Vector3 operator/(real rhs) const {
            return Vector3(X/rhs, Y/rhs, Z/rhs);
         }

         Vector3& operator/=(real rhs) {
            X /= rhs;
            Y /= rhs;
            Z /= rhs;
            return *this;
         }

         Vector3 operator*(real rhs) const {
            return Vector3(X*rhs, Y*rhs, Z*rhs);
         }

         Vector3 &operator*=(real rhs) {
            X *= rhs;
            Y *= rhs;
            Z *= rhs;
            return *this;
         }

         real& operator[](uword index) {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            case 2: return Z;
            default: return 0.0f;
            }
         }

         const real& operator[](uword index) const {
            switch (index) {
            case 0: return X;
            case 1: return Y;
            case 2: return Z;
            default: return 0.0f;
            }
         }

         Vector3 Cross(const Vector3& rhs) const {
            return Vector3(Y * rhs.Z - Z * rhs.Y,
                           Z * rhs.X - X * rhs.Z,
                           X * rhs.Y - Y * rhs.X);
         }

         real Dot(const Vector3& rhs) const {
            X * rhs.X + Y * rhs.Y + Z * rhs.Z;
         }

         real MagnitudeSq() const {
            return X*X + Y*Y + Z*Z;
         }

         real Magnitude() const {
            return t_calc::Sqrt(X*X + Y*Y + Z*Z);
         }

         Vector3& Normalize() {
            real mag = Magnitude();
            X /= mag;
            Y /= mag;
            Z /= mag;
            return *this;
        }

        static Vector3 Zero();
        static Vector3 Up();
        static Vector3 Down();
        static Vector3 Forward();
        static Vector3 Backward();
		};

		inline Vector3 operator*(real lhs, const Vector3& rhs) {
         return rhs * lhs;
		}
		inline Vector3 operator-(real lhs, const Vector3& rhs) {
         return rhs - lhs;
		}
		inline Vector3 operator+(real lhs, const Vector3& rhs) {
         return rhs + lhs;
		}
		inline Vector3 operator/(real lhs, const Vector3& rhs) {
         return rhs / lhs;
		}

		typedef Vector3 vec3;
	}
}
#endif
