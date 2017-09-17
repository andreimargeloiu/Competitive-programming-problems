# include <fstream>
# include <algorithm>
# include <vector>
# include <iomanip>
# define mp make_pair
# define f first
# define s second
# define NR 1000005
# define MOD1 125
# define MOD2 287
using namespace std;
ifstream f("harta2.in");
ofstream g("harta2.out");
vector <pair <int, int> > v[MOD1+5][MOD2+5];
struct elem {
    int x, y;
}a[NR];
int i,j,n,m;
double ci,cs,mij,sol;
int dx[]={1, 0, 1};
int dy[]={0, -1, -1};

void curata () {
    for (int i=0; i<MOD1; ++i)
        for (int j=0; j<MOD2; ++j)
            v[i][j].clear();
}
bool add(int X, int Y, int x, int y, double K) {
    for (int i=0; i<v[X][Y].size(); ++i)
        if ((int)(v[X][Y][i].f/K) == x && (int)(v[X][Y][i].s/K) == y) return 0;

    return 1;
}
bool solutie (double K) {
    //le impart in caroiaj
    int i,j,x,y,X,Y,I;
    curata ();
    for (i=1; i<=n; ++i) {
        x=((int)(a[i].x/K))%MOD1; y=((int)(a[i].y/K))%MOD2;

        if (add(x, y, (int)(a[i].x/K), (int)(a[i].y/K), K)) v[x][y].push_back(mp(a[i].x, a[i].y));
        else return 0;
    }
    //daca am ajuns pana aici inseamna ca fiecare punct
    //are caroul propriu

    //verific cu distanta vecinii
    for (i=1; i<=n; ++i) {
        x=((int)(a[i].x/K))%MOD1; y=((int)(a[i].y/K))%MOD2;

        for (I=0; I<3; ++I) {
            X=x+dx[I]; Y=y+dy[I];
            if (X>=0 && Y>=0 && v[X][Y].size()) {
                for (j=0; j<v[X][Y].size(); ++j) {
                    if ((v[X][Y][j].f!=x || v[X][Y][j].s!=y) &&
                        (double)(abs(a[i].x - v[X][Y][j].f))<=K &&
                        (double)(abs(a[i].y - v[X][Y][j].s))<=K)
                         return 0;
                }
            }
        }
    }
    return 1;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i].x>>a[i].y;
        ++a[i].x; ++a[i].y;
        a[i].y*=3;
    }

    ci=0; cs=1000;
    while (ci+0.01 <= cs) {
        mij=(ci+cs)/2;
        if (solutie (mij)) ci=mij+0.01, sol=mij;
                      else cs=mij-0.01;
    }
    g<<fixed<<setprecision(3)<<sol/3<<"\n";

    return 0;
}
