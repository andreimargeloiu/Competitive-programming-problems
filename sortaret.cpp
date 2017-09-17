# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 50005
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
queue <int> q;
vector <int> v[NR];
int i,j,x,y,n,m;
int grad[NR];
void sortaret () {
    int i,k;
    while (! q.empty ()) {
        k=q.front(); q.pop();
        g<<k<<" ";
        for (auto &x: v[k]) {
            --grad[x];
            if (grad[x]==0) q.push(x);
        }
    }
}
int main ()
{
   f>>n>>m;
   for (i=1; i<=m; ++i) {
       f>>x>>y;
       v[x].push_back(y);
       ++grad[y];
   }
   for (i=1; i<=n; ++i)
        if (grad[i]==0) q.push(i);
   sortaret ();


    return 0;
}
