




#include "Ngen.File.hpp"


namespace Ngen {

   Map<FileStream*, ifstream> mOpened;

   FileStream::FileStream(const File* file, EFileAccess accessModifer) : mNode(file), mModifier(accessModifer), mCursor(0), mBuffer(250) {
      mOpened.Add(this, ifstream(file->RelativeFileName()));

   }
   ~FileStream() {
      mOpened.Remove(mOpened);
   }

	void FileStream::Close();
   uword FileStream::Length() const;
   void FileStream::Resize(uword length) const;
   uword FileStream::Offset() const;
   uword FileStream::Forward(uword offset) const;
   uword FileStream::Backward(uword offset) const;
   bool FileStream::ReadByte(uint8*& buffer) const;
   bool FileStream::Read(uint8*& buffer, uword start, uword count) const;
   bool FileStream::WriteByte(uint8 value) const;
   bool FileStream::Write(uint8* buffer, uword start, uword count) const;
   void FileStream::Flush();
   void FileStream::Offset();
}
