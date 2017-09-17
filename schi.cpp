 # include <fstream>
 # include <algorithm>
 # define NR 30005
 using namespace std;
 ifstream f("schi.in");
 ofstream g("schi.out");
 int i,j,n,LOC;
 int poz[NR], loc[NR], ARB[4*NR];
 void init (int nod, int ci, int cs)
 {
     if (ci==cs) ARB[nod]=1;
     else {
              int mij=(ci+cs)/2;
              if (ci<=mij) init (2*nod, ci, mij);
              if (cs>mij)  init (2*nod+1, mij+1, cs);

              ARB[nod]=ARB[2*nod]+ARB[2*nod+1];
          }
 }
 void cauta (int nod, int ci, int cs, int ord)
 {
     if (ci==cs)
     {
         LOC=ci; --ARB[nod];
     }
     else {
              int mij=(ci+cs)/2;
              if (ord<=ARB[2*nod]) cauta (2*nod, ci, mij, ord);
                              else cauta (2*nod+1, mij+1, cs, ord-ARB[2*nod]);
              --ARB[nod];
          }
 }
 int main ()
 {
     f>>n;
     for (i=1; i<=n; ++i)
         f>>loc[i];

     init (1, 1, n);

     for (i=n; i>=1; --i)
     {
         cauta(1, 1, n, loc[i]);
         poz[LOC]=i;
     }

     for (i=1; i<=n; ++i)
        g<<poz[i]<<"\n";

     return 0;
 }
