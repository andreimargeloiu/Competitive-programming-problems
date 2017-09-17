# include <cstdio>
# include <algorithm>
# define NR 50005
using namespace std;
int i,j,n,VM,VE,ME;
int v_m[NR], v_e[NR], m_e[NR], ce[NR], cv[NR], cm[NR], v[NR], m[NR], e[NR];
int minim (int a, int b, int c)
{
    return min(a, min(b, c));
}
int main ()
{
    freopen ("fluviu.in", "r", stdin);
    freopen ("fluviu.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i) scanf ("%d", &v_m[i]);
    for (i=1; i<=n; ++i) scanf ("%d", &v_e[i]);
    for (i=1; i<=n; ++i) scanf ("%d", &m_e[i]);

    for (i=1; i<=n; ++i)
    {
        VM=v_m[i];
        VE=v_e[i];
        ME=m_e[i];

        v_m[i]=min(VM, VE+ME);
        v_e[i]=min(VE, VM+ME);
        m_e[i]=min(ME, VM+VE);
    }

    for (i=2; i<=n; ++i) scanf ("%d", &v[i]);
    for (i=2; i<=n; ++i) scanf ("%d", &m[i]);
    for (i=2; i<=n; ++i) scanf ("%d", &e[i]);

    cv[1]=0; cm[1]=v_m[1]; ce[1]=v_e[1];

    for (i=2; i<=n; ++i)
    {
        ce[i]=e[i] + minim(ce[i-1], cv[i-1]+v_e[i-1], cm[i-1]+m_e[i-1]);
        cv[i]=v[i] + minim(cv[i-1], ce[i-1]+v_e[i-1], cm[i-1]+v_m[i-1]);
        cm[i]=m[i] + minim(cm[i-1], cv[i-1]+v_m[i-1], ce[i-1]+m_e[i-1]);
    }

    printf ("%d\n", min(ce[n], min(cm[n], cv[n])));

    return 0;
}
