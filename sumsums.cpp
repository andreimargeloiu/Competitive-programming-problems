# include <fstream>
//# include <iostream>
# include <algorithm>
# define MOD 98765431
# define C 5
# define NR 50005
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int i,j,T,X;
int M[C][C], F[C][C], a[NR];
long long c[C][C], S, n;
void inmultire (int a[][C], int b[][C], int la, int ca, int lb, int cb)
{
    int lc=lb, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            c[i][j]=0;
            for (int k=1; k<=ca; ++k)
                c[i][j]=c[i][j] + (1LL*a[i][k]*b[k][j])%MOD;

                if (c[i][j]>=MOD) c[i][j]%=MOD;
        }
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            b[i][j]=c[i][j];
}
int putere (int N)
{
    while (N>0) {
        if (N%2==1) {
            inmultire (M, F, 2, 2, 2, 1);
            --N;
        }
        else {
            inmultire (M, M, 2, 2, 2, 2);
            N=N/2;
        }
    }
    return F[1][1];
}
int main ()
{
    cin>>n>>T;
    for (i=1; i<=n; ++i) {
        cin>>a[i];
        S+=a[i];
        if (S>=MOD) S-=MOD;
    }

    M[1][1]=1; M[1][2]=n-2;
    M[2][2]=1LL*(n-1)*(n-1)%MOD;

    if (T%2==1) {
        F[1][1]=S;
        F[2][1]=1LL*S*(n-1)%MOD;

        X=putere ((T-1)/2);
        for (i=1; i<=n; ++i)
            cout<<(X-a[i]+MOD)%MOD<<"\n";
    }
    else {
       F[1][1]=1LL*(n-2)*S%MOD;
       F[2][1]=1LL*((n-1)*(n-1))%MOD*S%MOD;

       X=putere ((T-1)/2);
       if (T==0) X=0;
       for (i=1; i<=n; ++i)
          cout<<(X+a[i]+MOD)%MOD<<"\n";
    }

    return 0;
}
