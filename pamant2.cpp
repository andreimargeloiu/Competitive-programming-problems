# include <cstdio>
# include <vector>
# include <algorithm>
# define maxi 100005
using namespace std;
vector <int> v[maxi];
int ap[maxi],minn[maxi],low[maxi],luat[maxi],nod[maxi];
int i,j,n,m,x,y,nrfii,M,N;
void DFS (int k, int nivel, int parinte)
{
    int i;
    minn[M]=min(minn[M], k);
    ap[k]=1; low[k]=nivel;
    for (i=0; i<v[k].size(); ++i)
    {
        if (v[k][i]!=parinte)
        {
            int ok=0;
            if (ap[v[k][i]]==0)
            {
                if (nivel==1) ++nrfii;
                ok=1;
                DFS(v[k][i],nivel+1,k);
            }
            low[k]=min(low[k], low[v[k][i]]);
            if (nivel!=1 && ok && low[v[k][i]]>=nivel && !luat[k])
            {
                luat[k]=1;
                nod[++N]=k;
            }
        }
    }
}
int main ()
{
    freopen ("pamant.in", "r", stdin);
    freopen ("pamant.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
    {
        if (!ap[i])
        {
            minn[++M]=n; nrfii=0;
            DFS(i,1,0);
            if (nrfii>1) nod[++N]=i;
        }
    }
    sort (minn+1,minn+M+1);
    sort (nod+1,nod+N+1);
    printf ("%d\n", M);
    for (i=1; i<=M; ++i)
        printf ("%d ", minn[i]);
    printf ("\n%d\n", N);
    for (i=1; i<=N; ++i)
        printf ("%d ", nod[i]);
    return 0;
}
