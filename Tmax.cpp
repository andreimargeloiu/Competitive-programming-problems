# include <fstream>
# include <algorithm>
# include <vector>
# define NR 2005
using namespace std;
ifstream f("trmax.in");
ofstream g("trmax.out");
int i,j,n,m,K,sol,x,y;
short DP[NR][NR], cons, maxx;
bool a[NR][NR];
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<=K; ++i) {
        f>>x>>y;
        a[x][y]=true;
    }

    for (i=1; i<=n; ++i) {
        cons=0;
        for (j=1; j<=m; ++j) {
            if (a[i][j]==true) cons=0;
            else {
                cons+=1;
                if (DP[i-1][j-1]) {
                    if (cons >= DP[i-1][j-1]+2) // iau sus
                       DP[i][j]=DP[i-1][j-1]+2;
                    else {
                        DP[i][j]=cons;
                        if (cons%2==0) --DP[i][j];
                    } //iau jos
                }
                else DP[i][j]=1;

                maxx=max(maxx, DP[i][j]);
            }
        }
    }

    for (i=1; i<=maxx; i+=2)
        sol=sol + i;
    g<<sol<<"\n";


    return 0;
}
