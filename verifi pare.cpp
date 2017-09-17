#include <iostream>

using namespace std;

int n,i,a[1000][1000],m,j,ok,s;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        cin>>a[i][j];
    ok=1;
    for(j=2;j<=m;j++)
        if(a[i][j]!=a[i][j-1])
          ok=0;
    if(ok==1)
      s++;
    }

    cout<<s;

    return 0;
}
