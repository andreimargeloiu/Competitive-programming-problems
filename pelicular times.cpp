#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX_N 100005
#define MAX_L 20

#define foreach(V) for(typeof (V).begin() it = (V).begin(); it != (V).end(); ++it)

int K, N, M;
int L[MAX_N << 1], H[MAX_N << 1],Lg[MAX_N << 1], First[MAX_N];
int Rmq[MAX_L][MAX_N << 2];
int u[MAX_N];

vector <int> G[MAX_N];
void dfs(int nod, int lev)
{
    H[++K] = nod; //nodul actual este adaugat in reprezentarea Euler a arborelui
    L[K] = lev; //se retine nivelul fiecarei pozitii din reprezentarea Euler a arborelui
    First[nod] = K; //se retine si prima aparitie a fiecarui nod in reprezentarea Euler a arborelui
    u[nod]=1;
    foreach(G[nod])
    {
        if(u[*it]==0)
        {
        dfs(*it, lev+1);

        H[++K] = nod;
        L[K] = lev;
        }
    }
}

void rmq()
{
    for(int i = 2; i <= K; ++i)
        Lg[i] = Lg[i >> 1] + 1;
    for(int i = 1; i <= K; ++i)
        Rmq[0][i] = i;

        for(int i = 1; (1 << i) < K; ++i)
    for(int j = 1; j <= K - (1 << i); ++j)
            {int l = 1 << (i - 1);Rmq[i][j] = Rmq[i-1][j];if(L[Rmq[i-1][j + l]] < L[Rmq[i][j]])
                    Rmq[i][j] = Rmq[i-1][j + l];
            }
}

int lca(int x, int y)
{

    int diff, l, sol, sh;
    int a = First[x], b = First[y];
if(a > b) swap(a, b);
    diff = b - a + 1;
l = Lg[diff];
    sol = Rmq[l][a];
    sh = diff - (1 << l);
    if(L[sol] > L[Rmq[l][a + sh]])
        sol = Rmq[l][a + sh];
        //if(sol==0) return -1;
    return H[sol];
}

int main()
{
    cin >> N >> M;

    for(int i = 2; i <= N; ++i)
    {
        int x,y;
        cin >> x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    rmq();

    while(M--)
    {
        int x, y, tip;
        cin>>tip;
        if(tip==1)
        {
            for(int i=0;i<=N;++i) u[i]=0;
            K=0;
            cin>>x;dfs(x, 0);
            rmq();
        }
        else
        {
            cin >> x >> y;int rez=lca(x, y);
            if(rez == x || rez == y) cout<<"-1"<<'\n';
            else cout << lca(x, y) << "\n";
        }
    }
    return 0;
}
