/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 FIXCOM, LLC

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

#include "Ngen.Math.hpp"

namespace Ngen {
   namespace Math {
      // Vector3 constants

      Vector3 _zeroVector3 = Vector3(0.f, 0.f, 0.f);
      Vector3 _upVector3 = Vector3(0.f, 1.f, 0.f);
      Vector3 _downVector3 = Vector3(0.f, -1.f, 0.f);
      Vector3 _unitXVector3 = Vector3(1.f, 0.f, 0.f);
      Vector3 _unitYVector3 = Vector3(0.f, 1.f, 0.f);
      Vector3 _unitZVector3 = Vector3(0.f, 0.f, 1.f);

      Vector3 Vector3::Up() { return _upVector3; }
      Vector3 Vector3::Down() { return _downVector3; }
      Vector3 Vector3::UnitX() { return _unitXVector3; }
      Vector3 Vector3::UnitY() { return _unitYVector3; }
      Vector3 Vector3::UnitZ() { return _unitZVector3; }

      // Matrix4 constants

      Matrix4 _identityMatrix4 = Matrix4(1.0f, 0.f, 0.f, 0.f,
                                         0.f, 1.0f, 0.f, 0.f,
                                         0.f, 0.f, 1.0f, 0.f,
                                         0.f, 0.f, 0.f, 1.0f);

      Matrix4 Matrix4::Identity() { return _identityMatrix4; }
   }
}
