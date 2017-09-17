# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1005
# define inf 999999999
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n,m,x,y,minn,K,k,lv,cv;
int a[NR][NR], mat[NR][NR];
int a2[100005], mat2[100005];
int dx[]={-1, 0}, dy[]={0, -1};

int xdoi[]={0, -1, -2}, ydoi[]={-2, -1, 0};
bool bun (int x, int y)
{
    if (1<=x && x<=n && 1<=y && y<=m) return 1;
                                else  return 0;
}
int main ()
{
    f>>n>>m>>K;
    if (m<=1000)
    {
        //citire
        for (i=1; i<=n; ++i)
            for (j=1; j<=m; ++j)
                f>>a[i][j];

        mat[1][1]=0;
        for (i=1; i<=n; ++i)
            for (j=1; j<=m; ++j)
            {
                if (i==1 && j==1) continue;
                minn=inf;
                //vin de la distanta 1
                for (k=0; k<2; ++k)
                {
                    lv=i + dx[k]; cv=j + dy[k];
                    if (bun (lv, cv))
                    {
                        minn=min(minn, mat[lv][cv]+1-(a[i][j]==a[lv][cv]));
                    }
                }
                //vin de la distanta 2
                for (k=0; k<3; ++k)
                {
                    lv=i + xdoi[k]; cv=j + ydoi[k];
                    if (bun(lv, cv) && a[i][j]==a[lv][cv]) //daca sunt egale, fac o punte intre ele
                    {
                        if (k==0) minn=min(minn, mat[lv][cv] + 1 - (a[i][j]==a[i][j-1]));
                        if (k==1)
                        {
                            minn=min(minn, mat[lv][cv] + 1 - (a[i][j]==a[i][j-1]));
                            minn=min(minn, mat[lv][cv] + 1 - (a[i][j]==a[i-1][j]));
                        }
                        if (k==2) minn=min(minn, mat[lv][cv] + 1 - (a[i][j]==a[i-1][j]));
                    }
                }
                mat[i][j]=minn;
            }
        g<<mat[n][m]<<"\n";
    }
    else if (n==1) //identic ca mai sus, doar ca adaptat la un singur rand
    {
        //citire
        for (j=1; j<=m; ++j)
            f>>a2[j];

        mat2[1]=0;
        for (i=2; i<=m; ++i)
        {
            minn=inf;
            //vin de la distanta 1
            minn=min(minn, mat2[i-1]+1-(a2[i]==a2[i-1]));

            //vin de la distanta 2
            if (i>2 && a2[i]==a2[i-2]) //daca sunt egale, fac o punte intre ele
            {
                minn=min(minn, mat2[i-2] + 1 - (a2[i]==a2[i-1]));
            }
            mat2[i]=minn;
        }
        g<<mat2[m]<<"\n";
    }

    /*for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<mat[i][j]<<" ";
        g<<"\n";
    }*/

    return 0;
}
