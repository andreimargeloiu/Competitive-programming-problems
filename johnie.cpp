# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
queue <int> q;
vector <int> v[50005],sol[200005],st;
int i,j,n,m,x,y,VV,o,vizitate,impare,R,nrsol;
int var[200005],ap[50005];
void BFS (int k)
{
    int i;
    ap[k]=1;
    q.push(k);
    while (! q.empty())
    {
        ++vizitate;
        k=q.front (); q.pop();
        if (v[k].size()%2==1) //e impar
        {
            ++impare;
            v[R].push_back(k);
            v[k].push_back(R);
        }
        for (i=0; i<v[k].size(); ++i)
        {
            if ( !ap[v[k][i]])
            {
                ap[v[k][i]]=1;
                q.push(v[k][i]);
            }
        }
    }
}
void euler (int k)
{
    int y;
    st.push_back(k);
    while (st.size())
    {
        k=st.back();
        if (v[k].size())
        {
            y=v[k].back();
            v[k].pop_back();
            st.push_back(y);
            v[y].erase(find(v[y].begin(), v[y].end(), k));
        }
        else {
                 var[++VV]=k;
                 st.pop_back();
             }
    }
}
int main ()
{
    freopen ("johnie.in", "r", stdin);
    freopen ("johnie.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    R=n+1;
    for (o=1; o<=n; ++o)
    {
        if (! ap[o])
        {
            impare=0; vizitate=0;
            v[R].clear();
            BFS (o);
            if (vizitate>1)
            {
                VV=0;
                if (impare)
                {
                    euler (R);
                    for (i=1; i<VV; ++i)
                    {
                        if (var[i]==R)
                        {
                            if (var[i+1]==R) continue;
                            ++nrsol;
                        }
                        else {
                                sol[nrsol].push_back(var[i]);
                             }
                    }
                }
                else {//nu e nevoie de R
                        ++nrsol;
                        euler (o);
                        for (i=1; i<=VV; ++i)
                            sol[nrsol].push_back(var[i]);
                     }
            }
        }
    }
    printf ("%d\n", nrsol);
    for (i=1; i<=nrsol; ++i)
    {
        printf ("%d ", sol[i].size());
        for (j=0; j<sol[i].size(); ++j)
            printf ("%d ", sol[i][j]);
        printf ("\n");
    }
    return 0;
}
