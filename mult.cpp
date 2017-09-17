#include<bits/stdc++.h>
using namespace std;

ifstream fin("mult.in");
ofstream fout("mult.out");

const int base=100000000;
const int NMAX=2505;
const int LIMIT=1005;

int n,k,a[NMAX],mod[10005];
int dp[2][LIMIT][LIMIT];

inline void Aduna(int *A,int *B)
{
    int i,t=0;
    A[0]=max(A[0],B[0]);
    for (i=1;i<=A[0];i++)
        {
            A[i]+=B[i]+t;
            t=0;
            if (A[i]>=base) {A[i]-=base;t=1;}
        }
    if (t) A[++A[0]]=t;
}

inline int Cif(int x)
{
    if (x==0) return 0;
    else return 1+Cif(x/10);
}

int main()
{
    int i,j,l,nr;
    fin>>n>>k;
    for (i=1;i<=n;i++) fin>>a[i];
    for (i=1;i<10005;i++) mod[i]=i%k;
    dp[0][a[1]%k][0]=dp[0][a[1]%k][1]=1;
    dp[1][501][0]=dp[1][501][1]=1;
    for (i=2;i<=n;i++)
        {
            for (j=0;j<k;j++)
                {
                    for (l=1;l<=dp[1][j][0];l++) dp[1][j][l]=0;
                    dp[1][j][0]=0;
                }
            for (j=0;j<k;j++) Aduna(dp[1][mod[j*10+a[i]]],dp[0][j]);
            Aduna(dp[0][mod[a[i]]],dp[1][501]);
            for (j=0;j<k;j++) Aduna(dp[0][j],dp[1][j]);
        }
    fout<<dp[0][0][dp[0][0][0]];
    for (i=dp[0][0][0]-1;i>=1;i--)
        {
            nr=Cif(dp[0][0][i]);
            while (nr<8) {nr++;fout<<"0";}
            if (dp[0][0][i]>0) fout<<dp[0][0][i];
        }
    fout<<"\n";
    return 0;
}
