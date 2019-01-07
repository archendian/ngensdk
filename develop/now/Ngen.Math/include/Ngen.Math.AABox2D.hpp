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
#ifndef __NGEN_MATH_AABOX2D_HPP
#define __NGEN_MATH_AABOX2D_HPP

#include "Ngen.Math.Vector2.hpp"
#include "Ngen.Math.Line2D.hpp"
#include "Ngen.Math.CollisionResult.hpp"

namespace Ngen {
	namespace Math {

		class AxisAlignedBox2D {
      public:
			Vector2 TopLeft;
			Vector2 BottomRight;

         AxisAlignedBox2D () : TopLeft(), BottomRight() {}
         AxisAlignedBox2D(real x, real y, real width, real height) : TopLeft(x, y), BottomRight(x+width, y+height) {}
         AxisAlignedBox2D (const AxisAlignedBox2D& copy) : TopLeft(copy.TopLeft), BottomRight(copy.BottomRight) {}
         AxisAlignedBox2D (const Vector2& TopLeft, const Vector2& BottomRight) : TopLeft(TopLeft), BottomRight(BottomRight) {}
         AxisAlignedBox2D (const Vector2& TopLeftBottomRight) : TopLeft(TopLeftBottomRight), BottomRight(TopLeftBottomRight) {}

         //Operators
         bool operator==(const AxisAlignedBox2D& rhs) const {
            return TopLeft == rhs.TopLeft && BottomRight == rhs.BottomRight;
         }

         bool operator!=(const AxisAlignedBox2D& rhs) const {
            return TopLeft != rhs.TopLeft || BottomRight != rhs.BottomRight;
         }

         AxisAlignedBox2D& operator+=(const AxisAlignedBox2D& rhs) {
            TopLeft.X = TopLeft.X > rhs.TopLeft.X ? rhs.TopLeft.X : TopLeft.X;
            TopLeft.Y = TopLeft.Y > rhs.TopLeft.Y ? TopLeft.Y : rhs.TopLeft.Y;
            BottomRight.X = BottomRight.X > rhs.BottomRight.X ? BottomRight.X : rhs.BottomRight.X;
            BottomRight.Y = BottomRight.Y < rhs.BottomRight.Y ? BottomRight.Y : rhs.BottomRight.Y;
            return *this;
         }

         AxisAlignedBox2D operator+(const AxisAlignedBox2D& rhs) const {
             auto result = AxisAlignedBox2D(*this);
             result += rhs;
             return result;
         }

         AxisAlignedBox2D& operator-=(const AxisAlignedBox2D& rhs) {
            TopLeft.X = TopLeft.X < rhs.TopLeft.X ? rhs.TopLeft.X : TopLeft.X;
            TopLeft.Y = TopLeft.Y < rhs.TopLeft.Y ? TopLeft.Y : rhs.TopLeft.Y;
            BottomRight.X = BottomRight.X < rhs.BottomRight.X ? BottomRight.X : rhs.BottomRight.X;
            BottomRight.Y = BottomRight.Y > rhs.BottomRight.Y ? BottomRight.Y : rhs.BottomRight.Y;
            return *this;
         }

         AxisAlignedBox2D operator-(const AxisAlignedBox2D& rhs) const {
             auto result = AxisAlignedBox2D(*this);
             result -= rhs;
             return result;
         }

         // Methods
         Vector2 TopRight() const { return Vector2(BottomRight.X, TopLeft.Y); }
		   void TopRight(const Vector2& rhs) { BottomRight.X = rhs.X; TopLeft.Y = rhs.Y; }

		   Vector2 BottomLeft() const { return Vector2(TopLeft.X, BottomRight.Y); }
		   void BottomLeft(const Vector2& rhs) { TopLeft.X = rhs.X; BottomRight.Y = rhs.Y; }

		   real X() const { return TopLeft.X; }
		   real Y() const { return TopLeft.Y; }
		   real Width() const { return BottomRight.X - TopLeft.X; }
		   real Height() const { return BottomRight.Y - TopLeft.Y; }

         bool IsValid() const { return TopLeft.X < BottomRight.X && TopLeft.Y > BottomRight.Y; }

         CollisionResult2D CheckCollision(const Vector2& point) const {
            CollisionResult2D result;
            result.Lhs = result.Rhs = ECollisionKind::NONE;

            bool isHolding =  (point.X > TopLeft.X && point.Y < TopLeft.Y && point.Y > BottomRight.Y && point.Y < BottomRight.X);
            bool isTouching = (point.X == TopLeft.X && point.Y >= BottomRight.Y && point.Y <= TopLeft.Y) ||
                              (point.X == BottomRight.X && point.Y >= BottomRight.Y && point.Y <= TopLeft.Y) ||
                              (point.Y == TopLeft.Y && point.X >= TopLeft.X && point.X <= BottomRight.X) ||
                              (point.Y == BottomRight.Y && point.X >= TopLeft.X && point.X <= BottomRight.X);

            if(isHolding) {
               result.Lhs = ECollisionKind::HOLDING;
               result.Rhs = ECollisionKind::INSIDE;
            } else if(isTouching) {
               result.Lhs = result.Rhs = ECollisionKind::TOUCHING;
            }

            return result;
         }

         CollisionResult2D CheckCollision(real x, real y) const {
            return CheckCollision(Vector2(x, y));
         }
		};

		typedef AxisAlignedBox2D aabox2d;
	}
}
#endif
