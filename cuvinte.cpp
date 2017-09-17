# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 205
using namespace std;
ifstream f("cuvinte.in");
ofstream g("cuvinte.out");
int i,j,n,m,K,maxx,ant,k;
int D[NR][NR], a[NR];
int main ()
{
    //D[i][j] - numarul de moduri de a incepe siruri crescatoare
    //          de lungime j de pe pozitia i

    f>>n>>K;
    for (i=1; i<=n; ++i)
        f>>a[i];

    maxx=1;
    for (i=n; i>=1; --i) {
        D[i][1]=1;
        for (j=2; j<=n; ++j) {
            for (k=i+1; k<=n; ++k)
                if (a[i]<a[k]) D[i][j]+=D[k][j-1];
            if (D[i][j]==0) break;
            maxx=max(maxx, j);
        }
    }
    ant=-1;
    for (i=1; i<=n && maxx; ++i) {
        if (D[i][maxx] && a[i]>ant) {
            if (D[i][maxx] < K) K-=D[i][maxx];
            else {
                g<<i<<" ";
                ant=a[i];
                --maxx;
            }
        }
    }
    g<<"\n";

    return 0;
}
