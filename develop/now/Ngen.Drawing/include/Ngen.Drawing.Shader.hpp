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
#ifndef __NGEN_DRAWING_SHADER_HPP
#define __NGEN_DRAWING_SHADER_HPP

#include "Ngen.Drawing.EShaderType"

namespace Ngen {

   namespace Drawing {

      class ngen_drawing_api Shader : public class Content::Resource {
      public:
         Shader(const string& name, const string& filename) :
            Content::Resource(name, filename, true), mObject(glCreateShader(typeof(mType))) {

         }

         Shader(const string& name) : Content::Resource(name), mObject(glCreateShader(typeof(mType))), m{

         }

         virtual ~Shader() {
            this->~Content::Resource();
         }

         static Shader FromSource(const string& name, const string& source, bool shadow) {
            auto result = Shader(name);
            result.pSetSource(source, shadow);
            return result;
         }

         uword Object() const { return mObject; }
      protected:
         unknown pShadow(uword& length) {
            length = mSource.Length();
            return (unknown)mSource.ToPointer();
         }

         void pSetSource(const string8& source, bool shadow) {
            if(shadow) {
               uword len = this->mShadow.Length();
               this->pSetShadow(source.ToPointer());
               glShaderSourceARB(mObject, 1, &this->mShadow.ToPointer(), &len);
               return;
            }

            uword len = this->mShadow.Length();
            glShaderSourceARB(mObject, 1, &this->mShadow.ToPointer(), &len);
         }

         uword mObject;
      };
   }
}

#endif // __NGEN_DRAWING_SHADER_HPP
