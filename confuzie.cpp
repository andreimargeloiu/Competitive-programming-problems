/*  am incercat, dar n-a fost sa fie :(
# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 200005
# define LB(p) ((-p)&p)
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,tip,S,VV,sss,ci,cs,mij,Q,var,sol;
int AIB[NR*2], st[NR*2], last[NR], first[NR], ap[NR];
void DFS (int k, int tata)
{
    st[++VV]=k; first[k]=VV;

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS(v[k][i], k);

    st[++VV]=k; last[k]=VV;
}
void update (int poz, int val)
{
    for (int i=poz; i<=VV; i+=LB(i))
        AIB[i]+=val;
}
int suma (int poz)
{
    int S=0;
    for (int i=poz; i>=1; i-=LB(i))
        S+=AIB[i];
    return S;
}
int main ()
{
    freopen ("confuzie.in", "r", stdin);
    freopen ("confuzie.out", "w", stdout);
    scanf ("%d%d", &n, &Q);

    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1, 0);

    for (i=1; i<=Q; ++i)
    {
        scanf ("%d", &tip);
        if (tip==0) // schimba culoarea
        {
            //pun -1 pe first si 1 pe last
            scanf ("%d", &x);
            if (ap[x]) //daca e negru
            {
                ap[x]=0;
                update (first[x], 1);
                update (last[x], -1);
            }
            else {
                      ap[x]=1;
                      update (first[x], -1);
                      update (last[x], 1);
                 }
        }
        else { // query
                 scanf ("%d%d", &x, &y);
                 sol=-1; S=suma(last[x]); var=suma(last[y]-1); S-=var;
                 ci=last[y]; cs=last[x]; sol=-1;

                 while (ci<=cs)
                 {
                     mij=(ci+cs)/2;
                     sss=suma(mij) - var;
                     if (sss>=S) {
                                    if (ap[st[mij]]==1) sol=st[mij];
                                    cs=mij-1;
                                 }
                     else ci=mij+1;
                 }

                 printf ("%d\n", sol);
             }
    }


    return 0;
}
*/
# include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 200000;
const int MAXM = 450001;

int N, M;

vector<int> con[MAXN];
int cnt[MAXN], child[MAXN], lvl[MAXN], p[MAXN];
int path[MAXN], flipped[MAXN];

int Pid = -1;
vector<vector<int> > paths;
vector<set<pair<int, int> > > sets;

void dfs(int k) {
    vector<int> :: iterator it;
    cnt[k] = 1; child[k] = -1;
    for (it = con[k].begin(); it != con[k].end(); it++) {
        if (*it == p[k]) {
            continue;
        }
        lvl[*it] = lvl[k] + 1;
        p[*it] = k;
        dfs(*it);
        cnt[k] += cnt[*it];
        if (child[k] == -1 || cnt[*it] > cnt[child[k]]) {
            child[k] = *it;
        }
    }

    if (child[k] == -1) {
        Pid += 1;
        path[k] = Pid;
        paths.push_back(vector<int>(1, k));
        sets.push_back(set<pair<int, int> >());
    } else {
        path[k] = path[child[k]];
        paths[path[k]].push_back(k);
    }
}

int main()
{
    freopen("confuzie.in", "rt", stdin);
    freopen("confuzie.out", "wt", stdout);

    scanf("%d %d", &N, &M);
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x -= 1; y -= 1;
        con[x].push_back(y);
        con[y].push_back(x);
    }
    p[0] = -1;
    dfs(0);

    for (int i = 0; i < M; i++)
    {
        int type; scanf ("%d", &type);
        if (type == 0)
        {
            int nod; scanf("%d", &nod);
            nod -= 1;
            if (flipped[nod]) {
                flipped[nod] = 0;
                sets[path[nod]].erase(make_pair(lvl[nod], nod));
            } else {
                flipped[nod] = 1;
                sets[path[nod]].insert(make_pair(lvl[nod], nod));
            }
        } else if (type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            x -= 1; y -= 1;
            int rez = -2;
            for (; path[y] != path[x]; y = p[paths[path[y]].back()]) {
                if (!sets[path[y]].empty() &&
                    lvl[sets[path[y]].begin()->second] <= lvl[y]) {
                    rez = sets[path[y]].begin()->second;
                }
            }
            set<pair<int, int> > :: iterator it;
            it = sets[path[y]].upper_bound(make_pair(lvl[x] - 1, 0x3f3f3f3f));
            if (it != sets[path[y]].end() && lvl[it->second] <= lvl[y]) {
                rez = it->second;
            }

            printf("%d\n", rez + 1);
        }
    }

    return 0;
}

