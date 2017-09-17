# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
vector <int> v[102];
queue <int> q;
ifstream f("prieteni3.in");
ofstream g("prieteni3.out");
int ap[105],sol[105];
int i,j,A,n,k,VV,nr,x;
void bfs ()
{
    int x,i;
    q.push(A);
    while (! q.empty ())
    {
        x=q.front (); q.pop ();
        if (ap[x]==k) sol[++VV]=x;

        for (i=0; i<v[x].size(); ++i)
        {
            if (ap[v[x][i]]==0 && v[x][i]!=A)
            {
                ap[v[x][i]]=ap[x]+1;
                q.push(v[x][i]);
            }
        }
    }
}
int main ()
{
    f>>n>>A>>k;
    for (i=1; i<=n; ++i)
    {
        f>>nr;
        for (j=1; j<=nr; ++j)
        {
            f>>x;
            v[i].push_back(x);
        }
    }
    bfs ();
    g<<VV<<"\n";
    sort (sol+1,sol+VV+1);
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
