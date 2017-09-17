# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 20005
# define sigma 26
# define MOD 666013
using namespace std;
ifstream f("criptare2.in");
ofstream g("criptare2.out");
vector <int> H[MOD+1];
int i,j,n,m,x,y,l,cod,ok;
int mat[NR][sigma+2], nr[30];
char s[40];
void etalonare (char s[], int l) {
    for (int i=1; i<=l; ++i)
        s[i]=s[i]-'a'+1;
}
bool cmp (int x, int y) {
    if (x<=y) return 0;
         else return 1;
}
int make_code (int mat[]) {
    int i,rez=1;
    for (i=1; i<=sigma; ++i) {
        if (mat[i]==0) break;

        rez=(1LL*rez*mat[i])%MOD;
    }

    return rez;
}
bool egal (int nr[], int k) {
    int i;
    for (i=1; i<=sigma; ++i) {
        if (mat[k][i]==0) break;
        if (nr[i]!=mat[k][i]) return 0;
    }

    return 1;
}
int main ()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i) {
        f>>(s+1); f.get();
        //face hash-ul
        l=strlen(s+1); etalonare (s, l);

        memset (nr, 0, sizeof(nr));
        for (j=1; j<=l; ++j) // fiecare litera
            nr[s[j]]+=(1<<j);

        sort (nr+1, nr+sigma+1, cmp);
        for (j=1; j<=sigma; ++j)
            mat[i][j]=nr[j];

        H[make_code (mat[i])].push_back(i);
    }
    //M
    f>>m; f.get();
    for (i=1; i<=m; ++i) {
        f>>(s+1); f.get();
        //face hash-ul
        l=strlen(s+1); etalonare (s, l);

        memset (nr, 0, sizeof(nr));
        for (j=1; j<=l; ++j) // fiecare litera
            nr[s[j]]+=(1<<j);

        sort (nr+1, nr+sigma+1, cmp);
        cod=make_code (nr);
        ok=0;
        for (j=0; j<H[cod].size() && !ok; ++j)
            if (egal (nr, H[cod][j])) ok=1;

        g<<ok<<"\n";
    }

    return 0;
}
