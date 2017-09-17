# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("euclid3.in");
ofstream g("euclid3.out");
int i,j,n,m,x,y,a,b,c;
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
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a>>b>>c;

        int x, y, D;
        D=euclid (a, b, x, y);

        if (c%D) g<<"0 0\n";
        else g<<x*(c/D)<<" "<<y*(c/D)<<"\n";
    }

    return 0;
}
