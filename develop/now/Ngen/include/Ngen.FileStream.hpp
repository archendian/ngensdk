/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2018 FIXCOM, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef __NGEN_FILESTREAM_HPP
#define __NGEN_FILESTREAM_HPP

#include "Ngen.String.hpp"
#include "Ngen.Stream.hpp"
#include "Ngen.Exception.hpp"

using namespace std;

typedef Ngen::string nstring;

namespace Ngen {

   class ngen_api FileStream : public virtual Stream {
   public:
      FileStream() : Stream(), mIsOpen(false), mCursor(0), mFileName(nstring::Empty()), mLength(0), mFile() {
      }

      FileStream(const nstring& fileName) : Stream(), mIsOpen(false), mCursor(0), mFileName(fileName), mLength(0), mFile() {

      }

      FileStream(const FileStream& copy) : Stream(), mIsOpen(copy.mIsOpen), mCursor(copy.mCursor), mFileName(copy.mFileName), mLength(copy.mLength), mFile() {
         if(mIsOpen) {
            Close();
         }
      }

      virtual ~FileStream() {
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

          return result;
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

      const ifstream& std_ifstream() const { return mFile; }
      ifstream& std_ifstream() { return mFile; }

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
}

#endif // __NGEN_FILESTREAM_HPP





