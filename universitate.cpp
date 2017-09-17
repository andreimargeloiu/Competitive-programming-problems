# include <fstream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# include <vector>
# define NR 105
using namespace std;
ifstream f("universitate.in");
vector <int> v[NR], C[NR];
int i,j,n,m,x,y,X,K,l,cuplate,sol;
int ap[NR], M1[NR], M2[NR];
char s[NR];
int match (int k)
{
    if (ap[k]) return 0;
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]])
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    for (int i=0; i<v[k].size(); ++i)
        if (match(M2[v[k][i]]))
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
}
int main ()
{
    f>>n>>m>>K; f.get(); // calculatoare, echipamente

    for (i=1; i<=n; ++i)
    {
        f.getline(s+1, NR); l=strlen(s+1);
        for (j=1; j<=l; j+=0)
        {
            C[i].push_back(s[j]-'0');
            j+=2;
        }
    }
    for (i=1; i<=m; ++i) // echipamente
    {
        f.getline(s+1, NR); l=strlen(s+1);
        for (j=1; j<=l; j+=0)
        {
            X=(s[j]-'0');
            for (int o=1; o<=n; ++o)
                for (int k=0; k<C[o].size(); ++k)
                    if (C[o][k]==X) v[i].push_back(o);
            j+=2;
        }
    }

    //stanga - echipamentele
    //dreapta - calculatoarele

    cuplate=1;
    while (cuplate)
    {
        cuplate=0;
        memset (ap, 0, sizeof(ap));
        for (i=1; i<=m; ++i)
            if (! M1[i]) cuplate+=match(i);
    }
    for (i=1; i<=m; ++i)
        if (! M1[i]) ++sol;

    freopen ("universitate.out", "w", stdout);
    printf ("%d\n", sol);

    return 0;
}
