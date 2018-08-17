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
#ifndef __NGEN_DRAWING_TYPEDEFS_HPP
#define __NGEN_DRAWING_TYPEDEFS_HPP

#include "Build.Ngen.Drawing.Logic.hpp"

namespace Ngen {
   namespace Drawing {
      class Canvas;
      class Shader;
      class Texture;
      class GpuElement;
      class GpuScheme;
      class GpuProgram;
      class MeshBuffer;

      template<typename T> struct gl_set_uniform {
         gl_set_uniform(uword location, const T& value) {
            THROW(NotImplementedException());
         }
      };

      template<> struct gl_set_uniform<float> {
         gl_set_uniform(uword location, const real& value) {
            glUniform1f(location, value);
         }
      };

      template<> struct gl_set_uniform<double> {
         gl_set_uniform(uword location, const real& value) {
            glUniform1d(location, value);
         }
      };

      template<> struct gl_set_uniform<uint32> {
         gl_set_uniform(uword location, const uint32& value) {
            glUniform1i(location, value);
         }
      };

      template<> struct gl_set_uniform<Math::Vector2> {
         gl_set_uniform(uword location, const Math::Vector2& value) {
            glUniform2f(location, value.X, value.Y);
         }
      };

      template<> struct gl_set_uniform<Math::Vector3> {
         gl_set_uniform(uword location, const Math::Vector3& value) {
            glUniform3f(location, value.X, value.Y, value.Z);
         }
      };

      template<> struct gl_set_uniform<Math::Vector4> {
         gl_set_uniform(uword location, const Math::Vector4& value) {
            glUniform4f(location, value.X, value.Y, value.Z, value.W);
         }
      };

      template<> struct gl_set_uniform<Math::Matrix3> {
         gl_set_uniform(uword location, const Math::Matrix3& value) {
            //glUniformMatrix3fv(location, 9, false, (GLfloat*)&value.M);
         }
      };

      template<> struct gl_set_uniform<Math::Matrix4> {
         gl_set_uniform(uword location, const Math::Matrix4& value) {
            //glUniformMatrix4fv(location, 16, false, &value.M);
         }
      };
   }
}

#endif // __NGEN_DRAWING_TYPEDEFS_HPP
