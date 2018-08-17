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
#ifndef __NGEN_FILEHANDLER_HPP
#define __NGEN_FILEHANDLER_HPP

#include "Ngen.Mirror.hpp"
#include "Ngen.File.hpp"
#include "Ngen.Map.hpp"

namespace Ngen {

   template<typename TResource>
   class ngen_api FileHandler {
   public:
      FileHandler(const string& extension) : mExtension(extension) {
         Add(extension, this);
      }

      virtual ~FileHandler() {
         Remove(mExtension);
      }

      virtual TResource Extract(const string& fileName) pure;
      virtual void Save(const TResource& obj, const string& fileName) pure;

      static TResource Load(const string& fileName) {
         auto extension = fileName.ReverseReadTo('.');
         if(!Handler.ContainsKey(mirror(extension))) {
            THROW(Exception(E"Unable to locate FileHandler to load resource."));
         }

         return Handler[mirror(extension)].Load(fileName);
      }

      static TResource Save(TResource resource, const string& fileName) {
         auto extension = fileName.ReverseReadTo('.');
         if(!Handler.ContainsKey(mirror(extension))) {
            THROW(Exception(E"Unable to locate FileHandler to load resource."));
         }

         return Handler[mirror(extension)].Save(resource, fileName);
      }

      static FileHandler<TResource>* Get(const string& fileExtension) {
         return Get(mirror(fileExtension));
      }

      static FileHandler<TResource>* Get(const mirror& fileExtension) {
         if(!Handler.ContainsKey((fileExtension))) {
            THROW(Exception(E"Unable to locate FileHandler."));
         }

         return Handler[(fileExtension)];
      }

      static void Add(const mirror& extension, FileHandler<TResource>* add) {
         if(!Handler.ContainsKey((extension))) {
            Handler.Add((extension), add);
         }
      }

      static void Add(const string& extension, FileHandler<TResource>* add) {
         Add(mirror(extension), add);
      }

      static void Remove(const string& extension) {
         Remove(mirror(extension));
      }

      static void Remove(const mirror& extension) {
         Handler.Remove((extension));
      }

      static void Replace(const mirror& extension, FileHandler<TResource>* replace) {
         if(!Handler.ContainsKey((extension))) {
            Handler.Add((extension), replace);
         } else {
            Handler[(extension)] = replace;
         }
      }

      static void Replace(const string& extension, FileHandler<TResource>* replace) {
         Replace(mirror(extension), replace);
      }

      // for each type of 'T' (T being the resource type), we create
      // an instance for Handler (in a cpp file ~ see below)
      static Map<mirror, FileHandler<TResource>*> Handler;

   protected:
      mirror mExtension;
   };

   // Forward declarations of various built-in file-handler types.
   // Each declaration requires a private static instance
   //  of FileHandler<T>::Handler in a .cpp source file.
   // See "Ngen.FileHandler.cpp" for examples.

   typedef Map<string, string> Dictionary;

   typedef FileHandler<ByteArray> ByteArrayHandler;
   typedef FileHandler<Dictionary> DictionaryHandler;
}

#endif // __NGEN_FILEHANDLER_HPP
