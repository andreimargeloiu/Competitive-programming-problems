# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 30005
using namespace std;
int i,j,n,m,top,VV,maxx, D,sol;
int a[NR], copie[NR], st[NR];
short ARB[4*NR], DP[NR], maxim;
void normalizare ()
{
    sort (copie+1, copie+n+1);
    for (int i=1; i<=n; ++i)
        if (copie[i]!=copie[i-1]) copie[++VV]=copie[i];

    for (int i=1; i<=n; ++i)
        a[i]=lower_bound (copie+1, copie+VV+1, a[i]) - copie;
}
int cmlsc ()
{
    int top=0,ci,cs,mij,sol;
    for (int i=1; i<=n; ++i)
        if (a[i]>=st[top]) st[++top]=a[i];
        else {
                 ci=1; cs=top;
                 while (ci<=cs) {
                     mij=(ci + cs)/2;
                     if (st[mij]<=a[i]) ci=mij+1;
                                   else cs=mij-1, sol=mij;
                 }
                 st[sol]=a[i];
             }
    return top;
}
void cauta (int nod, int ci, int cs, int CI, int CS)
{
    if (CI<=ci && cs<=CS)
    {
        maxim=max(maxim, ARB[nod]);
    }
    else {
             int mij=(ci + cs)/2;
             if (CI<=mij) cauta (2*nod, ci, mij, CI, CS);
             if (mij<CS) cauta (2*nod+1, mij+1, cs, CI, CS);
         }
}
void update (int nod, int ci, int cs, int NOD, short NOU)
{
    if (ci==NOD && cs==NOD) ARB[nod]=max(ARB[nod], NOU);
    else {
             int mij=(ci + cs)/2;
             if (NOD<=mij) update (2*nod, ci, mij, NOD, NOU);
                      else update (2*nod+1, mij+1, cs, NOD, NOU);
             ARB[nod]=max (ARB[2*nod], ARB[2*nod+1]);
         }
}
bool verifica (int DIF)
{
    memset (ARB, 0, sizeof(ARB));
    memset (DP, 0, sizeof(DP));
    //DP[i] - cmlsc care se termina pe pozitia i
    int ci, cs;
    for (int i=1; i<=n; ++i) {
        ci=lower_bound (copie+1, copie+VV+1, copie[a[i]]-DIF) - copie; ci=max(ci, 1);
        cs=a[i];

        maxim=0;
        cauta (1, 1, VV, ci, cs);
        DP[i]=maxim+1;

        if (DP[i]==maxx)
        {
            return 1;
        }
        update (1, 1, VV, a[i], DP[i]);
    }
    return 0;
}
int main ()
{
    freopen ("subs.in", "r", stdin);
    freopen ("subs.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {scanf ("%d", &a[i]); copie[i]=a[i];}

    normalizare ();
    maxx=cmlsc ();

    // incepem dinamica

    int ci=0, cs=copie[VV], mij;

    while (ci<=cs) {
        mij=(ci + cs)/2;

        if (verifica(mij)) cs=mij-1, sol=mij;
                      else ci=mij+1;
    }

    printf ("%d %d\n", maxx, sol);

    return 0;
}
