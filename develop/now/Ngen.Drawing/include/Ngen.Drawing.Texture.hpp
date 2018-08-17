#ifndef __NGEN_DRAWING_TEXTURE_HPP
#define __NGEN_DRAWING_TEXTURE_HPP

namespace Ngen {

   namespace Drawing {

      class ngen_drawing_api Texture {
      public:
         Texture() : mId(0) {}

         Texture(uword width, uword height, byte* data) : mId(0), mWidth(width), mHeight(height) {
            Initialize();
            Bind();
            SetData(width, height, data);
            Unbind();
         }

         void Initialize() {
            if(mId != null) {
               glGenTextures(1, &mId);
            }
         }

         void Bind() const {
            if(mId != null) {
               glBindTexture(GL_TEXTURE_2D, mId);
            } else {
               THROW(Exception(E"Attempted to call Bind() on null texture!"));
            }
         }

         void Unbind() const {
            glBindTexture(GL_TEXTURE_2D, 0);
         }

         void SetData(uword width, uword height, byte* data) {
            mWidth = width;
            mHeight = height;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
         }

         GLuint Id() const { return mId; };

      protected:
         GLuint mId;
         uword mWidth;
         uword mHeight;
      };
   }
}
#endif // __NGEN_DRAWING_TEXTURE_HPP
