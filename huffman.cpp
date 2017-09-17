# include <fstream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# define inf 1LL<<60
# define NR 1000005
using namespace std;
//ifstream f("huffman.in");
ofstream g("huffman.out");
struct elem {
    long long val;
    int fiu[2];
}nod[2*NR+5];

int i,j,n,m,x,y,nrsol,ci,cs,copil,V,VV,o;
int a[NR], L[NR], usedind[NR];
long long minn, SOL, val[NR], usednr[NR];
char s[105];

void solve () {
    ci=1; cs=0; VV=1;
    usednr[ci]=inf;

    for (o=n+1; o<=2*n-1; ++o) {
        for (j=0; j<2; ++j) {
            if (VV<=n && (a[VV] < usednr[ci] || (ci>cs)))
                 minn=a[VV], copil=VV, VV++;
            else minn=usednr[ci], copil=usedind[ci], ci++;

            nod[o].fiu[j]=copil;
            nod[o].val+=minn;
        }
        ++cs;
        usednr[cs]=nod[o].val; usedind[cs]=o;
    }
}
void make_numere (int V, long long nr, int l) {
    if (nod[V].fiu[0]) {
        make_numere (nod[V].fiu[0], nr*2, l+1);
        make_numere (nod[V].fiu[1], nr*2+1, l+1);
    }
    else {
        L[V]=l; val[V]=nr;
        SOL+=(1LL*a[V]*l);
    }
}
void read (int &x) {
    //f.getline(s, 105);
    x=0;

    int i=0;
    while (s[i]!='\0') {
        x=x*10 + s[i]-'0';
        ++i;
    }
}
int main ()
{
    freopen("huffman.in","r",stdin);
   // freopen("huffman.out","w",stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &a[i]);
        nod[i].val=a[i];
    }
    solve ();
    make_numere (2*n-1, 0, 0);

    g<<SOL<<"\n";
    for (i=1; i<=n; ++i)
        g<<L[i]<<" "<<val[i]<<"\n";

    return 0;
}
