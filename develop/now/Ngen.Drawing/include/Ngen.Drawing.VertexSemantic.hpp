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
