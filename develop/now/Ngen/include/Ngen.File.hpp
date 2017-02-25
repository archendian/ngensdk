#ifndef __NGEN_FILE_HPP
#define __NGEN_FILE_HPP




namespace Ngen {

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
}
#endif // __NGEN_FILE_HPP
