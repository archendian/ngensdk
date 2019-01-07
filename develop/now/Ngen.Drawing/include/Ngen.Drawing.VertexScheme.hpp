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
#ifndef __NGEN_DRAWING_VERTEXSCHEME_HPP
#define __NGEN_DRAWING_VERTEXSCHEME_HPP

#include "Ngen.Drawing.VertexElement.hpp"

namespace Ngen {
   namespace Drawing {

		class ngen_drawing_api VertexScheme {
		public:
		   /** @brief Creates a new scheme that describes a vertex structure used in a GPU program.
		    * @param name A unique identifier that describes the vertex structure scheme.
          * @param init An ordered list of vertex element information constructs that detail the
          * vertex structure of the scheme.
		    */
			VertexScheme(const string& name, std::initializer_list<VertexElement> init) :
            mName(name), mElementMap(), mSize(0) {
				uword offset = 0;
            uword i = 0;

            // build element offsets and vertex structure size
				for(auto e : init) {
               e.Offset(offset);
					mSize += e.Size();
					offset += e.Size();

               mElementMap.Add(e.Id(), e);
					i++;
				}
			}

			/** @brief The byte-size of the vertex structure being represented by the scheme.  */
			uword Size() const { return mSize; }

			/** @brief The unique identifier that represents the scheme. */
			const mirror Name() const { return mName; }

			/** @brief
			 * @param usage An identifier that describes how the vertex element is used by the program.
			 * @param usageIndex The index describing the processing method of the vertex element. Default: 0
			 */
			VertexElement* Element(const string& usage, uword usageIndex=0) {
				return &mElementMap[usage+string::From(usageIndex)];
			}

         Array<VertexElement> Elements() const {
            return mElementMap.Values();
         }

         void BindElementArray() const {
            auto element = Elements();
            if(!element.IsNullOrEmpty()) {
               auto begin = element.Begin();
               auto end = element.End();
               uword index = 0;

               do {
                  glVertexAttribPointer(index, element.Length(), gl_typeof(begin->Type()), 0, begin->Offset(), 0);
               } while(begin++ != end);
            }
         }
		protected:
			const mirror mName;
			Map<mirror, VertexElement> mElementMap;
			uword mSize;
		};
   }
}

#endif // __NGEN_DRAWING_VERTEXSCHEME_HPP
