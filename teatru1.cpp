# include <fstream>
# include <algorithm>
# define NR 105
using namespace std;
ifstream f("teatru1.in");
ofstream g("teatru1.out");
int i,j,n,m,nou,act;
int a[3][NR][NR];
void aduna (int a[], int b[], int c[]) {
    c[0]=max(a[0], b[0]);
    int t=0;
    for (int i=1; i<=c[0]; ++i) {
        t=t+a[i] + b[i];
        c[i]=t%10;
        t=t/10;
    }
    while (t) c[++c[0]]=t%10, t=t/10;
}
void inmultire (int a[], int X) {
    for (int i=2; i<=X; ++i) {
        int t=0;
        for (j=1; j<=a[0]; ++j) {
            t=t + a[j]*i;
            a[j]=t%10;
            t=t/10;
        }
        while (t) a[++a[0]]=t%10, t=t/10;
    }
}
int main ()
{
    // tin minte doar ultimele 2 randuri
    a[1][0][0]=a[1][0][1]=1;
    f>>n>>m;
    act=1; nou=2;
    for (i=1; i<=n; ++i) {
        a[nou][0][0]=a[nou][0][1]=1;
        for (j=1; j<=i; ++j)
            aduna (a[nou][j-1], a[act][j], a[nou][j]);
        swap(act, nou);
    }
    inmultire (a[act][m], n);
    inmultire (a[act][m], m);

    for (i=a[act][m][0]; i>=1; --i)
        g<<a[act][m][i];
    g<<"\n";

    return 0;
}
