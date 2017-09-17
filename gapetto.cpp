# include <algorithm>
# include <iostream>
# include <fstream>
# define NR 25
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,x,y;
int NU[NR][NR];
int a[NR], sol;
int main ()
{
    cin>>n>>m;
    for (i=1; i<=m; ++i) {
        cin>>x>>y;
        if (x>y) swap(x,y);

        NU[y][x]=1;
    }

    sol=1;
    // a[i] - numarul de pizze care se termian cu ingredientul i
    for (i=1; i<=n; ++i) {
        a[i]=1;
        for (j=1; j<i; ++j)
            if (NU[i][j]==0) a[i]+=a[j];
        sol+=a[i];
    }

    cout<<sol<<"\n";

    return 0;
}
