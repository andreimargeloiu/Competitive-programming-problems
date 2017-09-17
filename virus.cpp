# include <bits/stdc++.h>
# define NR 100005
# define ll 1005
# define sigma 2
using namespace std;
ifstream f("virus.in");
ofstream g("virus.out");
struct trie {
    int nr;
    trie *fiu[sigma], *fail;
    vector <trie*> adj;
    trie () {
        nr=0; fail=NULL;
        memset (fiu, 0, sizeof(fiu));
        adj.clear();
    }
}*poz[NR];
trie *T=new trie;

int i,j,n,m,L,laux;
char s[NR], aux[ll];

trie *ins(trie *nod, char *s) {
    if (*s=='\0') return nod;

    if (nod->fiu[*s - '0']==NULL)
        nod->fiu[*s - '0']=new trie;

    return ins(nod->fiu[*s - '0'], s+1);
}
void BFS () {
    queue <trie*> q;
    q.push(T);
    while (! q.empty()) {
        trie *nod=q.front(); q.pop();
        for (int i=0; i<sigma; ++i) {
            if (nod->fiu[i]==NULL) continue;

            trie *aux=nod->fail;
            while (aux && aux->fiu[i]==NULL)
                aux=aux->fail;
            if (aux==NULL) aux=T;
                      else aux=aux->fiu[i];

            nod->fiu[i]->fail=aux;
            aux->adj.push_back(nod->fiu[i]);
            q.push(nod->fiu[i]);
        }
    }
}
void DFS (trie *nod) {
    for (auto &x: nod->adj) {
        DFS (x);
        nod->nr+=(x)->nr;
    }
}
int main ()
{
    f>>L>>n; f.get();
    f.getline (s+1, NR);
    for (i=1; i<=n; ++i) {
        f>>laux; f.get();
        f.getline(aux+1, ll);
        poz[i]=ins(T, aux+1);
    }
    BFS ();
    trie *curr=T;
    for (i=1; i<=L; ++i) {
        while (curr && curr->fiu[s[i]-'0']==NULL)
            curr=curr->fail;
        if (curr==NULL) curr=T;
                   else curr=curr->fiu[s[i]-'0'];
        curr->nr ++;
    }
    DFS (T);
    for (i=1; i<=n; ++i)
        g<<poz[i]->nr<<"\n";

    return 0;
}
