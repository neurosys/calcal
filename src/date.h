
#ifndef __DATE_H__
#define __DATE_H__

#define SECONDS_IN_A_DAY (60 * 60 * 24)
#define MINUTES_IN_A_DAY (60 * 24)
#define HOURS_IN_A_DAY   (24)

#include <string>
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

namespace calcal
{
    class Date
    {
        public:
            Date();
            Date(int utime);
            Date(int y, int m, int d);
            Date& operator --(); // Decrease day by one
            Date& operator --(int); // Substract days
            Date& operator ++(); // Increase day by one
            Date& operator ++(int); // Add days
            Date& operator +=(int); // Add days
            Date& operator -=(int); // Substract days (get past dates)
            Date  operator +(int); 
            Date  operator -(int);
            int   operator -(Date&);

        public:
            int GetYear() const;
            int GetMonth() const;
            int GetDayOfMonth() const;
            int GetDayOfWeek() const;
            std::string GetStrDayOfWeek() const;
            std::string GetStrMonth() const;
            void PrintISO() const;

        private:
            std::time_t unix_now;
            std::tm     now;
            static const std::string DayNames[];
            static const std::string MonthNames[];
            static const std::string ShortDayNames[];
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
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday" };

    const std::string Date::DayNames[] = { "None"
            "Mo",
            "Tu",
            "We",
            "Th",
            "Fr",
            "Sa",
            "Su" };

    class Calendar
    {

    };
}

#endif // __DATE_H__
