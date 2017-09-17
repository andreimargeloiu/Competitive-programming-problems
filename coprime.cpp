# include <fstream>
# include <bitset>
# include <algorithm>
# define NR 15000
using namespace std;
ifstream f("coprime.in");
ofstream g("coprime.out");
int i,j,n,m,x,y,k,VV;
int a[20000], viz[50][50], mat[50][155];
bitset <NR> ap;
void prime ()
{
    a[1]=2; k=1;
    for (int i=3; i<=NR; i+=2)
        if (! ap[i])
        {
            a[++k]=i;
            for (int j=3; i*j<=NR; j+=2)
                ap[i*j]=1;
        }
}
void inmulteste (int k, int H)
{
    int t=0;
    for (int i=1; i<=mat[k][0]; ++i)
    {
        t=t + mat[k][i]*H;
        mat[k][i]=t%10;
        t=t/10;
    }
    while (t) mat[k][++mat[k][0]]=t%10, t=t/10;
}
int main ()
{
    prime ();

    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        mat[i][0]=1; mat[i][1]=1;
        while (mat[i][mat[i][0]]>9) mat[i][++mat[i][0]]=mat[i][mat[i][0]-1]/10, mat[i][mat[i][0]-1]%=10;
    }
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        viz[x][y]=viz[y][x]=1;
    }

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
        {
            if (! viz[i][j])
            {
                inmulteste (i, a[++VV]);
                inmulteste (j, a[VV]);
            }
        }

    for (i=1; i<=n; ++i)
    {
        for (j=mat[i][0]; j>=1; --j)
            g<<mat[i][j];
        g<<"\n";
    }


    return 0;
}
