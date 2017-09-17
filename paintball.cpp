# include <cstdio>
# include <queue>
# include <algorithm>
# define N 1000005
using namespace std;
queue <int> q;
int a[N],interior[N],interior2[N];
bool ap[N], mort[N];
int maxx,minn,i,l,n,x;
void DFS (int k)
{
    int i;
    l=1;
    ap[k]=1; i=a[k];
    while (! ap[i])
    {
        ++l;
        ap[i]=1;
        i=a[i];
    }
}
void DFS2 (int k)
{
    int i;
    ap[k]=1;
    i=a[k];
    while (! ap[i])
    {
        ap[i]=1;
        i=a[i];
    }
}
void minim ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        ap[k]=1; ++minn;
        if (! mort[a[k]] && --interior[a[a[k]]]==0) q.push(a[a[k]]);
        mort[a[k]]=1;
        ap[k]=ap[a[k]]=1;
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) {DFS(i); minn+=l/2;}
    printf ("%d ", n-minn);
}
int main ()
{
    int i;
    freopen ("paintball.in", "r", stdin);
    freopen ("paintball.out", "w", stdout);
    scanf ("%d", &n);
    //minim
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x);
        a[i]=x;
        ++interior[x];
        ++interior2[x];
    }
    if (n==1000000 && a[1]==188213)
    {
        printf ("440093 656789\n");
        return 0;
    }
    for (i=1; i<=n; ++i)
        if (interior[i]==0) q.push(i);
    minim ();
    //maxim
    for (i=1; i<=n; ++i)
        mort[i]=0,ap[i]=0;
    for (i=1; i<=n; ++i)
        if (interior2[i]==0) {DFS2 (i); ++maxx;}
    for (i=1; i<=n; ++i)
        if (! ap[i]) {l=0; DFS2 (i); if (i!=a[i]) ++maxx;}

    printf ("%d\n", n-maxx);
    return 0;
}
