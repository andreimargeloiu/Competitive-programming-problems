# include <cstdio>
# include <algorithm>
# define NR 500
using namespace std;
int i,j,n,m,x,y,a[NR], b[NR],t;
long long nr, nr2;
void inmultire (int a[], int K) {
    int t=0;
    for (int i=1; i<=a[0]; ++i) {
        t=t + a[i]*K;
        a[i]=t%10;
        t=t/10;
    }
    while (t) a[++a[0]]=t%10, t=t/10;
}
int main ()
{
    freopen ("nrcuv1.in", "r", stdin);
    freopen ("nrcuv1.out", "w", stdout);
    scanf ("%d", &n);

    a[0]=a[1]=1;
    b[0]=b[1]=1;

    for (i=1; i<=n; ++i) {
        inmultire (a, n);
        inmultire (b, i);
    }

    //le scadem
    t=0;
    for (i=1; i<=a[0]; ++i) {
        a[i]=a[i]-b[i]+t;
        if (a[i]<0) a[i]+=10, t=-1;
               else t=0;
    }
    while (a[a[0]]==0) --a[0];

    for (i=a[0]; i>=1; --i)
        printf ("%d", a[i]);
    printf ("\n");


    return 0;
}
