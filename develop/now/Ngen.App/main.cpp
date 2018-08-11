
#include "Ngen.hpp"
#include "Ngen.Drawing.hpp"

using namespace Ngen;
using namespace Ngen::Drawing;


int main() {
   auto window = Window(0, 0, 800, 640, const_string("Ngen Framework"));
   window.Show();

   auto ccparam = CanvasCreationParams();
   ccparam.Width = window.Width();
   ccparam.Height = window.Height();
   ccparam.ColorDepth = 32;
   ccparam.Stero = false;
   ccparam.ZFar = 100.0f;
   ccparam.ZNear = 0.01f;
   //ccparam.Background = Color4::Blue();

   auto canvas = Canvas(&window, ccparam);

   while(window.HandleMessage()) {
      canvas.Clear();
      canvas.Update();
   }

   return 0;;
}
