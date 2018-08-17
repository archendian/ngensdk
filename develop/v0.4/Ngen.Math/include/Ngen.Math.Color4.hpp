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
#ifndef __NGEN_MATH_COLOR4_HPP
#define __NGEN_MATH_COLOR4_HPP

#include "Ngen.Math.Typedefs.hpp"

namespace Ngen {
	namespace Math {
		class Color4 {
		public:
			real R;
			real G;
			real B;
			real A;

			Color4() : R(0), G(0), B(0), A(0) {}
			Color4(real rgba) : R(rgba), G(rgba), B(rgba), A(rgba) {}
			Color4(real r, real g, real b, real a) : R(r), G(g), B(b), A(a) {}
			Color4(const Color4& copy) : R(copy.R), G(copy.G), B(copy.B), A(copy.A) {}

			static Color4 Blue() { return Color4(0.f,0.f,1.f,1.f); }
			static Color4 Green() { return Color4(0.f,1.f,0.f,1.f); }
			static Color4 Red() { return Color4(1.f,0.f,0.f,1.f); }
			static Color4 CornflowerBlue() { return Color4(0.f,0.7f,1.f,1.f); }
		};
	}
}
#endif
