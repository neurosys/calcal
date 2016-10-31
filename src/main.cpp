#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>

#include "date.h"

namespace calcal
{



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
        unix_now += SECONDS_IN_A_DAY * x;
        ::localtime_r(&unix_now, &now);
        return *this;
    }

    Date& Date::operator -=(int x)
    {
        unix_now -= SECONDS_IN_A_DAY * x;
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

    int Date::operator -(Date& x)
    {
        int delta = unix_now - x.unix_now;
        return (delta / SECONDS_IN_A_DAY);
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
    calcal::Date b;
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

    std::cout << "Azi din nou = " << b - c << std::endl;

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
