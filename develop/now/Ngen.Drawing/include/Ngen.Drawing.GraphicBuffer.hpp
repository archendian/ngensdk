#ifndef __NGEN_DRAWING_GRAPHICBUFFER_HPP
#define __NGEN_DRAWING_GRAPHICBUFFER_HPP



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

         void Set(ubyte* data, uint64 length, bool shadow=false) {
            if(shadow) {
               mShadow.AddRange(data, length, 0);
               this->mUsage = EGraphicBufferUsage::DYNAMIC_DRAW;
            }

            pSet(data, length);
         }

         template<typename T> T* ShadowAt(uword at=0) {
            if(!HasShadow()) {
               return null;
            }

            return (T*)mShadow.Begin((sizeof(T))*at);
         }

      protected:
         void pSet(ubyte* data, uword length);

         uword mId;
         Array<ubyte> mShadow;
         EGraphicBufferUsage mUsage;
      };
   }
}

#endif // __NGEN_DRAWING_GRAPHICBUFFER_HPP
