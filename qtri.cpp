# include <fstream>
# include <algorithm>
# include <cmath>
using namespace std;
ifstream f("qtri.in");
ofstream g("qtri.out");
struct elem
{
    int x1,x2,x3,X,y1,y2,y3,Y;
}a;
int i,A1,A2,A3,A,n;
int arie (int x1, int y1, int x2, int y2, int x3, int y3)
{
    int rez;
    rez=x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1;
    rez=abs(rez);
    return rez;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a.x1>>a.y1>>a.x2>>a.y2>>a.x3>>a.y3>>a.X>>a.Y;
        A1=arie(a.x1,a.y1,a.x2,a.y2,a.X,a.Y);
        A2=arie(a.x1,a.y1,a.x3,a.y3,a.X,a.Y);
        A3=arie(a.x2,a.y2,a.x3,a.y3,a.X,a.Y);
        A=arie(a.x1,a.y1,a.x2,a.y2,a.x3,a.y3);

        if (A1+A2+A3==A) g<<"DA\n";
            else g<<"NU\n";
    }
    return 0;
}
