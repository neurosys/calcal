#include <iostream>
#include <ctime>
#include <string>
#include <vector>

namespace calcal
{
/*

       October 2016    
       Mo Tu We Th Fr Sa Su
                       1  2 
        3  4  5  6  7  8  9 
       10 11 12 13 14 15 16 
       17 18 19 20 21 22 23 
       24 25 26 27 28 29 30 
       31                   

       struct tm {
       int tm_sec;    // Seconds (0-60) 
       int tm_min;    // Minutes (0-59) 
       int tm_hour;   // Hours (0-23) 
       int tm_mday;   // Day of the month (1-31) 
       int tm_mon;    // Month (0-11) 
       int tm_year;   // Year - 1900 
       int tm_wday;   // Day of the week (0-6, Sunday = 0) 
       int tm_yday;   // Day in the year (0-365, 1 Jan = 0) 
       int tm_isdst;  // Daylight saving time 
       };

*/


    class Date
    {
        public:
            Date();
            Date(int utime);
            //operator ++(); // Increase day by one
            //operator ++(int); // Increase day by one
            //operator +(int); // Add days
            //operator +=(int); // Add days
            //operator -=(int); // Add days

        public:
            int GetYear();
            int GetMonth();
            int GetDayOfMonth();
            int GetDayOfWeek();
            std::string GetStrDayOfWeek();
            std::string GetStrMonth();

        private:
            std::time_t unix_now;
            std::tm     now;
            static const std::string DayNames[];
            static const std::string MonthNames[];
    };

    const std::string Date::MonthNames[] = { "None"
        "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December" };

    const std::string Date::DayNames[] = { "None"
        "Monday",
            "Tuesday",
            "Wensday",
            "Thirstday",
            "Friday",
            "Saturday",
            "Sunday" };

    Date::Date()
    {
        unix_now = std::time(NULL);
        ::localtime_r(&unix_now, &now);
        //std::cout << "Date()" << std::endl;
    }

    Date::Date(int utime)
    {
        unix_now = utime;
        ::localtime_r(&unix_now, &now);
    }

    int Date::GetMonth()
    {
        return now.tm_mon + 1;
    }

    std::string Date::GetStrMonth()
    {
        return MonthNames[GetMonth()];
    }

    int Date::GetYear()
    {
        return now.tm_year + 1900;
    }

    int Date::GetDayOfMonth()
    {
        return now.tm_mday;
    }

    int Date::GetDayOfWeek()
    {
        return now.tm_wday + 1;
    }

    std::string Date::GetStrDayOfWeek()
    {
        return DayNames[GetDayOfWeek()];
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Program = '" << argv[0] << "' argc = " << argc << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "] = '" << argv[i] << "'" << std::endl;
    }
    calcal::Date c;
    std::cout << c.GetYear() << "-"
              << c.GetMonth() << "-"
              << c.GetDayOfMonth() << std::endl;
    return 0;
}
