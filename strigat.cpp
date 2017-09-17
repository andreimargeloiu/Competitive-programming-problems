# include <bits/stdc++.h>
# define NR 105
# define sigma 26
# define N 100005
using namespace std;
ifstream f("strigat.in");
ofstream g("strigat.out");
struct trie {
    int  VV;
    long long adaos;
    trie *fiu[sigma], *fail;
    vector <trie*> adj;

    trie () {
        fail=NULL; adaos=0; VV=0;
        memset (fiu, 0, sizeof(fiu));
        adj.clear();
    }
};
trie *T=new trie;
queue <trie*> q;
struct stiva {
    char ch;
    int ant;
    long long adaos;
    trie *nod;
}st[N];
struct anterior {
    int i, j;
}ant[NR][N], antaux[N];
int i,j,n,m,VV,L,val,I,J, sol[N], lsol;
long long dp[NR][N], dpaux[N], maxx;
char s[NR];

void ins (trie *nod, char *s, int val) {
    if (*s=='\0') {
        nod->adaos +=val;
        return;
    }
    if (nod->fiu[*s - 'a']==NULL)
        nod->fiu[*s - 'a']=new trie;

    ins (nod->fiu[*s - 'a'], s+1, val);
}
void BFS () {
    q.push(T);
    while (! q.empty()) {
        trie *nod=q.front(); q.pop();

        for (int i=0; i<sigma; ++i) {
            if (nod->fiu[i]==NULL) continue;

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
void make_adaosuri (trie *nod, int tata, char ch) {
    if (nod!=T) {
        ++VV; nod->VV=VV;
        st[VV].ant=tata;
        st[VV].ch=ch;
        st[VV].adaos=nod->adaos;
        st[VV].nod=nod;

        for (auto &x: nod->adj)
            x->adaos += nod->adaos;
    }
    int VVaux=VV;

    for (int i=0; i<sigma; ++i)
        if (nod->fiu[i]!=NULL) {
            make_adaosuri (nod->fiu[i], VVaux, i);
        }
}
int main ()
{
    f>>L>>m; f.get();
    for (i=1; i<=m; ++i) {
        f.getline (s+1, NR);
        f>>val; f.get();
        ins (T, s+1, val);
    }
    BFS ();
    make_adaosuri (T, 0, 0);

    // dp[i][j] - valoarea maxima pe care o pot obtine in sirul de lungime i, terminand
    //            in starea j
    // ant[i][j]

    dp[0][0]=1;
    for (int i=1; i<=L; ++i) {
        for (int o=0; o<=VV; ++o) //init
                dpaux[o]=0, antaux[o].i=0, antaux[o].j=0;

        for (int j=1; j<=VV; ++j) {
            if (dp[i-1][st[j].ant]) { // evolutie normala
                if (dp[i][j] < dp[i-1][st[j].ant]+st[j].adaos) { //evolutie normala
                    dp[i][j]=  dp[i-1][st[j].ant]+st[j].adaos;

                    ant[i][j].i=i-1;
                    ant[i][j].j=st[j].ant;
                }
            }
            dpaux[j]  =dp[i][j];
            antaux[j]=ant[i][j];

            if (i==L) { if (dp[i][j] > maxx) {maxx=dp[i][j]; J=j;} }
        }

        for (int j=1; j<=VV; ++j) {
            if (dp[i][j]) { //pun si in starile acceptate de starea j
                trie *aux=st[j].nod->fail;
                while (aux!=NULL) {
                    if (dpaux[aux->VV] < dp[i][j]) {
                        dpaux[aux->VV]=dp[i][j];

                        antaux[aux->VV].i=i;
                        antaux[aux->VV].j=j;
                    }
                    aux=aux->fail;
                }
            }
        }
        for (int j=0; j<=VV; ++j)
            if (dp[i][j] < dpaux[j]) {
                dp[i][j]=dpaux[j];
                ant[i][j]=antaux[j];
            }
    }
    g<<maxx-1<<"\n";

    I=L;
    while (I) {
        if (ant[I][J].i==I) J=ant[I][J].j;

        sol[++lsol]=st[J].ch;

        int Iaux, Jaux;
        Iaux=ant[I][J].i;
        Jaux=ant[I][J].j;

        I=Iaux; J=Jaux;
    }
    for (int i=lsol; i>=1; --i)
        g<<(char)(sol[i] + 'a');
    g<<"\n";

    return 0;
}
