#ifndef __NGEN_DRAWING_TEXTURE_HPP
#define __NGEN_DRAWING_TEXTURE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {

   namespace Drawing {

      class ngen_drawing_api Model {
      public:
         Model(MeshBuffer* buffer, initializer_list<Texture*> texture) : mBuffer(buffer), mTexture(texture) {
         }


         void Initialize() {}

         void Draw() {}

         void Delete
      protected:
         MeshBuffer* mBuffer;
         Material* mMaterial;
         Array<Texture*> mTexture;

      };
      class ngen_drawing_api Texture {
      public:
         Texture() : ,Name(), mId(0), mWidth(0), mHeigh(0) {}

         Texture(const string& varName, uword width, uword height, byte* data) : mName(varName), mId(0), mWidth(width), mHeight(height) {
            Initialize();
            Bind();
            SetData(width, height, data);
            Unbind();
         }

         void Delete() {
            glDeleteTextures(1, &mId);
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

         void AttachTo(GpuProgram* program, uword index) const {
            if(mId != null) {
               program->Sampler2d(mName, index)
            } else {
               THROW(Exception(E"Attempted to call Bind() on null texture!"));
            }
         }

         void Unbind() const {
            glBindTexture(GL_TEXTURE_2D, 0);
         }

         /** @brief Sets the RGBA image data for the texture.*/
         void SetImage(uword width, uword height, byte* image) {
            mWidth = width;
            mHeight = height;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, image);
         }

         string Name() const { return mName; }
         void Name(const string& name) { mName = name; }

         GLuint Id() const { return mId; };


      protected:
         string mName;
         GLuint mId;
         uword mWidth;
         uword mHeight;
      };
   }
}
#endif // __NGEN_DRAWING_TEXTURE_HPP
