
#include "Ngen.hpp"
#include "Ngen.Drawing.hpp"
#include "Ngen.Math.hpp"

using namespace Ngen;
using namespace Ngen::Drawing;

typedef SVertexO vertex_t;

auto vertex_scheme = vertex_t::Scheme();
auto vertex_array = Array<vertex_t>();
auto index_array = Array<uint32>();

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
   params.Background = Color4::CornflowerBlue();

   // bind a canvas to the window
   auto canvas = Canvas(&window, &params);

   // setup the camera
   auto camera = Camera(Vector3::Zero(), Vector3(10.f, 5.f, 10.f));

   // create a viewport (not neccessary)
   auto viewport = Viewport(&canvas, 0, 0, canvas.Width(), canvas.Height());

   // load some content
   auto gui = Gui(&canvas);
   auto messageBox = GuiMessageBox(&gui, const_string("Press OK to close the window."), [](GuiElement* self) {
                           messageBox.Close();
                        });
   auto panel =  GuiPanel(&gui, )
   gui.AddElement()
   // the main loop for the application
   window.Show();

   while(window.HandleMessage()) {

      camera.Bind();
      scene.Update();
      canvas.Clear();
      // draw scene
      scene.Draw();

      // draw gui
      gui.Draw();

      canvas.Update();
      camera.Unbind();
   }

   return 0;
}
