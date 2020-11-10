#include<iostream>
using namespace std;

int main()
{
    int n,p,m,nn,t,g,c,tmp;
    unsigned *data;
    cin>>n>>p;
    data=new unsigned [n];
    for(int i=0;i<n;i++)
    cin>>data[i];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>nn;
        switch(nn){
    case 1:cin>>t>>g>>c;
            for(int j=t-1;j<g;j++)data[j]=(data[j]*c);
            break;
    case 2:cin>>t>>g>>c;
            for(int j=t-1;j<g;j++)data[j]=(data[j]+c);
            break;
    case 3:cin>>t>>g;
            int sum=0;
            for(int j=t-1;j<g;j++)sum=(sum+data[j])%p;
            cout<<sum<<endl;
            break;
        }
    }
    return 0;
}
