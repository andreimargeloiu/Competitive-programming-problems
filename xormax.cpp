# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("xormax.in");
ofstream g("xormax.out");
struct trie {
    int last;
    trie *fiu[3];
    trie () {
        last=0;
        memset (fiu, 0, sizeof(fiu));
    }
};
trie *T=new trie;
int i,j,n,m,CI,CS,sol,maxim,maxx,XOR,I;
int a[NR], var[25];

void update (trie *nod, int *var, int niv, int poz) { // pune xoruri in trie
    if (niv==maxx) nod->last=poz;

    int CH=*var;

    if (niv<maxx) {
        if (nod->fiu[CH]==0) nod->fiu[CH]=new trie;

        update (nod->fiu[CH], var-1, niv+1, poz);
    }
}
void cauta (trie *nod, int *var, int niv) {
    if (niv==maxx) I=nod->last;

    int CH=*var, D=1-CH;

    if (niv<maxx) {
        if (nod->fiu[D]!=0) { // cel care trebuie
            maxim=maxim*2+1;
            cauta (nod->fiu[D], var-1, niv+1);
        }
        else {
            maxim=maxim*2;
            cauta (nod->fiu[CH], var-1, niv+1);
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        XOR=XOR ^ a[i];

        for (j=21; j>=maxx; --j)
            if ((1<<j) & XOR) {
                maxx=max(maxx, j);
                break;
            }
    }

    XOR=0; sol=-1;
    update (T, var+maxx, -1, 0);
    for (i=1; i<=n; ++i) {
        XOR=XOR ^ a[i];
        for (j=maxx; j>=0; --j)
            if ((1<<j) & XOR) var[j]=1;
                         else var[j]=0;
        maxim=0; I=0;
        cauta (T, var+maxx, -1);

        if (maxim > sol) {sol=maxim; CI=I; CS=i;}

        update (T, var+maxx, -1, i);
    }
    g<<sol<<" "<<CI+1<<" "<<CS<<"\n";


    return 0;
}
