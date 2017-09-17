# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("circulatie.in");
ofstream g("circulatie.out");
vector <int> v[NR];
struct elem {
    int x, y;
}M[3*NR];
int i,j,n,m,x,y, cuplate;
int M1[NR], M2[NR], ap[NR];
bool match (int k)
{
    if (ap[k]) return 0;
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i) {
        if (! M2[v[k][i]] || match(M2[v[k][i]])) {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    }
    return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=3*n; ++i) {
        f>>M[i].x>>M[i].y;
        v[M[i].x].push_back(M[i].y);
    }

    cuplate=1;
    while (cuplate) {
        memset (ap, 0, sizeof(ap)); cuplate=0;
        for (i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=match(i);
    }

    for (i=1; i<=3*n; ++i) {
        x=M[i].x; y=M[i].y; g<<x<<" "<<y<<" ";
        if (M1[x]==y) g<<"-2\n";
                 else g<<"1\n";
    }



    return 0;
}
