# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 100005
# define mod 1999999973
using namespace std;
vector <int> v[NR];
ifstream f("disjoint.in");
ofstream g("disjoint.out");
int i,j,n,m,x,y,tip,Rx,Ry;
int R[NR], H[NR];
int radacina (int k)
{
    while (k!=R[k]) k=R[k];
    return k;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        R[i]=i, H[i]=1;

    for (i=1; i<=m; ++i)
    {
        f>>tip>>x>>y;
        Rx=radacina (x);
        Ry=radacina (y);
        if (tip==1) //reunire
        {
            if (H[Rx]>H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
                        else R[Rx]=Ry, H[Ry]+=H[Rx];
        }
        else {
                 if (Rx==Ry) g<<"DA\n";
                        else g<<"NU\n";
             }
    }

    return 0;
}
