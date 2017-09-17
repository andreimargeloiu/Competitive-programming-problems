# include <fstream>
# include <algorithm>
# include <cstring>
# include <bitset>
# define mil 1000005
using namespace std;
ifstream f("rocker.in");
ofstream g("rocker.out");
int n,m,maxx,VV1,VV2,k,l,put,x,Q,nr;
char s[mil];
bitset <mil> ap;
struct elem
{
    int nr,i;
}a[mil];
bool cmp (elem x, elem y)
{
    if (x.nr>=y.nr) return 0;
        else return 1;
}
int main ()
{
    int i,j,nr=0;
    f>>n>>k; f.get();
    f.getline (s+1, mil); l=strlen(s+1);
    put=1;
    for (i=1; i<=k; ++i)
    {
        if (s[i]=='E') x=0;
            else x=1;
        ap[i]=x;

        nr=nr*2+x;
        put=put*2;
    }
    a[++Q].nr=nr; a[Q].i=1; put/=2;
    for (i=k+1; i<=n; ++i)
    {
        if (s[i]=='E') x=0;
            else x=1;
        ap[i]=x;

        nr=(nr-put*ap[i-k])*2+x;
        a[++Q].nr=nr; a[Q].i=i-k+1;
    }
    sort (a+1, a+Q+1, cmp);
    for (i=1; i<n-k+1; ++i)
    {
        maxx=0; VV1=a[i].i; VV2=a[i+1].i;
        for (j=0; j<k; ++j)
            if (ap[VV1+j]==ap[VV2+j]) ++maxx;
                else break;
        g<<maxx<<"\n";
    }


    return 0;
}
