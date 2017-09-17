# include <bits/stdc++.h>
# define NR 25
# define sigma 26
using namespace std;
ifstream f("trie.in");
ofstream g("trie.out");
struct trie {
    int nrfii, cnt;
    trie *fiu[sigma];
    trie () {
        nrfii=0; cnt=0;
        memset (fiu, 0, sizeof(fiu));
    }
};
trie *T=new trie;
int i,j,n,m;
char s[NR];

void ins (trie *nod, char *s) {
    if (*s=='\0') {
        nod->cnt ++;
        return;
    }

    if (nod->fiu[*s - 'a']==NULL) {
        nod->fiu[*s - 'a']=new trie;
        nod->nrfii ++;
    }

    ins(nod->fiu[*s - 'a'], s+1);
}
int del (trie *nod, char *s) {
    if (*s=='\0') nod->cnt --;
    else {
        if (del (nod->fiu[*s - 'a'], s+1)) {
            nod->nrfii --;
            nod->fiu[*s - 'a']=NULL;
        }
    }

    if (nod->cnt==0 && nod->nrfii==0 && nod!=T) {
        delete nod;
        return 1;
    }
    return 0;
}
int query (trie *nod, char *s) {
    if (*s=='\0') return nod->cnt;
    if (nod->fiu[*s - 'a']!=NULL) return query(nod->fiu[*s - 'a'], s+1);
    return 0;
}
int prefix (trie *nod, char *s, int nivel) {
    if (*s=='\0' || nod->fiu[*s-'a']==NULL) {
        return nivel;
    }
    else return prefix (nod->fiu[*s-'a'], s+1, nivel+1);
}
int main ()
{
    while (f.getline(s, NR)) {
        if (s[0]=='0') ins(T, s+2);
        else if (s[0]=='1') del(T, s+2);
        else if (s[0]=='2') g<<query(T, s+2)<<"\n";
        else g<<prefix(T, s+2, 0)<<"\n";
    }
    return 0;
}
