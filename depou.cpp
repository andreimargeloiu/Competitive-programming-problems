# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100
using namespace std;
ifstream f("depou.in");
ofstream g("depou.out");
int i,j,n,m,x,y;
int a[NR], C[155][NR];
void produs (int x, int y)
{
    memset (a, 0, sizeof(a));
    int i,j,t=0;
    a[0]=C[x][0]+C[y][0]-1;
    for (i=1; i<=C[x][0]; ++i)
        for (j=1; j<=C[y][0]; ++j)
            a[i+j-1]+=(C[x][i]*C[y][j]);

    //etalonam
    for (i=1; i<=a[0]; ++i) {
        t=t + a[i];
        a[i]=t%10;
        t=t/10;
    }
    while (t) a[++a[0]]+=t%10, t=t/10;
}
void aduna (int k)
{
    int i, t=0;
    C[k][0]=max(C[k][0], a[0]);
    for (i=1; i<=C[k][0]; ++i) {
        t=t + C[k][i] + a[i];
        C[k][i]=t%10;
        t=t/10;
    }
    while (t) C[k][++C[k][0]]=t%10, t=t/10;
}
int main ()
{
    f>>n;

    //facem Catalan (n)

    C[0][0]=1; C[0][1]=1;
    for (i=1; i<=n; ++i) {
        // C[i]= suma C[k]*C[i-k-1]
        for (j=0; j<=i-1; ++j) {
            produs (j, i-j-1);
            aduna (i);
        }
    }

    for (i=C[n][0]; i>=1; --i)
        g<<C[n][i];
    g<<"\n";


    return 0;
}
