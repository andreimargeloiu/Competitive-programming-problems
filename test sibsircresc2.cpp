# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("nrsubsircresc2.in");
ofstream g("nrsubsircresc2.out");
int i,j,n,m,P,nrsol,T;
int var[50], a[50];
void back (int k)
{
    if (k==P+1) ++nrsol;
    else {
           for (int i=var[k-1]+1; i<=n; ++i)
              if (a[i] > a[var[k-1]]){
                 var[k]=i;
                 back(k+1);
                 var[k]=0;
              }
    }
}
int main ()
{

        nrsol=0;
        f>>n>>P;
        for (i=1; i<=n; ++i)
            f>>a[i];

        back(1);
        g<<nrsol;

    return 0;
}
