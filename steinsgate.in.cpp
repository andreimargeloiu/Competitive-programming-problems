# include <cstring>
# include <fstream>
# include <algorithm>
# include <vector>
# define NR 205
using namespace std;
ifstream f("steinsgate.in");
ofstream g("steinsgate.out");
vector <int> v[NR], vt[NR];
int i,j,n,m,x,y,K,maxx;
int risc[NR];
bool a[NR][NR], b[NR][NR], c[NR][NR], sol[NR][NR];
void inmultire (bool a[][NR], bool b[][NR]) {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            c[i][j]=0;
            for (int k=1; k<=n; ++k)
                if (a[i][k] && b[k][j]) c[i][j]=1;
        }
    }

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            a[i][j]=c[i][j];
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        a[x][y]=1; sol[x][y]=1;
    }
    for (i=1; i<=n; ++i)
        f>>risc[i];
    --K;
    while (K) {
        if (K%2==1) {
            inmultire (sol, a);
            --K;
        } else {
            inmultire (a, a);
            K=K/2;
        }
    }

    for (i=1; i<=n; ++i) {
        maxx=0;
        for (j=1; j<=n; ++j)
            if (sol[j][i]) maxx=max(maxx, risc[j]);
        g<<maxx<<" ";
    }
    g<<"\n";

    return 0;
}
