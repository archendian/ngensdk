
#ifndef __NGEN_TIMESTAMP_HPP
#define __NGEN_TIMESTAMP_HPP

using namespace std;
using namespace chrono;

namespace Ngen {
    typedef duration<int, ratio_multiply<hours::period, ratio<24> >::type> days;

    class TimeStamp {
    public:
        uint64 Microsecond() const { return (uint64)duration_cast<chrono::microseconds>(mTime).count(); }
        uint64 Nanosecond() const { return (uint64)duration_cast<chrono::nanoseconds>(mTime).count(); }
        uint64 Millisecond() const { return (uint64)duration_cast<chrono::milliseconds>(mTime).count(); }
        uint64 Second() const { return (uint64)duration_cast<chrono::seconds>(mTime).count(); }
        uint64 Minute() const { return (uint64)duration_cast<chrono::minutes>(mTime).count(); }
        uint64 Hour() const { return (uint64)duration_cast<chrono::hours>(mTime).count(); }
        uint64 Day() const { return (uint64)duration_cast<chrono::day>(mTime).count(); }
        uint64 Month() const { return (uint64)duration_cast<chrono::month>(mTime).count(); }
        uint64 Year() const { return LocalTime().tm_year; }
        //uint64 Period() const;
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
                    //case 'a': result += string(Period() == 0 ? "AM" : "PM"); break;
                    default: result += format[i]; break;
                }
            }

            return result;
        }

    protected:
        TimeStamp(bool utc=false) : mTime(system_clock::now()) {}
         time_point mTime;
    };


#endif // __NGEN_TIMESTAMP_HPP
