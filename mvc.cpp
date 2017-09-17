# include <fstream>
# include <algorithm>
# include <vector>
# define NR 400
# define INF 999999999
using namespace std;
ifstream f("rmvc.in");
ofstream g("rmvc.out");
struct elem {
    int ci, cs;
}a[NR];
int i,j,n,m,x,y,maxx,minn;
int st[NR], ap[NR], sol[NR];
void back (int k, int muchie) {
    if (k-1>=minn) return;

    int ok=1;
    for (int i=muchie; i<=m && ok; ++i)
        if (! ap[a[i].ci] && ! ap[a[i].cs]) ok=0;

    if (ok) {
        minn=k-1;
        for (int i=1; i<=k-1; ++i)
            sol[i]=st[i];

        return;
    }

    for (int i=muchie; i<=m; ++i) {
        if (! ap[a[i].ci] && ! ap[a[i].cs]) {
            //stanga
            st[k]=a[i].ci; ap[a[i].ci]=1;
            back(k+1, i+1);
            st[k]=0; ap[a[i].ci]=0;

            //dreapta
            st[k]=a[i].cs; ap[a[i].cs]=1;
            back(k+1, i+1);
            st[k]=0; ap[a[i].cs]=0;

            break;
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
        f>>a[i].ci>>a[i].cs;
    random_shuffle(a+1, a+m+1);

    minn=20;
    back (1, 1);

    g<<minn<<"\n";
    for (int i=1; i<=minn; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
