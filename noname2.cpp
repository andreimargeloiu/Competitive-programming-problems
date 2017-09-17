# include <fstream>
# include <algorithm>
# include <cstring>
# include <cmath>
# define inf 999999999
# define NR 100005
using namespace std;
ifstream f("noname2.in");
ofstream g("noname2.out");
int i,j,n,m,x,y,ci,cs,mij,sol;
long long K, cost, a[NR];

bool verifica (int H) {
    //initial
    int i,ci,cs,M,jos,sus;
    long long minn,cost=0;
    M=((H+1)/2);
    ci=1; cs=H;
    jos=M-1; sus=H-M;

    for (i=1; i<=H; ++i)
        cost=cost + abs(a[M]-a[i]);
    minn=cost;

    for (i=H+1; i<=n; ++i) {
        // il scot pe cel de jos
        cost=cost - abs(a[M] - a[ci]);
        ++ci; --jos;

        // il adaug pe cel de sus
        ++cs; ++sus;
        cost=cost + abs(a[M] - a[cs]);

        // mut mijlocul
        cost=cost + (jos+1-sus)*(a[M+1] - a[M]);
        ++M; ++jos; --sus;

        minn=min(minn, cost);
    }

    if (minn<=K) return 1;
            else return 0;
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i)
        f>>a[i];

    sort (a+1, a+n+1);

    ci=1; cs=n;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (verifica (mij)) ci=mij+1, sol=mij;
                       else cs=mij-1;
    }
    g<<sol<<"\n";

    return 0;
}
