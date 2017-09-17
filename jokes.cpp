# include <fstream>
# include <algorithm>
# define NR 305
using namespace std;
ifstream f("jokes.in");
ofstream g("jokes.out");
int i,j,n,m,x,y,maxx;
int a[NR][NR], var[NR];

bool cmp (int x, int y) // -> iti baga valorile de pe 2 pozitii
{
    for (int i=1; i<=n; ++i)
        if (a[x][i] > a[y][i]) return 0;
            else if (a[x][i] < a[y][i]) return 1;

    if (x>y) return 0;
        else return 1;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j)
            f>>a[i][j];
        var[i]=i;
    }
    for (i=1; i<=n; ++i) {
        maxx=0;
        for (j=1; j<=n; ++j)
            maxx=max(maxx, a[j][i]);
        a[i][i]=maxx;
    }

    sort (var+1, var+n+1, cmp);

    for (i=1; i<=n; ++i)
        g<<var[i]<<" ";
    g<<"\n";

    return 0;
}
