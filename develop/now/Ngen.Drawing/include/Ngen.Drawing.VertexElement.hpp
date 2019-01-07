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
#include "Ngen.Drawing.EGpuElementType.hpp"

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api VertexElement {
		public:
		   VertexElement() {}

			VertexElement(const mirror& usage, uword usageIndex, EGpuElementType type, uword length, uword offset=0) :
				mUsage(usage), mUsageIndex(usageIndex), mType(type), mLength(length), mOffset(offset) {
			}

			VertexElement(const string& usage, uword usageIndex, EGpuElementType type, uword length, uword offset=0) :
				mUsage(mirror(usage)), mUsageIndex(usageIndex), mType(type), mLength(length), mOffset(offset) {
			}

			/** @brief Gets the byte size of the vertex element. */
			uword Size() { return gl_sizeof(mType, mLength); }

			/** @brief Gets the unique identifier for the vertex element. */
			const string Id() { return mUsage.ToString() + string::From(mUsageIndex); }

			/** @brief A string used to describe the usage, or intentions, of the vertex element. */
			const mirror Usage() const { return mUsage; }

			/** @brief The usage index which is used when vertex elements in an array have similar intentions, but different
			* processing methods (like two set of UV coordinates).
         */
			uword UsageIndex() const { return mUsageIndex; }
			EGpuElementType Type() const { return mType; }

			/** @brief Gets the number of individual components compiled into the element. A 'Math::Vector3' has three, 'real' typed, components (X, Y, & Z). */
			uword ElementLength() const { return mLength; }

			/** @brief Gets the byte offset of the vertex element in the vertex element array. */
			uword Offset() const { return mOffset; }

			/** @brief The elements byte offset in the vertex element array. */
         void Offset(uword offset) { mOffset = offset; }

		protected:
			mirror mUsage;
			uword mUsageIndex;
			EGpuElementType mType;
			uword mLength;
			uword mOffset;
		};
   }
}
#endif
