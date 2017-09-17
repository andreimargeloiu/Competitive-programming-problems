# include <algorithm>
# include <fstream>
# include <cmath>
# define NR 105
using namespace std;
ifstream f("cmin.in");
ofstream g("cmin.out");
struct elem {
    int x, y, x2, y2, cost;
}E, vect[NR*NR];
bool cmp (elem x, elem y) {
    if (x.cost>=y.cost) return 0;
                   else return 1;
}
int i,j,n,m,VV,VV1,V,V1,nr1,nr2,sol;
int a[NR][NR], b[NR][NR], var[NR];
void roteste ()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            b[i][j]=a[j][n-i+1];

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            a[i][j]=b[i][j];
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j) {
            f>>a[i][j];
            if (i<=n/2) nr1+=a[i][j];
            if (i>n/2) nr2+=a[i][j];
        }
    if (nr2 > nr1) {roteste(); roteste(); swap(nr1, nr2);}

    // avem mai multe puncte sus
    for (j=1; j<=n; ++j) {
        VV=0; VV1=0;
        for (i=n/2+1; i<=n; ++i)
            if (a[i][j]==0) var[++VV]=i;

        for (i=n/2; i>=1 && VV1<VV; --i) {
            if (a[i][j]) {
                ++VV1;
                E.x=i; E.y=j; E.x2=var[VV1]; E.y2=j; E.cost=var[VV1] - i;
                vect[++V]=E;
            }
        }
    }
    sort (vect+1, vect+V+1, cmp);

    while (abs(nr1-nr2)>1) {
        sol+=vect[++V1].cost;
        --nr1; ++nr2;
    }
    g<<sol<<"\n";


    return 0;
}
