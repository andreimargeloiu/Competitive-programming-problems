# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 2000002
using namespace std;
vector <int> sol;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int i,j,n,m,la,lb,VV;
int pi[NR];
char a[NR],b[NR];
void prefix ()
{
    int k=0;
    for (i=2; i<=la; ++i)
    {
        while (k>0 && a[k+1]!=a[i])
            k=pi[k];
        if (a[k+1]==a[i]) ++k;
        pi[i]=k;
    }
}
void KMP ()
{
    int q=0;
    for (i=1; i<=lb; ++i)
    {
        while (q>0 && a[q+1]!=b[i])
            q=pi[q];
        if (a[q+1]==b[i]) ++q;
        if (q==la)//am gasit sirul
        {
            ++VV;
            if (VV<=1000) sol.push_back(i-la);
            q=pi[q];
        }
    }
}
int main ()
{
    f.getline (a+1, NR); la=strlen(a+1);
    f.getline (b+1, NR); lb=strlen(b+1);

    prefix();
    KMP ();

    g<<VV<<"\n";
    for (i=0; i<sol.size(); ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
