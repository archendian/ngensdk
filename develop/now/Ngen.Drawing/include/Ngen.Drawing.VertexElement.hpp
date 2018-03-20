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
