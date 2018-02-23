#include <windows.h>
#include <gl/gl.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

class ngen_io IOManager {
public:
   IOManager();


protected:

};

class ngen_io Device {
public:
  Device(const mirror& name, const string& desc) : mName(name), mDescription(desc) {}
  virtual ~Device();

  const mirror Name() const { return mName; }
  const string Description() const { return mDescription; }
  bool Poll(unknown systemEvent)
protected:
   mirror mName;
   string mDescription;
};

class ngen_io DeviceDriver {

};

class ngen_io DisplayAdapterDriver : public virtual DisplayAdapterDriver {
public:
   DisplayAdapterDriver(uword id) : public DeviceDriver {

   }

   virtual Device* GetDevice(uword index) {
      return (Device*)mAdapter[index];
   }

   virtual Display* GetDisplayDevice(uword adapter, uword display) {
      return )mAdapter[index].GetDisplay(display);
   }

protected:
   uword mId;
   Array<DisplayAdapter> mAdapter;

};

class ngen_io DisplayMode {
public:
   DisplayMode() : mWidth(0), mHeight(0), mHz(0) {}
   DisplayMode(uword height, uword hz) : mWidth(width), mHeight(height), mHz(hz) {}
   DisplayMode(const DisplayMode& copy) : mWidth(copy.Width), mHeight(copy.Height), mHz(copy.Hz) {}

   bool operator== (const DisplayMode& rhs) const {
      return mWidth == rhs.mWidth && mHeight == rhs.mHeight && mHz == rhs.mHz;
   }

   bool operator!= (const DisplayMode& rhs) const {
      return mWidth != rhs.mWidth && mHeight != rhs.mHeight && mHz != rhs.mHz;
   }

   string ToString() const {
      return string::Format("~ x ~, ~hz"{ string::From(mWidth), string::From(mHeight), string::From(mHz)});
   }

   uword Width() const { return mWidth; }
   uword Height() const { return mHeight; }
   uword Hz() const { return mHz; }

protected:
   uword mWidth;
   uword mHeight;
   uword mHz;
};

/** @brief A device driver for hardware accelerated display drivers and graphic cards.
 */
class ngen_io DisplayAdapter : public virtual Device {
public:
   DisplayAdapter(const string& name, const string& desc) :  this->Name(name), this->Description(desc), mDisplay(0) {}

   virtual ~DisplayAdapter();

   const Display* GetDisplay(uword index) const {
      return mDisplay.Begin(index);
   }

   const Display* operator[](uword index) {
      return mDisplay.Begin(index);
   }

protected:
   Array<Display> mDisplay;

   friend class DeviceManager;
};

class ngen_io Display : public virtual Device {
public:
   Display(const string& name, const string& desc, const DisplayAdapter* parent, array<DisplayMode> modes) :
      this->Name(name), this->Description(desc), this->mAdapater(parent), mDisplayMode(modes),
         mIndex(parent->mDisplay.Length()) {
   }


protected:
   DisplayAdapter* mAdapater;
   Array<DisplayMode> mDisplayMode;
};

class ngen_draw_gui Gui {
public:
};

class ngen_draw_gui Control {
public:
   Control(const string& title) :
   vec2<int32> LocationToParent() const {
      return mRelativeLocation;
   }

   vec2<int32> LocationToDisplay() const {
      return mParent == null ? mRelativeLocation :
         mRelativeLocation + mParent.LocationToDisplay();
   }

   vec2<int32> Size() const { return mSize; }
   Display* ParentDisplay() { return mDisplay; }
   DisplayAdapter* ParentDisplayAdapter() { return mDisplay->Adapter(); }

   bool Update(Message* systemMessage) const pure;
   bool Draw(Message* systemMessage) const pure;

   Control* Parent() const { return mParent; }
   Control* Highest() const {
      auto result = mParent;
      bool top = false;

      do {
         if(result != null) {
            if(result->mParent != null) {
              result = result->mParent;
            } else {
               top = true;
            }
         } else {
            top = true;
         }
      }while(top==false)

      return result == null ? this : result;
   }

protected:
   Control* mParent;
   Display* mDisplay;
   vec2<int32> mSize;
   vec2<int32> mRelativeLocation;   // location relative to parent location (top-left)
   array<Control> mChildren;
};

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          256,
                          256,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();
            glRotatef(theta, 0.0f, 0.0f, 1.0f);

            glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

            glEnd();

            glPopMatrix();

            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
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

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

