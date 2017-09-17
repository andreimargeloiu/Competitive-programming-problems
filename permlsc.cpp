# include <algorithm>
# include <fstream>
# define NR 1005
using namespace std;
ifstream f("permlcs.in");
ofstream g("permlcs.out");
int i,j,n,m,x,maxx,o,ok;
int nr[NR], a[15][NR], sol[NR], ap[15][NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        for (j=1; j<=n; ++j) {
            f>>x;
            if (i==1) nr[x]=j;

            a[i][j]=nr[x];
            ap[i][nr[x]]=j;

            //g<<a[i][j]<<" ";
        }
        //g<<"\n";
    }

    /*for (i=1; i<=m; ++i) {
        for (j=1; j<=n; ++j) {
            g<<ap[i][j]<<" ";
        }
        g<<"\n";
    }*/


    for (i=1; i<=n; ++i) { //fiecare numar
        sol[i]=1;
        for (j=1; j<i; ++j) { //fiecare numar mai mic
            ok=1;
            for (o=1; o<=m && ok; ++o)
                if (ap[o][j] > ap[o][i]) ok=0;

            if (ok) sol[i]=max(sol[i], 1+sol[j]);
        }
        maxx=max(maxx, sol[i]);
    }
    g<<maxx<<"\n";



    return 0;
}
