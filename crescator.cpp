# include <algorithm>
# include <fstream>
using namespace std;
ifstream f("crescator.in");
ofstream g("crescator.out");
int i,j,n,sol,maxx,nr,s,ant,x;
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        if (ant<=x) ++nr;
        else {
                 sol=sol + nr*(nr+1)/2;
                 maxx=max(maxx, nr);
                 nr=1;
             }
        ant=x;
    }
    sol=sol + nr*(nr+1)/2;
    maxx=max(maxx, nr);

    g<<sol<<" "<<maxx<<"\n";

    return 0;
}
