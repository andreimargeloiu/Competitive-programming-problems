#include<fstream>
using namespace std;
ifstream fin("semipal.in");
ofstream fout("semipal.out");
int t,n,VV;
long long k;
char sol[1005];
void semipal(long long nr, int t)
{
    if (t)
    {
        semipal(nr>>1,t-1);
        sol[++VV]=(char)((nr&1)+'a');
    }
}
int main()
{
    int i;
    fin>>t;
    for (i=1;i<=t;++i)
    {
        fin>>n>>k; VV=0;
        if (k>(1LL<<(n-2)))
        {
            sol[++VV]='b';
            semipal(k-(1LL<<(n-2))-1,n-2);
            sol[++VV]='b';
        }
        else
        {
            sol[++VV]='a';
            semipal(k-1,n-2);
            sol[++VV]='a';
        }
    }
    return 0;
}
