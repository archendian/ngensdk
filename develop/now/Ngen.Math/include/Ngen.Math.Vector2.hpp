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

      template<typename R> class Vector2 {
		public:
		   typedef Vector2<R> TSelf;

			R X;
			R Y;

			Vector2() : X(0), Y(0) {}
			Vector2(R xy) : X(xy), Y(xy) {}
			Vector2(R x, R y) : X(x), Y(y) {}
			template<typename T> Vector2(const Vector2<T>& copy) : X((R)copy.X), Y((R)copy.Y) {}

			template<typename T> bool operator==(const Vector2<T>& rhs) const {
            return X == rhs.X && Y == rhs.Y;
         }

         template<typename T> bool operator!=(const Vector2<T>& rhs) const {
            return X != (R)rhs.X || Y != (R)rhs.Y;
         }

         template<typename T> TSelf operator-(const Vector2<T>& rhs) const {
            return Vector2(X-(R)rhs.X, Y-(R)rhs.Y);
         }

         template<typename T> TSelf operator+(const Vector2<T>& rhs) const {
            return Vector2(X+(R)rhs.X, Y+(R)rhs.Y);
         }

         template<typename T> TSelf operator*(const Vector2<T>& rhs) const {
            return Vector2(X*(R)rhs.X, Y*(R)rhs.Y);
         }

         template<typename T> TSelf operator/(const Vector2<T>& rhs) const {
            return Vector2(X/(R)rhs.X, Y/(R)rhs.Y);
         }

         template<typename T> TSelf& operator-=(const Vector2<T>& rhs) {
            X -= (R)rhs.X;
            Y -= (R)rhs.Y;
            return *this;
         }

         template<typename T> TSelf& operator+=(const Vector2<T>& rhs) {
            X += (R)rhs.X;
            Y += (R)rhs.Y;
            return *this;
         }

         template<typename T> TSelf& operator*=(const Vector2<T>& rhs) {
            X *= (R)rhs.X;
            Y *= (R)rhs.Y;
            return *this;
         }

         template<typename T> TSelf& operator/=(const Vector2<T>& rhs) {
            X /= (R)rhs.X;
            Y /= (R)rhs.Y;
            return *this;         }

         template<typename T> R Dot(const Vector2<T>& rhs) const {
            return (X*(R)rhs.X) + (Y*(R)rhs.Y);
         }

         R Dot() const {
            return (X*X) + (Y*Y);
         }

         template<typename T> R DistanceToSq(const Vector2<T>& rhs) const {
            R x = (X-(R)rhs.X);
            R y = (Y-(R)rhs.Y);
            return ((x*x)+(y*y));
         }

         template<typename T> R DistanceTo(const Vector2<T>& rhs) const {
            R x = (X-(R)rhs.X);
            R y = (Y-(R)rhs.Y);
            return Calculator::Sqrt((x*x)+(y*y));
         }

         template<typename T> TSelf& Roatate(const Vector2<T>& center, R theta) const {
            /** Irrlicht Engine: http://irrlicht.sourceforge.net/docu/vector2d_8h_source.html */
            const float64 c = cos(theta);
            const float64 s = sin(theta);

            X -= center.X;
            Y -= center.Y;

            X = (R)(X * c - Y * s);
            Y = (R)(X * s + Y * c);

            X += center.X;
            Y += center.Y;

            return *this;
         }

         R Magnitude() const {
            return Calculator::Sqrt((X*X) + (Y*Y));
         }

         R MagnitudeSq() const {
            return (X*X) + (Y*Y);
         }

         TSelf& Normalize() {
            R xy = (R)1.0 / Magnitude();
            X *= xy;
            Y *= xy;
            return *this;
         }

         template<typename T> TSelf& Reflect(const Vector2<T> normal) {
            R dot = Dot(normal);
            X = X - (R)2 * dot * (R)normal.X;
            Y = Y - (R)2 * dot * (R)normal.Y;
            return *this;
         }

         template<typename T> TSelf& Lerp(const Vector2<T> dest, R theta) {
            X = X + ((R)dest.X - X) * theta;
            Y = Y + ((R)dest.Y - Y) * theta;
            return *this;
         }

         template<typename T> static Vector2<T> Zero() { return Vector2<T>(); }
         template<typename T> static Vector2<T> Up() { return Vector2<T>(0, 1); }
         template<typename T> static Vector2<T> Down() { return Vector2<T>(0, -1); }
         template<typename T> static Vector2<T> Left() { return Vector2<T>(-1, 0); }
         template<typename T> static Vector2<T> Right() { return Vector2<T>(1, 0); }
         template<typename T> static Vector2<T> UnitX() { return Vector2<T>(1, 0); }
         template<typename T> static Vector2<T> UnitY() { return Vector2<T>(0, 1); }
		};

		typedef Vector2<real> vec2;
		typedef Vector2<uword> vec2u;
		typedef Vector2<word> vec2w;
		typedef Vector2<uint64> vec2u64;
		typedef Vector2<int64> vec2i64;
		typedef Vector2<float64> vec2f64;
	}
}
#endif
