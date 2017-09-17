# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("repeat.in");
ofstream g("repeat.out");
int i,j,n,m,x,y,K,Pmin,maxx,nr;
int a[NR];
char s[NR];
bool cmp (int x, int y)
{
    for (int i=0; i<K; ++i)
        if (s[x+i]>s[y+i]) return 0;
        else if (s[x+i]<s[y+i]) return 1;

    if (x>y) return 0;
        else return 1;
}
bool egal (int x, int y)
{
    for (int i=0; i<K; ++i)
        if (s[x+i]!=s[y+i]) return 0;

    return 1;
}
int main ()
{
    f.getline (s+1, NR); n=strlen(s+1);
    f>>K;
    n=n-K+1;
    for (i=1; i<=n; ++i)
        a[i]=i;

    sort (a+1, a+n+1, cmp);

    maxx=1; Pmin=a[1]; nr=1;
    for (i=2; i<=n; ++i) {
        if (egal(a[i], a[i-1])) ++nr;
        else {
                nr=1;
             }
        if (nr>maxx) maxx=nr, Pmin=a[i-nr+1];
        else if (nr==maxx) Pmin=min(Pmin, a[i-nr+1]);
    }

    g<<maxx<<"\n"<<Pmin<<"\n";


    return 0;
}
