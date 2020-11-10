#include<iostream>
using namespace std;

int digui(int s,int x,int**num,int **yes,bool*c,int *len,int n)
{
    int _len = len[x];
    int ans=1;
    if(c[x]){
        for (int i =1; i <=_len; ++i) if(yes[x][i]!=s)
            ans+=num[x][i];
    }else{
        int tmp = 0;
        for (int i =1; i<_len; ++i)
        {
            num[x][i] =digui(x,yes[x][i],num,yes,c,len,n);
            tmp +=num[x][i];
            if(yes[x][i]!=s)
                ans+=num[x][i];
        }
        num[x][_len] = n-1-tmp;
        ans+=num[x][_len];
        c[x] = true;
    }
    return ans;
}

int main()
{
    int n,x,y;
    int **yes;//是否联通 结点i第j个分支的数字
    yes=new int*[10050];
    for(int i=0;i<10010;i++)
        yes[i]=new int[10010]();
    int** num;//记录结点数量 结点i第j个分支上结点的个数
    num=new int*[10050];
    for(int i=0;i<10010;i++)
        num[i]=new int[10010]();
    bool *c;
    c=new bool[10010]();
    int *len;//有几个分支
    len=new int[10010]();
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        len[x]++;len[y]++;
        yes[x][len[x]]=y;
        yes[y][len[y]]=x;
    }
    for(int i=1;i<=n;i++)
       {
           if(len[i]==1)
            {num[i][1]=n-1;
            c[i]=true;}
       }
    for (int i = 1; i <= n; ++i) if(len[i]==2)
    {
        if(len[yes[i][1]]==1){
            num[i][1] =1;
            num[i][2] = n-2;
            c[i] = true;
        }
        if(len[yes[i][2]]==1){
            num[i][2] = 1;
            num[i][1] = n-2;
            c[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i) if(!c[i])
    {
        int _len = len[i];
        int tmp = 0;
        for (int j = 1; j <_len; ++j){
            num[i][j] =digui(i,yes[i][j],num,yes,c,len,n);
            tmp += num[i][j];
        }
        num[i][_len] = n-1-tmp;
        c[i] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        bool ok = true;
        for (int j =1;j<=len[i]; ++j) if(num[i][j]>n/2)
        {
            ok = false;
            break;
        }
        if(ok)
            cout<<i<<endl;
    }
}
