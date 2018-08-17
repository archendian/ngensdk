





#include <Ngen.hpp>

namespace Ngen {
  namespace Content {

     template<typename T>
     class Resource {
     public:
        Resource(const string& id, const string& fileName, bool persist=false) :
            mId(id), mFilename(fileName), mIsPersistent(persist), mInstance(), mRefernce(0) {
           mRefernce = new Reference(1);
           mInstance = FileHandler<T>::Load();
        }

        virtual ~Resource() {
          Drop();
        }

        void IsPersistent(bool rhs) {
           if(!mIsPersistent) {
              if(rhs) {
                 mIsPersistent = rhs;
                 mRefernce->Grab();
              }

              mIsPersistent = rhs;
           } else {
              pDrop();
              mIsPersistent = false;
           }
        }

        bool IsPersistent() const {
           return mIsPersistent;
        }

        T& Instance() {
           return &mInstance;
        }

        const T& Instance() const {
           return &mInstance;
        }

        Resource<T>& Grab() {
           mRefernce->Grab();
           return *this;
        }

     protected:
        void pDrop() {
           mRefernce->Drop();
           if(mRefernce.Current() <= 0) {
              mInstance.~T();
              delete mRefernce;
           }
        }

        mirror mId;
        string mFilename;
        bool mIsPersistent;
        T mInstance;
        Reference* mRefernce;

        static Map<mirror, Resource<T>> mResource;
     };


  }
}
