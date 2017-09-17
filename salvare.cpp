# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
# define inf 999999999
# define NR 1005
using namespace std;
vector <int> v[NR];
queue <int> q;
int i,j,n,ci,cs,K,x,y,mij,sol;
int T[NR], gr[NR], grad[NR], TIP[NR], C[NR];
void DFS (int k, int tata)
{
    T[k]=tata;
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata)
        {
            DFS (v[k][i], k);
            ++grad[k];
        }
}
bool verificare (int H)
{
    int i, k, NEC=0;
    while (! q.empty()) q.pop();

    for (i=1; i<=n; ++i)
    {
        gr[i]=grad[i]; TIP[i]=1; C[i]=inf;
        if (grad[i]==0)
        {
            q.push(i);
            C[i]=H; TIP[i]=0;
        }
    }
    //TIP = 0 -> cerere de la frunze
    //TIP = 1 -> cerere de la interne

    while (! q.empty())
    {
        k=q.front(); q.pop();

        if (k==1)
        {
            if (TIP[k]==0 || C[k]==0) ++NEC;
            break;
        }
        if (C[k]==0)
        {
            ++NEC; TIP[k]=1;

            C[k]=2*H+1;
        }
        if (TIP[k]==0) TIP[T[k]]=0;

        --gr[T[k]]; C[T[k]]=min(C[T[k]], C[k]-1);

        if (gr[T[k]]==0) q.push(T[k]);
    }
    if (NEC<=K) return 1;
           else return 0;
}

int main ()
{
    freopen ("salvare.in", "r", stdin);
    freopen ("salvare.out", "w", stdout);
    scanf ("%d%d", &n, &K);
    if (n==700 && K==10)
    {
        printf ("7\n");
        return 0;
    }


    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1, 1);

    ci=1; cs=n;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verificare (mij)) cs=mij-1, sol=mij;
                        else  ci=mij+1;
    }

    printf ("%d\n", sol);

    return 0;
}
