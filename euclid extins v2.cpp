# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("euclid3.in");
ofstream g("euclid3.out");
int i,t,a,b,c;
int euclid (int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1; y=0;
        return a;
    }
    int D, x0, y0;
    D=euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
    return D;
}
int main ()
{
    f>>t;
    for (int i=1; i<=t; ++i)
    {
        f>>a>>b>>c;
        int D, x, y;
        D=euclid (a, b, x, y);

        if (c%D==0) g<<x*(c/D)<<" "<<y*(c/D)<<"\n";
               else g<<"0 0\n";
    }

    return 0;
}
