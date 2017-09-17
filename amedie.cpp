# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
int i,j,n,m,x,y,q,l,col,VV,mij,active;
int a[805][805], poz[805][805], ant[805*805], urm[805*805];
struct elem
{
    int l,c,nr;
}E,v[805*805];
char c;
bool cmp (elem x, elem y)
{
    if (x.nr>=y.nr) return 0;
    return 1;
}
void procesare ()
{
    sort (v+1, v+VV+1, cmp);
    mij=(1+VV)/2; active=VV;

    for (int i=1; i<=VV; ++i)
        ant[i]=i-1, urm[i]=i+1, poz[v[i].l][v[i].c]=i;
}
void eliminare (int l, int c)
{
    int i,M=poz[l][c];
    urm[ant[M]]=urm[M]; ant[urm[M]]=ant[M];

    if (active==1) { mij=0; return; }
    if (poz[l][c]==mij)//se elimina chiar elementul median
    {
        if (active%2==1) mij=ant[mij];
                    else mij=urm[mij];
        --active;
        return;
    }
    if (poz[l][c]<mij)
    {
        if (active%2==0) mij=urm[mij];
        --active;
        return;
    }
    if (poz[l][c]>mij)
    {
        if (active%2==1) mij=ant[mij];
        --active;
        return;
    }
}
int main ()
{
    freopen ("amedie.in", "r", stdin);
    freopen ("amedie.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &q);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            scanf ("%d", &a[i][j]);
            E.l=i; E.c=j; E.nr=a[i][j];
            v[++VV]=E;
        }
    scanf ("\n");

    procesare();

    for (i=1; i<=q; ++i)
    {
        scanf ("%ch", &c);
        if (c=='L')
        {
            scanf (" %d\n", &l);
            for (j=1; j<=m; ++j)
                if (a[l][j]!=-1)
                {
                    eliminare(l,j);
                    a[l][j]=-1;
                }
        }
        else if (c=='C')
        {
            scanf (" %d\n", &col);
            for (j=1; j<=n; ++j)
                if (a[j][col]!=-1)
                {
                    eliminare(j,col);
                    a[j][col]=-1;
                }
        }
        else if (c=='Q')
        {
            scanf ("\n");
            printf ("%d\n", v[mij].nr);
        }
    }
    return 0;
}
