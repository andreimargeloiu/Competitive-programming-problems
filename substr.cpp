# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 20000
using namespace std;
ifstream f("substr.in");
ofstream g("substr.out");
struct elem {
    int nr1, nr2, i;
}var[NR];
bool cmp (elem x, elem y) {
    if (x.nr1 > y.nr1) return 0;
        else if (x.nr1==y.nr1 && x.nr2 >= y.nr2) return 0;
            else return 1;
}

struct elem2 {
    int i, poz;
}ind[NR];
bool cmp2 (elem2 x, elem2 y) {
     if (x.poz >= y.poz) return 0;
                    else return 1;
}

int i,j,n,m,x,y,K,sol,VV;
int lg[4*NR], P[20][4*NR];
char s[4*NR];

int lca (int x, int y) {
    int sol=0;
    x=ind[x].i; y=ind[y].i;

    for (int i=lg[n]; i>=0 && x<=n && y<=n; --i) {
        if (P[i][x]==P[i][y]) {
            x+=(1<<i);
            y+=(1<<i);
            sol+=(1<<i);
        }
    }
    return sol;
}
void logaritmi () {
    for (int i=2; i<=n; ++i)
        lg[i]=lg[i/2]+1;
}
int main ()
{
    f>>n>>K; f.get();
    f.getline(s+1, NR);
    while (strlen(s+1)==0) f.getline(s+1, NR);
    for (i=1; i<=n; ++i) {
        P[0][i]=s[i];
        s[i+n]='$';
        s[i+2*n]='$';
    }
    logaritmi ();

    for (i=1; i<=lg[n]+1; ++i) {
        for (j=1; j<=n; ++j) {
            var[j].nr1=P[i-1][j];
            var[j].nr2=P[i-1][j+(1<<(i-1))];
            var[j].i=j;
        }
        sort (var+1, var+n+1, cmp);

        VV=0;
        for (j=1; j<=n; ++j) {
            if (var[j].nr1!=var[j-1].nr1 || var[j].nr2!=var[j-1].nr2)
                ++VV;

            P[i][var[j].i]=VV;
        }
    }
    for (i=1; i<=n; ++i)
        ind[i].i=i, ind[i].poz=P[lg[n]+1][i];

    sort (ind+1, ind+n+1, cmp2);

    for (i=1; i<=n-K+1; ++i)
        sol=max(sol, lca(i, i+K-1));
    g<<sol<<"\n";


    return 0;
}
