# include <cstdio>
# include <algorithm>
# define inf 999999999
# define mil 1000005
using namespace std;
int i,j,n,m,k,ci,cs,mij,S,rez,NR,maxx;
int dist[mil];
int verificare (int mij)
{
    int i=2, S=0, K=0;
    while (i<=n)
    {
        S=0;
        //avansare
        while (S+dist[i]<=mij && i<=n)
        {
             S+=dist[i]; ++i;
        }
        //am gasit solutie
        S=0; ++K;//trecem de orasul centru
        //recuperez
        if (i==n) break;
        while (S+dist[i]<=mij && i<=n)
        {
             S+=dist[i]; ++i;
        }
        if (i==n) ++K;
        ++i;
    }
    return K;
}
int main ()
{
    freopen ("orase.in", "r", stdin);
    freopen ("orase.out", "w", stdout);
    scanf ("%d%d", &n, &k);
    for (i=2; i<=n; ++i)
    {
        scanf ("%d", &dist[i]);
        S+=dist[i];
    }
    dist[n+1]=inf; maxx=inf;
    ci=1; cs=S;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        //verificare
        rez=verificare(mij);
        if (rez>k) ci=mij+1; //daca nu a gasit solutie
            else {
                     cs=mij-1;
                     if (mij<maxx || (mij==maxx && NR<rez)) maxx=mij, NR=rez; //a gasit solutie
                 }
    }
    printf ("%d %d\n", maxx, NR);

    return 0;
}
