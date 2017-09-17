# include <fstream>
# include <algorithm>
# define NR 105
# define inf 999999999
using namespace std;
ifstream f("joc.in");
ofstream g("joc.out");
struct elem
{
    int x,y;
}sol[1000];
int i,j,n,m,x,y,k,ok,o,lv,cv,nrsol,I,J;
int a[NR][NR], sum[NR][NR], nr[NR];
int dx[]={-1,-1,0};
int dy[]={0,-1,-1};
void init ()
{
    int i,j;
    //prima linie
    for (i=0; i<=n+1; ++i)
        a[i][0]=a[i][m+1]=-1;
    for (i=0; i<=m+1; ++i)
        a[0][i]=a[n+1][i]=-1;

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            sum[i][j]=-inf;

    sum[1][1]=nr[a[1][1]];
}
int main ()
{
    f>>n>>m>>k;
    for (i=1; i<=k; ++i)
        f>>nr[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            f>>a[i][j];

    init ();

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            if (i==1 && j==1) continue;

            ok=1;
            for (o=0; o<3; ++o)
            {
                lv=i+dx[o]; cv=j+dy[o];
                if (a[lv][cv]!=-1)
                {
                    ok=0;
                    sum[i][j]=max(sum[i][j], sum[lv][cv]+nr[a[i][j]]);
                }
            }
            if (ok) a[i][j]=-1;
        }

    if (a[n][m]==-1)//imposibil
    {
        g<<"imposibil\n";
    }
    else {
             g<<sum[n][m]<<"\n";
             I=n; J=m;
             while (1)
             {
                 sol[++nrsol].x=I; sol[nrsol].y=J;

                 if (I==1 && J==1) break;

                 for (o=0; o<3; ++o)
                 {
                     lv=I+dx[o]; cv=J+dy[o];
                     if (a[lv][cv]!=-1)
                     {
                        if (sum[lv][cv]==sum[I][J]-nr[a[I][J]])
                        {
                            I=lv; J=cv; break;
                        }
                     }
                 }
             }

             for (i=nrsol; i>=1; --i)
                g<<sol[i].x<<" "<<sol[i].y<<"\n";
         }

    return 0;
}
