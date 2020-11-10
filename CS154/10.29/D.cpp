#include<iostream>
using namespace std;
int judge(int a)
   {
       if(((a%4)==0)&&((a%100)>0))
          return(0);
       else return(1);
   }
int main()
{
    int a[6]={0},b[1],r,k,p,n;
    int month[1][11];
    month[0][0]=31;month[0][1]=29;month[0][2]=31;month[0][3]=30;month[0][4]=31;month[0][5]=30;month[0][6]=31;month[0][7]=31;month[0][8]=30;month[0][9]=31;month[0][10]=30;month[0][11]=31;
    month[1][0]=31;month[1][1]=28;month[1][2]=31;month[1][3]=30;month[1][4]=31;month[1][5]=30;month[1][6]=31;month[1][7]=31;month[1][8]=30;month[1][9]=31;month[1][10]=30;month[1][11]=31;
    cin>>n;
    p=1;
    a[6]=0;
    b[0]=366;b[1]=365;
    for(int i=1;i<=n;i++)
    {
        r=1;k=0;
        for(int s=1;s<=b[judge(1900+i-1)];s++)
            {
                if(r==13)a[p%7]++;
             p++;r++;
             if(r>month[judge(1900+i-1)][k])
                {
                    r=r-month[judge(1990+i-1)][k];
                    k++;
                }
            }
    }
     for(int i=1;i<=6;i++)
        cout<<a[i]<<' ';
     return 0;
}

