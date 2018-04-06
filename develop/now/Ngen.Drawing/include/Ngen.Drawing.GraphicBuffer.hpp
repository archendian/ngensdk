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
#ifndef __NGEN_DRAWING_GRAPHICBUFFER_HPP
#define __NGEN_DRAWING_GRAPHICBUFFER_HPP

#include "Ngen.Drawing.EGraphicBufferUsage.hpp"
#include "Ngen.Drawing.EGraphicDrawMode.hpp"

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api GraphicBuffer {
      public:
         GraphicBuffer(uword id, EGraphicBufferUsage usage) : mId(id), mShadow(), mUsage(usage) {}

         virtual ~GraphicBuffer() {}

         Array<ubyte> Shadow() { return mShadow; }
         uword BufferId() const { return mId; }
         bool HasShadow() const { return !mShadow.IsEmpty(); }
         EGraphicBufferUsage Usage() const { return mUsage; }

         void Set(ubyte* data, uint64 length, EGraphicBufferUsage usage=EGraphicBufferUsage::DYNAMIC_DRAW, bool shadow=false) {
            if(shadow) {
               mShadow.AddRange(data, length, 0);
            }

            this->mUsage = usage;
            pSet(data, length);
         }

         template<typename T> T* ShadowAt(uword at=0) {
            if(!HasShadow()) {
               return null;
            }

            return (T*)mShadow.Begin((sizeof(T))*at);
         }

      protected:
         virtual void pSet(ubyte* data, uword length) pure;

         uword mId;
         Array<ubyte> mShadow;
         EGraphicBufferUsage mUsage;
      };
   }
}

#endif // __NGEN_DRAWING_GRAPHICBUFFER_HPP
