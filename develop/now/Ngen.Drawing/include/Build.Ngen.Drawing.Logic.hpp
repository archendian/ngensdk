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
#ifndef __NGEN_BUILD_DRAWING_LOGIC_HPP
#define __NGEN_BUILD_DRAWING_LOGIC_HPP

#include <Ngen.hpp>
#include <Ngen.Math.hpp>
#include <GL/glew.h>

#define NGEN_DRAWING_MAX_LIGHT 100

/** @brief Used to export or import public symbols from the framework. */
#if _tkn_Platform == _tknval_Platform_Windows
#  ifdef NGEN_DRAWING_EXPORT
#       define ngen_drawing_api __declspec(dllexport)
#  elif defined(__MINGW32__)
#     define ngen_drawing_api
#  else
#     define ngen_drawing_api __declspec(dllimport)
#  endif
#else // other supported platforms (Linux, MacOSX and iPhone)
#	if (__GNUC__ >= 4) // && defined(NGEN_EXPORT)
#       ifdef(NGEN_DRAWING_EXPORT)
#		    define ngen_drawing_api __attribute__ ((visibility("default")))
#       else
#           define ngen_drawing_api
#       endif
      /** @brief Used to export or import private symbols from the framework. */
#		define ngen_drawing_api_private __attribute__ ((visibility("hidden")))
#	else
#     define ngen_drawing_api
      /** @brief Used to export or import private symbols from the framework. */
#     define ngen_drawing_api_private
#	endif
#endif

#endif // __BUILD_NGEN_DRAWING_LOGIC_HPP
