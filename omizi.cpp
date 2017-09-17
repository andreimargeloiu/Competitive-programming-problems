# include <fstream>
# include <cstring>
# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 20005
using namespace std;
ifstream f("omizi.in");
vector <int> v[NR];
struct omida {
    int i, nod;
    char ch;
}a[NR];
int i,j,n,m,x,nod,VVst,VVdr,NOU;
int sol[NR], ST1[NR], ST2[NR], DR1[NR], DR2[NR], niv[NR];
int ARB[3][4*NR], euler[3][NR];
char ch;
bool cmp (omida x, omida y) {
    if (niv[x.nod] < niv[y.nod]) return 0;
    else if (niv[x.nod]==niv[y.nod] && x.i>=y.i) return 0;
                             else return 1;
}
void DFSst (int k,  int nivel) {
    niv[k]=nivel; ST1[k]=VVst+1;
    for (int i=0; i<v[k].size(); ++i)
        DFSst(v[k][i], nivel+1);

    ++VVst; euler[1][VVst]=k; ST2[k]=VVst;
}
void DFSdr (int k)
{
    DR1[k]=VVdr+1;
    for (int i=v[k].size()-1; i>=0; --i)
        DFSdr (v[k][i]);

    ++VVdr; euler[2][VVdr]=k; DR2[k]=VVdr;
}
void arb_make (int nod, int ci, int cs)
{
    ARB[1][nod]=cs-ci+1; ARB[2][nod]=cs-ci+1;

    if (ci!=cs) {
        int mij=(ci+cs)/2;
        arb_make(2*nod, ci, mij);
        arb_make(2*nod+1, mij+1, cs);
    }
}
void update (int tip, int nod, int ci, int cs, int D, int Plus)
{
    ARB[tip][nod]+=Plus;
    if (ci<cs)
    {
        int mij=(ci+cs)/2;
        if (D<=mij) update (tip, 2*nod, ci, mij, D, Plus);
               else update (tip, 2*nod+1, mij+1, cs, D, Plus);
    }
}
int gasire (int tip, int nod, int ci, int cs, int CI, int CS)
{
    if (ci==cs) NOU=euler[tip][ci];
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij && ARB[tip][2*nod]) gasire (tip, 2*nod, ci, mij, CI, CS);
             if (! NOU && mij<CS && ARB[tip][2*nod+1]) gasire (tip, 2*nod+1, mij+1, cs, CI, CS);
         }
}
int main ()
{
    f>>n>>m;
    nod=1;
    while (nod<=n && f>>x)
    {
        if (x==0) ++nod;
        else v[nod].push_back(x);
    }
    for (i=1; i<=m; ++i) {
        f>>a[i].nod; f.get();
        f>>ch; a[i].ch=ch; f.get();
           a[i].i=i;
    }
    // facem arborii cu parcurgerile din stanga si dreapa
    DFSst (1, 0); DFSdr (1);

    arb_make(1, 1, n);
    // pun omizile la pozitiilor lor de start
    // arborele este pe vectorul EULER @@@@@@@@@@@@@@@@@@@@@@@@@
    // ST, DR - pozitia in vectorul de euler
    for (i=1; i<=m; ++i) {
        //ARB[1] - stanga
        //ARB[2] - dreapta
        update(1, 1, 1, n, ST2[a[i].nod], -1);
        update(2, 1, 1, n, DR2[a[i].nod], -1);
    }
    sort (a+1, a+m+1, cmp);

    for (i=1; i<=m; ++i) {
        // il extragem
        if (i==14)
        {

            i+=0;

        }
        NOU=0;
        update (1, 1, 1, n, ST2[a[i].nod], 1);
        update (2, 1, 1, n, DR2[a[i].nod], 1);
        if (a[i].ch=='S') gasire (1, 1, 1, n, ST1[a[i].nod], ST2[a[i].nod]);
                     else gasire (2, 1, 1, n, DR1[a[i].nod], DR2[a[i].nod]);

        if (NOU==0) {
            NOU+=0;
        }

        update (1, 1, 1, n, ST2[NOU], -1);
        update (2, 1, 1, n, DR2[NOU], -1);

        sol[a[i].i]=NOU;
    }

    freopen ("omizi.out", "w", stdout);
    for (i=1; i<=m; ++i)
        printf ("%d\n", sol[i]);


    return 0;
}
