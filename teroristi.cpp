# include <bits/stdc++.h>
# define NR 1000005
# define INF 999999999
# define N 1005
using namespace std;
ifstream f("teroristi.in");
ofstream g("teroristi.out");
vector <int> v[N], litera[30], ziar[N];
queue <int> q;
int i,j,n,m,X1,X2,S,D,c1,c2,minn,FLUX;
int cap[N][N], flux[N][N], aplit[N], apziar[N], T[N];
char s[NR], ch1, ch2;

int nod (int x, int y) {
    int sol=X1 + ((x-1)*27) + y;
    return sol;
}
bool apare (int x, int X) {
    X=X-X1;
    if (X%27==0) return 0;
    else {
        if (X%27==x || (X/27+1)==x) return 1;
                               else return 0;
    }
}
int BFS (int S) {
    int OK=0; q.push(S);
    memset (T, 0, sizeof(T)); T[S]=-1;

    while (! q.empty()) {
        int k=q.front(); q.pop();
        for (auto &x: v[k]) {
            if (T[x]==0 && flux[k][x] < cap[k][x]) {
                if (x==D) OK=1;
                else {
                    T[x]=k;
                    q.push(x);
                }
            }
        }
    }
    return OK;
}
int main ()
{
    f>>n>>m; f.get();
    f.getline (s+1, NR);
    for (i=1; i<=n; ++i) {
        s[i]=s[i]-'a'+1;

        ++aplit[s[i]];
    }

    X1=30; X2=X1 + (27 * 26);
    for (i=1; i<=m; ++i) {
        f>>ch1; f.get(); f>>ch2; f.get();
        ch1=ch1-'a'+1; ch2=ch2-'a'+1;

        if (ch1 > ch2) swap(ch1, ch2);

        ++apziar[nod(ch1, ch2)];
        ziar[nod(ch1, ch2)].push_back(i);
    }

    S=999; D=1000;
    //fac muchiile de la sursa la noduri
    for (i=1; i<=26; ++i) {
        cap[S][i]=aplit[i];
        v[S].push_back(i);
        v[i].push_back(S);
    }
    //muchiile dintre noduri
    for (i=1; i<=26; ++i)
        for (j=X1+1; j<=X2; ++j) {
            if (aplit[i] && apziar[j] && apare(i, j)) {
                cap[i][j]=INF;
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }

    //muchiile dintre  noduri si destinatie
    for (i=X1+1; i<=X2; ++i) {
        cap[i][D]=apziar[i];
        v[i].push_back(D);
        v[D].push_back(i);
    }

    //incep fluxul
    while (BFS (S)) {
        for (auto &x: v[D]) {
            minn=INF;
            if (T[x] && flux[x][D] < cap[x][D]) {
                T[D]=x;
                for (int nod=D; nod!=S; nod=T[nod])
                    minn=min(minn, cap[T[nod]][nod]-flux[T[nod]][nod]);

                if (minn<=0) continue;
                FLUX+=minn;
                for (int nod=D; nod!=S; nod=T[nod]) {
                    flux[T[nod]][nod]+=minn;
                    flux[nod][T[nod]]-=minn;
                }
            }
        }
    }
    // pun pentru fiecare litera bucatile de ziar
    // de unde am luat aceam litera
    for (i=1; i<=26; ++i) {
        for (auto &x: v[i]) {
            for (j=1; j<=flux[i][x]; ++j) {
                litera[i].push_back(ziar[x].back());
                ziar[x].pop_back();
            }
        }
    }
    for (i=1; i<=n; ++i) {
        g<<litera[s[i]].back()<<" ";
        litera[s[i]].pop_back();
    }

    return 0;
}
