# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
# define inf 999999999
using namespace std;
struct elem
{
    int x, y, timp, i;
}E;
vector <elem> v[105];
struct elem2
{
    int k, timp;
}X;
queue <elem2> q;
int minn,i,j,n,m,x,y,A,B,T;
int p[105],c[505][105],cost[105][105];
void parcurgere ()
{
    minn=inf;
    int i,j,k,timp,TP,arrive,next,tp,var,I;
    X.k=A; X.timp=0;
    q.push(X);
    while (! q.empty())
    {
        X=q.front(); q.pop();
        k=X.k; timp=X.timp;

        if (k==B && cost[k][timp]<minn)
        {
            minn=cost[k][timp];
        }
        if (cost[k][timp]>=minn) continue;

        for (i=0; i<v[k].size(); ++i)
        {
            next=v[k][i].y;
            tp=v[k][i].timp;
            I=v[k][i].i;
            for (j=timp; j<=T; ++j)
            {
                TP=j-timp;
                if (k==A) TP=0;

                arrive=j+tp;

                if (arrive<=T)
                    if (cost[next][arrive]==0 || cost[next][arrive]>cost[k][timp]+TP*p[k]+tp*c[I][j])
                    {
                        cost[next][arrive]=cost[k][timp]+TP*p[k]+tp*c[I][j];

                        X.k=next; X.timp=arrive;
                        q.push(X);
                    }
            }
        }
    }
}
int main ()
{
    freopen ("auto2.in", "r", stdin);
    freopen ("auto2.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    scanf ("%d%d%d", &A, &B, &T);

    for (i=1; i<=n; ++i)
        scanf ("%d", &p[i]);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &E.timp); E.i=i;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);

        for (j=0; j<T; ++j)
            scanf ("%d", &c[i][j]);
    }

    parcurgere ();

    printf ("%d\n", minn);

    return 0;
}
