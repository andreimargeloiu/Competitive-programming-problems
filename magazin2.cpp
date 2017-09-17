# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("magazin2.in");
ofstream g("magazin2.out");
int i,j,n,k,x,tip,VV;
int v[100005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>tip;
        if (tip==1)
        {
            f>>x; v[++VV]=x;
        }
        else {
                 f>>k;
                 nth_element(v+1, v+k, v+VV+1);
                 g<<v[k]<<"\n";
             }
    }



    return 0;
}
