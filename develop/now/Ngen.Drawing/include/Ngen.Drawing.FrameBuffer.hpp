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
#ifndef __NGEN_DRAWING_MATERIAL_HPP
#define __NGEN_DRAWING_MATERIAL_HPP

#include "Ngen.Drawing.GpuProgram.hpp"

namespace Ngen {
   namespace Content {

      class ngen_drawing_api FrameBuffer {
      public:
         FrameBuffer() : mId(0) {
            Initialize();
         }

         void Initialize() {
            if(mId == null) {
               glGenFramebuffers(1, &mId);
            }
         }

         void Bind() const {
            glBindFramebuffer(GL_FRAMEBUFFER, mId);
         }

         void BindForDraw() const {
            glBindFramebuffer(GL_FRAMEBUFFER, mId);
         }

         void BindForRead() const {
            glBindFramebuffer(GL_READ_FRAMEBUFFER, mId);
         }

         void Delete() {
            if(mId != null) {
               glDeleteFramebuffers(1, &mId);
               mId = null;
            }
         }

         GLuint Id() const { return mId; }

      protected:
         GLuint mId;
      };
   }
}


#endif // __NGEN_DRAWING_MATERIAL_HPP
