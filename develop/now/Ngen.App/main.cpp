
#include "Ngen.hpp"
#include "Ngen.Drawing.hpp"

using namespace Ngen;
using namespace Ngen::Drawing;

int main() {
   // create a window to bind a canvas to
   auto window = Window(0, 0, 800, 600, "NGen Framework v.1.0");

   // the configuration for our canvas
   auto params = CanvasCreationParams();
   params.Width = 800;
   params.Height = 600;
   params.ColorDepth = 32;
   params.Stero = false;
   params.ZFar = 100.0f;
   params.ZNear = 0.01f;

   // bind a canvas to the window
   auto canvas = Canvas(&window, params);

   // load content

   // the main loop for the application
   window.Show();
   while(window.HandleMessage()) {
      canvas.Clear();
      canvas.Update();
   }

   return 0;
}
