/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

Copyright (c) 2016 FIXCOM, LLC

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
#ifndef __NGEN_CONTENT_FILE_HPP
#define __NGEN_CONTENT_FILE_HPP

#include "Build.Ngen.Content.Logic.hpp"

namespace Ngen {
    namespace Content {

        class ResourceManager {
        public:
            ResourceManager(const string& library="default") {

            }
        };

        class ResourceHandler {
         public:
            ResourceHandler()

            virtual bool IsSupportedFile(const string& fileName) const pure;
            virtual bool IsSupportedExtension(const string& fileNameExtension) const pure;

            template<typename TResource>
            TResource* Load(const string& fileName, const mirror& id) const {
               Resource* result = null;
               if(!mResource.TryGetValue(id, inref result)) {
                  result = (TResource*)pLoadResource(fileName, id);
               }

               return (TResource*)result;
            }

         protected:
            virtual Resource* pLoadResource(const string& fileName, const mirror& id) pure;
            virtual Resource* pUnloadResource(const string& fileName, const mirror& id) pure;
            virtual Resource* pLoadResource(const string& fileName, uword id) pure;
            virtual Resource* pUnloadResource(const string& fileName, uword id) pure;

            Map<mirror, Resource*> mResource;
        };

        class Resource {
        public:

            Resource(const string& filename=const_string("")) {

            }

        };
    }
}

#endif // __NGEN_CONTENT_FILE_HPP
