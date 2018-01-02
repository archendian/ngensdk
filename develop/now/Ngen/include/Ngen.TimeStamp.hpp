
#ifndef __NGEN_TIMESTAMP_HPP
#define __NGEN_TIMESTAMP_HPP

using namespace std;
using namespace chrono;

namespace Ngen {

    class TimeStamp {
    public:
        uint64 Microsecond() { return (uint64)duration_cast<chrono::microseconds>((uint64)mTime).count(); }
        uint64 Nanosecond() { return (uint64)duration_cast<chrono::nanoseconds>((uint64)mTime).count(); }
        uint64 Millisecond() { return (uint64)duration_cast<chrono::milliseconds>((uint64)mTime).count(); }
        uint64 Second() { return (uint64)duration_cast<chrono::seconds>((uint64)mTime).count(); }
        uint64 Minute() { return (uint64)duration_cast<chrono::minutes>((uint64)mTime).count(); }
        uint64 Hour() { return (uint64)duration_cast<chrono::hours>((uint64)mTime).count(); }
        uint64 Day() { return (uint64)duration_cast<chrono::days>((uint64)mTime).count(); }
        uint64 Month() { return (uint64)duration_cast<chrono::months>((uint64)mTime).count(); }
        uint64 Year() { return (uint64)duration_cast<chrono::years>((uint64)mTime).count();}

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
                    //case 'T': result += string(Tick()); break;
                    //case 'a': result += string(Period() == 0 ? "AM" : "PM"); break;
                    default: result += format[i]; break;
                }
            }

            return result;
        }

        bool IsUtcTime() const { return mIsUtc; }

    protected:
        TimeStamp(bool utc=false) : mTime(system_clock::now()), mIsUtc(utc) {}

        system_clock::time_point mTime;
        bool mIsUtc;
    };
}

#endif // __NGEN_TIMESTAMP_HPP
