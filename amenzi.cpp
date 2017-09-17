# include <fstream>
# include <algorithm>
# include <vector>
# define Tmax 3505
# define N 155
using namespace std;
ifstream f("amenzi.in");
ofstream g("amenzi.out");
struct elem2
{
    int a, b;
}var[8005];
struct elem
{
    int y, cost;
}E;
vector <elem> v[N];
int i,j,n,m,K,p,x,y,a,b,c,t,cost,maxx;
int mat[N][Tmax], amenda[N][Tmax];
int main ()
{
    f>>n>>m>>K>>p;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>E.cost;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }

    for (i=1; i<=K; ++i)
    {
        f>>a>>b>>c;
        amenda[a][b]+=c; //intersectia a la momentul b
    }

    for (i=1; i<=p; ++i)
    {
        f>>var[i].a>>var[i].b;
        maxx=max(maxx, var[i].b);
    }

    mat[1][0]=1+amenda[1][0];
    for (t=1; t<=maxx; ++t)
    {
        for (i=1; i<=n; ++i)
        {
            mat[i][t]=mat[i][t-1];
            for (j=0; j<v[i].size(); ++j)
            {
                if (t>=v[i][j].cost && mat[v[i][j].y][t-v[i][j].cost])
                    mat[i][t]=max(mat[i][t], mat[v[i][j].y][t-v[i][j].cost]);
            }
            if (mat[i][t]) mat[i][t]+=amenda[i][t];
        }
    }

    for (i=1; i<=p; ++i)
    {
        a=var[i].a; b=var[i].b;
        if (mat[a][b]) g<<mat[a][b]-1<<"\n";
                  else g<<"-1\n";
    }

    return 0;
}
