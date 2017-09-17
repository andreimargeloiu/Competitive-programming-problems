# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("perle2.in");
ofstream g("perle2.out");
int i,j,n,m,maxx,S,x,k;
int main ()
{
    f>>n>>k;
    maxx=-99999999;
    for (i=1; i<=n; ++i)
    {
        f>>x; x-=k;
        if (S+x>x) S+=x;
        else S=x;
        maxx=max(maxx, S);
    }
    if (maxx<0) g<<"0\n";
    else g<<maxx<<"\n";


    return 0;
}
