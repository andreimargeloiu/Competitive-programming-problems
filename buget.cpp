# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("buget.in");
ofstream g("buget.out");
int i,j,n,m,P[NR],ci,cs,mij,maxx;
long long B,suma,sol;
long long verifica (int H)
{
    long long S=0;
    for (int i=1; i<=n; ++i)
        S=S+min(H, P[i]);
    return S;
}
int main ()
{
    f>>n>>B;
    for (i=1; i<=n; ++i) {
        f>>P[i];
        maxx=max(maxx, P[i]);
    }
    ci=1; cs=maxx;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        suma=verifica(mij);
        if (suma<=B) ci=mij+1, sol=mij;
                else cs=mij-1;
    }
    g<<sol<<"\n";

    return 0;
}
