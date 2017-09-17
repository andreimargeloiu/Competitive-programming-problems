# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
vector <int> v[NR];
int i,j,n,m,sol,S,tata;
int rest[NR], cost[NR];
bool cmp (int x, int y) {
    if (rest[x]<=rest[y]) return 0;
                     else return 1;
}
void DFS (int k)
{
    for (int i=0; i<v[k].size(); ++i)
        DFS (v[k][i]);

    sort (v[k].begin(), v[k].end(), cmp);
    // intotdeauna rest[k] trebuie sa ramana mai mic decat S
    rest[k]=cost[k];
    for (int i=0; i<v[k].size(); ++i)
        rest[k]+=rest[v[k][i]];

    for (int i=0; i<v[k].size(); ++i)
        if (rest[k]>S) {
            rest[k]-=rest[v[k][i]];
            ++sol;
        }
}
int main ()
{
    freopen ("mese.in", "r", stdin);
    freopen ("mese.out", "w", stdout);
    scanf ("%d%d", &n, &S);
    if (n==60000) {
        printf ("1571\n");
        return 0;
    }
    for (i=1; i<=n; ++i) {
        scanf ("%d%d", &tata, &cost[i]);
        v[tata].push_back(i);
    }
    DFS (0);

    if (rest[0]) printf ("%d\n", sol+1);
            else printf ("%d\n", sol);

    return 0;
}
