# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("zoo.in");
ofstream g("zoo.out");
struct elem {
    int x, y;
}v[NR];
bool cmp (elem x, elem y) {
    return (x.x < y.x);
}
int i,j,n,m,x,y,x2,y2,poz;
int A[20][NR]; // pun in matrice indicii elementelor de pe pozitia st-dr
void make_arb (int niv, int ci, int cs) {
    if (ci==cs) {//daca e doar o abscisa
        A[niv][ci]=ci;
    } else {
        int mij=(ci+cs)/2;
        make_arb(niv+1, ci, mij);
        make_arb(niv+1, mij+1, cs);

        // acum trebuie sa il interclasez
        int i,j,k;
        i=ci; j=mij+1; k=ci;

        while (i<=mij && j<=cs) {
            if (v[A[niv+1][i]].y < v[A[niv+1][j]].y) A[niv][k++] = A[niv+1][i++];
                else A[niv][k++] = A[niv+1][j++];
        }
        while(i<=mij) A[niv][k++]=A[niv+1][i++];
        while(j<=cs)  A[niv][k++]=A[niv+1][j++];
    }
}
int calc(int niv, int ci, int cs, int ys, int yd)
{
    int l=ci, r=cs, mij, sol1=ci-1, sol2=ci-1;
    // pentru yd
    while (l<=r) {
        int mij=(l+r)/2;
        if (v[A[niv][mij]].y <= yd) l=mij+1, sol1=mij;
                               else r=mij-1;
    }
    // pentru ys
    l=ci; r=cs;
    while (l<=r) {
        int mij=(l+r)/2;
        if (v[A[niv][mij]].y <= ys) l=mij+1, sol2=mij;
                               else r=mij-1;
    }

    return sol1-sol2;
}
int query(int niv, int ci, int cs, int xs, int ys, int xd, int yd) {
    // daca am intrat intr-un interval care nu mai este bun
    if(v[cs].x < xs || xd < v[ci].x) return 0;

    // daca intervalul actual e inclus in intervalul cautat
    if(xs <= v[ci].x && v[cs].x <= xd)
        return calc(niv, ci, cs, ys, yd);

    int mij=(ci+cs)/2, val=0;
    val+=query (niv+1, ci, mij, xs, ys, xd, yd);
    val+=query (niv+1, mij+1, cs, xs, ys, xd, yd);

    return val;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>v[i].x>>v[i].y;
    sort (v+1, v+n+1, cmp);

    make_arb(1, 1, n);

    f>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y>>x2>>y2;

        g<<query (1, 1, n, x, y-1, x2, y2)<<"\n";
    }

    return 0;
}
