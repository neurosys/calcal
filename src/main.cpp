#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
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
            Date(int y, int m, int d);
            Date& operator --(); // Decrease day by one
            Date& operator --(int); // Substract days
            Date& operator ++(); // Increase day by one
            Date& operator ++(int); // Add days
            Date& operator +=(int); // Add days
            Date& operator -=(int); // Substract days (get past dates)
            Date  operator +(int); 
            Date  operator -(int);

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
        unix_now = std::time(nullptr);
        ::localtime_r(&unix_now, &now);
        //std::cout << "Date()" << std::endl;
    }

    Date::Date(int utime)
    {
        unix_now = utime;
        ::localtime_r(&unix_now, &now);
    }

    Date::Date(int y, int m, int d)
    {
        std::memset(&now, 0, sizeof(std::tm));
        now.tm_year = y;
        now.tm_mon = m;
        now.tm_mday = d;
        unix_now = mktime(&now);
    }

    int Date::GetMonth() const
    {
        return now.tm_mon + 1;
    }

    std::string Date::GetStrMonth() const
    {
        return MonthNames[GetMonth()];
    }

    int Date::GetYear() const
    {
        return now.tm_year + 1900;
    }

    int Date::GetDayOfMonth() const
    {
        return now.tm_mday;
    }

    int Date::GetDayOfWeek() const
    {
        return now.tm_wday + 1;
    }

    std::string Date::GetStrDayOfWeek() const
    {
        return DayNames[GetDayOfWeek()];
    }

    Date& Date::operator +=(int x)
    {
        unix_now += 60 * 60 * 24 * x;
        ::localtime_r(&unix_now, &now);
        return *this;
    }

    Date& Date::operator -=(int x)
    {
        unix_now -= 60 * 60 * 24 * x;
        ::localtime_r(&unix_now, &now);
        return *this;
    }

    Date& Date::operator --(int)
    {
        *this -= 1;
        return *this;
    }

    Date& Date::operator --()
    {
        *this -= 1;
        return *this;
    }

    Date& Date::operator ++(int)
    {
        *this += 1;
        return *this;
    }

    Date& Date::operator ++()
    {
        *this += 1;
        return *this;
    }

    Date Date::operator +(int x)
    {
        Date d = *this;
        d += x;
        return d;
    }

    Date Date::operator -(int x)
    {
        Date d = *this;
        d -= x;
        return d;
    }

    Date operator+(int x, Date& y)
    {
        Date d = y + x;
        return d;
    }

    Date operator-(int x, Date& y)
    {
        Date d = y - x;
        return d;
    }

    std::ostream& operator <<(std::ostream& out, Date const& d)
    {
        return out << d.GetYear()  << "-"
                   << d.GetMonth() << "-"
                   << d.GetDayOfMonth() ;
    }

    // YYYY-MM-DD
    void Date::PrintISO() const
    {
        std::cout << *this << std::endl;
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
    std::cout << "Azi " ;
    c.PrintISO();

    /*
    std::cout << "Ieri = " ;
    c -= 1;
    c.PrintISO();

    std::cout << "Acum doua zile = " ;
    c -= 1;
    c.PrintISO();

    std::cout << "Acum 10 zile = " ;
    c -= 8;
    c.PrintISO();
    */
    c -= 10;
    std::cout << "Acum 10 zile = " << c << std::endl;
    c.PrintISO();

    /*
    for (int i = 0; i < 10; i++)
    {
        std::cout << "i = " << i + 1<< " ";
        c++;
        c.PrintISO();
    }
    */


    return 0;
}
