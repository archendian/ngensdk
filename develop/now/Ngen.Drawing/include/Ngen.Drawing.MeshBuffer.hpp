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
#ifndef __NGEN_DRAWING_MESHBUFFER_HPP
#define __NGEN_DRAWING_MESHBUFFER_HPP

#include "Ngen.Drawing.VertexScheme.hpp"
#include "Ngen.Drawing.EGpuDrawMode.hpp"
#include "Ngen.Drawing.EGpuBufferUsage.hpp"

namespace Ngen {
   namespace Drawing {


      class ngen_drawing_api MeshBuffer {
      public:
         MeshBuffer()  :
            mScheme(null), mVertexBufferId(0), mVertexBufferSize(0), mVertexBufferLength(0),
            mUsage(EGpuBufferUsage::STATIC_DRAW), mIndexBufferId(0), mIndexBufferLength(0), mIndexBufferHasChanged(false), mVertexBufferHasChanged(false),
            mIndexBufferPtr(0), mMode(EGpuDrawMode::POINT) {
         }

         MeshBuffer(VertexScheme* scheme, EGpuDrawMode mode = EGpuDrawMode::TRIANGLE, EGpuBufferUsage usage = EGpuBufferUsage::STATIC_DRAW) :
            mScheme(scheme), mVertexBufferId(0), mVertexBufferSize(0), mVertexBufferLength(0),
            mUsage(usage), mIndexBufferId(0), mIndexBufferLength(0), mIndexBufferHasChanged(false), mVertexBufferHasChanged(false),
            mIndexBufferPtr(0), mMode(mode) {
         }

         MeshBuffer(VertexScheme* scheme, byte* vertexSubData, uword vertexCount, EGpuDrawMode mode = EGpuDrawMode::TRIANGLE, EGpuBufferUsage usage = EGpuBufferUsage::STATIC_DRAW) :
            mScheme(scheme), mVertexBufferId(0), mVertexBufferSize(mScheme->Size() * vertexCount), mVertexBufferLength(vertexCount), mUsage(usage), mIndexBufferId(0),
            mIndexBufferLength(0), mIndexBufferHasChanged(false), mVertexBufferHasChanged(false), mIndexBufferPtr(0), mMode(mode) {
            SetVertexData(vertexSubData, vertexCount);
         }

         MeshBuffer(VertexScheme* scheme, byte* vertexSubData, uword vertexCount, uint32* indexSubData, uword indexCount, EGpuDrawMode mode = EGpuDrawMode::TRIANGLE, EGpuBufferUsage usage = EGpuBufferUsage::STATIC_DRAW) :
            mScheme(scheme), mVertexBufferId(0), mVertexBufferSize(mScheme->Size() * vertexCount),mVertexBufferLength(vertexCount), mUsage(usage), mIndexBufferId(0),
            mIndexBufferLength(0), mIndexBufferHasChanged(false), mVertexBufferHasChanged(false), mIndexBufferPtr(0), mMode(mode) {
            SetVertexData(vertexSubData, vertexCount);
            SetIndexData(indexSubData, indexCount);
         }

         void SetVertexData(byte* vertexSubData, uword vertexCount) {
            if(mVertexBufferId) {
               glGenBuffers(1, &mVertexBufferId);
            }

            mVertexBufferSize = mScheme->Size() * vertexCount;
            glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
            glBufferData(this->mVertexBufferId, mVertexBufferSize, vertexSubData, gl_typeof(mUsage));
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            mVertexBufferHasChanged = true;
         }

         template<typename T>
         void SetVertexData(T* vertexSubData, uword vertexCount) {
            Initialize();

            mVertexBufferSize = mScheme->Size() * vertexCount;
            glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
            glBufferData(this->mVertexBufferId, mVertexBufferSize, (byte*)vertexSubData, gl_typeof(mUsage));
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            mVertexBufferHasChanged = true;
         }

         void SetIndexData(uint32* indexSubData, uword indexCount) {
             Initialize();

             glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferId);
             glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferLength * sizeof(uint32), indexSubData, gl_typeof(mUsage));
             glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
             mIndexBufferHasChanged = true;
         }

         void Delete() {
            if(mIndexBufferId != 0) {
               glDeleteBuffers(1, &mIndexBufferId);
               mIndexBufferId = 0;
               mIndexBufferLength = 0;
            }

            if(mVertexBufferId != 0) {
               glDeleteBuffers(1, &mVertexBufferId);
               mVertexBufferId = 0;
               mVertexBufferLength = 0;
            }
         }

         unknown IndexBufferPtr() const {
            if(mIndexBufferHasChanged) {
               glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, mIndexBufferLength* sizeof(uint32), mIndexBufferPtr);
            }

            return mIndexBufferPtr;
         }

         uword IndexBufferSize() const {
            return mIndexBufferLength*sizeof(uint32);
         }

         uword IndexBufferLength() const {
            return mIndexBufferLength;
         }

         uword VertexBufferSize() const {
            return mVertexBufferSize;
         }

         uword VertexBufferLength() const {
            return mVertexBufferLength;
         }

         uword VertexBufferId() const {
            return mVertexBufferId;
         }

         uword IndexBufferId() const {
            return mIndexBufferId;
         }

         Array<uint32> Indices() const {
            unknown array = null;
            glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, mIndexBufferLength * sizeof(uint32), array);
            return Array<uint32>((uint32*)array, mIndexBufferLength, 0, false);
         }

         template<typename T>
         Array<T> Vertices() const {
            unknown array = null;
            glGetBufferSubData(GL_ARRAY_BUFFER, 0, mVertexBufferLength * sizeof(T), array);
            return Array<T>((T*)array, mVertexBufferLength, 0, false);
         }

         void Initialize() {
            if(mVertexBufferId == 0) {
               glGenBuffers(1, &mVertexBufferId);
               glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
               mScheme->BindElementArray();
               glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            if(mIndexBufferId == 0) {
               glGenBuffers(1, &mIndexBufferId);
            }
         }

         void Bind() {
            glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferId);
         }

         void Unbind() {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
         }

         void Draw() {
            glDrawElements(gl_typeof(mMode), mVertexBufferLength, GL_UNSIGNED_INT, mIndexBufferPtr);
         }

      protected:
         VertexScheme* mScheme;
         GLuint mVertexBufferId;
         uword mVertexBufferSize;
         uword mVertexBufferLength;
         EGpuBufferUsage mUsage;
         GLuint mIndexBufferId;
         uword mIndexBufferLength;
         bool mIndexBufferHasChanged;
         bool mVertexBufferHasChanged;
         unknown mIndexBufferPtr;
         EGpuDrawMode mMode;
      };
   }
}
#endif // __NGEN_DRAWING_MESHBUFFER_HPP
