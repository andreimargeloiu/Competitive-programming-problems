# include <fstream>
# include <algorithm>
# define NR 2000005
# define lb 25
using namespace std;
ifstream f("dinti.in");
ofstream g("dinti.out");
int i,j,n,m,x,y,L,nr;
bool ap[NR];
char s[NR], B[lb];
void dinamica ()
{
    int cs=(1<<L)-1;
    for (int i=cs; i>=1; --i) {
        if (ap[i])
        {
            for (j=0; j<L; ++j)
                if (i & (1<<j)) ap[i - (1<<j)]=1;
        }
    }
}
int main ()
{
    f>>n>>m>>L; f.get();
    f.getline (s+1, NR);

    for (i=1; i<=L; ++i)
        nr=nr*2 + (1 - (s[i]-'0'));
    ap[nr]=1;

    for (i=L+1; i<=n; ++i) {
        nr=nr-(1<<(L-1)) * (1 - (s[i-L]-'0'));
        nr=nr*2 + 1 - (s[i]-'0');
        ap[nr]=1;
    }

    dinamica ();

    for (i=1; i<=m; ++i) {
        f.getline (B+1, lb); nr=0;
        for (j=1; j<=L; ++j)
            nr=nr*2 + B[j]-'0';

        g<<ap[nr]<<"\n";
    }

    return 0;
}
