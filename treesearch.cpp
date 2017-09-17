# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("treesearch.in");
ofstream g("treesearch.out");
vector <int> v[NR], a[NR];
queue <int> q;
int i,j,n,m,x,y,VV,S;
int ap[NR], gr[NR], T[NR], l;
int jos[NR], sus[NR], maxim[NR], cost[NR], maxx;
void DFS (int k, int tata)
{
    ap[k]=1; T[k]=tata;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i], k);
}
bool cmp (int x, int y)
{
    if (x>=y) return 0;
        else return 1;
}
void DFS2 (int k, int SUS)
{
    ap[k]=1; a[k].push_back(SUS);
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=T[k]) a[k].push_back(jos[v[k][i]]);

    sort (a[k].begin(), a[k].end(), cmp);

    int l=a[k].size();
    int maxx=a[k][l-1];
    if (l>1 && a[k][l-2]>0) maxx+=a[k][l-2];
    maxim[k]=maxx+cost[k];

    for (int i=0; i<v[k].size(); ++i)
    if (! ap[v[k][i]])
    {
        if (l==1 && a[k][l-1]==jos[v[k][i]])
        {
            DFS2(v[k][i], cost[k]);
            continue;
        }
        if (jos[v[k][i]]==a[k][l-1]) DFS2(v[k][i], max(cost[k], cost[k]+a[k][l-2]));
                                else DFS2(v[k][i], max(cost[k], cost[k]+a[k][l-1]));
}
    }
void sortaret ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();

        jos[k]=cost[k];
        for (i=0; i<v[k].size(); ++i)
            if (v[k][i]!=T[k])
                if (jos[v[k][i]]+cost[k]>jos[k]) jos[k]=jos[v[k][i]]+cost[k];

        --gr[T[k]];
        if ((gr[T[k]]==1 && T[k]!=S) || (gr[T[k]]==0 && T[k]==S)) q.push(T[k]);
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>cost[i];
    for (i=1; i<n; ++i)
    {
        f>>x>>y; ++gr[x]; ++gr[y];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (gr[i]==1)
        {
            if (S==0) S=i;
            else q.push(i);
        }

    DFS (S, 0);
    sortaret(); //jos
    memset (ap, 0, sizeof(ap));
    DFS2 (S, 0); //sus

    for (i=1; i<=m; ++i)
    {
        f>>x;
        g<<max(maxim[x], cost[x])<<"\n";
    }

    return 0;
}
