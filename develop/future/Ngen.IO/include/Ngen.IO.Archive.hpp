




namepsace Ngen {
   namespace IO {
      
      ngen_io_api class Device {
      public:
         event<Device*, string&, bool&> NameChanged;

         Device(const mirror name) : mName(name) {}


	 const string Name() const { return mName; }

	 void Name(const mirror& name) { 
            bool change = false;
            NameChanged(this, inref name, inref change);
            
            if(changed) {
                 mName = name;
	    } else {
                 THROW(Exception("name"));
            }
         }
	 
      protected:
         string mName;
         
      }

      interface ngen_io_api class IDevice {

      }


      abstract ngen_io_api class Archive  {
      public:
	 Archive(const string& path) : mPath(path) {
            
	 }

	 uword NodeCount() const;
         string[] AllFilenames() const;
	 string FilenameAt(uword index) const;
      	 
         
      protected:
         mirror mPath;
      }
   }
}