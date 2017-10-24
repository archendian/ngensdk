/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2017 FIXCOM, LLC

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
#ifndef _NGEN_MATH_VECTOR2
#define _NGEN_MATH_VECTOR2

#include "Ngen.Calculator.hpp"

namespace Ngen {
	namespace Math {

		class Vector2 {
		public:
			real X;
			real Y;

			Vector2() : X(0), Y(0) {}
			Vector2(real xy) : X(xy), Y(xy) {}
			Vector2(real x, real y) : X(x), Y(y) {}
			Vector2(const Vector2& copy) : X(copy.X), Y(copy.Y) {}

			real Distance(const Vector2& to) const;
		};

		typedef Vector2 vec2;
	}

	class Scene {
	};



	class MemoryStream : Stream {};

	typedef MemoryStream memstream;

	enum class EAccessFlag {
        CHECK = 0x0,
        READ = 0x1,
        WRITE = 0x2,
        LOAD = 0x4,
	     NEW = 0x8,

        RW = READ | WRITE,
        EDIT = RW | LOAD,
        EDIT_NEW = NEW | EDIT,
	};


	class File {
    public:
        static memstream Read(string filePath) {
            return Access(filePath, EAccessFlag::READ);
        }

        static memstream Edit(string filePath) {
            return Access(filePath, EAccessFlag::EDIT);
        }

         static memstream EditNew(string filePath) {
            return Access(filePath, EAccessFlag::EDIT_NEW);
        }

        static TimeSpan Touch(string filePath) {
            if(!Check(filePath)) {
                New(filePath);
                return true;
            }

            return false;
        }

        static memstream New(string filePath, bool overwrite=false) {
            if(!overwrite && Check(filePath)) {
                THROW(FileAccessException());
            }

            return Access(filePath, EAccessFlag::NEW);
        }

        static bool Check(string filePath);
        static memstream Access(string filePath, EAccessFlag access=EAccessFlag::RW);
	};
	class Asset;
	class AssetManager {
    public:

    protected:
        static Map<mirror, Asset> mAsset;
        static Map<mirror, Asset*> mPersistantAsset;
        static Map<mirror, Asset*> mPassiveAsset;
        static Map<mirror, Asset*> mRougeAsset;


	};

    class Asset {
    public:
        string mSourcePath;   //! The path used by the asset manager to construct the asset object.
        string mFullPath;     //! The entire path used by the local system to access the assets source.
        mirror mId;
        bool mIsReadonly;
        bool mIsLoaded;
        bool mIsVirtual;
        MemoryStream mPhysical;
        MemoryStrean mVirtual;

        Asset(string id=string::Random(15, string::Letters() + string:: Numbers()), bool load=true, bool readOnly=false) :
                    mSourcePath(path::Random(path::TemporaryPath(string::Random(10)))),
                  , mId(id), mIsReadonly(readOnly), mIsLoaded(false), mIsVirtual(false),
                    mPysical(null), mVirtual(null) {
            if(load) {
            }
        }


        virtual Asset PhysicalCopy(string copyId, string copySourcePath=string::Empty()) const {

        }

        virtual Asset VirtualCopy(string copyId, string copySourcePath=string::Empty()) const {

        }

        virtual Asset Copy(string copyId, string copySourcePath)const {

        }

        string SourcePath() const { return path::FullPath(mSourcePath); }
        string FullPath() const { return path::FullPath(mSourcePath); }
        string Id() const { return mName; }

        bool IsLoaded() const { return mIsLoaded; }
        bool IsVirtual() const { return mIsVirtual; }
    };


	class SceneNode {
    public:

    protected:
        string mId;
        Vector3 mLocation;
        map<mirror, Asset*> mAsset;
        map<mirror, SceneNode*> mChild;
        SceneNode* mParent;
	};

	class SceneNodeState {
    public:

    protected:

	};

    class Config {
    public:
        Config(string id);
    protected:
        string mId;

    };

    template<typename T>
    class Factory {
    public:
        virtual T* GetInstance(string id) const pure;
        virtual void DeleteInstance(string id) pure;
        virtual T* NewInstance(string id, ...) pure;
        virtual uword Count() const pure;
        virtual T* LoadInstance(const string& id, Stream* in) pure;
        virtual bool SaveInstance(const string& id, Stream* out) pure;
        virtual T* CopyInstance(const string& id, const string& copyId) pure;
    };


    class SceneNode;

    typedef StaticDelegate<SceneNode*, string, va_list>::TFunction CreateSceneNodeFunction;
    typedef StaticDelegate<SceneNode*, const string&, Stream*>::TFunction LoadSceneNodeFunction;
    typedef StaticDelegate<bool, const string&, Stream*>::TFunction SaveSceneNodeFunction;
    typedef StaticDelegate<SceneNode*, const string&, const string&>
    class SceneNodeFactory : Factory<SceneNode> {
    public:

        SceneNode* GetSceneNode(string id) pure;
        void RemoveSceneNode(string id) pure;
        SceneNode* CreateSceneNode(string id, ...);

    protected:
        string mId;
        CreateSceneNodeFunction::TFunction mCreate;

    };

    class PerspectiveCameraFactory : public SceneNodeFactory {
    public:

        PerspectiveCameraSceneNodeFactory() : SceneNodeFactory("factory/scene/perspective_camera") {

        }
    };

    class SceneManager {
    public:

        SceneManager(string configId="config/scene_manager_2D") : mConfig(Config::Get(configId), mNode() {

        }

        SceneNode* CreateSceneNode(const string& id, const string& factory, ...);
        Actor* CreateActor(string actorId, const vec3& location=vec3::Zero(), string factoryId, ...);
        Layer* CreateLayer(string stageId, const vec3& location=vec3::Zero(), string factoryId, ...);

    protected:
        Config* mConfig;
        map<mirror, SceneNodeState> mNode;
        map<mirror, SceneNodeFactory*> mFactory;
    };

	class Stage : SceneNode {};

	class Interface : SceneNode {};

	class Camera : SceneNode {};

	class Light : SceneNode {};

	class Actor : SceneNode {};

	class Interior : SceneNode {};

	class Exterior : SceneNode {};

}
#endif
