# include <cstdio>
# include <algorithm>
# define inf 10000000
using namespace std;
int i,j,T,minn,maxx,VV,n,m,k,x,y,c;
int a[100][100],st[100],t[10],ap[100], luat[100], C[100];
void back (int k)
{
    int i,start,Rx,Ry;
    if (k==maxx+1)
    {
        int muchii,COST=0,minim,I;
        //apm cu prim
        for (i=1; i<=VV; ++i)
            luat[st[i]]=0, C[st[i]]=inf;
        muchii=0; C[st[1]]=0; luat[st[1]]=1;
        //costurile initiale
        for (i=1; i<=VV; ++i)
            C[st[i]]=a[st[1]][st[i]];
        while (muchii<VV-1)
        {
            ++muchii; minim=inf;
            for (i=1; i<=VV; ++i)
                if (!luat[st[i]] && C[st[i]]<minim) minim=C[st[i]], I=i;
            COST+=minim; luat[st[I]]=1;
            for (i=1; i<=VV; ++i)
                if (!luat[st[i]]) C[st[i]]=min(C[st[i]], a[st[I]][st[i]]);
        }
        if (COST<minn) minn=COST;
    }
    else
    {
        if (k==1) start=1;
            else start=st[VV]+1;
        for (i=start; i<=n; ++i)
            if (! ap[i])
            {
                ap[i]=1; st[++VV]=i;
                back(k+1);
                ap[i]=0; st[VV]=0; --VV;
            }
    }
}
int main ()
{
    freopen ("subarbore.in", "r", stdin);
    freopen ("subarbore.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
        {scanf ("%d%d%d", &x, &y, &c); a[x][y]=c; a[y][x]=c;}
    for (k=1; k<=n; ++k)
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
                if (a[i][k] && a[k][j] && i!=j && (! a[i][j] || a[i][j]>a[i][k]+a[k][j]))
                    a[i][j]=a[i][k]+a[k][j];
    scanf ("%d", &T);
    for (i=1; i<=T; ++i)
        {scanf ("%d", &t[i]); st[++VV]=t[i]; ap[t[i]]=1;}
    minn=inf;
    for (i=0; i<=T-2; ++i)
        {maxx=i; back(1);}
    printf ("%d\n", minn);
    return 0;
}
