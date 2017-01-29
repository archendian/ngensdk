
#ifndef _NGEN_DRAWING_RENDERTARGET
#define _NGEN_DRAWING_RENDERTARGET

namespace Ngen {
	namespace Drawing {

		class RenderTarget {
		public:

			RenderTarget() mGLId(0), mWidth(0), mHeight(0) {}
			RenderTarget(uwhole width, uwhole height) : mGLId(0), mWidth(width), mHeight(height) {}

			uwhole Id() const { return mGLId; }

			uwhole Width const { return mWidth; }
			uwhole Height const { return mWidth; }
			virtual uwhole Width(uwhole value) { mWidth = value; }
			virtual uwhole Height(uwhole value) { mWidth = value; }
		protected:
			uwhole mGLId;
			uwhole mWidth;
			uwhole mHeight;

		};
	}
}
#endif
