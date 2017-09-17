# include <fstream>
# include <iomanip>
using namespace std;
ifstream f("balulbobocilor.in");
ofstream g("balulbobocilor.out");
float v1,v2,x,y,D,V,T;
int main ()
{
    f>>D;
    f>>v1>>x>>y;
    f>>v2>>x>>y;
    f>>V;

    T=D/(v1+v2);
    g<<fixed<<setprecision (6)<<T*V<<"\n";

    return 0;
}
