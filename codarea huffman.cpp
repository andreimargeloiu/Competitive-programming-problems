# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("huffman.in");
ofstream g("huffman.out");
struct elem {
    int fiu[2];
    long long val;
}nod[2*NR];
struct folosit {
    int ind;
    long long val;
}used[NR];
int i,j,n,m,VV;
int len[NR], a[NR];
long long suma, sol[NR];

void rezolva () {
    int ci=1, cs=0, ind;
    long long minn;
    for (int i=n+1; i<=2*n-1; ++i) {
        for (j=0; j<2; ++j) {//cei foi fii
            if (VV<n && (ci>cs || a[VV+1] < used[ci].val))
                  ++VV, minn=a[VV], ind=VV;
            else  minn=used[ci].val, ind=used[ci].ind, ++ci;

            nod[i].fiu[j]=ind;
            nod[i].val+=minn;
        }
        ++cs;
        used[cs].val=nod[i].val;
        used[cs].ind=i;
    }
}
void make_code (int node, long long nr, int L) {
  // g<<tata<<" "<<node<<"\n";
    if (nod[node].fiu[0]!=0) {//daca are fii
        make_code(nod[node].fiu[0], 2*nr, L+1);
        make_code(nod[node].fiu[1], 2*nr+1, L+1);
    } else {
        suma=suma + 1LL * a[node] * L;
        sol[node]=nr - (1LL<<L); len[node]=L;
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        nod[i].val=a[i];
    }
    rezolva ();
    make_code (2*n-1, 1, 0);

    g<<suma<<"\n";
    for (i=1; i<=n; ++i)
        g<<len[i]<<" "<<sol[i]<<"\n";

    return 0;
}
