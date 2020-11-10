#include<iostream>
using namespace std;
void qsort(int,int);
int  ff(int *p,int num,int ans);
int n,a[1000];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    qsort(0,n-1);
    cout<<ff(a,n,0);
    return 0;
}
void qsort(int l,int r)
{
    int mid=a[(l+r)/2],tmp,i=l,j=r;
    do{
       while(a[i]<mid)i++;
       while(a[j]>mid)j--;
        if(i<=j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
       }while(i<=j);
       if(i<r)qsort(i,r);
       if(j>l)qsort(l,j);
}
int ff(int *p,int num,int ans)
{
    if(num==0)return(ans);
    else if(num==1)return(ans+*p);
     else if(num==2)return(ans+*(p+1));
       else if(num==3)return(ans+*p+*(p+1)+*(p+2));
         else
         {
           if(*p+*(p+num-2)>2**(p+1))return(ff(p,num-2,ans+2**(p+1)+*p+*(p+num-1)));
                                            else return(ff(p,num-2,ans+2**p+*(p+num-1)+*(p+num-2)));
         }
}
