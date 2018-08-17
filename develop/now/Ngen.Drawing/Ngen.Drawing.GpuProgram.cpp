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

#include "Ngen.Drawing.GpuProgram.hpp"

namespace Ngen {
   namespace Drawing {
      GpuProgram::GpuProgram() : mId(null), mShader(0) {}

      GpuProgram::GpuProgram(initializer_list<GpuShader*> shader) : mId(0), mShader(shader.size()) {
         mId = glCreateProgram();

         for(uword i = 0; i < mShader.Length(); ++i){
            glAttachShader(mId, mShader[i]->Id());
         }
      }

      bool GpuProgram::Compile() {
         glLinkProgram(mId);

         bool compiled = false;
         glGetProgramiv(mId, GL_COMPILE_STATUS, (GLint*)&compiled);

         if(!compiled) {
            return false;
         }

         return true;
      }

      bool GpuProgram::Compile(string& glerror) {
         glLinkProgram(mId);

         bool compiled = false;
         glGetProgramiv(mId, GL_COMPILE_STATUS, (GLint*)&compiled);

         if(!compiled) {
            GLint length = 0;

            glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &length);
            glerror = string((uword)length);
            glGetProgramInfoLog(mId, length, &length, glerror.Begin());

            return false;
         }

         return true;
      }

      void GpuProgram::Delete() {
         if(mId != null) {
            glDeleteProgram(mId);
            mId = null;
         }
      }

      void GpuProgram::Bind() const {
         glUseProgram(mId);
      }

      void GpuProgram::Unbind() const {
         glUseProgram(null);
      }
   }
}
