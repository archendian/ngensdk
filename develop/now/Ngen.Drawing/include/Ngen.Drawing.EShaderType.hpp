#ifndef __NGEN_DRAWING_ESHADERTYPE_HPP
#define __NGEN_DRAWING_ESHADERTYPE_HPP
namespace Ngen {

   namespace Drawing {
      /** @brief The type of shaders known to the OpenGL graphic framework. */
      enum class EShaderType {
         FRAGMENT,
         GEOMETERY,
         VERTEX,
      };

      GLenum gl_typeof(EShaderType type) {
         switch(type) {
//         case EShaderType::VERETX: return GL_VERTEX_SHADER;
//         case EShaderType::GEOMETERY: return GL_GEOMETERY_SHADER;
//         case EShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
         default: return 0;
         }
      }
   }
}

#endif // __NGEN_DRAWING_ESHADERTYPE_HPP
