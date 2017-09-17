# include <fstream>
# include <algorithm>
# include <bitset>
# include <cstring>
# define NR 4100
using namespace std;
ifstream f("conserve.in");
ofstream g("conserve.out");
bitset <NR> ap[NR];
int i,j,n,m,x,y,nou,act,R,X,VV,P;
int rest[3*NR], sol[NR], a[NR], v[3][NR];
void procesare () {
    for (int i=0; i<=2*NR; ++i)
        rest[i]=i%P;
}
int main ()
{
    f>>P>>n; procesare ();

    act=0; v[0][0]=1;
    for (i=1; i<=n; ++i) {
        f>>a[i]; R=a[i]%P;

        nou=1-act; for (j=0; j<P; ++j) v[nou][j]=v[act][j];
        for (j=0; j<P; ++j) {
            if (v[act][j] && v[act][j] + a[i] > v[act][rest[j+R]]) {
                v[nou][rest[j+R]]=v[act][j] + a[i];
                ap[i][rest[j+R]]=1;
            }

        }
        act=nou;
    }
    g<<v[act][0]-1<<"\n";
    X=0;
    for (i=n; i>=1; --i) {
        if (ap[i][X]) {
            sol[++VV]=i;
            X=(P + X - a[i]%P)%P;
        }
    }
    g<<VV<<"\n";
    for (i=VV; i>=1; --i)
        g<<sol[i]<<" ";
    g<<"\n";


    return 0;
}
