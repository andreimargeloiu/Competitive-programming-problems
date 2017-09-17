# include <fstream>
using namespace std;
ifstream f("mere.in");
ofstream g("mere.out");
int i,m,n,k,o,nr;
int main ()
{
    f>>n;
    for (o=1; o<=n; ++o)
    {
        f>>m>>k;
        if (m<k)
        {
            g<<"remiza\n";
            continue;
        }
        nr=m/k;
        if (nr%2==1) g<<"Santa Klaus\n";
        else g<<"remiza\n";
    }


    return 0;
}
