#include<iostream>
using namespace std;
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day) {}
    int subtract(const Date d2)
    {
      int t1=0,t2=0;
      for(int i=1;i<=_year-1;i++)
        {if(((i%4==0)&&(i%100!=0))||(i%400==0))t1+=366;
           else t1+=365;}
      for(int i=1;i<=d2._year-1;i++)
        {if(((i%4==0)&&(i%100!=0))||(i%400==0))t2+=366;
           else t2+=365;}
      for(int i=1;i<=_month-1;i++)
        {
            if(((_year%4==0)&&(_year%100!=0))||(_year%400==0))
                {
                switch(i)
                {case 1:case 3:case 5:case 7:case 8:case 10:case 12:t1+=31;break;
                case 4:case 6:case 9:case 11:t1+=30;break;
                case 2:t1+=29;
                }
                }
            else
                {
                switch(i)
                {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:t1+=31;break;
                case 4:case 6:case 9:case 11:t1+=30;break;
                case 2:t1+=28;
                }
                }
        }
          for(int i=1;i<=d2._month-1;i++)
        {
            if(((d2._year%4==0)&&(d2._year%100!=0))||(d2._year%400==0))
                {
                switch(i)
                {case 1:case 3:case 5:case 7:case 8:case 10:case 12:t2+=31;break;
                case 4:case 6:case 9:case 11:t2+=30;break;
                default:t2+=29;}
                }
            else
                {
                switch(i)
                {case 1:case 3:case 5:case 7:case 8:case 10:case 12:t2+=31;break;
                case 4:case 6:case 9:case 11:t2+=30;break;
                default:t2+=28;}
                }
        }
        t1+=_day;
        t2+=d2._day;
        int t;
        t1>t2?t=t1-t2:t=t2-t1;
        return t;
    }

    Date add_year(int y)
    {
      ;
    }

    Date sub_year(int y)
    {
        ;
    }

    Date add_month(int m)
    {
        ;
    }

    Date sub_month(int m)
    {   ;
    }

    Date add_day(int d)
    {
       ;
    }

    Date sub_day(int d)
    {
        ;
    }


    void Display()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

