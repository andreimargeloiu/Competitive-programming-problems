# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("rucsac.in");
ofstream g("rucsac.out");
int i,j,n,G,gr,P;
int a[10005];
int main ()
{
    f>>n>>G;

    for (i=1; i<=n; ++i)
    {
        f>>gr>>P;

        for (j=G-gr; j>=0; --j)
        {
            if (a[j+gr]<a[j]+P) a[j+gr]=a[j]+P;
        }
    }
    g<<a[G]<<"\n";

    return 0;
}
