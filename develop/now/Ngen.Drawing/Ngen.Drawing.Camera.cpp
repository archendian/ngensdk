
#include "Ngen.Drawing.Camera.hpp"
#include "Ngen.Drawing.GpuProgram.hpp"

namespace Ngen {
   namespace Drawing {
      Camera* _currentCamera = null;

      Camera* Camera::Current() { return _currentCamera; }

      void Camera::Bind(const string& uniformId) {
         if(!isnull(GpuProgram::Current())) {
            if(_currentCamera != this || this->mHasChanged != true) {
               GpuProgram::Current()->Uniform(uniformId, this->Projection());
            }
         } else {
            this->Bind();
         }

         _currentCamera = this;
      }

      void Camera::Bind() {
         const auto m = Projection();
         glLoadMatrixf((real*)&m.M);
         _currentCamera = this;
      }

      void Camera::Unbind(const string& uniformId) const {
         if(!isnull(GpuProgram::Current())) {
            GpuProgram::Current()->Uniform(uniformId, Math::Matrix4::Identity());
         } else {
            this->Unbind();
         }

         _currentCamera = null;
      }

      void Camera::Unbind() const {
         glLoadIdentity();
         _currentCamera = null;
      }
   }
}
