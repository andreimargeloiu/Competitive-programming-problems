# include <algorithm>
# include <fstream>
# include <cstring>
# define NR 1050
# define mp make_pair
# define INF 999999999
using namespace std;
ifstream f("radio.in");
ofstream g("radio.out");
struct elem {
    int x, y;
}aa[NR], bb[NR];
int i,j,n,m,x,y;
int minn[NR][NR];
char A[NR], B[NR];

int dist (int x, int y, int x2, int y2) {
    return (x-x2)*(x-x2) + (y-y2)*(y-y2);
}
void rezolva () {
    int i,j,MIN,DIST;

    for (i=0; i<=n; ++i) {
        for (j=0; j<=m; ++j) {
            MIN=INF;
            if (i==0 && j==0) continue;

            if (i>0) MIN=min(MIN, minn[i-1][j] + dist(aa[i].x, aa[i].y, bb[j].x, bb[j].y));
            if (j>0) MIN=min(MIN, minn[i][j-1] + dist(aa[i].x, aa[i].y, bb[j].x, bb[j].y));
            if (i>0 && j>0 ) MIN=min(MIN, minn[i-1][j-1] + dist(aa[i].x, aa[i].y, bb[j].x, bb[j].y));

            minn[i][j]=MIN;
        }
    }
}
void citire () {
    f>>n>>m;
    f>>aa[0].x>>aa[0].y;
    f>>bb[0].x>>bb[0].y; f.get();

    f.getline (A+1, NR);
    for (i=1; i<=n; ++i) {
        switch (A[i]) {
            case 'N': {x=0; y=1; break;}
            case 'E': {x=1; y=0; break;}
            case 'S': {x=0; y=-1; break;}
            case 'W': {x=-1; y=0; break;}
        }
        aa[i].x = aa[i-1].x + x;
        aa[i].y = aa[i-1].y + y;
    }

    f.getline (B+1, NR);
    for (i=1; i<=m; ++i) {
        switch (B[i]) {
            case 'N': {x=0; y=1; break;}
            case 'E': {x=1; y=0; break;}
            case 'S': {x=0; y=-1; break;}
            case 'W': {x=-1; y=0; break;}
        }
        bb[i].x = bb[i-1].x + x;
        bb[i].y = bb[i-1].y + y;
    }
}
int main ()
{
    citire ();

    rezolva ();
    g<<minn[n][m]<<"\n";

    return 0;
}
