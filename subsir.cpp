# include <fstream>
# include <algorithm>
# include <cstring>
# define N 505
# define mod 666013
using namespace std;
ifstream f("subsir.in");
ofstream g("subsir.out");
int i,j,n,m,la,lb,NR[N][N], L[N][N];
char a[N], b[N];
int main ()
{
    f.getline (a+1, N); la=strlen (a+1);
    f.getline (b+1, N); lb=strlen (b+1);

    for (i=1; i<=la; ++i)
        for (j=1; j<=lb; ++j)
            if (a[i]==b[j]) L[i][j]=L[i-1][j-1]+1;
                       else L[i][j]=max(L[i-1][j], L[i][j-1]);

    for (i=1; i<=la; ++i)
        for (j=1; j<=lb; ++j)
        {
            if(i==1 || j==1) {NR[i][j]=1; continue;}
            if (a[i]==b[j]) NR[i][j]=NR[i-1][j-1];
            else {
                     if(L[i][j]==L[i-1][j]) NR[i][j] += NR[i-1][j];
                     if(L[i][j]==L[i][j-1]) NR[i][j] += NR[i][j-1];
                     if(L[i][j]==L[i-1][j-1]) NR[i][j]=NR[i][j]+mod, NR[i][j]-=NR[i-1][j-1];
                 }
            NR[i][j]%=mod;
        }

    g<<NR[la][lb]<<"\n";

    return 0;
}
