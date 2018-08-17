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
#ifndef __NGEN_FILE_HPP
#define __NGEN_FILE_HPP

#include "Ngen.Stream.hpp"
#include "Ngen.Exception.hpp"
#include "Ngen.FileStream.hpp"

using namespace std;

typedef Ngen::string nstring;

namespace Ngen {

   class ngen_api File {
   public:
      static string GetPathExtension(const nstring& path) {
         return path.ReverseReadTo('.');
      }

      static string8 ReadAll(const nstring& fileName) {
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
