# include <fstream>
# include <cmath>
using namespace std;
ifstream f("chiftea.in");
ofstream g("chiftea.out");
int i,j,n,m,t,rad,x;
int main ()
{
    f>>t;
    for (i=1; i<=t; ++i)
    {
        f>>x;
        rad=sqrt((double)x);
        if (rad*rad==x) g<<4*rad<<"\n";
        else {
                if (x-rad*rad<=rad) g<<4*rad+2<<"\n";
                else g<<4*rad+4<<"\n";
             }
    }


    return 0;
}
