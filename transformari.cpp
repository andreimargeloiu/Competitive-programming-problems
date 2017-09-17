# include <fstream>
# include <algorithm>
# define inf 999999999
using namespace std;
ifstream f("transformari.in");
ofstream g("transformari.out");
int i,j,n,minn,S,sol;
int numara (int a, int b)
{
    if (b==1) return a-1;
    if (b==0) return inf;

    //else
    return a/b + numara (b, a%b);
}
int main ()
{
    f>>n; minn=inf;
    for (i=1; i<n; ++i)
    {
        minn=min(minn, numara(i, n));
    }
    g<<minn<<"\n";

    return 0;
}
