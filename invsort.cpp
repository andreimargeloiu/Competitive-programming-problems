# include <bits/stdc++.h>
# define NR 35000
using namespace std;
ifstream f("invsort.in");
ofstream g("invsort.out");
int i,j,n,m,cost;
int a[NR];
void intoare (int ci, int cs) {
    int mij=(cs - ci + 1) / 2;
    for (int i=1; i<=mij; ++i)
        swap(a[ci+i-1], a[cs-i+1]);

    g<<ci<<" "<<cs<<"\n";
}
void uneste (int ci, int cs, int mij, int K) {
    int CI=mij, CS=mij+1, okST=0, okDR=0;
    for (int i=mij; i>=ci; --i) {
        if (! ((1<<K) & a[i])) break;
                          else CI=i, okST=1;
    }
    for (int i=mij+1; i<=cs; ++i) {
        if (((1<<K) & a[i])) break;
                        else CS=i, okDR=1;
    }
    if (okST && okDR) {
        cost=cost + CS-CI+1;
        intoare (CI, CS);
    }
}
void divide (int ci, int cs, int K, int niv) {
    if (ci==cs) { // un singur element
        return;
    }
    int mij=(ci + cs)/2;
    if (ci<=mij)    divide (ci,   mij, K, niv+1);
    if (mij+1<=cs)  divide (mij+1, cs, K, niv+1);

    uneste (ci, cs, mij, K);

    if (niv==1 && K>0) {
        // daca este divide-le principal si ma mai bag in divide inca o data
        int X=cs+1, ok=0;
        for (int i=ci; i<=cs; ++i)
            if (a[i] & (1<<K)) {X=i; ok=1; break;} //locul unde e primul bit de 1

        if (X==ci || X==cs+1) { //au celasi bit
            divide (ci, cs, K-1, niv);
        } else { //au biti diferiti
            if (ci<=X-1) divide (ci, X-1, K-1, niv);
            if (X<=cs)   divide (X, cs,   K-1, niv);
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    //acum trebuie sa sortam dupa biti

    divide (1, n, 14, 1);
    //for (i=1; i<=n; ++i)
    //   g<<a[i]<<" ";

    return 0;
}
