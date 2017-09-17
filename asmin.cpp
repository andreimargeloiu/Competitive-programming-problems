# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 16005
using namespace std;
ifstream f("asmin.in");
ofstream g("asmin.out");
vector <int> v[NR], sol;
int i,j,n,m,x,y,minn,K;
int ap[NR], R[NR], C[NR];
int minim (int a, int b)
{
    if (a<=b) return b-a;
         else return b+(K-a);
}
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) {
            C[1]+=minim (R[k], R[v[k][i]]);
            DFS (v[k][i]);
        }
}
void DFS2 (int k, int tata)
{
    C[k]=C[tata] - minim(R[tata], R[k]) + R[k] - R[tata] + minim(R[k], R[tata]);
    minn=min(minn, C[k]);

    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS2 (v[k][i], k);
}
int main ()
{
    f>>n>>K;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i) f>>R[i];

    C[1]=R[1]; DFS (1);
    memset (ap, 0, sizeof(ap)); ap[1]=1; minn=C[1];

    for (i=0; i<v[1].size(); ++i)
        DFS2 (v[1][i], 1);

    for (i=1; i<=n; ++i) if (C[i]==minn) sol.push_back(i);

    g<<minn<<" "<<sol.size()<<"\n";
    for (i=0; i<sol.size(); ++i)
        g<<sol[i]<<" ";
    g<"\n";

    return 0;
}
