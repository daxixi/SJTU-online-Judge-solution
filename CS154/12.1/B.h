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
      _year+=y;
    }

    Date sub_year(int y)
    {
     _year-=y;
    }

    Date add_month(int m)
    {
      for(int i=1;i<=m;i++)
      {
       _month++;
       if (_month>12){_month=1;_year++;}
      }
    }

    Date sub_month(int m)
    {
      for(int i=1;i<=m;i++)
      {
      _month--;
      if(_month<1){_month=12;_year--;}
      }
    }

    Date add_day(int d)
    {
     int a[2][12]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
     for(int i=1;i<=d;i++)
     {
         _day++;
         int b;
         if(((_year%4==0)&&(_year%100!=0))||(_year%400==0))b=0;else b=1;
         if(_day>a[b][_month-1]){_day=1;_month++;}
         if(_month>12){_month=1;_year++;}

     }
    }
    Date sub_day(int d)
    {
       int a[2][12]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
     for(int i=1;i<=d;i++)
     {
         _day--;
         int b;
         if(_day<1)
         {
           _month--;
           if(_month<1){_month=12;_year--;}
              if(((_year%4==0)&&(_year%100!=0))||(_year%400==0))b=0;else b=1;
           _day=a[b][_month-1];
         }
     }
    }
    void Display()
    {
       if(((_year%4==0)&&(_year%100!=0))||(_year%400==0))
       {if((_month==2)&&(_day==31))_day=29;}
       else{if((_month==2)&&(_day==29))_day=28;}
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

