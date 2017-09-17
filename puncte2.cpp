# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("puncte2.in");
ofstream g("puncte2.out");
int i,j,n;
int a[100];
int main ()
{
    f>>n; a[1]=1; a[0]=1;
    for (i=2; i<=n; ++i)
    {
        a[i]=a[i-1];
        for (j=i-1; j>=1; --j)
            a[i]+=(a[i-j]*a[j-1]);
    }
    g<<a[n]<<"\n";


    return 0;
}
