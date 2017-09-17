# include <fstream>
# include <algorithm>
# define inf 999999999
using namespace std;
ifstream f("saritura_calului1.in");
ofstream g("saritura_calului1.out");
int i,j,n,m,x,y,VV,lv,cv,I,J,l,c,o,minn,ok;
int a[105][105], nr[105][105];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
bool acces (int la, int ca)
{
    if (1<=la && la<=n && 1<=ca && ca<=m) return 1;
        else return 0;
}
void scad (int la, int ca)
{
    for (int o=0; o<8; ++o)
    {
        lv=la+dx[o]; cv=ca+dy[o];
        if (acces(lv,cv) && !a[lv][cv]) --nr[lv][cv];
    }
}
int main ()
{
    f>>n>>m>>l>>c;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            for (o=0; o<8; ++o)
            {
                lv=i+dx[o]; cv=j+dy[o];
                if (acces(lv,cv)) ++nr[i][j];
            }

    VV=1; a[l][c]=VV;
    while (1)
    {
        scad(l,c); minn=inf;
        if (VV!=n*m-1) ok=0;
            else ok=inf;
        for (o=0; o<8; ++o)
        {
            lv=l+dx[o]; cv=c+dy[o];
            if (acces(lv,cv) && !a[lv][cv] && nr[lv][cv]!=ok && nr[lv][cv]<minn)
                minn=nr[lv][cv], I=lv, J=cv;
        }
        if (minn==inf) break;
        else {
                 a[I][J]=++VV;
                 l=I; c=J;
             }
    }

    //afisarea
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }
    return 0;
}
