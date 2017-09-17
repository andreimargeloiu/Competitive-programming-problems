# include <fstream>
# include <iostream>
# include <algorithm>
# define NR 100005
# define inf 999999
# define r 300
using namespace std;
int i,j,n,m,k,v1,v2,vdif,I,dif,VV,o,t,minn,x;
int a[10000];
int main ()
{
    cin>>n>>t>>minn;
    if (t<minn) {cout<<"-1\n"; return 0;}

    //citesc primul numar
    cin>>x; x+=r;
    for (i=x-1; i>=x-minn; --i)
    {
        ++VV;
        for (j=i+1; j<=i+t; ++j)
            ++a[j];
    }
    for (o=2; o<=n; ++o)
    {
        cin>>x; x+=r;
        if (a[x]<minn)//daca nu sunt suficiente aprinse
        {
            dif=minn-a[x];
            for (i=x-1; i>=x-dif; --i)
            {
                ++VV;
                for (j=i+1; j<=i+t; ++j)
                    ++a[j];
            }
        }
    }
    cout<<VV<<"\n";

    return 0;
}
