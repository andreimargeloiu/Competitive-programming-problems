# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("euclid3.in");
ofstream g("euclid3.out");
int a, b, c, i, T;
int euclid (int a, int b, int &x, int &y) {
    if (b==0) {
        x=1; y=0;
        return a;
    }
    int x0, y0, D;
    D=euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
    return D;
}
int main ()
{
    f>>T;
    while (T--) {
        f>>a>>b>>c;
        int x, y, D;
        D=euclid (a, b, x, y);
        if (c%D==0) g<<x*(c/D)<<" "<<y*(c/D)<<"\n";
               else g<<"0 0\n";
    }
    return 0;
}
