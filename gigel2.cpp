# include <fstream>
# include <vector>
# include <cstring>
# include <algorithm>
# define NR 300
using namespace std;
vector <int> v[NR];
ifstream f("gigel.in");
ofstream g("gigel.out");
struct elem
{
    long long nr;
    int niv;
}leaf[NR];
int i,j,n,m,leafuri,final,l,nrcaractere,x,S,maxx,I;
int ap[NR], in[NR], luat[NR], niv[NR], out[NR];
long long sol[NR], nr;
char s[NR];
void DFS (int k, int nivel)
{
    if (k==0) return ;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (i==0) DFS (v[k][i], nivel+1);
        else {
                 nr+=(1<<nivel);
                 DFS(v[k][i], nivel+1);
                 nr-=(1<<nivel);
             }
    }
    if (out[k]==0)
    {
        leaf[++leafuri].nr=nr+(1<<nivel);
        leaf[leafuri].niv=nivel;
    }
}
bool cmp (elem x, elem y)
{
    if (x.nr>=y.nr) return 0;
        else return 1;
}
void citire ()
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
        v[i].push_back(x);
        if (x!=0) ++out[i];
    }
    for (i=1; i<=n; ++i)
    {
        f>>x; ++in[x];
        v[i].push_back(x);
        if (x!=0) ++out[i];
    }
}
void afisare (int k)
{
    for (int i=0; i<leaf[k].niv; ++i)
        if (leaf[k].nr & (1<<i)) g<<"1";
            else g<<"0";
}
int main ()
{
    citire();
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
            if (luat[s[j]]==0 && ap[s[j]]>maxx) maxx=ap[s[j]], I=s[j];
        if (maxx)
        {
            sol[I]=++final;
            luat[I]=1;
        }
    }
    //afisarea
    for (i=1; i<=l; ++i)
        afisare(sol[s[i]]);

    return 0;
}
