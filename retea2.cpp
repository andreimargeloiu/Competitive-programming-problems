# include <fstream>
# include <algorithm>
# include <vector>
# include <iomanip>
# define NR 2005
# define INF 999999999
using namespace std;
ifstream f("retea2.in");
ofstream g("retea2.out");
struct elem {
    long double x, y;
}C[NR], B[NR];
int i,j,n,m,I;
int ap[NR];
long double dist[NR], sol;
long double DIST (elem x, elem y) {
    return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y));
}
int minim () {
    int I;
    long double minim=INF;
    for (int i=1; i<=m; ++i)
        if (! ap[i] && dist[i]<minim) {
            I=i;
            minim=dist[i];
        }
    return I;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>C[i].x>>C[i].y;

    for (i=1; i<=m; ++i) {
        f>>B[i].x>>B[i].y;
        dist[i]=INF;
        for (j=1; j<=n; ++j)
            dist[i]=min(dist[i], DIST(C[j], B[i]));
    }
    for (i=1; i<=m; ++i) {
        I=minim (); ap[I]=1;
        sol+=dist[I];

        for (j=1; j<=m; ++j)
            if (!ap[j]) dist[j]=min(dist[j], DIST(B[j], B[I]));
    }
    g<<fixed<<setprecision(7)<<sol<<"\n";



    return 0;
}
