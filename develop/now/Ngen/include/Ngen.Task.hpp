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
#ifndef __NGEN_TASK_HPP
#define __NGEN_TASK_HPP

// TODO

#include "Ngen.Exception.hpp"

namespace Ngen {

	class ngen_api UnitOfWork {
   public:
      UnitOfWork(VoidStaticDelegate<void_t>::TFunction f) { }

   protected:
      T mWork;
	};

   /**@brief
    */
   class ngen_api Task {
	public:

      Task(VoidStaticDelegate<bool&>::TFunction threadStart);

		/** @brief Gets a unique handle used to identify the thread.
		 */
		int64 ThreadId() const;

		/** @brief Determines if the task is still running.
		 */
		bool IsRunning() const;


		void Wait(uword ms);


		/** @brief Gets the task instance for the thread currently being executed.
		 */
		static Task* Current();

		/** @brief Gets all the tasks that were forked as children off the thread currently being executed.
		 */
		static Array<Task*> Forks();
	private:

	   VoidStaticDelegate<UnitOfWork*> mStart;
	   Map<uword, VoidStaticDelegate<UnitOfWork*> mStateStartMap;

		Task() {

		}



		//Application* mParent;

		//friend class Application;
   };
}

#endif // __NGEN_THREAD_HPP
