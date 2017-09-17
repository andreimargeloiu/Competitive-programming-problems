# include <fstream>
# include <algorithm>
# include <cstring>
using namespace std;
ifstream f("energii.in");
ofstream g("energii.out");
int C[5005];
int n,G,i,j,E,cost;
int main ()
{
    f>>n>>G;
    for (i=1; i<=G; ++i) C[i]=100000;
    for (i=1; i<=n; ++i)
    {
        f>>E>>cost;
        for (j=G; j>=1; --j)
        {
            if (E>=j) C[j]=min(C[j],cost);
            else C[j]=min(C[j],C[j-E]+cost);
        }
    }
    if (C[G]==100000) g<<"-1\n";
    else g<<C[G]<<"\n";

    return 0;
}
