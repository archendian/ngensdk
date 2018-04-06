#ifndef __NGEN_FILESTREAM_HPP
#define __NGEN_FILESTREAM_HPP

#include "Ngen.Stream.hpp"

using namespace std;

namespace Ngen {
   class ngen_api FileStream : public virtual Stream {
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

      void Cursor(uint64 set) { mCursor = set; }

      uint64 Cursor() const { return mCursor; }

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

      string8 Read(uint64 length=1) {
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
      uint64 mCursor;
      string mFileName;
      ifstream mFile;
   };

   class ngen_api File {
   public:
      static string8 ReadAll(const string& fileName) {
         string8 result = string8::Empty();
         ifstream file;
         file.open(fileName.Begin(), ios::in);
         result = string8(this->Length());
         while (file.good() && !file.eof()) {
            result += file.get();
          }

          file.close();
          return result;
      }
   };
}
#endif // __NGEN_FILE_HPP
