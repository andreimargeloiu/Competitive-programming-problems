# include <fstream>
# include <vector>
# include <cstring>
# include <algorithm>
# define NR 300
using namespace std;
vector <int> v[NR];
ifstream f("gigel.in");
ofstream g("gigel.out");
int i,j,n,m,leafuri,final,l,nrcaractere,x,S,maxx,I;
int ap[NR], in[NR],luat[NR], niv[NR];
long long leaf[NR], sol[NR], nr;
char s[NR];
void DFS (int k, int nivel)
{
    if (k==0) return ;
    if (v[k].size())
    {
        for (i=0; i<v[k].size(); ++i)
        {
            if (i==0)
            {
                DFS (v[k][i], nivel+1);
            }
            else {
                     nr+=(1<<nivel);
                     DFS(v[k][i], nivel+1);
                     nr-=(1<<nivel);
                 }
        }
    }
    else {
             leaf[++leafuri]=nr+(1<<n);
             niv[leafuri]=nivel;
         }
}
bool cmp (long long x, long long y)
{
    if (x>=y) return 0;
        else return 1;
}
void afisare (long long k)
{
    for (int i=0; i<niv[k]; --i)
        if (k & (1<<i)) g<<"1";
        else g<<"0";
}
int main ()
{
    f>>l; f.get ();
    f.getline(s+1, NR);

    for (i=1; i<=l; ++i)
    {
        ++ap[s[i]];
        if (ap[s[i]]==1) ++nrcaractere;
    }
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x; ++in[x];
        if (x!=0) v[i].push_back(x);
    }
    for (i=1; i<=n; ++i)
    {
        f>>x; ++in[x];
        if (x!=0)
        {
            if (v[i].size()==0) v[i].push_back(0);
            v[i].push_back(x);
        }
    }
    for (i=1; i<=n; ++i)
        if (in[i]==0) S=i;

    DFS (S,0);

    if (leafuri<nrcaractere)
    {
        g<<"-1\n";
        return 0;
    }

    sort (leaf+1, leaf+leafuri+1, cmp);

    for (i=1; i<=l; ++i)
    {
        maxx=0;
        for (j=1; j<=l; ++j)
            if (luat[s[j]]==0 && ap[s[j]]>maxx) maxx=s[j], I=s[j];

        sol[I]=++final;
        luat[I]=1;
    }

    //afisarea
    for (i=1; i<=l; ++i)
        afisare(sol[s[i]]);

    return 0;
}
