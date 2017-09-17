# include <cstdio>
# include <algorithm>
# include <vector>
# define MOD 666013
# define NR 100005
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,p,VV;
int a[NR], desc[NR], fact[MOD+5];
void preprocesare ()
{
    fact[0]=1; fact[1]=1;
    for (i=2; i<=MOD; ++i)
        fact[i]=1LL*fact[i-1]*i%MOD;
}
void invers_modular (int a, int b, int &x, int &y) {
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    invers_modular (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
int Comb (int n, int k)
{
    int x1, y1, x2, y2;
    invers_modular (fact[k], MOD, x1, y1);
    if (x1<0) x1=MOD + x1%MOD;

    invers_modular (fact[n-k], MOD, x2, y2);
    if (x2<0) x2=MOD + x2%MOD;

    int sol=(1LL*fact[n]*x1%MOD*x2)%MOD;
    return sol;
}
void DFS (int k, int tata)
{
    desc[k]=1;

    for (int i=0; i<v[k].size(); ++i) {
        if (v[k][i]!=tata) {
            DFS (v[k][i], k);
            desc[k]+=desc[v[k][i]];
        }
    }

    //incepem dinamica
    int S=1; a[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        int urm=v[k][i];
        if (urm!=tata) {
            int C=Comb (desc[k]-S, desc[urm]);
            a[k]=(1LL * a[k] * a[urm]%MOD * C)%MOD;

            S+=desc[urm];
        }
    }
}
int main ()
{
    freopen ("bonuri.in", "r", stdin);
    freopen ("bonuri.out", "w", stdout);
    scanf ("%d%d", &n, &p);
    VV=1;
    for (i=1; i<=n; ++i) {
        if (VV==n) break;
        for (j=1; j<=p && VV<n; ++j) {
            ++VV;
            v[i].push_back(VV);
        }
    }

    preprocesare ();
    DFS (1, 0);

    printf ("%d\n", a[1]);


    return 0;
}
