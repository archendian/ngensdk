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

namespace Ngen {
	namespace Math {
      enum class ECollisionKind {
         // Simple Collision Kind
         /// @brief No collision.
         NONE,
         /// @brief No collision.  However, the boundaries of the two structures are the minimum distance away from the other.
         OUTSIDE,
         /// @brief Collision.  The boundaries of the two structures are resting inside the same space.
         TOUCHING,
         /// @brief Collision.  The structure is inside the boundary of the other structure.
         INSIDE,
         /// @brief Collision. The other structure is inside the boundary of this structure.
         HOLDING,
          /// @brief Collision. The other structure is partially inside the boundary of this structure.
         CROSSING,
      };

      template<typename R>
      class CollisionResult2D {
      public:
         /// @brief The information gathered for the testing structure.
         ECollisionKind Lhs;

         /// @brief The information gathered for the structure being tested.
         ECollisionKind Rhs;

         /// @brief The smallest distance from each of the two points of collision.
         Line2D<R> CollisonSpace;
      };

      typedef CollisionResult2D<real> collision2d;

      class CollisionResult3D {
      public:
         /// @brief The information gathered for the testing structure.
         ECollisionKind Lhs;

         /// @brief The information gathered for the structure being tested.
         ECollisionKind Rhs;

         /// @brief The smallest distance from each of the two colliding points on each structures.
         Line3D CollisonSpace;
      };

      template<typename R>
		class AxisAlignedBox2D {

      protected:
         typedef AxisAlignedBox2D<R> TSelf;
         typedef Vector2<R> TVec2;

         // Fields
			TVec2 mTopLeft;
			TVec2 mBottomRight;

		public:
		   //Properties
		   TVec2 TopLeft() const { return TVec2(mTopLeft); }
		   void TopLeft(const TVec2& rhs) { mTopLeft = rhs; }

		   TVec2 TopRight() const { return TVec2(mBottomRight.X, mTopLeft.Y); }
		   void TopRight(const TVec2& rhs) { mBottomRight.X = rhs.X; mTopLeft.Y = rhs.Y; }

		   TVec2 BottomRight() const { return TVec2(mBottomRight); }
		   void BottomRight(const TVec2& rhs) { mBottomRight = rhs; }

		   TVec2 BottomLeft() const { return TVec2(mTopLeft.X, mBottomRight.Y); }
		   void BottomLeft(const TVec2& rhs) { mTopLeft.X = rhs.X; mBottomRight.Y = rhs.Y; }

         bool IsValid() const { return mTopLeft.X < mBottomRight.X && mTopLeft.Y > mBottomRight.Y; }

			//Init
         AxisAlignedBox2D () : mTopLeft(0), mBottomRight(0) {}
         AxisAlignedBox2D (const TSelf& copy) : mTopLeft(copy.mTopLeft), mBottomRight(copy.mBottomRight) {}
         AxisAlignedBox2D (const TVec2& mTopLeft, const TVec2& mBottomRight) : mTopLeft(mTopLeft), mBottomRight(mBottomRight) {}
         AxisAlignedBox2D (const TVec2& mTopLeftmBottomRight) : mTopLeft(mTopLeftmBottomRight), mBottomRight(mTopLeftmBottomRight) {}

         //Operators
         template<typename T>
         bool operator==(const AxisAlignedBox2D<T>& rhs) const {
            return mTopLeft == (R)rhs.mTopLeft && mBottomRight == (R)rhs.mBottomRight;
         }

         template<typename T>
         bool operator!=(const AxisAlignedBox2D<T>& rhs) const {
            return mTopLeft != (R)rhs.mTopLeft || mBottomRight != (R)rhs.mBottomRight;
         }

         template<typename T>
         TSelf& operator+=(const AxisAlignedBox2D<T>& rhs) {
            mTopLeft.X = mTopLeft.X > (R)rhs.mTopLeft.X ? (R)rhs.mTopLeft.X : mTopLeft.X;
            mTopLeft.Y = mTopLeft.Y > (R)rhs.mTopLeft.Y ? mTopLeft.Y : (R)rhs.mTopLeft.Y;
            mBottomRight.X = mBottomRight.X > (R)rhs.mBottomRight.X ? mBottomRight.X : (R)rhs.mBottomRight.X;
            mBottomRight.Y = mBottomRight.Y < (R)rhs.mBottomRight.Y ? mBottomRight.Y : (R)rhs.mBottomRight.Y;
            return *this;
         }
         template<typename T>
         TSelf operator+(const AxisAlignedBox2D<T>& rhs) const {
             auto result = TSelf(*this);
             result += rhs;
             return result;
         }

         template<typename T>
         TSelf& operator-=(const TSelf& rhs) {
            mTopLeft.X = mTopLeft.X < (R)rhs.mTopLeft.X ? (R)rhs.mTopLeft.X : mTopLeft.X;
            mTopLeft.Y = mTopLeft.Y < (R)rhs.mTopLeft.Y ? mTopLeft.Y : (R)rhs.mTopLeft.Y;
            mBottomRight.X = mBottomRight.X < (R)rhs.mBottomRight.X ? mBottomRight.X : (R)rhs.mBottomRight.X;
            mBottomRight.Y = mBottomRight.Y > (R)rhs.mBottomRight.Y ? mBottomRight.Y : (R)rhs.mBottomRight.Y;
            return *this;
         }

         template<typename T>
         TSelf operator-(const AxisAlignedBox2D<T>& rhs) const {
             auto result = TSelf(*this);
             result -= rhs;
             return result;
         }

         // Methods
         CollisionResult2D<R> CheckCollision(const TVec2& point) const {
            CollisionResult2D<R> result;
            result.Lhs = result.Rhs = ECollisionKind::NONE;

            bool isHolding = (point.X > mTopLeft.X && point.Y < mTopLeft.Y && point.Y > mBottomRight.Y && point.Y < mBottomRight.X);
            bool isTouching = (point.X == mTopLeft.X && point.Y >= mBottomRight.Y && point.Y <= mTopLeft.Y) ||
                               (point.X == mBottomRight.X && point.Y >= mBottomRight.Y && point.Y <= mTopLeft.Y) ||
                               (point.Y == mTopLeft.Y && point.X >= mTopLeft.X && point.X <= mBottomRight.X) ||
                               (point.Y == mBottomRight.Y && point.X >= mTopLeft.X && point.X <= mBottomRight.X);

            if(isHolding) {
               result.Lhs = ECollisionKind::HOLDING;
               result.Rhs = ECollisionKind::INSIDE;
            } else if(isTouching) {
               result.Lhs = result.Rhs = ECollisionKind::TOUCHING;
            }

            return result;
         }

         CollisionResult2D<R> CheckCollision(R x, R y) const {
            return CheckCollision(TVec2(x, y));
         }
		};

		typedef AxisAlignedBox2D<real> aabox2d;
}
#endif
