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
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
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
#ifndef __NGEN_EXCEPTION_HPP
#define __NGEN_EXCEPTION_HPP

#include "Ngen.Typedefs.hpp"

namespace Ngen {
   /** @brief */
   class CompileTimeError {
      CompileTimeError() : mMessage(E"Compile-time error!") {}
      CompileTimeError(estring message) : mMessage(message) {}
      CompileTimeError(const CompileTimeError& copy) : mMessage(copy.mMessage) {}

      /** @brief */
      estring Message() const { return mMessage; }

   protected:
      estring mMessage;
   };

   /** @brief A general purpose exception message used by the framework. */
   class Exception : public virtual std::exception {
   public:
      /** @brief Constructor. Default. */
      Exception() : mMessage(E"Run-time error!") {}
      /** @brief Constructor.
       * @param message The text that will be displayed describing the cause of the exception.
       */
      Exception(estring message) : mMessage(message) {}

      /** @brief Gets the message that describes to potential problem that caused
       * the exception.
       * @note This will generally be encoded using the frameworks default encoding.
       */
      const char8* what() const throw() {
         return (const char8*)mMessage;
      }

   protected:
      estring mMessage;
   };

   /** @brief An exception thrown when invalid prerequisites cause an operation to fail. */
   class InvalidOperationException : public Exception {
   public:
      InvalidOperationException() : Exception(E"Invalid operation!") {}
      InvalidOperationException(const estring message) : Exception(message) {}
   };

   /** @brief An exception thrown when invalid or null parameter causes an operation to fail. */
   class InvalidParameterException : public Exception {
   public:
      InvalidParameterException() : Exception(E"Invalid or null parameter!") {}
      InvalidParameterException(const estring message) : Exception(message) {}
   };

   /** @brief An exception thrown when the program allocates memory beyond the range provided by the system. */
   class OutOfMemoryException : public Exception {
   public:
      OutOfMemoryException() : Exception(E"Out of memory") {}
   };

   /** @brief An exception thrown when a request is made that falls beyond the available range. */
   class OutOfRangeException : public Exception {
   public:
      OutOfRangeException() : Exception(E"Out of range!") {}
      OutOfRangeException(const estring message) : Exception(message) {}
   };

   /** @brief An exception thrown when a function that has not been implemented is invoked. */
   class NotImplementedException : public Exception {
   public:
      NotImplementedException() : Exception(E"Not implemented!") {}
      NotImplementedException(const estring message) : Exception(message) {}
   };

   /** @brief An exception thrown when a incompatible delegates attempt to enforce compatibility. */
   class IncompatibleDelegationException : public Exception {
   public:
      IncompatibleDelegationException() : Exception(E"Incompatible delegate operation!") {}
      IncompatibleDelegationException(const estring message) : Exception(message) {}
   };

   /** @brief An exception thrown if an operation is being performed on a null object instance. */
   class NullReferenceException : public Exception {
   public:
      NullReferenceException() : Exception(E"Null reference!") {}
      NullReferenceException(const estring message) : Exception(message) {}
   };
}


#endif // __NGEN_EXCEPTION_HPP
