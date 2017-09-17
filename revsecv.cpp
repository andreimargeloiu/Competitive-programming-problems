# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 10005
using namespace std;
ifstream f("revsecv.in");
ofstream g("revsecv.out");
struct Trie {
    int nrfii;
    long long nr;
    Trie *fiu[26];
    Trie () {
        nr=0; nrfii=0;
        memset (fiu, 0, sizeof(fiu));
    }
};
Trie *T= new Trie;
Trie *XX;
Trie *L[NR], *R[NR];
int i,j,n,l,ok[NR];
long long sol, var;
char s[NR];

void ins (Trie *nod, int CH, int stop, int I) {
    if (stop==0) {
        L[I]=nod;
        nod->nr ++;
        return;
    }

    if (nod->fiu[CH]==0) {
        nod->fiu[CH]=new Trie;
        nod->nrfii ++;
    }

    ins (nod->fiu[CH], CH, stop-1, I);
}

long long  query (Trie *nod, int CH, int stop, int I) {
    if (stop==0) {
        R[I]=nod;
        return nod->nr;
    }

    if (nod->fiu[CH]!=0) return query (nod->fiu[CH], CH, stop-1, I);
    return 0;
}
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1);

    for (i=1; i<=n; ++i)
        L[i]=T, R[i]=T;

    for (l=1; l<=n; ++l) {
        for (j=n-2*l+1; j>=1; --j) {
            ins (L[j+2*l-1], s[j+l]-'a', 1, j+2*l-1);

            if (ok[j]) var=0;
            else {
                XX=R[j];
                var=query (R[j], s[j+l-1]-'a', 1, j);
                if (R[j]==XX) ok[j]=1;
            }

            sol+=var;
        }
    }
    g<<sol<<"\n";


    return 0;
}
