/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 FIXCOM, LLC

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
#ifndef __NGEN_STREAM_HPP
#define __NGEN_STREAM_HPP

#include "Ngen.Exception.hpp"
#include "Ngen.String.hpp"

namespace Ngen {

	class ngen_api Stream {
   public:
      Stream() {}
      virtual ~Stream() {
      }

      /** @brief Reads from the current position of the cursor to the end of the stream.
       */
      virtual Ngen::string8 ReadToEnd() pure;

      /** @brief Reads from the current position of the cursor until a given length or EOF is reached.
       */
      virtual Ngen::string8 Read(uint64 count) pure;

      /** @brief Closes the stream.
       */
      virtual void Close() pure;

      /** @brief Opens the stream.
       */
      virtual bool Open() pure;

      /** @brief Gets the current cursor position.
       */
      virtual Ngen::uint64 Cursor() const pure;

      /** @brief Sets the current cursor position.
       */
      virtual void Cursor(Ngen::uint64 set) pure;
	};
}

#endif // __NGEN_STREAM_HPP
