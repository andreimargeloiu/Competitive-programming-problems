# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("online.in");
ofstream g("online.out");
struct elem
{
    int x,y,cost;
}E,v[10005];
bool cmp (elem x, elem y)
{
    if (x.cost>=y.cost) return 0;
        else return 1;
}
int i,j,n,m,x,y,K;
int R[205],H[205];
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
void APM (int nr)
{
    int i,ok=0,VV,cost=0,Rx,Ry;
    if (nr==1) sort (v+1, v+m+1, cmp);
    else {
             for (i=n; i>=1; --i)
             {
                 R[i]=i; H[i]=1;
                 if (v[i].cost<v[i-1].cost) swap(v[i],v[i-1]);
             }
         }
    VV=0;
    for (i=1; i<=m; ++i)
    {
        Rx=radacina(v[i].x);
        Ry=radacina(v[i].y);
        if (Rx!=Ry)
        {
            v[++VV]=v[i];
            cost+=v[i].cost;
            if (H[Rx]>=H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
                else R[Rx]=Ry, H[Ry]+=H[Rx];
        }
    }
    m=n;
    g<<cost<<"\n";
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        if (i<=n) R[i]=i, H[i]=1;
        f>>v[i].x>>v[i].y>>v[i].cost;
    }
    APM (1);
    f>>K;
    for (i=2; i<=K+1; ++i)
    {
        f>>E.x>>E.y>>E.cost;
        v[n]=E;
        APM(K);
    }

    return 0;
}
