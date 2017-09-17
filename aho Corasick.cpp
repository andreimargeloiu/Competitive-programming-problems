# include <bits/stdc++.h>
# define NR 1000005
# define L 10005
# define N 105
# define sigma 26
using namespace std;
ifstream f("ahocorasick.in");
ofstream g("ahocorasick.out");
struct trie {
    int cnt; //nuamrul de aparitii
    trie *fiu[sigma], *fail;
    vector <trie*> adj;
    trie () {
        cnt=0; fail=NULL; adj.clear();
        memset (fiu, 0, sizeof(fiu));
    }
}*poz[N];
trie *T=new trie;

int i,j,n,m,l;
char s[NR], var[L];

trie *ins (trie *nod, char *s) {
    if (*s=='\0') return nod;

    if (nod->fiu[*s - 'a']==NULL)
        nod->fiu[*s - 'a']=new trie;

    return ins(nod->fiu[*s - 'a'], s+1);
}
void BFS () {
    queue <trie*> q;
    q.push(T);
    while (! q.empty()) {
        trie *nod=q.front(); q.pop();
        for (int i=0; i<sigma; ++i) {
            if (nod->fiu[i]!=NULL) {
                trie *aux=nod->fail;

                while (aux!=NULL && aux->fiu[i]==NULL)
                    aux=aux->fail;

                if (aux==NULL) aux=T;
                          else aux=aux->fiu[i];

                nod->fiu[i]->fail=aux;
                aux->adj.push_back(nod->fiu[i]);

                q.push(nod->fiu[i]);
            }
        }
    }
}
void DFS (trie *nod) {
    for (auto &x: nod->adj) {
        DFS(x);
        nod->cnt += x->cnt;
    }
}
int main ()
{
    f.getline (s+1, NR); l=strlen(s+1);
    f>>n; f.get();
    for (int i=1; i<=n; ++i) {
        f.getline(var+1, L);
        poz[i]=ins(T, var+1);
    }
    BFS ();
    //facem ca la KMP
    trie *curr=T;
    for (int i=1; i<=l; ++i) {
        while (curr!=NULL && curr->fiu[s[i]-'a']==NULL)
            curr=curr->fail;

        if (curr==NULL) curr=T;
                   else curr=curr->fiu[s[i]-'a'];
        curr->cnt ++;
    }
    DFS(T);
    for (int i=1; i<=n; ++i)
        g<<poz[i]->cnt<<"\n";


    return 0;
}
