# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("plantatie.in");
ofstream g("plantatie.out");
int i,j,n,m,x,y,maxx,k,L,Q;
int lg[600], a[505][505][10];
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            f>>a[i][j][0];

    for (i=2; i<=n; ++i)
        lg[i]=lg[i/2]+1;

    for (k=1; k<=lg[n]; ++k)
        for (i=1; i<=n-(1<<k)+1; ++i)
            for (j=1; j<=n-(1<<k)+1; ++j)
            {
                int l=(1<<(k-1));
                a[i][j][k]=max(a[i][j][k-1], a[i+l][j+l][k-1]);
                a[i][j][k]=max(a[i][j][k], a[i][j+l][k-1]);
                a[i][j][k]=max(a[i][j][k], a[i+l][j][k-1]);
            }
    for (i=1; i<=Q; ++i)
    {
        f>>x>>y>>L;
        k=lg[L]; int R=L-(1<<k);

        int maxx1=max(a[x][y][k], a[x][y+R][k]);
        int maxx2=max(a[x+R][y][k], a[x+R][y+R][k]);
        g<<max(maxx1, maxx2)<<"\n";
    }


    return 0;
}
