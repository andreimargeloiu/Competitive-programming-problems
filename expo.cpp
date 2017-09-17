# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("expo.in");
ofstream g("expo.out");
int n;
long long ci,cs,mij,S,H,L,minn;
int main ()
{
    f>>H>>L>>n;
    ci=1; cs=n*max(H,L);
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        S=(mij/H)*(mij/L);
        if (S>=n) minn=mij, cs=mij-1;
           else ci=mij+1;
    }
    g<<minn<<"\n";

    return 0;
}
