# include <fstream>
using namespace std;
ifstream f("triplet.in");
ofstream g("triplet.out");
int a,b,c,k;
int main ()
{
    f>>k;
    if (k%2==1) c=0;
        else --k, c=1;
    a=(k-1)/2+1;
    b=-(k-1)/2;

    g<<a<<" "<<b<<" "<<c<<"\n";

    return 0;
}
