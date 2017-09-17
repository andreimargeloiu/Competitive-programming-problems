# include <fstream>
# include <algorithm>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 20
using namespace std;
ifstream f("permutari3.in");
ofstream g("permutari3.out");
int i,j,n,m,Q,t;
long long F[NR], D, X;
int p[NR], ap[NR], a[NR], sol[NR];
void factoriale (int n) {
    F[0]=1; F[1]=1;
    for (int i=2; i<=n; ++i)
        F[i]=F[i-1] * i;
}
long long determinare () {
    long long nrsol=0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<a[i]; ++j)
            if (ap[j]==0) nrsol+=F[n-i];

        ap[a[i]]=1;
    }
    return nrsol+1;
}
void procesare (long long X) {
    memset (sol, 0, sizeof(sol));
    memset (ap, 0, sizeof(sol));
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (ap[j]==0) {
                if (X > F[n-i]) X-=F[n-i];
                else {sol[i]=j; ap[j]=1; break;}
            }
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) f>>a[i];

    factoriale (n);
    D=determinare (); //g<<D<<"\n";

    f>>Q;
    for (t=1; t<=Q; ++t) {
        f>>X;
        procesare (D+X);
        for (i=1; i<=n; ++i)
            g<<sol[i]<<" ";
        g<<"\n";
    }



    return 0;
}
