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
#ifndef __NGEN_MACRO_HPP
#define __NGEN_MACRO_HPP

#include "Build.Ngen.Token.hpp"

namespace Ngen {
	struct error_incomplete {};

   /** @brief An RTI macro used to generate a __type construct that is used by the 'typeof' template function to get an Ngen.Type pointer tied to a given C++ typename. */
#  define __set_type_pointer(__TYPENAME__, __TYPEPTR__) template<> struct __type<__TYPENAME__> { Type* value() { return __TYPEPTR__; } }

   /** @brief A macro used to signify that a given C++ typename represents a built-in primitive. */
#  define trait_make_primitive(__TYPENAME__) template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a built-in primitive. */
#  define trait_make_integral(__TYPENAME__)\
   template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } };\
   template<> struct __is_integral<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a built-in primitive. */
#  define trait_make_decimal(__TYPENAME__)\
   template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } };\
   template<> struct __is_decimal<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a movable type. */
#  define trait_make_movable(__TYPENAME__) template<> struct __is_movable<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a nullable primitive pointer type. */
#  define trait_make_nullable(__TYPENAME__) template<> struct __is_nullable<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to set the minimum and maximum possible value for the instance of a C++ typename.
    * @note This relies on the standard C++ std::numeric_limits template and the specialization must be defined prior using this macro.
    */
#  define trait_make_limited(__TYPENAME__)\
      template<> struct __is_limited<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a limited type with minimum and maximum value boundaries. */
#  define trait_make_nullable(__TYPENAME__) template<> struct __is_nullable<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a nullable primitive data type. */
#  define trait_make_nullable_primitive(__TYPENAME__)\
      template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } };\
      template<> struct __is_nullable<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a built-in primitive with the specified limits. */
#  define trait_make_limited_primitive(__TYPENAME__)\
      template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } };\
      template<> struct __is_limited<__TYPENAME__> { static constexpr bool result() { return true; } }

   /** @brief A macro used to signify that a given C++ typename represents a built-in integral primitive with the specified limits.
    * @note This relies on the standard C++ std::numeric_limits template and the specialization must be defined prior using this macro.
    */
#  define trait_make_limited_integral(__TYPENAME__)\
      template<> struct __is_primitive<__TYPENAME__> { static constexpr bool result() { return true; } };\
      template<> struct __is_integral<__TYPENAME__> { static constexpr bool result() { return true; } };\
      template<> struct __is_limited<__TYPENAME__> { static constexpr bool result() { return true; } }


#  define set_typename(TYPENAME, NAME)\
        template<> struct __typename<TYPENAME> {\
            static Ngen::string text() { return const_string(NAME); }\
            static Ngen::mirror mirror() { return const_mirror(__typename<TYPENAME>::text()); }\
        };

#  define __inline_containers(__TYPENAME__)\
      typedef Map<Mirror, __TYPENAME__> TMirrorMap;\
      typedef Map<Mirror, __TYPENAME__*> TPtrMirrorMap;\
      typedef Array<__TYPENAME_> TArray;\
      typedef Array<_TYPENAME__*> TPtrArray;\
      typedef List<__TYPENAME__> TList;\
      typedef List<__TYPENAME__*> TPtrList;\
      typedef __TYPENAME__ TSelf

#  define __inline_standard_containers(__TYPENAME__) \
      typedef Map<Mirror, __TYPENAME__>      Mirror##__TYPENAME__##Map;\
      typedef Map<Mirror, __TYPENAME__*>     Mirror##__TYPENAME__##PtrMap;\
      typedef Array<__TYPENAME__>            __TYPENAME__##Array;\
      typedef Array<__TYPENAME__*>           __TYPENAME__##PtrArray;\
      typedef List<__TYPENAME__>            __TYPENAME__##List;\
      typedef List<__TYPENAME__*>           __TYPENAME__##PtrList
}

#endif // __NGEN_MACRO_HPP
