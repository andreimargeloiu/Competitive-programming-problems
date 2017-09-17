# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("sport.in");
ofstream g("sport.out");
vector <int> v[10005];
int i,j,n,minn,MINN,VV,var;
int a[1005],b[1005],poz[10005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i]; b[i]=a[i];
        poz[a[i]]=i;
    }
    sort(b+1,b+n+1);
    for (i=1; i<n; ++i)
        v[b[i]].push_back(b[i+1]);
    MINN=1005;
    for (i=1; i<=n; ++i)
    {
        minn=1; VV=a[i];
        while (v[VV].size())
        {
            if (poz[v[VV][0]]>poz[VV]) {VV=v[VV][0]; ++minn;}
                else break;
        }
        if (n-minn<MINN) MINN=n-minn;
    }
    g<<MINN<<"\n";
    return 0;
}
