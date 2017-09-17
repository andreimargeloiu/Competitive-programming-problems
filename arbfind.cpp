# include <bits/stdc++.h>
# define NR 80000
# define N 20
using namespace std;
vector <int> v1[NR], v2[NR];
struct elem {
    int nr1, nr2, i;
}var[4*NR];
int i,j,n,m,VV,x,l,IND,L,AUX;
int start[4*NR], lg[4*NR], suma[4*NR], ap[NR], Z[4*NR];
int P[4*NR];
int mask=(1<<8)-1;

void citire () {
    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &l);
        for (j=1; j<=l; ++j) {
            scanf ("%d", &x);
            v1[i].push_back(x);
        }
    }

    scanf ("%d", &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d", &l);
        for (j=1; j<=l; ++j) {
            scanf ("%d", &x);
            v2[i].push_back(x);
        }
    }
}
void make_euler1 (int k, int tata) {
    P[++VV]=1;
    for (auto &x: v1[k])
        if (x!=tata) {
            P[++VV]=2;
            make_euler1 (x, k);
            P[++VV]=3;
        }
}
void make_euler2 (int k, int tata) {
    P[++VV]=1; start[k]=VV;
    for (auto &x: v2[k])
        if (x!=tata) {
            P[++VV]=2;
            make_euler2 (x, k);
            P[++VV]=3;
        }
}
void Z_algorithm() {
    int L=0, R=0;
    for (int i=2; i<=VV; ++i) {
        if (R<i) { //un Z-Box nou
            L=R=i;
            while (R<=VV && P[R-i+1]==P[R])
                ++R;

            --R; Z[i]=R-i+1;
        } else { //este intr-un Z-Box
            int k=i - L + 1;
            if (i + Z[k] - 1 < R) Z[i]=Z[k];
            else {
                 L=i; ++R;
                 while (R<=VV && P[R-i+1]==P[R])
                    ++R;

                --R; Z[i]=R-i+1;
            }
        }
    }
}
int main ()
{
    freopen ("arbfind.in", "r", stdin);
    freopen ("arbfind.out", "w", stdout);

    citire ();
    make_euler1 (1, 0); //arborele 1
    P[++VV]='$';
    make_euler2 (1, 0); //arborele 2

    Z_algorithm ();

    /*for (i=1; i<=VV; ++i)
        printf ("%d ", P[i]);
    printf ("\n");
    for (i=1; i<=VV; ++i)
        printf ("%d ", Z[i]);
    printf ("\n");*/

    //fac sumele partiale
    for (i=1; i<=VV; ++i) {
        suma[i]=suma[i-1];
        if (P[i]==1) ++suma[i];
    }

    for (i=1; i<=m; ++i)
        printf ("%d\n", suma[start[i] + Z[start[i]] - 1] - suma[start[i]-1]);

    return 0;
}
