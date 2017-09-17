# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("xerox.in");
ofstream g("xerox.out");
int i,j,n,m,x,XOR,T,N;
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t)
    {
        f>>n>>x>>x;
        XOR=0;
        for (j=1; j<=n; ++j)
        {
            f>>N; XOR^=N;
            for (int o=1; o<=2*N; ++o)
                f>>x;
        }
        if (XOR) g<<"1\n";
            else g<<"0\n";
    }

    return 0;
}
