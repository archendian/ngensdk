


namespace Ngen {
   template<typename TResource>
   class ngen_api FileHandler {
   public:
      virtual ~FileHandler();

      static void Unload(const mirror& id) {
         TResource* resource = null;
         if(!mResource.TryGetValue(id, resource)) {
            return;
         }

         resource->~TResource();
      }

      static TResource* Load(const mirror& id, const string& fileName) {
         FileHandler<TResource>* handler = null;
         if(!mHandler.TryGetValue(File.GetPathExtension(fileName), handler)) {
            return null;
         }

         return handler->LoadResource(id, fileName);
      }

      TResource* LoadResource(const mirror& id, const string& fileName) {
         TResource* result = null;
         if(!mResource.TryGetValue(id), inref result) {
            pLoad(fileName);
            return mResource[id];
         }

         return result;
      }

      static FileHandler<TResource>* Get(const string& fileExtension) {
         return mHandler[const_mirror(fileExtension));
      }
   protected:
      virtual void pLoad(const string& fileName) pure;

      static Map<mirror, TResource> mResource;
      static Map<mirror, FileHandler<TResource>*> mHandler;
   };

   // See Ngen.Content library
}
