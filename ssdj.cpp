# include <bits/stdc++.h>
# define NR 1005
# define INF 999999999
using namespace std;
ifstream f("ssdj.in");
ofstream g("ssdj.out");
int i,j,n,var,m,J,ant,mx,minn,sol,VV;
int H[NR][NR], st[NR], poz[NR];
char mat[NR][NR];
int main ()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i)
        f.getline(mat[i]+1, NR);
    for (mx='b'; mx<='z'; ++mx) {
        for (i=1; i<=n; ++i)
            for (j=1; j<=n; ++j)
                if (mat[i][j]>=mx) H[i][j]=0;
                             else  H[i][j]=H[i-1][j] + 1;

        for (int i=1; i<=n; ++i) {
            VV=0;
            for (int j=1; j<=n; ++j) {
                if (mat[i][j]<mx) {
                    while (VV>0 && st[VV]>=H[i][j])
                        --VV;
                    st[++VV]=H[i][j];
                    poz[VV]=j;
                } else {
                    int hh=H[i-1][j]+1;
                    while (VV>0 && st[VV]>=hh)
                        --VV;
                    for(int k=1; k<=VV; ++k)
                        if(mat[i][j]==mx || mat[i-st[k]][poz[k]]==mx)
                            ++sol;
                    VV=0;
                }
            }
        }
    }
    g<<sol<<"\n";

    return 0;
}
