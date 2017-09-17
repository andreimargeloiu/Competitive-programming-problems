# include <fstream>
using namespace std;
ifstream f("poly.in");
ofstream g("poly.out");
int prim[]={2, 3, 7, 11, 19, 23, 37};
int i,j,n,m,x,y,X,maxx;
int a[1005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x; X=0;
        for (j=0; j<7; ++j)
            if (x%prim[j]==0) X+=(1<<j);
        for (j=0; j<=(1<<7)-1; ++j)
            if ((X & j)==0) a[X]=max(a[X], a[j]+1);
    }
    for (i=0; i<(1<<7); ++i)
        maxx=max(maxx, a[i]);
    g<<maxx<<"\n";


    return 0;
}
