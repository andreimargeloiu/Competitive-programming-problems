# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# include <queue>
# define mp make_pair
# define f first
# define s second
# define NR 1005
# define N 1000005
using namespace std;
ifstream f("pirati.in");
ofstream g("pirati.out");
queue <pair <int, int> > q;
vector <int> v[N];
pair <int, int> E;
int i,j,n,m,X,Y,x,y,x2,y2,VV,st,Q;
int lg[N], comp[NR][NR], T[N][15], stiva[N], niv[N], luat[N], tip[N];
char a[NR][NR];
int dx[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};

void BF (int l, int c) {
    int i,lv,cv;
    q.push(mp(l, c));
    comp[l][c]=VV; tip[VV]=a[l][c]-'0';
    while (! q.empty()) {
        E=q.front(); q.pop();
        l=E.f; c=E.s;

        for (i=0; i<8; ++i) {
            lv=l + dx[i];
            cv=c + dy[i];
            if (a[l][c]==a[lv][cv]) { // daca e aceiasi componenta
                if (! comp[lv][cv]) {
                    comp[lv][cv]=VV;
                    E.f=lv; E.s=cv;
                    q.push(E);
                }
            }
            else { // daca poate fac o muchie in arbore
                 if (luat[comp[lv][cv]]!=VV && comp[lv][cv]!=0) {
                    luat[comp[lv][cv]]=VV;
                    v[VV].push_back(comp[lv][cv]);
                    v[comp[lv][cv]].push_back(VV);
                 }
            }
        }
    }
}
void logaritmi () {
    for (int i=2; i<=VV; ++i)
        lg[i]=lg[i/2] + 1;
}
void DFS (int k, int nivel) {
    stiva[nivel]=k; niv[k]=nivel;
    for (int i=0; i<=lg[VV]; ++i)
        if (nivel > (1<<i)) T[k][i]=stiva[nivel - (1<<i)];

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i] != T[k][0]) DFS (v[k][i], nivel+1);
}
int LCA (int X, int Y) {
    if (X==Y) return 0;

    int nr=0;
    if (niv[Y] > niv[X]) swap(X, Y);
    for (int i=lg[VV]; i>=0; --i)
        if (niv[T[X][i]] >= niv[Y]) X=T[X][i], nr=nr+(1<<i);

    if (X==Y) return (nr)/2;

    for (int i=lg[VV]; i>=0; --i)
        if (T[X][i] != T[Y][i]) X=T[X][i], Y=T[Y][i], nr=nr+2*(1<<i);

    return nr/2 + 1;
}
int main ()
{
    f>>n>>m>>Q; f.get();
    for (i=1; i<=n; ++i)
        f.getline(a[i]+1, NR);

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (! comp[i][j]) {
                ++VV;
                BF (i, j);
            }
    logaritmi ();
    DFS (1, 1);
    for (i=1; i<=Q; ++i) {
        f>>x>>y>>x2>>y2;
        int nr=0;
        X=comp[x][y]; Y=comp[x2][y2];

        while (X!=Y) {
            if (niv[X] > niv[Y]) {X=T[X][0]; if (tip[X]) ++nr;}
            else if (niv[Y] > niv[X]) {Y=T[Y][0]; if (tip[Y]) ++nr;}
            else {
                X=T[X][0];
                Y=T[Y][0];
                if (X==Y) {if (tip[X]) ++nr;}
                else {if (tip[X]) ++nr; if (tip[Y]) ++nr;}
            }
        }
        g<<nr<<"\n";

        //g<<LCA (X, Y)<<"\n";
    }

    return 0;
}
