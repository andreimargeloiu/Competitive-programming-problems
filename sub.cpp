# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 305
# define CH (*s - 'a')
using namespace std;
ifstream f("sub.in");
ofstream g("sub.out");
struct trie {
    int last, sters;
    trie *fiu[26];
    trie () {
        last=0; sters=0;// la al catalea element m-am oprit
        memset (fiu, 0, sizeof(fiu));
    }
};
trie *T=new trie;
int i,j,n,m,sol,l,VV;
char s[NR], var[NR];

void make (trie *nod, char *s, int last) {
    if ((nod->last)==last-1) nod->last ++;
    if ((nod->last) < last) return;
    if (*s=='\0') return;

    if (last==1 && nod->fiu[CH]==0) nod->fiu[CH]=new trie;

    if (nod->fiu[CH]) make (nod->fiu[CH], s+1, last);
}
void verifica (trie *nod, char *s) {
    nod->sters=1;
    if (*s=='\0') return;

    if (nod->fiu[CH]) {
        verifica (nod->fiu[CH], s+1);
    }
}
void numara (trie *nod) {
    if (nod->sters==0 && nod->last==n) {
        ++sol;
    }
    for (int i=0; i<26; ++i)
        if (nod->fiu[i]!=0)
        {
            ++VV; var[VV]='a'+i;
            numara (nod->fiu[i]);
            var[VV]=0; --VV;
        }
}
int main ()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i) {
        f.getline(s, NR); l=strlen(s);
        for (j=0; j<l; ++j)
            make (T, s+j, i);
    }

    f>>m; f.get();
    for (i=1; i<=m; ++i) {
        f.getline(s, NR); l=strlen(s);
        for (j=0; j<l; ++j)
            verifica (T, s+j);
    }
    numara (T);
    g<<sol<<"\n";


    return 0;
}
