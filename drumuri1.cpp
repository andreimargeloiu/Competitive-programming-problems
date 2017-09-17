# include <cstdio>
# include <vector>
# include <queue>
using namespace std;
queue <int> q;
vector <int> v[100005];
int i,j,n,act,nrsol;
int nr[100005],bigger[100005],a[305][305];
void parcurgere ()
{
    int k,i;
    while (!q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            nr[v[k][i]]+=nr[k];
            --bigger[v[k][i]];
            if (bigger[v[k][i]]==0) q.push(v[k][i]);
        }
        if (v[k].size()==0) nrsol+=nr[k];
    }
}
int main ()
{
    freopen ("drumuri1.in", "r", stdin);
    freopen ("drumuri1.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            scanf ("%d", &a[i][j]);
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            act=(i-1)*n+j;
            if (a[i-1][j]!=0 && a[i-1][j]<a[i][j]) v[act].push_back(act-n), ++bigger[act-n];
            if (a[i][j+1]!=0 && a[i][j+1]<a[i][j]) v[act].push_back(act+1), ++bigger[act+1];
            if (a[i+1][j]!=0 && a[i+1][j]<a[i][j]) v[act].push_back(act+n), ++bigger[act+n];
            if (a[i][j-1]!=0 && a[i][j-1]<a[i][j]) v[act].push_back(act-1), ++bigger[act-1];
        }
    for (i=1; i<=n*n; ++i)
        if (bigger[i]==0) q.push(i),++nr[i];
    parcurgere ();
    printf ("%d\n", nrsol);
    return 0;
}
