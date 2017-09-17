# include <fstream>
# include <algorithm>
# define NR 101
using namespace std;
ifstream f("munte.in");
ofstream g("munte.out");
int i,j,n,m,k,K,S;
int pct[NR];
long long a[NR][NR][NR][2];
void aduna (int i, int j, int k, int k2)
{
    if (j<n)
    {
        //fara H max
        a[i][j][k][0] += a[i-1][j-1][k2][0]; //urca
        a[i][j][k][0] += a[i-1][j][k2][0];   //merge
        a[i][j][k][0] += a[i-1][j+1][k2][0]; //coboara

        //cu H max
        a[i][j][k][1] += a[i-1][j-1][k2][1]; //urca
        a[i][j][k][1] += a[i-1][j][k2][1];   //merge
        a[i][j][k][1] += a[i-1][j+1][k2][1]; //coboara
    }
    if (j==n)
    {
        a[i][j][k][1] += a[i-1][j-1][k2][0]; //urca
        a[i][j][k][1] += a[i-1][j][k2][0];   //merge
        a[i][j][k][1] += a[i-1][j+1][k2][0]; //coboara

        a[i][j][k][1] += a[i-1][j-1][k2][1]; //urca
        a[i][j][k][1] += a[i-1][j][k2][1];   //merge
        a[i][j][k][1] += a[i-1][j+1][k2][1]; //coboara
    }
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=K; ++i)
        f>>pct[i];
    pct[0]=999;

    //a[i][j][k] - numarul de moduri de a ajunge la dist i pe orizontala,
    //             j pe verticala si sa fi trecut prin primele k puncte
    a[0][0][0][0]=1;
    for (i=1; i<=m; ++i)
    {
        if (i==m) S=0;
             else S=1;
        for (j=S; j<=n; ++j)
            for (k=0; k<=K; ++k)
            {
                if (k>0 && j==pct[k])
                {
                    aduna (i, j, k, k-1);
                }
                else aduna (i, j, k, k);
            }
    }
    g<<a[m][0][K][1];

    return 0;
}
