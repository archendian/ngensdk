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
#ifndef __NGEN_MATH_MATRIX4_HPP
#define __NGEN_MATH_MATRIX4_HPP

#include "Ngen.Math.Typedefs.hpp"
#include "Ngen.Math.Vector3.hpp"
#include "Ngen.Math.Vector4.hpp"

namespace Ngen {
	namespace Math {

		class Matrix4 {
		public:
			real M[16];

			real M00() const { return M[0]; }
			real M01() const { return M[1]; }
			real M02() const { return M[2]; }
			real M03() const { return M[3]; }

			real M10() const { return M[4]; }
			real M11() const { return M[5]; }
			real M12() const { return M[6]; }
			real M13() const { return M[7]; }

			real M20() const { return M[8]; }
			real M21() const { return M[9]; }
			real M22() const { return M[10]; }
			real M23() const { return M[11]; }

			real M30() const { return M[12]; }
			real M31() const { return M[13]; }
			real M32() const { return M[14]; }
			real M33() const { return M[15]; }

			void M00(real m00) { M[0] = m00; }
			void M01(real m01) { M[1] = m01; }
			void M02(real m02) { M[2] = m02; }
			void M03(real m03) { M[3] = m03; }

			void M10(real m10) { M[4] = m10; }
			void M11(real m11) { M[5] = m11; }
			void M12(real m12) { M[6] = m12; }
			void M13(real m13) { M[7] = m13; }

			void M20(real m20) { M[8] = m20; }
			void M21(real m21) { M[9] = m21; }
			void M22(real m22) { M[10] = m22; }
			void M23(real m23) { M[11] = m23; }

			void M30(real m30) { M[12] = m30; }
			void M31(real m31) { M[13] = m31; }
		 	void M32(real m32) { M[14] = m32; }
			void M33(real m33) { M[15] = m33; }

			Matrix4() {}

			Matrix4(real m) {
				for(int i = 0; i < 16; ++i) {
					M[i] = m;
				}
			}

			Matrix4(real m0, real m1, real m2, real m3) {
				M00(m0);
				M01(m0);
				M02(m0);
				M03(m0);

				M10(m1);
				M11(m1);
				M12(m1);
				M13(m1);

				M20(m2);
				M21(m2);
				M22(m2);
				M23(m2);

				M30(m3);
				M31(m3);
				M32(m3);
				M33(m3);
			}

			Matrix4(real m00, real m01, real m02, real m03,
							 real m10, real m11, real m12, real m13,
							 real m20, real m21, real m22, real m23,
							 real m30, real m31, real m32, real m33) {
				M00(m00);
				M01(m01);
				M02(m02);
				M03(m03);

				M10(m10);
				M11(m11);
				M12(m12);
				M13(m13);

				M20(m20);
				M21(m21);
				M22(m22);
				M23(m23);

				M30(m30);
				M31(m31);
				M32(m32);
				M33(m33);
			}

			Matrix4(const Matrix4& copy) {
				for(int i = 0; i < 16; ++i) {
					M[i] = copy.M[i];
				}
			}

			static Matrix4 CreateLookAtPerspective(const Vector3& position, const Vector3& target, const Vector3& up) {
            auto result = Matrix4::Identity();
            auto zaxis = (position - target).Normalize();
            auto xaxis = up.Cross(zaxis).Normalize();
            auto yaxis = zaxis.Cross(xaxis);

            result.M[0] = xaxis.X;
            result.M[1] = yaxis.X;
            result.M[2] = zaxis.X;
            result.M[3] = 0;
            result.M[4] = xaxis.Y;
            result.M[5] = yaxis.Y;
            result.M[6] = zaxis.Y;
            result.M[7] = 0;
            result.M[8] = xaxis.Z;
            result.M[9] = yaxis.Z;
            result.M[10] = zaxis.Z;
            result.M[11] = 0;
            result.M[12] = -xaxis.Dot(position);
            result.M[13] = -yaxis.Dot(position);
            result.M[14] = -zaxis.Dot(position);
            result.M[15] = 1;

            return result;
			}

			static Matrix4 Identity();
		};

		typedef Matrix4 mat4;
	}
}
#endif
