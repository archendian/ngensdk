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
#ifndef __NGEN_DRAWING_VERTEXSEMANTIC_HPP
#define __NGEN_DRAWING_VERTEXSEMANTIC_HPP

#include "Ngen.Drawing.VertexElement.hpp"

namespace Ngen {
   namespace Drawing {

		class ngen_drawing_api VertexScheme {
		public:
			VertexScheme(const mirror& name, initialzer_list<VertexElement> init) : mName(name), mElementMap(init.length()) , mSize(0) {
				uword offset = 0;
				for(uword i = 0; i < init.length(); ++i) {
					mElementMap.Add(init[i].Id(), init[i]);
					mElementMap[i].mOffset = offset;
					mSize += init[i].Size();
					offset += init[i].Size();
				}
			}

			uword Size() const { return mSize; }
			const mirror Name() const { return mName; }

			void Set() const {
				for(uowrd i = 0; i < mElementMap.Length(); i++) {
					 glVertexAttribIPointer(i, mElementMap[i].Length(), typeof(mElementMap[i].Type()), 0, mElementMap[i].Offset());
				}
			}

			VertexElement* Element(const string& usage, uword usageIndex) {
				return mElementMap[usage+string::From(usageIndex)];
			}

			/** @brief Xyz */       static VertexScheme* o3();
			/** @brief Xyz, Rgb */  static VertexScheme* o3c3();
		protected:
			const mirror mName;
			Map<mirror, VertexElement> mElementMap;
		};
   }
}

#endif // __NGEN_DRAWING_VERTEXSEMANTIC_HPP
