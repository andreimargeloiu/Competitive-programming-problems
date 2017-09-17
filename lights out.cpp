# include <fstream>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <vector>
# define MOD 666013
# define MOD2 213487
# define NR 205
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("lightsout.in");
ofstream g("lightsout.out");
struct elem {
    int x, y;
}st, dr;
struct elem2 {
    int cod, i, l;
}X;
vector <elem2> HASH[MOD];

int i,j,n,m,distPanaAcum,maxx,cost,VV,colt,D,D_next;
int ceas[NR], trig[NR], x[NR], y[NR];
int drum[NR][3*NR], minn[NR];
long long produs, produs2;

int corner (int k) {

    st.x=x[k-1]; st.y=y[k-1];
    dr.x=x[k+1]; dr.y=y[k+1];

    if (st.x != dr.x && st.y != dr.y) return -3; // - colt drept
                                 else return -7; // - colt orizontal
}
int dist (int i, int j) {
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
int gaseste (int I, int l) {
    // hash  [produs][suma]
    int L=2*l+1, ok;

    for (int i=2; i<n; ++i) {
        if (i==I) continue;
        ok=1;
        for (j=1; j<=l && ok; ++j)
            if (drum[i][j]!=drum[I][j]) ok=0;

        if (ok) return 1;
    }
    return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x[i]>>y[i]; x[n+i]=x[i]; y[n+i]=y[i];
        // sens trigonometric
        if (i>1) trig[i]=trig[i-1] + dist (i, i-1);
    }
    x[0]=x[n]; y[0]=y[n];

    for (i=n; i>=2; --i) {
        ceas[i]=ceas[i+1] + dist (i, i+1);
        minn[i]=min(ceas[i], trig[i]);
    }

    // fac drumurile + hash
    // colt + drum + colt
    for (i=2; i<n; ++i) {
        VV=0; produs=1; produs2=1;

        //coltul
        drum[i][++VV]=corner(i);
        for (j=1; i+j<=n+1; ++j) {
            colt=i+j;

            //lungimea
            drum[i][++VV]=dist(colt-1, colt);
            drum[i][++VV]=corner(colt);
        }
    }
    // pun in hash suma si indicele de la care plec
    for (i=2; i<n; ++i) {
         distPanaAcum=0;
         if (gaseste(i, 0)) continue;

         for (j=0; i+j<=n+1; ++j) {
            colt=i+j; D_next=dist(colt-1, colt);
            if (gaseste(i, j)) { // e solutie
                D=min(distPanaAcum + 2*D_next + trig[colt-1], ceas[i]);
                D-=minn[colt-1];

                maxx=max(maxx, D);

                break;
            }
            distPanaAcum+=D_next;
        }
    }

    g<<maxx<<"\n";

    return 0;
}
