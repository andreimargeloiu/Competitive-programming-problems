# include <cstdio>
# include <algorithm>
# include <queue>
# define NR 100005
using namespace std;
queue <int> q;
int i,j,n,m,s,tip,maxx,x,y,S;
int grad[NR], T[NR], nr[NR], cost[NR];
void sortaret ()
{
    int i,j,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        maxx=max(maxx, nr[k]);

        nr[T[k]]+=nr[k]+1;
        --grad[T[k]];
        if (grad[T[k]]==0) q.push(T[k]);
    }
}
void sortaret2 ()
{
    int i,j,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        S+=cost[k];

        cost[T[k]]=max(cost[T[k]], cost[k]+1);
        --grad[T[k]];
        if (grad[T[k]]==0) q.push(T[k]);
    }
}
int main ()
{
    freopen ("firma.in", "r", stdin);
    freopen ("firma.out", "w", stdout);
    scanf ("%d", &tip);
    scanf ("%d%d%d", &n, &m, &s);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        T[y]=x; ++grad[x];
    }

    if (tip==1) //nr de sefi
    {
        int nr=0;
        for (i=1; i<=n; ++i)
            if (! T[i]) ++nr;
        printf ("%d\n", nr);
    }
    else if (tip==2) //departamentul maxim
    {
        for (i=1; i<=n; ++i)
            if (grad[i]==0) q.push(i);
        sortaret ();
        printf ("%d\n", maxx+1);
    }
    else if (tip==3) //suma minima
    {
        for (i=1; i<=n; ++i)
            if (grad[i]==0) {cost[i]=s; q.push(i);}

        sortaret2();
        printf ("%d\n", S);
    }


    return 0;
}
