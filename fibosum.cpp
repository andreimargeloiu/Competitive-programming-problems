# include <fstream>
# include <algorithm>
//# include <iostream>
# include <cstring>
# define NR 5
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int i,j,p,K,X,Y,T;
int a[NR][NR], F[NR][NR], b[NR], c[NR];
long long C[NR][NR], n,m;
void init ()
{
    for (int i=1; i<=3; ++i)
        memset (a[i], 0, sizeof(a[i]));

    a[1][1]=a[1][2]=1;
    a[2][3]=1;
    a[3][2]=a[3][3]=1;
    F[1][1]=0;
    F[2][1]=1;
    F[3][1]=1;
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
    while (N)
    {
        if (N%2==1) {
            inmultire (a, F, 3, 3, 3, 1);
            --N;
        }
        else {
                 inmultire (a, a, 3, 3, 3, 3);
                 N=N/2;
             }
    }
    return F[1][1];
}
int main ()
{
    cin>>T;
    for (int t=1; t<=T; ++t) {
        cin>>n>>m; p=1000000007;
        //S[i]= sumele partiale;
        //S[i]=S[i-1] + a[i];

        X=putere (m);
        Y=putere (n-1);
        cout<<(X-Y+p)%p<<"\n";
    }

    return 0;
}
