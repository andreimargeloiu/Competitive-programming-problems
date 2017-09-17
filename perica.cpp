# include <fstream>
# include <iostream>
# include <algorithm>
# define MOD 1000000007
using namespace std;
//ifstream f("perica.in");
//ofstream g("perica.out");
int i,j,n,m,K,x,x2,y;
long long S, var, var2, F[100005], a[100005];
void euclid (int a, int b, int &x, int &y) {
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
void factorial () {
    F[0]=1; F[1]=1;
    for (int i=2; i<=n; ++i)
        F[i]=1LL*F[i-1]*i%MOD;
}
int main ()
{
    cin>>n>>K;
    factorial ();

    for (i=1; i<=n; ++i) cin>>a[i];
    sort (a+1, a+n+1);

    for (i=K; i<=n; ++i) {
        if (K==1) S=(S + a[i])%MOD;
        else {
             euclid (F[K-1], MOD, x, y);
             if (x<0) x=MOD+x%MOD;

             euclid (F[i-K], MOD, x2, y);
             if (x2<0) x2=MOD+x2%MOD;

             S=S + 1LL*a[i]*(1LL*F[i-1]*x%MOD*x2%MOD)%MOD;
             S%=MOD;
        }
    }
    cout<<S<<"\n";

    return 0;
}
