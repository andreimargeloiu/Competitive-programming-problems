# include <fstream>
using namespace std;
ifstream f("disjoint.in");
ofstream g("disjoint.out");
int i,n,m,tip,x,y,rx,ry;
int marime[100005], R[100005];
int radacina (int k)
{
    while (R[k]!=k) k=R[k];
    return k;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        R[i]=i;
        marime[i]=1;
    }
    for (i=1; i<=m; ++i)
    {
        f>>tip>>x>>y;
        rx=radacina(x);
        ry=radacina(y);
        if (tip==1) //unesc
        {
            if (marime[rx]>marime[ry]) R[ry]=rx, marime[rx]+=marime[ry];
                else R[rx]=ry, marime[ry]+=marime[rx];
        }
        else {
                 if (rx==ry) g<<"DA\n";
                    else g<<"NU\n";
             }
    }
    return 0;
}
