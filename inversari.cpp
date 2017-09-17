# include <bits/stdc++.h>
# define NR 5005
using namespace std;
ifstream f("inversari.in");
ofstream g("inversari.out");
struct elem {
    int cs, ind;
    int sol;
}E;
vector <elem> v[NR];
int i,j,n,m,x,y,act,nou,l,nrQ,ci,cs;
int a[NR], big[2][NR];
int dp[2][NR], sol[100005];

int main ()
{
    f>>n>>nrQ;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=nrQ; ++i) {
        f>>ci>>cs;
        E.cs=cs; E.ind=i;
        v[(cs-ci+1)].push_back(E);
    }
    // dp[i][j] - numarul de inversiuni ale secventei de lungime i ce se termian pe pozitia j
    // big[i][j] - numarul de numere mai mari decat a[j], dintre primele i de la stanga

    act=0; nou=1;
    for (l=1; l<=n; ++l) {
        for (j=l; j<=n; ++j) {
            big[nou][j] = big[act][j] + (a[j-l+1] > a[j]);

            dp[nou][j]  = dp[act][j-1] + big[nou][j];
        }
        for (auto &x: v[l])
            sol[x.ind]=dp[nou][x.cs];

        swap(act, nou);
    }

    for (i=1; i<=nrQ; ++i)
        g<<sol[i]<<"\n";
    return 0;
}
