# include <fstream>
# include <algorithm>
# define NR 200005
using namespace std;
ifstream f("tarabe.in");
ofstream g("tarabe.out");
int i,j,n,caut_suma;
int a[NR], b[NR];
long long ci,cs,cost,sol,suma,adunate,K;
long long verif (long long H)
{
    long long maxx=0, S=0;
    for (int i=1; i<=n; ++i)
    {
        if (H>=a[i])
        {
            maxx=(H - a[i]) / b[i] + 1;
            if (maxx)
            {
                S=S + maxx;
                if (caut_suma)  suma+=maxx*a[i] + (maxx*(maxx-1)/2)*b[i];
            }
        }
    }
    return S;
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i)
        f>>b[i]>>a[i];

    ci=1; cs=a[1] + 1LL*K*b[1];

    while (ci<=cs)
    {
        //calculam ce suma dorim sa dedicam fiecarul layer
        cost=(ci+cs)/2;

        adunate=verif (cost);

        if (adunate>=K) cs=cost-1, sol=cost;
                   else ci=cost+1;
    }

    caut_suma=1;
    adunate=verif (sol);

    suma -= 1LL*sol * (adunate - K);

    g<<suma<<"\n";

    return 0;
}
