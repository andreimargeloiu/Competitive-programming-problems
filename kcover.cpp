# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
# define MAX 2000000
using namespace std;
ifstream f("kcover.in");
ofstream g("kcover.out");
int i,j,n,m,x,y,T,K,nr,ok,l,mij,V;
unsigned int D[NR], var[NR], dist;
int a[NR];
bool cmp (unsigned int x, unsigned int y)
{
    if (x<=y) return 0;
        else  return 1;
}
char s[MAX];
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t)
    {
        f>>n>>K; f.get(); f.getline(s+1, MAX);

        l=strlen(s+1); i=1; ok=1; nr=0; int o=0;
        while (i<=l)
        {
            if (s[i]=='-') ok=-1, ++i;
            while (s[i]!=' ' && i<=l) nr=nr*10+(s[i]-'0'), ++i;

            ++i;
            a[++o]=nr*ok; ok=1; nr=0;
        }

        sort (a+1, a+n+1);

        int VV=0; V=0;
        for (i=2; i<=n; ++i)
            D[++VV]=D[0]+a[i]-a[i-1];

        dist=1LL*a[n]-a[1];
        nth_element (D+1, D+VV-K+1, D+VV+1);
        mij=D[VV-K+1];

        memset (var, 0, sizeof(var));

        for (i=1; i<=VV; ++i)
            if (D[i]>mij) var[++V]=D[i];

        for (i=1; i<=VV; ++i)
            if (D[i]==mij && V<K) var[++V]=D[i];

        for (i=1; i<K; ++i)
            dist-=var[i];

        g<<dist<<"\n";
    }

    return 0;
}
