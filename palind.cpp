# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# define nrmax 7005
using namespace std;
int i,j,n,m,dif,sol,q,o,t,l,maxx,k,nrsol[5],x;
int ap[2][nrmax],mari[2][nrmax],mici[2][nrmax],ptmari[2][nrmax],ptmici[2][nrmax],minn[5];
void procesare ()
{
    int i;
    memset(mici, 0, sizeof(mici));
    memset(mari, 0, sizeof(mari));
    for (i=1; i<=maxx; ++i)
    {
        mici[0][i]=mici[0][i-1]+ap[0][i-1];
        mici[1][i]=mici[1][i-1]+ap[1][i-1];
    }
    for (i=maxx; i>=1; --i)
    {
        mari[0][i]=mari[0][i+1]+ap[0][i+1];
        mari[1][i]=mari[1][i+1]+ap[1][i+1];
    }
}
void numarare ()
{
    int i;
    //calculam costul
    minn[0]=99999999; minn[1]=99999999;
    memset(ptmici, 0, sizeof(ptmici));
    memset(ptmari, 0, sizeof(ptmari));
    for (i=1; i<=maxx; ++i)
    {
        ptmici[0][i]=ptmici[0][i-1]+mici[0][i-1]+ap[0][i-1];
        ptmici[1][i]=ptmici[1][i-1]+mici[1][i-1]+ap[1][i-1];
    }
    for (i=maxx; i>=1; --i)
    {
        ptmari[0][i]=ptmari[0][i+1]+mari[0][i+1]+ap[0][i+1];
        ptmari[1][i]=ptmari[1][i+1]+mari[1][i+1]+ap[1][i+1];
    }
    for (i=1; i<=maxx; ++i)
    {
        if (ptmari[0][i]+ptmici[0][i]<minn[0]) minn[0]=ptmari[0][i]+ptmici[0][i],nrsol[0]=1;
            else if (ptmari[0][i]+ptmici[0][i]==minn[0]) ++nrsol[0];

        if (ptmari[1][i]+ptmici[1][i]<minn[1]) minn[1]=ptmari[1][i]+ptmici[1][i],nrsol[1]=1;
            else if (ptmari[1][i]+ptmici[1][i]==minn[1]) ++nrsol[1];
    }
}
int main ()
{
    freopen ("palind.in", "r", stdin);
    freopen ("palind.out", "w", stdout);
    scanf ("%d", &t);
    for (o=1; o<=t; ++o)
    {
        scanf ("%d", &n);
        memset(ap, 0, sizeof(ap));
        maxx=0;
        for (i=1; i<=n; ++i)
        {
            scanf ("%d", &x);
            if (x>maxx) maxx=x;
            ++ap[i%2][x];
        }
        procesare ();
        numarare();
        printf ("%d %d\n", minn[0]+minn[1], nrsol[0]*nrsol[1]);
    }



    return 0;
}
