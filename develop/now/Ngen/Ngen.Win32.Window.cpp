

#include "Ngen.Window.hpp"

namespace Ngen {
#  if tkn_Platform == tknval_Platform_Windows
   LRESULT CALLBACK WindowProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
   MSG win32_AppMessage;
   HDC win32_WindowHDC;
   WNDCLASSEX win32_ClassEx;
   HINSTANCE win32_HInstance = GetModuleHandle(NULL);
   bool win32_Quit;

   LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
       win32_Quit = false;

       switch (uMsg) {
           case WM_CLOSE:
               PostQuitMessage(0);
           break;

           case WM_DESTROY:
               return 0;

           case WM_KEYDOWN:
           {
               switch (wParam) {
                   case VK_ESCAPE:
                       PostQuitMessage(0);
                   break;
               }
           }
           break;

           default:
               return DefWindowProc(hwnd, uMsg, wParam, lParam);
       }

       return 0;
   }

   Window::Window(uword x, uword y, uword width, uword height, const string& title) :
      OnMoved(), OnResized(), OnClosed(), mHandle(0), mX(x), mY(y), mWidth(width), mHeight(height) {
      if(win32_ClassEx.hInstance==0) {
         win32_ClassEx.cbSize = sizeof(WNDCLASSEX);
         win32_ClassEx.style = CS_OWNDC;
         win32_ClassEx.lpfnWndProc = WindowProc;
         win32_ClassEx.cbClsExtra = 0;
         win32_ClassEx.cbWndExtra = 0;
         win32_ClassEx.hInstance = win32_HInstance;
         win32_ClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
         win32_ClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
         win32_ClassEx.lpszMenuName = NULL;
         win32_ClassEx.lpszClassName = "NGENWINDOW";
         win32_ClassEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;
         if (!RegisterClassEx(&win32_ClassEx)) {
            THROW(Exception("Win32 Error: Failed to register window class. RegisterClassEx()"));
            return;
         }
      }

      mHandle = (unknown)CreateWindowEx(0, "NGENWINDOW", title.Begin(),
                            WS_OVERLAPPEDWINDOW,
                            mX, mY, mWidth, mHeight,
                            NULL, NULL, win32_HInstance, NULL);
   }

   Window::~Window() {
      if(mHandle == null) {
         this->Close();
         this->mHandle = null;
      }
   }

   bool Window::HandleMessage() {
      if(mHandle != null) {
         if (PeekMessage(&win32_AppMessage, NULL, 0, 0, PM_REMOVE)) {
            if (win32_AppMessage.message == WM_QUIT) {
                this->Close();
                win32_Quit = true;
                return false;
            }

            TranslateMessage(&win32_AppMessage);
            DispatchMessage(&win32_AppMessage);
         }

         return true;
      }

      return false;
   }

   void Window::Show() {
      ShowWindow((HWND)mHandle, SW_SHOW);
   }

   void Window::Hide() {
      ShowWindow((HWND)mHandle, SW_HIDE);
   }

   void Window::Close() {
      if(mHandle != null) {
         DestroyWindow((HWND)mHandle);
         OnClosed.Fire(this);
      }
   }

   void Window::Resize(uword width, uword y) {
      if(mHandle != null) {
            //
         OnResized.Fire(this);
      }
   }


   void Window::Move(uword x, uword y) {
      if(mHandle != null) {
            //
         OnMoved.Fire(this);
      }
   }
#  endif
}
