# include <fstream>
# include <algorithm>
# include <bitset>
# define NR 1000005
using namespace std;
ifstream f("eliminare.in");
ofstream g("eliminare.out");
struct elem
{
    int sum, poz;
}ARB[4*NR];
int i,j,n,m,x,y,POZ,ok,X,Y,I,ramase,Q,CI,CS,maxim;
int a[NR], ap[NR];
void update (int nod, int ci, int cs)
{
    if (ci==cs)
    {
        ARB[nod].sum+=ok;
        if (ok==1) ARB[nod].poz=ci;
              else ARB[nod].poz=0;
    }
    else {
             int mij=(ci+cs)/2;
             if (I<=mij) update (2*nod, ci, mij);
             else update (2*nod+1, mij+1, cs);

             if (a[ARB[2*nod].poz] >= a[ARB[2*nod+1].poz]) ARB[nod].poz=ARB[2*nod].poz;
                                                      else ARB[nod].poz=ARB[2*nod+1].poz;

             ARB[nod].sum=ARB[2*nod].sum + ARB[2*nod+1].sum;
         }
}
void real (int nod, int ci, int cs, int &sol)
{
    if (ci==cs) sol=ci;
    else {
             int mij=(ci+cs)/2;
             if (ramase<=ARB[2*nod].sum) real (2*nod, ci, mij, sol);
             else
             {
                 ramase-=ARB[2*nod].sum;
                 real (2*nod+1, mij+1, cs, sol);
             }
         }
}
void cauta (int nod, int ci, int cs)
{
    if (CI<=ci && cs<=CS)
    {
        if (a[ARB[nod].poz]>a[POZ]) POZ=ARB[nod].poz;
        else if (a[ARB[nod].poz]==a[POZ]) POZ=min(POZ, ARB[nod].poz);
    }
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij) cauta (2*nod, ci, mij);
             if (CS>mij) cauta (2*nod+1, mij+1, cs);
         }
}
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
    {
        f>>x; a[i]=x;
        ok=1; I=i;
        update (1, 1, n);
    }

    for (i=1; i<=Q; ++i)
    {
        f>>x>>y;
        if (x>y) swap(x, y);
        ramase=x; real(1, 1, n, X);
        ramase=y; real(1, 1, n, Y);

        CI=X; CS=Y; POZ=0;
        cauta (1, 1, n);

        ap[POZ]=1; X=0; ok=-1; I=POZ;
        update (1, 1, n);
    }

    for (i=1; i<=n; ++i)
        if (! ap[i]) g<<a[i]<<"\n";

    return 0;
}
