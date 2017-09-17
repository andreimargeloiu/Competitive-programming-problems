# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("arbint.in");
ofstream g("arbint.out");
int i,j,n,m,tip,a,b,x,poz,maxx;
int ARB [4*NR];
void actualizare (int nod, int ci, int cs, int poz, int val)
{
    if (ci==poz && cs==poz) ARB[nod]=val;
    else {
             int mij=(ci+cs)/2;
             if (poz<=mij) actualizare (nod*2, ci, mij, poz, val);
                      else actualizare (nod*2+1, mij+1, cs, poz, val);

             ARB[nod]=max(ARB[2*nod], ARB[2*nod+1]);
         }
}
int maxim (int nod, int ci, int cs, int st, int dr)
{
    if (st<=ci && cs<=dr) maxx=max (maxx, ARB[nod]);
    else {
             int mij=(ci+cs)/2;
             if (st<=mij) maxim (nod*2, ci, mij, st, dr);
             if (dr>mij)  maxim (nod*2+1, mij+1, cs, st, dr);
         }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        actualizare (1, 1, n, i, x);
    }

    for (i=1; i<=m; ++i)
    {
        f>>tip;
        if (tip==0) //maxim
        {
            f>>a>>b;
            maxx=0; maxim (1, 1, n, a, b);
            g<<maxx<<"\n";
        }
        else { //actualizare
                 f>>poz>>x;
                 actualizare (1, 1, n, poz, x);
             }
    }




    return 0;
}
