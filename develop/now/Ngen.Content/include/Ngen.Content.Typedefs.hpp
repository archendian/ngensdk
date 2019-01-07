
#ifndef __NGEN_CONTENT_TYPEDEFS_HPP
#define __NGEN_CONTENT_TYPEDEFS_HPP

#include "Build.Ngen.Content.Logic.hpp"

namespace Ngen {

	typedef FileHandler<Drawing::Image> ImageResourceHandler;
	typedef FileHandler<Drawing::Texture> TextureResourceHandler;
	typedef FileHandler<Drawing::Model> ModelResourceHandler;
	typedef FileHandler<Drawing::GpuProgram> GpuProgramHandler;
	typedef FileHandler<Drawing::Shader> ShaderHandler;

}

#endif
