/*
   You are given the following information, but you may prefer to do some
   research for yourself.

     •1 Jan 1900 was a Monday.
     •Thirty days has September,
       April, June and November.
       All the rest have thirty-one,
       Saving February alone,
       Which has twenty-eight, rain or shine.
       And on leap years, twenty-nine.
     •A leap year occurs on any year evenly divisible by 4, but not on a
       century unless it is divisible by 400.

   How many Sundays fell on the first of the month during the twentieth
   century (1 Jan 1901 to 31 Dec 2000)?
*/

namespace pr19 {
    int detectSunday(long day){
        if (day % 7 == 0){
            return 1;
        } else {
            return 0;
        }
    }
}

int problem19 () {
    int year = 1900;
    int sundays = 0;
    long days = 0;
    days += (30*4 + 28 + 31*7);
    year++;
    while(year < 2001){
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 28;
        if (year % 4 == 0){
            days += 1;}
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 30;
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 30;
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 30;
        sundays += pr19::detectSunday(days);
        days += 31;
        sundays += pr19::detectSunday(days);
        days += 30;
        sundays += pr19::detectSunday(days);
        days += 31;
        year++;
    }
    return sundays - 1;
}
