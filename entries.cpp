# include <cstdio>
# include <algorithm>
# define NR 10005
using namespace std;
int i,j,n,m,x,y,k,VV,Rx,Ry;
int v[NR],H[NR],R[NR];
void eliminare ()
{
    int i, n=VV; VV=0;
    for (i=1; i<=n; ++i)
        if (v[i]!=v[i-1])
        {
            v[++VV]=v[i];
            R[VV]=VV; H[VV]=1;
        }
}
int cb (int x)
{
    int ci=1, cs=VV, mij;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (v[mij]==x) return mij;
        else if (x<v[mij]) cs=mij-1;
                      else ci=mij+1;
    }
}
int radacina (int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
int main ()
{
    freopen ("entries.in", "r", stdin);
    freopen ("entries.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d%d", &x, &y, &k);
        v[++VV]=x; v[++VV]=y;
    }
    sort (v+1, v+VV+1);
    eliminare ();

    fclose(stdin);
    freopen ("entries.in", "r", stdin);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d%d", &x, &y, &k);
        x=cb(x); y=cb(y);
        Rx=radacina(x);
        Ry=radacina(y);

        if (k==1) //unim
        {
            if (Rx!=Ry)
            {
                if (H[Rx]>H[Ry]) H[Rx]+=H[Ry], R[Ry]=Rx;
                            else H[Ry]+=H[Rx], R[Rx]=Ry;
            }
        }
        else {
                 if (Rx==Ry) printf ("1\n");
                        else printf ("0\n");
             }
    }

    return 0;
}
