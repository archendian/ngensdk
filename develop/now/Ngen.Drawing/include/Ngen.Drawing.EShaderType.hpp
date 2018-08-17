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
#ifndef __NGEN_DRAWING_ESHADERTYPE_HPP
#define __NGEN_DRAWING_ESHADERTYPE_HPP

#include "Build.Ngen.Drawing.Logic.hpp"

namespace Ngen {

   namespace Drawing {
      /** @brief The type of shaders known to the OpenGL graphic framework. */
      enum class EShaderType {
         FRAGMENT,
         GEOMETRY,
         VERTEX,
      };

      GLenum gl_typeof(EShaderType type) {
         switch(type) {
         case EShaderType::VERTEX: return GL_VERTEX_SHADER;
         case EShaderType::GEOMETRY: return GL_GEOMETRY_SHADER;
         case EShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
         default: return 0;
         }
      }
   }
}

#endif // __NGEN_DRAWING_ESHADERTYPE_HPP
