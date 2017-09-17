# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 105
# define M 505
using namespace std;
ifstream f("senat.in");
ofstream g("senat.out");
vector <int> v[NR];
int i,j,n,m,k,l,nr,cuplate;
int M1[NR], M2[NR], ap[NR];
char s[M];
int cuplaj (int k)
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
        if (cuplaj(M2[v[k][i]]))
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    return 0;
}
int main ()
{
    f>>n>>m; f.get();
    for (i=1; i<=m; ++i)
    {
        f.getline (s+1, M); l=strlen(s+1);
        int it=1;
        while (it<=l)
        {
            nr=0;
            while ('0'<=s[it] && s[it]<='9')
                nr=nr*10+(s[it]-'0'), ++it;
            v[nr].push_back(i);
            ++it;
        }
    }
    cuplate=1;
    while (cuplate)
    {
        memset (ap, 0, sizeof(ap));
        cuplate=0;
        for (i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=cuplaj (i);
    }
    for (i=1; i<=m; ++i)
        if (! M2[i]) {g<<"0\n"; return 0;}
    for (i=1; i<=m; ++i)
        g<<M2[i]<<"\n";

    return 0;
}
