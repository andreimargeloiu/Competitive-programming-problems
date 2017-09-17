# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 200005
using namespace std;
vector <int> v[NR],vect[NR];
int i,j,n,m,x,y,sol,K,o;
int P[NR];
void DFS (int k, int tata, int nivel)
{
    int i,act;

    if (v[k].size()==1) P[k]=0;
    else
    {
        for (i=0; i<v[k].size(); ++i)
        {
            if (v[k][i]!=tata)
            {
                DFS(v[k][i], k, nivel+1);
                vect[nivel].push_back(P[v[k][i]]);
            }
        }
        sort (vect[nivel].begin(), vect[nivel].end());
        if (k==o) act=v[k].size()-1;
            else  act=v[k].size()-2;

        if (act==0)
        {
            if (vect[nivel][act]+1<=K) P[k]=vect[nivel][act]+1;
                else             ++sol,P[k]=0;
        }
        else
        {
            if (vect[nivel][act]+vect[nivel][act-1]+2>K)
            {
                while (act && vect[nivel][act]+vect[nivel][act-1]+2>K)
                    ++sol, P[k]=vect[nivel][act-1]+1, --act;
                if (P[k]>K) ++sol, P[k]=0;
            }
            else P[k]=vect[nivel][act]+1;
        }
        vect[nivel].clear();
    }
}
int main ()
{
    freopen ("kdtree.in", "r", stdin);
    freopen ("kdtree.out", "w", stdout);
    scanf ("%d%d", &n, &K);
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (o=1; o<=n; ++o)
    {
        if (v[o].size()!=1) {DFS(o,0,1); break;}
    }
    printf ("%d\n", sol);
    return 0;
}
