# include <fstream>
//# include <iostream>
# include <algorithm>
# include <vector>
# define NR 105
# define MOD 1000000000
using namespace std;
ifstream cin("parovi.in");
ofstream cout("parovi.out");
vector <int> P[NR];
int i,j,n,m,x,y,VV,M,ci;
int a[NR], put[1005];
struct elem {
    int x, y;
}muchie[NR];
int prim (int a, int b) {
    int R=0;
    while (b!=0) {
        R=a%b;
        a=b;
        b=R;
    }
    if (a==1) return 1;
         else return 0;
}
void puteri () {
    put[0]=1;
    for (int i=1; i<=1000; ++i)
        put[i]=(1LL*put[i-1]*2)%MOD;
}
int nrmuchii (int ci, int cs) {
    int sol=0;
    for (int i=1; i<=M; ++i)
        if (ci<=muchie[i].x && muchie[i].y<=cs) ++sol;
    return sol;
}
int main() {
    cin>>n; puteri ();

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
            if (prim(i, j)) {
                P[j].push_back(i);
                muchie[++M].x=i; muchie[M].y=j;
            }

    a[1]=1;
    for (i=2; i<=n; ++i) {
        for (j=0; j<P[i].size(); ++j) {
            ci=P[i][j];
            a[i]=(1LL * a[i] + 1LL * a[ci] * put[nrmuchii(ci, i)-1]%MOD)%MOD;
        }
    }
    cout<<a[n]<<"\n";


    return 0;
}
