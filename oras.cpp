#include <cstdio>
#include <cstring>

using namespace std;

char v[210][210];

int main()
{
    freopen("oras.in", "r", stdin);
    freopen("oras.out", "w", stdout);
    int n,i;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) v[i][j]='0';
    if(n==4)
    {
        printf("-1");
        return 0;
    }
    if(n%2)
    {
        strcpy(v[1]+1,"010");
        strcpy(v[2]+1,"001");
        strcpy(v[3]+1,"100");
        i=5;
    }
    else
    {
        strcpy(v[1]+1,"010101");
        strcpy(v[2]+1,"001011");
        strcpy(v[3]+1,"100100");
        strcpy(v[4]+1,"010010");
        strcpy(v[5]+1,"101001");
        strcpy(v[6]+1,"001100");
        i=8;
    }
    for(;i<=n;i+=2)
    {
        v[i-1][i]='1';
        for(int j=1;j<=i-2;j++) v[j][i-1]=v[i][j]='1';
    }
    for(int i=1;i<=n;i++) printf("%s\n",v[i]+1);
    return 0;
}
