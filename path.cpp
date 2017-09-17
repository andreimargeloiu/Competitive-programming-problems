# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# include <queue>
# define NR 200
using namespace std;
ifstream f("path.in");
ofstream g("path.out");
queue <int> q;
vector <int> v[NR], vt[NR];
int i,j,n,m,S,Lmax,K,c1,c2;
int grad[NR], E[NR], L[NR], nr[NR];
char ch1, ch2;
void sorteaza () {
    for (int i=1; i<=150; ++i)
        if (v[i].size()) sort(v[i].begin(), v[i].end());
}
void sortaret () {
    while (! q.empty()) {
        int k=q.front(); q.pop();

        for (int i=0; i<vt[k].size(); ++i) {
            if (L[vt[k][i]] < L[k]+1) {
                L[vt[k][i]]=L[k]+1;
                q.push(vt[k][i]);
            }

            Lmax=max(Lmax, L[vt[k][i]]);
        }
    }
}
int norm (int x) {
    if ('a'<=x && x<='z') return x-'a'+1;
                      else return x-'A'+30;
}
void DFS (int k) {
    if (v[k].size()==0) nr[k]=1;
    else {
        for (int i=0; i<v[k].size(); ++i) {
            if (! nr[v[k][i]]) DFS (v[k][i]);
            if (L[v[k][i]]==L[k]-1)nr[k]+=nr[v[k][i]];
        }
    }
}
int main ()
{
    f>>n>>m>>K; f.get();
    for (i=1; i<=m; ++i) {
        f>>ch1; f.get(); f>>ch2; f.get();
        c1=(int)ch1; c2=(int)ch2;
        c1=norm (c1); c2=norm (c2);

        E[c1]=1; E[c2]=1;

        v[c1].push_back(c2); ++grad[c1];
        vt[c2].push_back(c1);
    }

    sorteaza ();
    for (i=1; i<=150; ++i)
        if (E[i] && grad[i]==0) {
            L[i]=1;
            q.push(i);
        }
    sortaret ();

    S=0; L[S]=Lmax+1;
    for (i=1; i<=150; ++i)
        if (L[i]==Lmax) {
            DFS (i);
            v[S].push_back(i);
        }

    for (i=1; i<=Lmax; ++i) { //pentru fiecare din lungime
        for (j=0; j<v[S].size(); ++j) {
            if (L[v[S][j]] != L[S]-1) continue;

            if (nr[v[S][j]] < K) K-=nr[v[S][j]];
            else {
                S=v[S][j];
                if (S<=26) g<<(char)(S+'a'-1);
                      else g<<(char)(S+'A'-30);
                break;
            }
        }
    }
    g<<"\n";

    return 0;
}
