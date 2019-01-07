

#ifndef __NGEN_MATH_RAY2D_HPP
#define __NGEN_MATH_RAY2D_HPP

#include "Ngen.Math.Vector2.hpp"

namespace Ngen {
	namespace Math {

		class Ray2D {
		public:
			Vector2 Location;
			Vector2 Direction;

			Ray2D() : Location(), Direction() {}
			Ray2D(const Vector2& location, Vector2& direction) : Location(location), Direction(direction) {}
			Ray2D(const Ray2D& copy) : Location(copy.Location), Direction(copy.Direction) {}
		};


		typedef Ray2D ray2d;
	}
}
#endif
