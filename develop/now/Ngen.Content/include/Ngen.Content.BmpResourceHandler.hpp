
#ifndef __NGEN_CONTENT_BMPRESOURCEHANDLER_HPP
#define __NGEN_CONTENT_BMPRESOURCEHANDLER_HPP

#include "Ngen.Content.Typedefs.hpp"

using namespace Ngen;
using namespace Ngen::Drawing;
using namespace Ngen::Math;

namespace Ngen {
	namespace Content {

		class ngen_content_api BmpResourceHandler : public virtual TextureResourceHandler {
		public:
			BmpResourceHandler() {
				mHandler.Add(const_mirror(".bmp"), this);
			}

			virtual ~BmpResourceHandler() {
				mHandler.Remove(const_mirror(".bmp"));
			}

		protected:

			virtual void pLoad(const string& fileName) {
				auto data = File::ReadAll(fileName);

			}
		};
	}
}

#endif





