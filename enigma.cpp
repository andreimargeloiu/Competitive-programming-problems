# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 300005
# define MOD 31333
# define sigma 26
# define CH (*s - 'a')
using namespace std;
ifstream f("enigma.in");
ofstream g("enigma.out");
int i,j,n,m,l;
int sol[NR];
char s[NR], s2[105];

struct trie {
    int cnt;
    trie *fiu[sigma];
    trie () {
        cnt=0;
        memset (fiu, 0, sizeof(fiu));
    }
};
trie *T=new trie;
void adauga (trie *nod, char *s) {
    nod->cnt ++;
    if (*s=='\0') return;

    if (nod->fiu[CH]==0)
        nod->fiu[CH]=new trie;

    adauga(nod->fiu[CH], s+1);
}
void query (trie *nod, char*s, int S, int F) {
    if (nod->cnt==0) return;
    if (nod!=T) {
        sol[F]+=(nod->cnt)*sol[S];
        sol[F]%=MOD;
    }

    if (F==n || nod->fiu[CH]==0) return;
        else query (nod->fiu[CH], s+1, S, F+1);
}
int main ()
{
    f>>n>>m; f.get();
    f.getline (s+1, NR);
    for (j=1; j<=m; ++j) {
        f.getline (s2, 105);
        adauga (T, s2);
    }
    sol[0]=1;
    for (i=1; i<=n; ++i)
        query (T, s+i, i-1, i-1);

    g<<sol[n]<<"\n";

    return 0;
}
