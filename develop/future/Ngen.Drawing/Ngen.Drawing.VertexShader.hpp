










namespace Ngen {
	namespace Drawing {
		
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
	
	  enum class EPermission {
       Read,
       Write,
       Execute,
       Move,
       Lock,
    };

    enum class EFileAccess {
       Read,
       Write,
       Execute,
    };

    enum class EAppState {
       Opening,
       Closing,
       Updating,
       Drawing
    };


   class ngen_api User {
   public:

   };

   class ngen_api Platform {
   public:

   };

   class ngen_api Application {
   public:
      File* OpenReadLock(const string& pathName) {
         auto file = mWorking.OpenFile(pathName);
         if(isnull(file)) {
            file = File::Open(pathName);
         }

         mLocked.Add(file);
         return file;
      }

      void Unlock(File* file) {
         if(mLocked.Contains(file)) {
            mLocked.Remove(file);
         }
      }

      void ClearLocked() {
         mLocked.Clear();
      }

      void Close();

      virtual bool Updated(ApplicationError& error) pure;
      virtual bool Draw(ApplicationError& error) pure;

      static bool Run(Application* app) {

      }
   protected:
      Folder mWorking;
      File::TPtrArray mLocked;
      User* mUser;
      Platform* mPlatform;
   };

    class ngen_api Folder {
    public:
        typedef Array<Folder> TArray;
        typedef Array<Folder*> TPtrArray;

        Folder(const string& relativePath);

        const string& RelativePath() const { return mRelativePath; }
        const string& FullPath() const;
        bool Exists() const;
        uword SizeInBytes() const;
        uword FileCount() const;
        uword FolderCount() const;
        TArray SubFolders() const;
        Array<File> Files() const;

    protected:
        string mRelativePath;
    };

    class ngen_api File {
    public:
        typedef Array<File> TArray;
        typedef Array<File*> TPtrArray;

        File(const string& path);

        const string& RelativePath() const { return mRelativePath; }
        const string& FullPath() const;
        uword SizeInBytes() const;
        uword Touch() const;
        bool Exists() const;
        bool IsReadOnly() const;
        FileStream* Open(EFileAccess accessModifier) {
            mStreamMap.Add(FileStream(this, accessModifier));
            return mStreamMap[mStreamMap.Length()-1];
        }

        //User Owner() const;
        //Application Holding() const;
        //DateTime LastModified() const; // UTC
    protected:
        string mRelativePath;
        Map<uword, FileStream> mStreamMap; /* session id, stream */
        FileStream* mLock;
    };


    class ngen_api FileStream : public Stream {
    public:
      virtual ~FileStream();
		virtual void Close();
		virtual uword Length() const;
		virtual void Resize(uword length) const;
		virtual uword Offset() const;
		virtual uword Forward(uword offset) const;
		virtual uword Backward(uword offset) const;
		virtual bool ReadByte(uint8*& buffer) const;
		virtual bool Read(uint8*& buffer, uword start, uword count) const;
		virtual bool WriteByte(uint8 value) const;
		virtual bool Write(uint8* buffer, uword start, uword count) const;
		virtual bool CanRead() const { return !mNode.IsReadOnly() && mModifier == EFileAccess.Read; }
		virtual bool CanWrite() const { return !mNode.IsReadOnly() && mModifier == EFileAccess.Write; }
		virtual void Flush();
		
    protected:
        FileStream(const File* file, EFileAccess accessModifer);

        File* mNode;
        EFileAccess mModifier;
        uword mCursor;
        ByteArray mBuffer;

        friend class Folder;
        friend class File;
    };
	
	template<typename T>
	class RpgStat {
	public:
		RpgStat(T current, T bonus=0) : mMax(current), mCurrent(current), mBonus(bonus) {
			
		}
		
		T Max() const { return mMax; }
		T& Current() const { return mMax; }
		T& Bonus() const { return mMax; }
		
		RpgStat& operator-=(T rhs) {
			mCurrent -= rhs;
			return *this;
		}
		
		RpgStat& operator+=(T rhs) {
			mCurrent += rhs;
			return *this;
		}
		
	protected:
		T mMax;
		T mCurrent;
		T mBonus;
	};
	
	template<typename T> using rpg_stat = RpgStat<T>;
	
	class RpgCharacterScheme {
	public:
		RpgCharacterScheme(const mirror& name) : mName(name) {
			mScheme.Add(mirror, *this);
		}
		
		const string& Name() const {
			return mName;
		}
		
		static CharacterScheme* Get(const mirror& name) { return &mScheme[name]; }
	protected:
		mirror mName;
		
		static Map<mirror, CharacterScheme> mScheme;
	};

	struct hero {
		string name;
		
	};
	
	
	class ngen_drawing_api GraphicBuffer {
	public:
		GraphicBuffer(EGfxBufferUsage usage, EGfxBufferUsage::DYNAMIC_DRAW) : mId(0), mUsage(usage), mData(0) {
			
		}
		
		GraphicBuffer(unknown id) : mId(id), mData(0) {
			
		}
		
		GraphicBuffer(uword id, const Array<uint8> data) : mId(id), mUsage(EGfxBufferUsage::DYNAMIC_DRAW), mData(data) {
			
		}
		
		virtual ~GrapicBuffer() {
			if(mId != null) {
					DestroyBuffer();
			}
		}
		
		virtual void Set(const Array<uint8> data) {
			
		}
		
		virtual void Set(const Array<uint8> data, bool shadow) {
			if(shadow) {
				mData = data;
			}
			
			Set(data);
		}
		
		virtual void DeleteBuffer() const;
	protected:
		uknown mId;
		EGfxBufferUsage mUsage;
		Array<uint8> mData;
		