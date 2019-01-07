
#ifndef __NGEN_CONTENT_OBJRESOURCEHANDLER_HPP
#define __NGEN_CONTENT_OBJRESOURCEHANDLER_HPP

#include "Ngen.Content.Typedefs.hpp"

namespace Ngen {
	namespace Content {

		struct VertexPNUC {
			vec3f Position;
			vec3f Normal;
			vec2f Uv;
			color4 Color;

			static VertexSemantic* Semantic();
		};

		struct VertexPNU {
			vec3f Position;
			vec3f Normal;
			vec2f Uv;

			static VertexSemantic* Semantic();
		};

		struct VertexPNUUC {
			vec3f Position;
			vec3f Normal;
			vec2f Uv1;
			vec2f Uv2;
			color4 Color;

			static VertexSemantic* Semantic();
		};

		struct VertexPNUCW {
			vec3f Position;
			vec3f Normal;
			vec2f Uv;
			color4 Color;
			real  Weight;

			static VertexSemantic* Semantic();
		};

		VertexSemantic _vertexpnu = VertexSemantic({
			VertexElement(const_string("Position"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Normal"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Uv"), 0, EVertexElementType::Float, 2),
		});

		VertexSemantic _vertexpnuc = VertexSemantic({
			VertexElement(const_string("Position"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Normal"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Uv"), 0, EVertexElementType::Float, 2),
			VertexElement(const_string("Color"), 0, EVertexElementType::Float, 4),
		});

		VertexSemantic _vertexpnuuc = VertexSemantic({
			VertexElement(const_string("Position"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Normal"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Uv"), 0, EVertexElementType::Float, 2),
			VertexElement(const_string("Uv"), 1, EVertexElementType::Float, 2),
			VertexElement(const_string("Color"), 0, EVertexElementType::Float, 4),
		});

		VertexSemantic _vertexpnucw = VertexSemantic({
			VertexElement(const_string("Position"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Normal"), 0, EVertexElementType::Float, 3),
			VertexElement(const_string("Uv"), 0, EVertexElementType::Float, 2),
			VertexElement(const_string("Color"), 0, EVertexElementType::Float, 4),
			VertexElement(const_string("Weight"), 0, EVertexElementType::Float, 1),
		});

		VertexSemantic* VertexPNU::Semantic() { return &_vertexpnu; }
		VertexSemantic* VertexPNUC::Semantic() { return &_vertexpnuc; }
		VertexSemantic* VertexPNUUC::Semantic() { return &_vertexpnuuc; }
		VertexSemantic* VertexPNUCW::Semantic() { return &_vertexpnucw; }

		class ngen_content_api ObjResourceHandler : public virtual ModelResourceHandler {
		public:
			typedef VertexPNU TVertex;

			ObjResourceHandler() {
				mHandler.Add(const_mirror(".obj"), this);
			}

			virtual ~ObjResourceHandler() {
				mHandler.Remove(const_mirror(".obj"));
			}

		protected:

			virtual void pLoad(const string& fileName) {
				auto data = File::ReadLines(fileName);


				auto vertex = Array<vertex_obj>();
				auto indices = Array<uword>();

				vec3f position;
				vec3f normal;
				vec2f uv;
				uword pos_ind=0;
				uword norm_ind=0;
				uword uv_ind=0;
				string tmp;

				for(uword i = 0; i < data.Length(); ++i) {
				char8 c = data[i][0];
				   switch(c) {
				   case '#': continue;
				   case 'v': {
					  c = data[i][1];
					  switch(c) {
						 case ' ': {
							tmp = string(data[i].Begin(2));
							string::ReadData("%f %f %f", tmp, &position.X, &position.Y, &position.Z);
							vertex[pos_ind++].Position = position;
							break;
						 }
						 case 't':
							tmp = string(data[i].Begin(3));
							string::ReadData("%f %f", tmp, &uv.X, &uv.Y);
							vertex[uv_ind++].Uv = uv;
							break;
						 case 'n':
							tmp = string(data[i].Begin(3));
							string::ReadData("%f %f %f", tmp, &normal.X, &normal.Y, &normal.Z);
							vertex[norm_ind++].Normal = normal;
							break;
							break;
					  }
				   }

				   case 'f': {
					  break;
				   }
				   default: continue;
				   }
				}

			}

		} ObjResourceHandlerInstance;
	}
}

#endif
