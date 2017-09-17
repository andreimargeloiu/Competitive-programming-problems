# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 50
using namespace std;
int i,j,n,m,x,y,VV,ord,T;
int a[NR], var[NR];
void dinamica ()
{
    int S=0;
    // a[i] - numarul de moduri de a face submultimi care incep cu cifra i
    for (i=n; i>=1; --i){
        S+=a[i+2];
        a[i]=1 + S;
    }
}
int main ()
{
    freopen ("subm.in", "r", stdin);
    freopen ("subm.out", "w", stdout);

    scanf ("%d", &n); dinamica ();
    scanf ("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf ("%d", &ord);
        if (ord==1) {printf ("1\n"); continue;}

        memset(var, 0, sizeof(var));
        VV=0; var[0]=-1;

        while (ord) {
            for (i=var[VV]+2; i<=n; ++i) {
                if (ord > a[i]) ord-=a[i];
                else {
                         var[++VV]=i; --ord;
                         break;
                     }
            }
        }
        for (i=1; i<=VV; ++i)
            printf ("%d ", var[i]);
        printf ("\n");
    }


    return 0;
}
