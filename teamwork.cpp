# include <fstream>
# include <algorithm>
# define NR 500000
using namespace std;
ifstream f("teamwork.in");
ofstream g("teamwork.out");
int i,j,n,m,x,y,stop;
int maxx[NR], bit[NR], a[20][20];
void biti () {
    for (i=1; i<=stop; ++i){
        int VV=i;
        while (VV) {
            bit[i]+=VV%2;
            VV/=2;
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            f>>a[i][j];

    // maxx[i] - maximul pe care il pot obtine folosind
    //           elevii bitii lui i, in biti[i] zile

    stop=(1<<n)-1; biti ();
    for (i=0; i<=stop; ++i) {
        for (j=0; j<n; ++j)
            if (! (i & (1<<j))){
                maxx[i + (1<<j)]=max(maxx[i + (1<<j)], maxx[i] + a[j+1][bit[i]+1]);
            }
    }
    g<<maxx[stop]<<"\n";


    return 0;
}
