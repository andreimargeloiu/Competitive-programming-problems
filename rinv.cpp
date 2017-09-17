# include <fstream>
using namespace std;
ifstream f("rfinv.in");
ofstream g("rfinv.out");
int i,j,n,m,k,q,t,x,y,ok,ok1;
int a[105][105],mat[105][105],ap[105][105];
int main ()
{
    f>>t;

    for (q=1; q<=t; ++q)
    {
        f>>n>>m;
        //initializam
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
                ap[i][j]=0,mat[i][j]=0;
        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            ap[x][y]=1; ap[y][x]=1;
        }
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
            {
                f>>a[i][j];
                if (ap[i][j]) mat[i][j]=a[i][j];
            }
        ok=1;
        for (k=1; k<=n; ++k)
            for (i=1; i<=n; ++i)
                for (j=1; j<=n; ++j)
                    if (mat[i][k] && mat[k][j] && (mat[i][k]+mat[k][j]<mat[i][j] || !mat[i][j]) && i!=j) mat[i][j]=mat[i][k]+mat[k][j];

       for (i=1; i<=n; ++i)
           for (j=1; j<=n; ++j)
               if (mat[i][j]!=a[i][j]) ok=0;

       if (ok) g<<"DA\n";
          else g<<"NU\n";
    }



    return 0;
}
