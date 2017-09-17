# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 1005
using namespace std;
ifstream f("pandora.in");
ofstream g("pandora.out");
struct elem {
    int l, c;
}E;
queue <elem> q;
int i,j,n,m,K,nrzone,x,y,c,tip;
short a[NR][NR], dr[NR][NR], jos[NR][NR], P[NR][NR];
int munte[NR][NR];
bool luat[200005];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
void FILL (int l, int c) {
    int i,lv,cv;

    munte[l][c]=nrzone;
    E.l=l; E.c=c;
    q.push(E);
    while (! q.empty()) {
        E=q.front(); q.pop();
        l=E.l; c=E.c;

        for (i=0; i<4; ++i) {
            lv=l + dx[i];
            cv=c + dy[i];
            if (a[lv][cv] && ! munte[lv][cv]) {
                munte[lv][cv]=nrzone;

                E.l=lv; E.c=cv;
                q.push(E);
            }
        }
    }
}
int main ()
{
    f>>tip;
    f>>n>>K>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y>>c;
        a[x][y]=c;
    }

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            if (a[i][j] && ! munte[i][j]) {// o zona noua
                ++nrzone;
                FILL (i, j);
            }

    if (tip==1) { //doar prima cerinta
        g<<nrzone<<"\n";
        return 0;
    }

    //dr[i][j] - numarul de elemente egale cu a[i][j] la dreapta
    //jos[i][j] - numarul de elemente egale cu a[i][j] in jos

    for (i=n; i>=1; --i)
        for (j=n; j>=1; --j)
            if (a[i][j]) { //daca e munte
            //daca este la fel ca elementul din dreapta
            if (a[i][j] == a[i][j+1]) dr[i][j]=dr[i][j+1] + 1;
                                 else dr[i][j]=1;

            //daca este la fel ca elementul de sub el
            if (a[i][j] == a[i+1][j]) jos[i][j]=jos[i+1][j] + 1;
                                 else jos[i][j]=1;

            //daca pot avea un patrat din acest punct
            if (a[i][j]==a[i][j+1] && a[i][j]==a[i+1][j] && a[i][j]==a[i+1][j+1])
                P[i][j] = 1 + min (P[i+1][j+1], min(jos[i+1][j], dr[i][j+1]));
            else P[i][j]=1;
        }

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            // daca este munte, si inca nu am gasit o zona de aterizare de pe el
            // iar acest punct e un posibil loc de aterizare
            if (a[i][j] && !luat[munte[i][j]] && P[i+1][j+1]>=K-2) {
                //daca colturile respecta conditia
                if (  a[i+1][j+1]>a[i][j+K-1]     && a[i+1][j+1]>a[i+K-1][j]
                   && a[i+1][j+1]>a[i+K-1][j+K-1] && a[i+1][j+1]>a[i][j]) {
                    if (jos[i+1][j]==K-2 && jos[i+1][j+K-1]==K-2 && dr[i][j+1]==K-2 && dr[i+K-1][j+1]==K-2) {
                        g<<i<<" "<<j<<"\n";
                        luat[munte[i][j]]=1;
                    }
                }
            }


    return 0;
}
