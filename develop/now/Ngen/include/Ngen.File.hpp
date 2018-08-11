#ifndef __NGEN_FILESTREAM_HPP
#define __NGEN_FILESTREAM_HPP

#include "Ngen.Stream.hpp"
#include "Ngen.Exception.hpp"

using namespace std;

namespace Ngen {
   class ngen_api FileStream : public virtual Stream {
   public:
      FileStream() : mIsOpen(false), mCursor(0), mFileName(string::Empty()) {
      }

      FileStream(const string& fileName) : mIsOpen(false), mCursor(0), mFileName(fileName), mFile() {

      }

      ~FileStream() {
         if(this->mIsOpen) {
            this->Close();
         }
      }

      virtual bool IsValid() {
         return mFile.good();
      }

      uint64 Length() {
         if(mLength == 0) {
            this->Open();
            if(!mFile.good()) {
               return 0;
            }

            mCursor = mFile.tellg();
            mFile.seekg(0,ios::end);
            mLength = mFile.tellg();
            mFile.seekg(ios::beg);
         }

         return mLength;
      }

      void Cursor(uint64 set) { mCursor = set; }

      uint64 Cursor() const { return mCursor; }

      void Close() {
         mFile.close();
         mCursor = 0;
         mLength = 0;
      }

      bool Open() {
         if(!mIsOpen) {
            try {
            mFile.open(mFileName.Begin(), ios::in);
            mCursor = 0;
            } catch(exception) {
               THROW(Exception(E"FileStream::Open() - Failed to open file: ~"));
               return false;
            }
         }

         return true;
      }

      string8 ReadToEnd() {
         string8 result = string8::Empty();
         if(!mIsOpen) {
            THROW(Exception(E"FileStream::ReadToEnd() - File not open. ~"));
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
            THROW(Exception(E"FileStream::ReadToEnd() - File not open. ~"));
            return result;
         }

         uword i = 0;
         result = string8(length);
         while (mFile.good() && i < length) {
            result += mFile.get();       // get 8bit character from file.
            mCursor++;
            i++;
            if (mFile.eof()) {
               break;
            }
         }

         return result;
      }

      string8 ReadTo(char8 c) {
         string8 result = string8::Empty();
         if(!mIsOpen) {
            THROW(Exception(E"FileStream::ReadToEnd() - File not open. ~"));
            return result;
         }

         result = string8::Empty();
         while (mFile.good()) {
            char8 tmp = (char8)mFile.get();
            result += tmp;       // get 8bit character from file.
            mCursor++;
            if (mFile.eof() || c == tmp) {
               break;
            }
         }

         return result;
      }

      string8 ReadTo(const Array<char8>& any) {
         string8 result = string8::Empty();
         if(!mIsOpen) {
            THROW(Exception(E"FileStream::ReadToEnd() - File not open. ~"));
            return result;
         }

         result = string8::Empty();
         while (mFile.good()) {
            char8 tmp = (char8)mFile.get();
            result += tmp;       // get 8bit character from file.
            mCursor++;
            if (mFile.eof() || any.Contains(tmp)) {
               break;
            }
         }

         return result;
      }

      string8 ReadTo(const string8& str) {
         string8 result = string8::Empty();
         if(!mIsOpen) {
            THROW(Exception(E"FileStream::ReadToEnd() - File not open. ~"));
            return result;
         }

         result = string8::Empty();
         while (mFile.good()) {
            char8 tmp = (char8)mFile.get();
            result += tmp;       // get 8bit character from file.
            mCursor++;

            if(tmp == str[0]) {
               uword i = 1;
               while(mFile.good() && i < str.Length()) {
                  tmp = (char8)mFile.get();
                  result += tmp;
                  mCursor++;
                  if(str[i] != tmp) {
                     break;
                  } else {
                     i++;
                  }
               }

               break;
            }

            if (mFile.eof()) {
               break;
            }
         }

         return result;
      }

      string8 ReadLine() {
         return ReadTo("\n\r");
      }

      const ifstream& StdStream() const { return mFile; }
      ifstream& StdStream() { return mFile; }

      template<typename... T> void Query(const string& format, T... params) {
         fscanf(mFile, format.Std(), params...);
      }

   protected:
      bool mIsOpen;
      uint64 mCursor;
      string mFileName;
      uint64 mLength;
      ifstream mFile;
   };

   class ngen_api File {
   public:
      static string8 ReadAll(const string& fileName) {
         string8 result = string8::Empty();
         ifstream file;
         file.open(fileName.Begin(), ios::in);
         while (file.good() && !file.eof()) {
            result += file.get();
          }

          file.close();
          return result;
      }

      static Array<string8> ReadLines(const string& fileName) {
         auto result = Array<string8>(1);
         std::string str = std::string();
         ifstream file;

         file.open(fileName.Begin(), ios::in);
         while (file.good() && !file.eof()) {
            std::getline(file, str);
            result.Add(string8(str));
          }

          file.close();
          return result;
      }

      static uint64 Size(const string& fileName) {
         uint64 result;
         ifstream file;

         file.open(fileName.Begin(), ios::in);
         if(!file.good()) {
               return 0;
         }

         file.tellg();
         file.seekg(0,ios::end);
         result = file.tellg();
         file.seekg(ios::beg);
         return result;
      }
   };
}
#endif // __NGEN_FILE_HPP
