# include <iostream>
# include <algorithm>
using namespace std;
int i,j,n;
long long minn;
struct elem
{
    long long a,b;
}v[5005];
bool cmp (elem x, elem y)
{
    if (x.a==y.a) return x.b<y.b;
    return x.a<y.a;
}
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>v[i].a>>v[i].b;
    sort (v+1, v+n+1, cmp);
    minn=v[1].b;
    for (i=2; i<=n; ++i)
    {
        if (v[i].b>=minn) minn=v[i].b;
           else minn=v[i].a;
    }
    cout<<minn<<"\n";
    return 0;
}
