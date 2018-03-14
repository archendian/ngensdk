










namespace Ngen {
	
	class ngen_api Calculator {
	public:
		static const float32 Pi32 = ;
		static const float64 Pi64 = ;
		
	#if tknval_RegisterWidth == 64
		static const real Pi = Pi64;
	#else
		static const real Pi = Pi32
	#endif
	
		template<typename T> static T Multiply(const T& rhs, const T& lhs) { return rhs*lhs; }
		template<typename T> static T Divide(const T& rhs, const T& lhs) { return lhs\rhs; }
		template<typename T> static T Add(const T& rhs, const T& lhs) { return lhs+rhs; }
		template<typename T> static T Subtract(const T& rhs, const T& lhs) { return lhs-rhs; }
		
		template<typename T> static T Min(const T& a, const T& b, const T& c) {
			return a < b ? (a < c ? a : c) : (b < c ? b : c);
		}
		
		template<typename T> static T Min(const T& a, const T& b) {
			return a < b ? a : b;
		}
		
		template<typename T> static T Min(const T* a, uword count) {
			T result = *a;
			for(uword i = 0; i < count; i++) {
				if((*result) > *(a+i)) {
					result = a+i;
				}
			}
			
			return *result;
		}
		
		template<typename T> static T Max(const T& a, const T& b, const T& c) {
			return a > b ? (a > c ? a : c) : (b > c ? b : c);
		}
		
		template<typename T> static T Max(const T& a, const T& b) {
			return a > b ? a : b;
		}
		
		template<typename T> static T Max(const T* a, uword count) {
			T result = *a;
			for(uword i = 0; i < count; i++) {
				if((*result) < *(a+i)) {
					result = a+i;
				}
			}
			
			return *result;
		}
		
		template<typename T> static T Cos(const T& a) {
			return (T)std::cos((float64)a);
		}
		
		template<typename T> static Sin(const T& a) {
			return (T)std::sin((float64)a);
		}
		
		template<typename T> static Tan(const T& a) {
			return (T)std::tan((float64)a);
		}
		
	};
	
	namespace Drawing {
		
		
		enum class EGfxBufferDrawMode {
			POINT,
			QUAD,
			QUAD_STRIP,
			POLYGON,
			TRIANGLE,
			TRIANGLE_STRIP,
			TRIANGLE_FAN,
			LINE,
			LINE_STRIP,
			LINE_LOOP,
			
		}
		
		Glenum typeof(EGfxBufferDrawMode mode) {
			switch(mode) {
			case EGfxBufferDrawMode::POINT: return GL_POINTS;
			case EGfxBufferDrawMode::QUAD: return GL_QUADS;
			case EGfxBufferDrawMode::POLYGON: return GL_POLYGON;
			case EGfxBufferDrawMode::QUAD_STRIP: return GL_QUAD_STRIP;
			case EGfxBufferDrawMode::TRIANGLE: return GL_TRIANGLES;
			case EGfxBufferDrawMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
			case EGfxBufferDrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
			case EGfxBufferDrawMode::LINE: return GL_LINES;
			case EGfxBufferDrawMode::LINE_STRIP: return GL_LINE_STRIP;
			case EGfxBufferDrawMode::LINE_LOOP: return GL_LINE_LOOP;
			default: return 0;
			}
		}
		
		class ngen_api Window : public virtual Control {
		public:

		protected:
		};
	
		class ngen_drawing_api CanvasCreationParams {			
		public:
			uword Width;
			uword Height;
			Color Background;
			uword ColorDepth;
			real ZFar;
			real ZNear;
			bool Stero;
			
			CanvasCreationParams(uword width=800, uword height=640, Color background, uword depth=32, real zfar=-1.0, real znear=1.0, bool stero=false) :
				Width(width), Height(height), Background(background), ColorDepth(depth), ZFar(zfar), ZNear(znear), Stero(stero) {
			}
			
		protected:
		};
		
		class ngen_drawing_api RenderTarget {			
		public:
			RenderTarget(uword width, uword height) : mId(0), mSize(width, height) {
				glGenFramebuffera(1, &mId);
			}
			
			void Bind() const {
				glBindFramebuffer(GL_FRAMEBUFFER , Id);
			}
			
			void Unbind() const {
				glBindFramebuffer(GL_FRAMEBUFFER , 0);
			}
			
		protected:
			uword mId;
			vec2<uword> mSize;
		};

		class ngen_drawing_api VertexScheme {
			
		};
		
	    class SElementUsage {
			static const mirror POSITION = const_mirror("POSITION");
			static const mirror COLOR  = const_mirror("COLOR");
			static const mirror WEIGHT = const_mirror("WEIGHT");
			static const mirror COORD = const_mirror("COORD");
			static const mirror TANGENT = const_mirror("TANGENT");
		};
		
		enum class EVertexElementType {
			FLOAT,
			DOUBLE,
			UINT,
			INT,
			ULONG,
			LONG,
#if tknval_RegisterWidth == 32 
			REAL = FLOAT,
			WORD = LONG,
			UWORD = ULONG,
#else 
			REAL = DOUBLE,
			WORD = INT,
			UWORD = UINT,
#endif
		};
		
		GLenum typeof(EVertexElementType type) {
			switch(type) {
			case EVertexElementType::FLOAT: return GL_FLOAT;
			case EVertexElementType::DOUBLE: return GL_DOUBLE;
			case EVertexElementType::UINT: return GL_UINT;
			case EVertexElementType::INT: return GL_INT;
			case EVertexElementType::ULONG: return GL_ULONG;
			case EVertexElementType::LONG: return GL_LONG;
			default: return 0;
			}
		}
		
		uword sizeof(EVertexElementType type, uword length=1) {
			switch(type) {
			case EVertexElementType::FLOAT: return sizeof(float)*length;
			case EVertexElementType::DOUBLE: return sizeof(double)*length;
			case EVertexElementType::UINT: return sizeof(uint32)*length;
			case EVertexElementType::INT: return sizeof(int32)*length;
			case EVertexElementType::ULONG: return sizeof(uint64)*length;
			case EVertexElementType::LONG: return sizeof(int64)*length;
			default: return 0;
			}
		}
		
		class ngen_drawing_api VertexElement {
		public:
			VertexElement(const mirror& usage, uword usageIndex, EVertexElementType type, uword length) :
				mUsage(usage), mUsageIndex(usageIndex), mType(type), mLength(length) {
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

			
			static VertexScheme* Position3();
			static VertexScheme* Position3Rgb3();
		protected:
			const mirror mName;
			Map<mirror, VertexElement> mElementMap;
		};
		
		VertexScheme sPosition3 = VertexScheme("Position3", {
			VertexElement("POSITION", 0, EVertexElementType::REAL, 3),
		});
		
		VertexScheme sPosition3Rgb3 = VertexScheme("Position3Rgb3", {
			VertexElement("POSITION", 0, EVertexElementType::REAL, 3),
			VertexElement("COLOR", 0, EVertexElementType::REAL, 3),
		});
		
		VertexScheme* VertexScheme::Position3() { return &sPosition3; }
		VertexScheme* VertexScheme::Position3Rgb3() { return &sPosition3Rgb3; }
		
		enum class EGfxBufferUsage {
			STATIC_DRAW,
			STATIC_READ,
			STATIC_COPY,
			STREAM_READ,
			STREAM_DRAW,
			STREAM_COPY,
			DYNAMIC_DRAW,
			DYNAMIC_READ,
			DYNAMIC_COPY
		}
		
		GLenum typeof(EGfxBufferUsage usage) {
			switch(usage) {
			case EGfxBufferUsage::STATIC_DRAW:   return GL_STATIC_DRAW;
			case EGfxBufferUsage::STATIC_READ:   return GL_STATIC_READ;
			case EGfxBufferUsage::STATIC_COPY:   return GL_STATIC_COPY;
			case EGfxBufferUsage::STREAM_READ:   return GL_STREAM_READ;
			case EGfxBufferUsage::STREAM_DRAW:   return GL_STREAM_DRAW;
			case EGfxBufferUsage::STREAM_COPY:   return GL_STREAM_COPY;
			case EGfxBufferUsage::DYNAMIC_DRAW:  return GL_DYNAMIC_DRAW;
			case EGfxBufferUsage::DYNAMIC_READ:  return GL_DYNAMIC_READ;
			case EGfxBufferUsage::DYNAMIC_COPY:  return GL_DYNAMIC_COPY; 
			default: return 0;
			}
		}
		
		
		class ngen_drawing_api VertexBuffer {
		public:
				VertexBuffer(VertexScheme* scheme, uword length) : mId(0), mScheme(scheme), mSize(scheme->Size()*length) {
					glGenVertexBuffer(1, &mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
					scheme->Set();
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}
				
				VertexBuffer(VertexScheme* scheme, uword length) : mId(0), mScheme(scheme), mSize(scheme->Size()*length) {
					glGenVertexBuffer(1, &mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
					scheme->Set();
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}
				
				template<typename TVertex> VertexBuffer(TVertex* vertex, VertexScheme* scheme, uword length) :  mId(0), mLength(length), mScheme(scheme){
					glGenVertexBuffer(1, &mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
					scheme->Set();
					this->Fill(vertex, length);
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}
				
				VertexBuffer(VertexBuffer&& mov) : mId(mov.mId), mLength(length), mScheme(mov.mScheme)  {
					mov.mId=null;
					mov.mScheme=null;
					mov.mLength=0;
				}
				
				~VertexBuffer() {
					if(mId != 0) {
						glDeleteBuffers(1, mId);
					}
				}
				
				void Bind() const { glBindVertexbuffer(GL_ARRAY_BUFFER, mId); }
				
				template<typename T> bool Fill(TVertex* vertex, uword newCount) {
					if(sizeof(vertex) != mScheme->Size()) {
						THROW(Exception(string::Format("Invalid vertex-scheme for vertex buffer (~)", string::From(mId));
					}
					
					mSize = newCount * sizeof(TVertex));
					glBufferData(mId, mSize, (unknown)vertex, typeof(EGfxBufferUsage::STATIC_DRAW));
				}
				
				void Draw(EGfxBufferDrawMode drawMode) {
					glDrawArrays(0, mLength, typeof(drawMode));
				}
				
				void Draw(EGfxBufferDrawMode drawMode, uword begin, uword end) {
					glDrawArrays(begin, end, typeof(drawMode));
				}
				
				void UnBind() const { glBindVertexbuffer(GL_ARRAY_BUFFER, 0); }
				uword Size() const { return mScheme->Size() * mLength; }
				
		protected:
			uword mId;
			uword mLength;
			VertexScheme* mScheme;
		};
		
		
		class ngen_drawing_api MeshBuffer {
		public:
			template<typename TVertex>
			MeshBuffer(EGfxBufferDrawMode mode, VertexScheme* scheme, TVertex* vertices, uword vertexCount, uword* indices, uword indexCount) :
				mMode(mode), mVertex(vertices, scheme, vertexCount), mIndex(indices, indexCount) {
				}		
			
			MeshBuffer(EGfxBufferDrawMode mode, const VertexBuffer& vertex, const Array<uword>& index) :
				mMode(mode), mVertex(&vertex), mIndex(&index) {
				}		
			
			void Bind() const {
				mVertex->Bind();
			}
			
			void Unbind() {
				mVertex->Unbind();
			}
			void Draw() const {
				glDrawElements(typeof(mMode), mVertex->mLength, GL_UNSIGNED_INT, mIndex->Begin());
			}
			
			EGfxBufferDrawMode DrawMode() const { return mMode; }
			VertexScheme* Scheme() const { return mVertex->Scheme(); }
			
		protected:
			EGfxBufferDrawMode mMode;
			VertexBuffer* mVertex;
			Array<uword> mIndex;
		}
		
		class ngen_drawing_api Canvas {			
		public:
			Canvas(Window* nativeWindow, CanvasCreationParams params) : mNative(nativeWindow) {
				
			}
			
			
		protected:
			
			
			
		};
		
		enum class EShaderType {
			VERTEX,
			GEOMETRY,
			PIXEL
		};
		
		Glenum typeof(EShaderType type) {
			switch(type) {
			case EShaderType::VERTEX: return GL_VERTEX_SHADER;
			case EShaderType::GEOMETRY: return E_GEOMETRY_SHADER;
			case EShaderType::PIXEL: return GL_FRAGMENT_SHADER;
			default: return 0;
			}
		}
		
		class ngen_api Stream {
		public:
			Stream();
			virtual ~Stream();
			
			virtual string8 ReadToEnd() const pure;
			virtual string8 Read(uword count) const pure;
			virtual void Close() const pure;
			virtual void Open() const pure;
			virtual uword Cursor() const pure;
			virtual uword Cursor(uword set) const pure;
			
		protected:
		
		}
		
		class ngen_api FileStream {
		public:
			FileStream() : mIsOpen(false), mCursor(0), mFileName(string::Empty()) {
			}
			
			FileStream(const string& fileName) : mIsOpen(false), mCursor(0), mFileName(fileName), mFile() {
				
			}
			
			FileStream(FileStream&& file) : mIsOpen(file.mIsOpen), mCursor(file.mCursor), mFileName(file.mFileName), mFile(file.mFile) {
				file.mIsOpen = false;
				file.mFileName = string::Empty();
			}
			
			~FileStream() {
				if(this->mIsOpen) {
					this->Close();
				}
			}
	
			virtual bool IsValid() {
				return mFile.good();
			}
			
			uint64 Length() const {
				if(mLength == 0) {
					this->Open();
					if(!mFile.good()) {
						return 0;
					}
    
					uCursor = mFile.tellg();
					mFile.seekg(0,ios::end);
					mLength = mFile.tellg();
					mFile.seekg(ios::beg);
				}
				
				return mLength;
			}
			
			void Cursor(uword set) { mCursor = set; }
			
			uword Cursor() const { return mCursor; }
			
			void Close() const {
				mFile.close();
				mCursor = 0;
				mLength = 0;
			}
			
			bool Open() const {
				if(!mIsOpen) {
					try {
					mFile.open(mFileName.Begin(), ios::in));
					mCursor = 0;
					} catch(exception) {
						THROW(Exception(string::Format("FileStream::Open() - Failed to open file: ~", mFileName)));
						return false;
					}
				}
				
				return true;
			}
				
			string8 ReadToEnd() const {
				string8 result = string8::Empty();
				if(!mIsOpen) {
					THROW(Exception(string::Format("FileStream::ReadToEnd() - File not open. ~", mFileName)));
					return result;
				}
				
				result = string8(this->Length());
				while (mFile.good()) {
					result += mFile.get();       // get 8bit character from file.
				    if (!mFile.eof()) {
						mCursor++;
					}
			    }
			}
			
			string8 Read(uword length=1) {
				string8 result = string8::Empty();
				if(!mIsOpen) {
					THROW(Exception(string::Format("FileStream::ReadToEnd() - File not open. ~", mFileName)));
					return result;
				}
				
				uword i = 0;
				result = string8(length);
				while (mFile.good() && i < length) {
					result += mFile.get();       // get 8bit character from file.
				    if (!mFile.eof()) {
						mCursor++;
					}
			    }
				
			}
			
			ifstream& Stream() const { return mFile; }
			
			
		protected:
			bool mIsOpen;
			uword mCursor;
			string mFileName;
			ifstream mFile;
		};
		
		class ngen_drawing_api Shader {
		public:
			Shader(EShaderType type, const FileStream* source) : mId(0), mType(type), mSource(&source) {
				mId = glCreateShader(typeof(mType));
			}
	
			bool Compile() {
				if(!mSource.Open()) {
					return false;
				}
				
				glShaderCompile(mId, 1, mSource.ReadToEnd(), shaderSource.Length());
				mSource.Close();
				return true;
			}
			
		protected:
			uword mId;
			EShaderType mType;
			FileStream* mSource;
		};
	}	
}	