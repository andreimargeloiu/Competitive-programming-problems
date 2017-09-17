# include <fstream>
# include <algorithm>
# include <vector>
# define NR 150
using namespace std;
ifstream f("revolutie.in");
ofstream g("revolutie.out");
vector <int> v[NR];
int i,j,n,m,x,y,ok,VV;
int M1[NR], M2[NR], ap[NR], row[NR];

int cuplaj (int k) {
    if (ap[k]==VV) return 0;
    ap[k]=VV;
    for (int i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]] || (M2[v[k][i]] && cuplaj(M2[v[k][i]]))) {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    return 0;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            f>>x;
            if (x)v[i].push_back(j);
        }
    }

    ok=1;
    while (ok) {
        ok=0; ++VV;
        for (i=1; i<=n; ++i)
            if (! M1[i]) ok+=cuplaj(i);
    }

    for (i=1; i<=n; ++i)
        if (! M1[i]) {g<<"-1\n"; return 0;}

    g<<n<<"\n";
    for (i=1; i<=n; ++i) {
        if (M2[i]!=i) {
            g<<"C "<<i<<" "<<M1[i]<<"\n";
            M2[M1[i]]=M2[i];
            M1[M2[i]]=M1[i];
        }
        else g<<"C "<<i<<" "<<M2[i]<<"\n";
    }



    return 0;
}
