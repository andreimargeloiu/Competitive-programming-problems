# include <fstream>
# include <algorithm>
# include <vector>
# define MOD 666013
# define NR 100005
using namespace std;
ifstream f("karb2.in");
ofstream g("karb2.out");
vector <int> v[NR];
int i,j,n,m,x,y;
int dp[NR][3], special[NR], K, L[NR], R[NR], aux[NR];
//dp[i][0] - culoarea vine de jos
//dp[i][1] - culoarea vine de sus
void DFS (int k, int tata) {
    if (v[k].size()==1 && k!=1) { // e frunza
        if (special[k]) dp[k][0]=1;
                   else dp[k][1]=1;
    }
    else {
        int VV=0, x;
        for (auto &x: v[k])
            if (x!=tata) DFS (x, k);
        for (auto &x: v[k])
            if (x!=tata) aux[++VV]=x;

        if (special[k]) {
            dp[k][0]=1;
            for (int i=1; i<=VV; ++i) {
                 x=aux[i];
                 dp[k][0]=(1LL * dp[k][0] * (dp[x][0] + dp[x][1]))%MOD;
            }
        }
        else {
            dp[k][1]=1;
            for (int i=1; i<=VV; ++i) {
                 x=aux[i];
                 dp[k][1]=(1LL * dp[k][1] * (dp[x][0] + dp[x][1]))%MOD;
            }


            L[0]=1; R[VV+1]=1;
            for (int i=1; i<=VV; ++i) {
                x=aux[i];
                L[i]=(1LL * L[i-1] * (dp[x][0] + dp[x][1]))%MOD;
            }
            for (int i=VV; i>=1; --i) {
                x=aux[i];
                R[i]=(1LL * R[i+1] * (dp[x][0] + dp[x][1]))%MOD;
            }
            if (VV==1) dp[k][0]=dp[aux[1]][0];
            else {
                for (int i=1; i<=VV; ++i) {
                    x=aux[i];
                    dp[k][0]=(1LL * dp[x][0] * L[i-1] * R[i+1] + dp[k][0])%MOD;

                    if (dp[k][0] >= MOD) dp[k][0]-=MOD;
                }
            }
        }
    }
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=K; ++i) {
        f>>x;
        special[x]=1;
    }

    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1, 0);

    g<<dp[1][0]<<"\n";

    return 0;
}
