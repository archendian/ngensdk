
#ifndef _NGEN_DRAWING_TEXTURE
#define _NGEN_DRAWING_TEXTURE

#include <GL/gl.h>
#include <GL/wglext.h>
#include <GL/glcorearb.h>

namespace Ngen {
	namespace Drawing {

		extern "C" {
		   unsigned create_array(uword size);
		   unsigned create_array();
            unsigned array_get(unsigned index);

		   // data nodes
		   unsigned load_image(const char* fileName);
		   unsigned new_image(const char* fileName);
            unsigned save_image(unsigned source);

		   unsigned load_video(const char* fileName);
         unsigned new_video(const char* fileName);
            unsigned save_video(unsigned source);

         /*
            PASS Scene ?(Fog) {

            }

            PASS Layer <- Scene {

            }

            BLOCK Curve ? (|2D, |3D) {
               2D? CURVE2D Point;
               3D? CURVE3D Point;
            }


            BLOCK Value[$0] ? (Single, Array, Range) {
               Single|? MULITPLE [$0]    Value;
               Array?   MULTIPLE [$0][]  Array, USIGNED Length;
               Range?   MULTIPLE [$0]    Min, [$0]    Max;
            }

            BLOCK Color ? (Value, |Ramp, |Gradient) {
               Value|?   COLOR4 Color;
               Gradient? COLOR4[] Gradient,
                         COLOR4[] GradientWeight;
               Ramp?     COLOR4 Min, COLOR4 Max;
            }


            PASS Entity[] <- Scene ? (Node, Drawable, Material) {
               Node?       FLOAT3      Origin,
                           HIDDEN BOOL HasChanged;
               Drawable?   MATRIX4  ModelView,
                           BOOL     IsVisible;
               Material    FLOAT    Mass,
                           FLOAT    Friction,
                           FLOAT    Elasticity;
                           FLOAT    Bounce;
                           FLOAT4[] Body;
            }


            PASS Model[] <- Entity+Drawable ? (Position, Color, Normal, UV)
               Position?   FLOAT4   Location;
               Color?      MULTIPLE COLOR4  Color;
               Normal?     MULTIPLE FLOAT4  Normal;
               UV?         MULTIPLE FLOAT4  UV;


            PASS Camera[] : Entity+Node <- Entity+Drawable ? (Windowed, Debug, View)
               FLOAT    AspectRatio;
               FLOAT    FieldOfView;
               MATRIX4  ModelViewProjection;
               View? FLOAT2 ViewLocation,
                     FLOAT2 ViewSize;
               FUNCTION MATRIX4 CalculateProjection() {
                  MATRIX4 mProject;
                  return $Model+Drawable.ViewModel * mProjection;
               }


            PASS Light <- Camera #Omni|Spot|Sun|Direction|Area|Vertex

            EFFECT Diffuse <- Light  ? (Color, Texture, Falloff) {

               Texture|Vertex+UVMap?          MULTIPLE(4) TEXTURE2D   DiffuseTexture;
               Color+Falloff|Vertex+Color?    MULTIPLE    COLOR4      Diffuse;
               Falloff|Vertex                 MULTIPLE    COLOR4      DiffuseEdge;

               SHADER VERTEX {
                  if(!$(CURRENT Model).IsVisible) {
                   // Transforming The Vertex
                   $Vertex.Location = $Camera0.CalculateProject() * $Vertex0.Location;

                   // Transforming The Normal To ModelView-Space
                   normal = gl_NormalMatrix * gl_Normal;

                   // Transforming The Vertex Position To ModelView-Space
                   vec4 vertex_in_modelview_space = gl_ModelViewMatrx * gl_Vertex;

                   // Calculating The Vector From The Vertex Position To The Light Position
                   vertex_to_light_vector = vec3(gl_LightSource[0].position  vertex_in_modelview_space);
                  }
               }
            }
         */
         unsigned load_effect(const char* fileName);
		   unsigned new_effect(const char* fileName);
            unsigned save_effect(unsigned effect);
            unsigned effect_propertysheet(unsigned effect, char**&);
            unsigned effect_function(unsigned effect, char**&);

         // resource nodes
         unsigned create_gpu_canvas
         unsigned create_gpu_shader(const char* source, unsigned shaderType);

         unsigned create_gpu_program(unsigned parent);
            void     gpu_program_link(unsiged program, unsigned shader);
            void     gpu_program_compile(unsigned program);
            void     gpu_program_signed(unsigned program, unsigned property, signed integer);
            signed   gpu_program_signed(unsigned program, unsigned property);
            void     gpu_program_unsigned(unsigned program, unsigned property, unsigned integer);
            unsigned gpu_program_unsigned(unsigned program, unsigned property);
            void     gpu_program_float(unsigned program, unsigned property, unsigned integer);
            unsigned gpu_program_double(unsigned program, unsigned property);
            void     gpu_program_sample(unsigned program, unsigned property, unsigned texture);
            unsigned gpu_program_unsigned(unsigned program, unsigned property);
            void     gpu_program_activate(unsigned program);

         unsigned create_gpu_texture(unsigned image);
         unsigned create_gpu_texture(unsigned width, unsigned height, unsigned pixelFormat);
            unsigned gpu_texture_width(unsigned texture);
            void     gpu_texture_width(unsigned texture, unsigned width);
            unsigned gpu_texture_height(unsigned texture);
            void     gpu_texture_height(unsigned texture, unsigned height);
		}

      class enum EPixelFormat {
         RGBA32 = GL_RGBA32UI,
         RGBA16 = GL_RGBA16UI,
         RGBA8 = GL_RGBA8UI,
         RGB32 = GL_RGB32UI,
         RGB16 = GL_RGB16UI,
         RGB8 = GL_RGB8UI
		};

		class Texture : public RenderTarget {
		private:

			Texture() : RenderTarget() {}
			Texture(uwhole width, uwhole height) : RenderTarget(width, height) {
				mResourceId = glLoadTexture(0, mWidth * mHeight, GL_PIXELFORMAT_RGBA4444);
			}

			Texture(const Image* image) : RenderTarget(image.Width, image.Height) {
				mResourceId = glLoadTexture((byte*)&image[0] , mWidth*mHeight, GL_PIXELFORMAT_RGBA4444);
				mIsLoaded = (mResourceId > 0);

			}


		};


	}
}
#endif
