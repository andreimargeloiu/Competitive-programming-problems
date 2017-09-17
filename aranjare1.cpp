# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 105
# define SIGMA 26
# define P1 97LL
# define P2 79LL
# define MOD1 500009LL
# define MOD2 666013LL
using namespace std;
ifstream f("aranjare1.in");
ofstream g("aranjare1.out");
struct elem
{
    int x,ap;
}E;
vector <elem> HASH[MOD1+5];
int i,j,n,m,K,l,c;
int a[NR][NR], ap[27];
char s[NR];
int hashCode (long long P, long long MOD)
{
    long long code=0;

    for (int i=1; i<=SIGMA; ++i)
        code=(code*P+ap[i])%MOD;

    return (int)code;
}
void insert (int k, int FIND)
{
    for (int i=0; i<HASH[k].size(); ++i)
        if (HASH[k][i].x==FIND)
        {
            ++HASH[k][i].ap;
            return;
        }

    E.x=FIND; E.ap=1;
    HASH[k].push_back(E);
}
void find (int k, int FIND)
{
    for (int i=0; i<HASH[k].size(); ++i)
        if (HASH[k][i].x==FIND)
        {
            g<<HASH[k][i].ap<<"\n";
            return ;
        }
    g<<"0\n";
}
int main ()
{
    f>>n>>m>>K; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline(s+1, NR);
        for (j=1; j<=n; ++j)
            a[i][j]=s[j]-'A'+1;
    }

    for (i=1; i<=n-m+1; ++i)
    {
        for (j=1; j<=n-m+1; ++j)
        {
            memset(ap,0,sizeof(ap));
            for (l=0; l<m; ++l)
                for (c=0; c<m; ++c)
                    ++ap[a[i+l][j+c]];
            //il inseram
            insert (hashCode(P1,MOD1), hashCode(P2,MOD2));
        }
    }
    m=m*m;
    for (i=1; i<=K; ++i)
    {
        f.getline(s+1, NR);
        //facel codul
        memset(ap,0,sizeof(ap));
        for (j=1; j<=m; ++j)
            ++ap[s[j]-'A'+1];

        find(hashCode(P1,MOD1), hashCode(P2,MOD2));
    }

    return 0;
}
