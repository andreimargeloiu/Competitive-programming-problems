# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
int i,j,n,mod,a;
void euclid (int a, int b, int &x, int &y)
{
   if (b==0) {
       x=1; y=0;
       return;
   }
   int x0, y0;
   euclid (b, a%b, x0, y0);
   x=y0;
   y=x0 - (a/b)*y0;
}
int main ()
{
    f>>a>>mod;
    int x, y;
    euclid (a, mod, x, y);

    if (x<0) x=mod+x%mod;
    g<<x<<"\n";

    return 0;
}
