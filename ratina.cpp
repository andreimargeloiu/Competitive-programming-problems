# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 2005
# define inf 999999999
# define N 10005
using namespace std;
int i,j,n,m,minn,maxx,MAXX,Q,x;
int ARB[4*N], identic[N], poz[N], nr[N];
char a[N][NR];
bool cmp (int x, int y) {
    if (strcmp(a[x], a[y])>0) return 0;
                         else return 1;
}
void procesare () {
    for (int i=2; i<=n; ++i) {
        int maxx=0; int l=min(strlen(a[nr[i-1]]), strlen(a[nr[i]]));
        if (i==112) {
            //adasd
            i+=0;
        }
        for (j=0; j<l; ++j) {
            if (a[nr[i-1]][j] != a[nr[i]][j]) break;
            ++maxx;
        }

        identic[i]=maxx;
    }
}
void make (int nod, int ci, int cs) {
    if (ci==cs) ARB[nod]=identic[ci];
    else {
        int mij=(ci+cs)/2;
        if (ci<=mij) make(2*nod, ci, mij);
        if (mij<cs) make(2*nod+1, mij+1, cs);

        ARB[nod]=min(ARB[2*nod], ARB[2*nod+1]);
    }
}
void maxim (int nod, int ci, int cs, int CI, int CS) {
    if (CI<=ci && cs<=CS) MAXX=min(MAXX, ARB[nod]);
    else {
        int mij=(ci+cs)/2;
        if (CI<=mij) maxim (2*nod, ci, mij, CI, CS);
        if (mij<CS) maxim(2*nod+1, mij+1, cs, CI, CS);
    }
}
int main ()
{
    freopen ("ratina.in", "r", stdin);
    freopen ("ratina.out", "w", stdout);

    scanf ("%d %d\n", &n, &m);
    for (i=1; i<=n; ++i) {
        scanf ("%s\n", &a[i]);
        nr[i]=i;
    }

    sort (nr+1, nr+n+1, cmp);
    procesare ();
    make (1, 1, n);

    for (i=1; i<=n; ++i) poz[nr[i]]=i; //pozitia din sortare a cuvantului

    for (j=1; j<=m; ++j) {
        scanf ("%d", &Q); minn=inf; maxx=0;
        for (i=1; i<=Q; ++i) {
            scanf ("%d", &x);
            minn=min(minn, poz[x]);
            maxx=max(maxx, poz[x]);
        }
        MAXX=inf;
        if (minn==maxx) MAXX=strlen(a[x]);
        else maxim(1, 1, n, minn+1, maxx);

        printf ("%d\n", MAXX);
    }


    return 0;
}
