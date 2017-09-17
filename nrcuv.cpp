# include <fstream>
# define MOD 104659
using namespace std;
ifstream f("nrcuv.in");
ofstream g("nrcuv.out");
int i,j,q,n,m,S;
int sum [1005][30],ap[50][50];
char ch1,ch2;
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>ch1>>ch2;
        ch1=ch1-'a'+1;
        ch2=ch2-'a'+1;
        ap[ch1][ch2]=1;
        ap[ch2][ch1]=1;
    }
    for (i=1; i<=26; ++i)
        sum[1][i]=1;
    for (i=2; i<=n; ++i)
    {
        for (j=1; j<=26; ++j)
        {
            for (q=1; q<=26; ++q)
                if (!ap[j][q]) sum[i][j]=(sum[i][j]+sum[i-1][q])%MOD;
        }
    }
    for (i=1; i<=26; ++i)
    {
        S+=sum[n][i];
        S%=MOD;
    }
    g<<S<<"\n";
    return 0;
}
