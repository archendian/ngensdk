
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

	#include <chrono>
	#include <datetimeapi.h>
	#include <ctime>

    typedef duration<int, ratio_multiply<hours::period, ratio<24> >::type> days;

    class TimeStamp {
    public:

        void Reset() const {
            mTickTime = Time::CurrentTick();
        }

        ulong Microsecond() const { return (ulong)duration_cast<chrono::microseconds>(mTime).count(); }
        ulong Nanosecond() const { return (ulong)duration_cast<chrono::nanoseconds>(mTime).count(); }
        ulong Millisecond() const { return (ulong)duration_cast<chrono::milliseconds>(mTime).count(); }
        ulong Second() const { return (ulong)duration_cast<chrono::seconds>(mTime).count(); }
        ulong Minute() const { return (ulong)duration_cast<chrono::minutes>(mTime).count(); }
        ulong Hour() const { return (ulong)duration_cast<chrono::hours>(mTime).count(); }
        ulong Day() const { return (ulong)duration_cast<chrono::days>(mTime).count(); }
        ulong Month() const { return (ulong)duration_cast<chrono::days>(mTime).count(); }
        ulong Year() const { return LocalTime().tm_year; }
        ulong Period() const;
        time_t LocalTime() const { return time_point::to_time_t(mTime); }
        time_t GmTime() const { return gmtime(&LocalTime()); }

        string ToString(string format="M(w):d($D):Y(b) h:m:S:n:T a (c)") const {
            auto result = string(format.Length());
            bool stringify = false;

            for(uword i = 0; i < format.Length(); ++i) {
                switch(format[i])) {
                    case '$': stringify = true; break;
                    case 'Y': result += string(Year()); break;
                    case 'M': result += stringify ? Time::MonthName(Month()) : string(Month()); if(stringify) { stringify=false; } break;
                    case 'd': result += string((Week()+1)*7 + (Day()+1)); break;
                    case 'D': result += stringify ? Time::DayName(Day()) : string(Day()); if(stringify) { stringify=false; }  break;
                    case 'w': result += string(Week()); break;
                    case 'h': result += string(HourOfDay()); break;
                    case 'H': result += string(HourOfPeriod()); break;
                    case 'm': result += string(Minute()); break;
                    case 'S': result += string(Second()); break;
                    case 's': result += string(Millisecond()); break;
                    case 'N': result += string(Microsecond()); break;
                    case 'n': result += string(Nanosecond()); break;
                    case 'T': result += string(Tick()); break;
                    case 'a': result += string(Period() == 0 ? "AM" : "PM"); break;
                    default: result += format[i]; break;
                }
            }

            return result;
        }

    protected:
        TimeStamp(bool utc=false) : mTime(system_clock::now()) {}
        time_point mTime;
    };

    #include <chrono>
    using namespace std;
    using namespace chrono;

	class Time {
	public:
	    static TimeSpan Now(bool utc=false, uword cpuid=0) { return TimeStamp(utc, cpuid); }
	    static TimeSpan UtcNow(uword cpuid=0) { return Now(true, cpuid); }
	    static ulong TickPerMicrosecond(uword cpuid=0) { return TickPerMillisecond() / 1000 < 1 ? 0 : TickPerMillisecond() / 1000; }
	    static ulong TickPerMillisecond(uword cpuid=0) { return TickPerSecond() / 1000; }
	    static ulong TickPerSecond(uword cpuid=0) { return system_clock::period()::den; }

        static string DayName(ulong day=0) {
            if(day > 6) {
                THROW(OutOfRangeException());
            }

            return mDayName[day];
        }

        static ulong DayNumber(string day=const_string("Sunday")) {
            ulong result = mDayName.Length();
            if(!mDayName.Contains(day, inref result)) {
                THROW(InvalidArgumentException());
            }

            return result;
        }

        static string MonthName(ulong month=0){
            if(month >= mMonthName.Length()) {
                THROW(OutOfRangeException());
            }

            return mMonthName[day];
        }

        static ulong MonthNumber(string month=const_string("January")) {
            ulong result = mDayName.Length();

            if(!mDayName.Contains(day, inref result)) {
                THROW(InvalidArgumentException());
            }

            return result;
        }
    protected:

        static array<string> mDayName;
        static array<string> mMonthName;
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

        static DateTime Touch(string filePath) {
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
    protected:
        string mId;
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
