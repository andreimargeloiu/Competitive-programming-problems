# include <fstream>
# include <algorithm>
# define MOD 578537
using namespace std;
ifstream f("sumk.in");
ofstream g("sumk.out");
int i,j,n,x,x2,y,y2,V1,V2,V3,k;
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
int factorial (int K) {
    int nrsol=1;
    for (int i=2; i<=K; ++i)
        nrsol=1LL*nrsol*i%MOD;

    return nrsol;
}
int main ()
{
    f>>n>>k;

    V1=factorial (n*k+n-1);

    V2=factorial (n-1);
    euclid (V2, MOD, x, y);
    if (x<0) x=MOD + x%MOD;


    V3=factorial (n*k);
    euclid (V3, MOD, x2, y2);
    if (x2<0) x2=MOD + x2%MOD;

    g<<1LL*V1*x*x2%MOD<<"\n";


    return 0;
}
