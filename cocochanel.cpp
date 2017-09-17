# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("cocochanel.in");
ofstream g("cocochanel.out");
int i,j,n,m,ci,VV,var,ant,Q;
int put[50], C[100005], G[100005];
void puteri ()
{
    int i;
    put[0]=1;
    for (i=1; i<=30; ++i)
        put[i]=put[i-1]<<1;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>C[i];
    for (i=1; i<=m; ++i)
        f>>G[i];
    sort (G+1, G+m+1);
    puteri ();
    for (i=1; i<=n; ++i)
    {
        ci=1; VV=0; ant=0;
        for (j=0; j<=30; ++j)
        {
            Q=C[i]*put[j];
            if (Q>G[m] || ci>m) break;
            var=lower_bound (G+ci, G+m+1, Q)-G;
            ++VV;
            ci=var+1;
        }
        g<<VV<<"\n";
    }
    return 0;
}
