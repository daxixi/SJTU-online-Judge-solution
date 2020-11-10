#include <iostream>
#define MaxN 6000
using namespace std;

int n;
int connect[MaxN][MaxN]={0};
int len_c[MaxN]={0};
int seg[MaxN][MaxN]={0};
bool caled[MaxN] = {0};

void init(){
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        connect[x][len_c[x]++] = y;
        connect[y][len_c[y]++] = x;
    }
    for (int i = 1; i <= n; ++i) if(len_c[i]==1)
    {
        seg[i][0] = n-1;
        caled[i] = true;
    }
    for (int i = 1; i <= n; ++i) if(len_c[i]==2)
    {
        if(len_c[connect[i][0]]==1){
            seg[i][0] = 1;
            seg[i][1] = n-2;
            caled[i] = true;
        }
        if(len_c[connect[i][1]]==1){
            seg[i][1] = 1;
            seg[i][0] = n-2;
            caled[i] = true;
        }

    }
}

int getComponent(int s, int x){
    int len = len_c[x];
    int res = 1;
    if(caled[x]){
        for (int i = 0; i < len; ++i) if(connect[x][i]!=s)
            res += seg[x][i];
    }else{
        int tmp = 0;
        for (int i = 0; i < len-1; ++i)
        {
            seg[x][i] = getComponent(x,connect[x][i]);
            tmp += seg[x][i];
            if(connect[x][i]!=s)
                res += seg[x][i];
        }
        seg[x][len-1] = n-1-tmp;
        res+=seg[x][len-1];
        caled[x] = true;
    }
    return res;
}

void Build(){

    for (int i = 1; i <= n; ++i) if(!caled[i])
    {
        int len = len_c[i];
        int tmp = 0;
        for (int j = 0; j < len-1; ++j){

            seg[i][j] = getComponent(i,connect[i][j]);
            tmp += seg[i][j];
        }
        seg[i][len-1] = n-1-tmp;
        caled[i] = true;
    }
}

void Output(){
    for (int i = 1; i <= n; ++i)
    {
        bool ok = true;
        for (int j = 0; j < 3; ++j) if(seg[i][j]>n/2)
        {
            ok = false;
            break;
        }
        if(ok)
            cout<<i<<endl;
    }
}

int main()
{
    init();
    Build();
    Output();

    return 0;
}
