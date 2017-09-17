# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 1005
using namespace std;
vector <int> v[NR];
queue <int> q;
ifstream f("chei.in");
ofstream g("chei.out");
int i,j,n,S;
int luat[NR], neluat[NR], in[NR], tata[NR], cost[NR];
void sortaret ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();

        --in[tata[k]];
        if (in[tata[k]]==0 && tata[k]!=0) q.push(tata[k]);

        //luam
        luat[k]=cost[k];
        for (i=0; i<v[k].size(); ++i)
            luat[k]+=neluat[v[k][i]];

        //neluat
        for (i=0; i<v[k].size(); ++i)
            neluat[k]+=max(luat[v[k][i]], neluat[v[k][i]]);
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>tata[i];
        if (tata[i]==0) S=i;
        else
        {
            v[tata[i]].push_back(i);
            ++in[tata[i]];
        }
    }
    for (i=1; i<=n; ++i)
        f>>cost[i];

    for (i=1; i<=n; ++i)
        if (in[i]==0) q.push(i);

    sortaret();

    g<<luat[S]<<"\n";


    return 0;
}
