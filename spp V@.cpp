# include <fstream>
# include <algorithm>
//# include <iostream>
# include <cstring>
# define NR 20
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int i,j,p,K,X,Y,T;
int a[NR][NR], F[NR][NR], b[NR], c[NR];
long long C[NR][NR], n,m;
void init ()
{
    for (int i=1; i<=K+1; ++i)
        memset (a[i], 0, sizeof(a[i]));

    for (int i=1; i<=K+1; ++i) {
            if (i==1) a[1][1]=1, a[1][2]=1;
            else if (i==K+1) for (int j=1; j<=K; ++j) a[i][j+1]=c[K-j+1];
            else a[i][i+1]=1;
        }
    F[1][1]=0;
    for (int i=1; i<=K; ++i)
        F[i+1][1]=b[i];
}
void inmultire (int a[][NR], int b[][NR], int la, int ca, int lb, int cb)
{
    int lc=ca, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            C[i][j]=0;
            for (int k=1; k<=ca; ++k) {
                C[i][j]+=1LL*a[i][k]*b[k][j];
                if (C[i][j]>=p) C[i][j]%=p;
            }
        }
     for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            b[i][j]=C[i][j];
}
int putere (long long N)
{
    init ();
    /*for (int i=1; i<=K+1; ++i) {
        for (int j=1; j<=K+1; ++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }*/
    while (N)
    {
        if (N%2==1) {
            inmultire (a, F, K+1, K+1, K+1, 1);
            --N;
        }
        else {
                 inmultire (a, a, K+1, K+1, K+1, K+1);
                 N=N/2;
             }
    }
    return F[1][1];
}
int main ()
{
    cin>>T;
    for (int t=1; t<=T; ++t) {
        cin>>K;
        for (int i=1; i<=K; ++i) cin>>b[i];
        for (int i=1; i<=K; ++i) cin>>c[i];

        cin>>n>>m>>p;
        //S[i]= sumele partiale;
        //S[i]=S[i-1] + a[i];

        X=putere (m);
        Y=putere (n-1);
        cout<<(X-Y+p)%p<<"\n";
    }

    return 0;
}
