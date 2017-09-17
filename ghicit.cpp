# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 60000
using namespace std;
ifstream f("ghicit.in");
ofstream g("ghicit.out");
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

int i,j,n,m,sol,VV;
int P[18][3*NR], lg[NR];
char s[NR];

void logaritmi () {
    for (i=2; i<=n; ++i)
        lg[i]=lg[i/2] + 1;
}
int LCP (int X, int Y) {
    int sol=0;

    for (int i=lg[n]; i>=0 && X<=n && Y<=n; --i)
        if (P[i][X]==P[i][Y]) {
            X+=(1<<i);
            Y+=(1<<i);
            sol+=(1<<i);
        }

    return sol;
}
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1); logaritmi ();
    for (i=1; i<=n; ++i) {
        P[0][i]=s[i]-'a'+1;
        s[i+n]='$';
        s[i+2*n]='$';
    }

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

    for (i=1; i<=n; ++i)
        sol=sol + (n-ind[i].i+1 - LCP(ind[i-1].i, ind[i].i));

    g<<sol<<"\n";

    return 0;
}
