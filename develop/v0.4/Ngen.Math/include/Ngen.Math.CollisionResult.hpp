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
#ifndef __NGEN_MATH_COLLISIONRESULT_HPP
#define __NGEN_MATH_COLLISIONRESULT_HPP

#include "Ngen.Math.Line2D.hpp"
#include "Ngen.Math.Line3D.hpp"

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

      class CollisionResult2D {
      public:
         /// @brief The information gathered for the testing structure.
         ECollisionKind Lhs;

         /// @brief The information gathered for the structure being tested.
         ECollisionKind Rhs;

         /// @brief The smallest distance from each of the two points of collision.
         Line2D CollisonSpace;
      };

      typedef CollisionResult2D collision2d;

      class CollisionResult3D {
      public:
         /// @brief The information gathered for the testing structure.
         ECollisionKind Lhs;

         /// @brief The information gathered for the structure being tested.
         ECollisionKind Rhs;

         /// @brief The smallest distance from each of the two colliding points on each structures.
         Line3D CollisonSpace;
      };

      typedef CollisionResult3D collision3d;
   }
}

#endif // __NGEN_MATH_COLLISIONRESULT_HPP
