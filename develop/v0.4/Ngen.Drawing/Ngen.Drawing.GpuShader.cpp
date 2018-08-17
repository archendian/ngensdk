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

#include "Ngen.Drawing.GpuShader.hpp"

namespace Ngen {
   namespace Drawing {

      GpuShader::GpuShader(EShaderType type, const string& fileName) : mId(0), mType(type) {
         mId = glCreateShader(gl_typeof(type));
         auto source = File::ReadAll(fileName);
         auto len = source.Length();
         auto begin = (GLchar**)source.Begin();
         glShaderSource(mId, 1, begin, (GLint*)&len);
      }

      bool GpuShader::Compile() {
         glCompileShader(mId);

         GLint compiled = false;
         glGetShaderiv(mId, GL_COMPILE_STATUS, &compiled);

         if(!compiled) {
            return false;
         }

         return true;
      }

      bool GpuShader::Compile(string& glerror) {
         glCompileShader(mId);

         GLint compiled = false;
         glGetShaderiv(mId, GL_COMPILE_STATUS, &compiled);

         if(!compiled) {
            GLsizei length = 0;

            glGetShaderiv(mId, GL_INFO_LOG_LENGTH, &length);
            glerror = string(length);
            glGetShaderInfoLog(mId, length, &length, glerror.Begin());

            return false;
         }

         return true;
      }

      void GpuShader::Delete() {
         if(mId != null) {
            glDeleteShader(mId);
            mId = null;
         }
      }


   }
}
