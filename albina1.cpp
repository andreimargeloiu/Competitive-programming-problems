# include <fstream>
# include <cstring>
# include <algorithm>
# define inf 999999999
# define NR 1005
using namespace std;
ifstream f("albine1.in");
ofstream g("albine1.out");
int i,j,n,m,x,y,ci,cs,mij,sol,minn,minim,nr0;
int suma[NR][NR], cost[NR][NR], a[NR][NR], MAX[NR];
bool start[NR][NR];
char s[10000];
void preprocesare ()
{
    for (int j=1; j<=m; ++j)
        for (int i=sol; i<=n; ++i)
            if (suma[i][j] - suma[i-sol][j]==sol-1) start[i-sol+1][j]=1;
}
int main ()
{
    f>>n>>m; f.get();
    for (i=1; i<=n; ++i) {
        f.getline (s+1, 5000);
        for (j=1; j<=m; ++j) {
            suma[i][j]=suma[i-1][j] + (s[j*2-1] - '0');
            a[i][j]=(s[j*2-1] - '0');
        }
    }

    sol=inf;
    for (j=1; j<=m; ++j) {
        ci=1; cs=0; nr0=0;
        while (cs<n) {
            while (!nr0 && cs<=n) { //gasim primul nr0
                if (a[cs+1][j]==0) {nr0=1; ++cs;}
                else ++cs;
            }
            while (a[cs+1][j]==1) ++cs;

            if (nr0) MAX[j]=max(MAX[j], cs-ci+1);

            while (nr0) { // sterg nr0
                if (a[ci][j]==0) nr0=0, ++ci;
                else ++ci;
            }
        }
    }
    for (i=1; i<=m; ++i)
        sol=min(sol, MAX[i]);

    preprocesare ();

    // incepem dinamica
    for (j=2; j<=m; ++j) {
        minim=inf;
        for (i=1; i<=n; ++i) {
            if (start[i][j-1]) minim=min(minim, cost[i][j-1]);

            cost[i][j]=minim;

            ++minim;
        }

        minim=inf;
        for (i=n; i>=1; --i) {
            if (start[i][j-1]) minim=min(minim, cost[i][j-1]);

            cost[i][j]=min(cost[i][j], minim);

            ++minim;
        }
    }
    minn=inf;
    for (i=1; i<=n; ++i)
    {
        //printf ("%d ", cost[i][m]);
        if (start[i][m]) minn=min(minn, cost[i][m]);
    }

    g<<sol<<" "<<minn<<"\n";


    return 0;
}
