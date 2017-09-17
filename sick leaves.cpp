# include <bits/stdc++.h>
# define NR 1005
using namespace std;
//ifstream f("sick.in");
//ofstream g("sick.out");
vector <int> v[NR];
int i,j,n,m,x,y,minn,D,sol;
int minim[NR], sick[NR], ap[NR];
int main ()
{
    cin>>D>>n>>m;
    for (i=1; i<=n; ++i) {
        cin>>sick[i];
        ap[sick[i]]=1;
    }
    sort (sick+1, sick+n+1);
    for (i=1; i<=D; ++i)
        minim[i]=9999;
    for (i=1; i<=m; ++i) {
        cin>>x>>y; if (x>y) swap(x, y);

        v[y].push_back(x);
    }
    sol=9999;
    for (i=1; i<=D; ++i) {
        minn=564564;
        if (! ap[i]) minn=min(minn, minim[i-1]);
        for (auto &x: v[i])
            minn=min(minn, minim[x-1]+1);

        minim[i]=minn;
        if (i>=sick[n]) sol=min(sol, minim[i]);
    }
    cout<<sol<<"\n";

    return 0;
}
