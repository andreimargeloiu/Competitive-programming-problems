# include <fstream>
# include <vector>
# include <algorithm>
# define N_Max 1000005
using namespace std;
ifstream f("divprim.in");
ofstream g("divprim.out");
vector <int> v[8];
vector <int>::iterator x;
int a[N_Max];
int i,j,n,nr,cat,poz;
void ciur ()
{
    int i,j;
    for (i=2; i<=N_Max; ++i)
    {
        if (a[i]==0)
        {
            for (j=1; i*j<=N_Max; ++j)
                ++a[i*j];
        }
        if (a[i]<=7) v[a[i]].push_back(i);
    }
}
int main ()
{
    ciur ();
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>nr>>cat;
        x=lower_bound(v[cat].begin(), v[cat].end(), nr);
        poz=x-v[cat].begin();
        if (poz==0) g<<"0\n";
            else g<<v[cat][poz-1]<<"\n";
    }


    return 0;
}
