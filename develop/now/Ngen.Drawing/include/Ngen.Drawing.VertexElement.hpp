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
#ifndef __NGEN_DRAWING_VERTEXELEMENT_HPP
#define __NGEN_DRAWING_VERTEXELEMENT_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api VertexElement {
		public:
			VertexElement(const mirror& usage, uword usageIndex, EVertexElementType type, uword length) :
				mUsage(usage), mUsageIndex(usageIndex), mType(type), mLength(length), mOffset(0) {
			}

			uword Size() { return sizeof(mType, mLength); }
			const string& Id() { return mUsage.ToString() + string::From(mUsageIndex); }
			const mirror& Usage() const { return mUsage; }
			uword UsageIndex() const { return mUsageIndex; ]
			EVertexElementType Type() const { return mType; }
			uword ElementLength() const { return mLength; }
			uword Offset() const { return mOffset; }

		protected:
			friend class VertexScheme;

			mirror mUsage;
			uword mUsageIndex;
			EVertexElementType mType;
			uword mLength;
			uword mOffset;
		};
   }
}
#endif // __NGEN_DRAWING_VERTEXELEMENT_HPP
