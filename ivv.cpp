# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 10005
using namespace std;
int i,j,n,m,x,y;
int a[NR], A[3][NR], l[3][NR], ok[NR], OK[NR];
void adunare (int a[], int b[], int val) {
    a[0]=max(a[0], b[0]);

    int t=val;
    for (int i=1; i<=a[0]; ++i) {
        t=t + a[i] + b[i];
        a[i]=t%10;
        t=t/10;
    }
    while (t) a[++a[0]]=t%10, t=t/10;
}
void afisare (int k) {
    for (int i=l[k][0]; i>=1; --i)
        printf ("%d", l[k][i]);
}
int main ()
{
    freopen ("ivv.in", "r", stdin);
    freopen ("ivv.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    // preprocesam aparitiile
    for (i=1; i<=n; ++i) {
        OK[i]=ok[a[i]];

        ok[a[i]]=1;
    }


    l[0][0]=l[0][1]=1;
    l[1][0]=l[1][1]=1;
    for (i=n-1; i>=1; --i) {
        adunare (A[0], l[0], 0);
        adunare (A[1], l[1], 0);
        if (a[i]!=a[i+1]) {
            memset (l[a[i]], 0, sizeof(l[a[i]]));
            adunare (l[a[i]], A[1-a[i]], 1);


            adunare (l[1-a[i]], A[a[i]], 0);
        }
        else {

            if (OK[i]) adunare (l[a[i]], l[1-a[i]], 0);

            memset (l[1-a[i]], 0, sizeof(l[1-a[i]]));
            adunare (l[1-a[i]], A[a[i]], 1);


        }
        printf ("%d  :  ", i);
        afisare (a[i]);
        printf ("\n");
    }

    afisare (a[1]);

    return 0;
}
