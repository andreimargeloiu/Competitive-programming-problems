# include <bits/stdc++.h>
# define NR 1005
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("autostrazi2.in");
ofstream g("autostrazi2.out");
vector <int> v[NR];
int i,j,n,m,x,y,VV;
int cuplat[NR];
pair <int, int> sol[NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (! cuplat[i]) {
            for (j=0; j<v[i].size(); ++j)
                if (! cuplat[v[i][j]]) {
                    cuplat[i]=v[i][j];
                    cuplat[v[i][j]]=i;

                    sol[++VV]=mp(i, v[i][j]);

                    break;
                }
        }
    for (i=1; i<=VV; ++i)
        g<<sol[i].f<<" "<<sol[i].s<<"\n";


    return 0;
}
