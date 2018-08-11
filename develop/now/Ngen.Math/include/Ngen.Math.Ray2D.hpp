

#ifndef __NGEN_MATH_RAY2D_HPP
#define __NGEN_MATH_RAY2D_HPP

#include "Ngen.Math.Vector2.hpp"

namespace Ngen {
	namespace Math {
      template<typename R>
		class Ray2D {
		public:
			Vector2<R> Location;
			Vector2<R> Direction;

			Ray2D() : Location(0), Direction(0) {}
		};


		typedef Ray2D<real> ray2d;
	}
}
#endif
