
/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2014 NGENWARE

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
#include "Ngen.File.hpp"
#include "Ngen.FileHandler.hpp"

namespace Ngen {

   // -------------------------------------------------------
   // ByteArray (Array<byte>) FileHandler instances
   // -------------------------------------------------------
   template<>
   Map<mirror, FileHandler<ByteArray>*> ByteArrayHandler::Handler = Map<mirror, ByteArrayHandler*>();

   // -- .bytes
   class bytes_FileHandler : virtual ByteArrayHandler {
   public:
      bytes_FileHandler() : ByteArrayHandler(".bytes") {

      }

      ByteArray Extract(const string& fileName) {
         auto bytes = File::ReadAll(fileName);
         auto length = *(uword*)bytes.Begin();
         byte* byteptr = (byte*)bytes.Begin(sizeof(uword));

         return ByteArray(byteptr, length, false);
      }

      void Save(const ByteArray& obj, const string& fileName) {
         auto stream = FileStream(fileName);
         stream.Open();

         //stream.Write(obj.Length());
         //stream.Write(obj.Begin(), obj.Length());

         stream.Close();
      }
   };

   auto _bytes_FileHandlerInstance = bytes_FileHandler();

   // -------------------------------------------------------
   // Dictionary (Map<string, string>) FileHandler instances
   // -------------------------------------------------------
   template<> Map<mirror, DictionaryHandler*> DictionaryHandler::Handler = Map<mirror, DictionaryHandler*>();

   // .dictionary
   class dict_FileHandler : public virtual DictionaryHandler {
   public:
      dict_FileHandler() : DictionaryHandler(".dictionary") {

      }

      virtual Dictionary Extract(const string& fileName) {
         auto data = File::ReadAll(fileName);
         auto kvlen = *(uword*)data.Begin();
         auto result = Dictionary();
         auto charptr = data.Begin() + sizeof(uword);
         uword keylen = 0;
         uword vallen = 0;
         string key = string::Empty();
         string value = string::Empty();

         for(uword i = 0; i < kvlen; ++i) {
            keylen = *(uword*)charptr;
            charptr+=sizeof(uword);
            key = string(charptr, keylen, false);
            charptr+=keylen;

            vallen = *(uword*)charptr;
            charptr+=sizeof(uword);
            value = string(charptr, vallen, false);

            result.Add(key, value);
         }

         return result;
      }

      virtual void Save(const Dictionary& obj, const string& fileName) {
         auto file = FileStream(fileName);
         auto array = obj.ToArray();
         file.Open();

         //file.Write(obj.Length());

         for(uword i=0; i<array.Length(); ++i) {
            //auto kv = array.Begin(i);
            //file.Write(kv->Key.Length());
            //file.Write(kv->Key);
            //file.Write(kv->Value.Length());
            //file.Write(kv->Value);
         }

         file.Close();
      }
   };

   auto _dictFileHandlerInstance = dict_FileHandler();
}
