#include <iostream>
using namespace std;
int day[10];
int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
int ju(int n)
{
    if((n%4==0&&n%100!=0)||(n%400==0))
        return 1;
    return 0;
    }
    int re(int flag,int n,int k)
    {    int date=1;
     for(int i=0;i<12;i++)
        for(int j=1;j<=month[flag][i];j++)
         {date++;
            date%=month[flag][i]; k++;k%=7;
            if(date==13)
                day[k]++;
            }
            return k;}
            int main()
            {    int n,k=1;
            cin>>n;
            for(int i=1900;i<=1900+n-1;i++)
                {k=re(ju(i),i,k);}
            cout<<day[1]<<" "<<day[2]<<" "<<day[3]<<" "<<day[4]<<" "<<day[5]<<" "<<day[6]<<" "<<day[0]<<endl;
             return 0;
            }
