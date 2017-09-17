# include <fstream>
# include <algorithm>
# include <cstring>
# include <queue>
# define mp make_pair
# define NR 2010
using namespace std;
ifstream f("gates.in");
ofstream g("gates.out");
queue <pair <int, int> > q;
int i,j,n,m,X,Y,conexe;
int colt[NR][NR][4], ap[NR][NR];
char S[NR];
bool bun (int lx, int ly) {
    if (0<=lx && lx<=2005 && 0<=ly && ly<=2005) return 1;
                                           else return 0;
}
void lee () {
    int i, lv, cv, x ,y;
    pair <int, int> K;
    while (! q.empty()) {
        K=q.front(); q.pop(); x=K.first; y=K.second;
        ap[x][y]=1;

        //merg la nord
        lv=x-1; cv=y;
        if (bun (lv, cv) && !ap[lv][cv]) {
            if (! colt[x-1][y-1][1] && ! colt[x-1][y][3]) {
                K.first=lv; K.second=cv;
                ap[lv][cv]=1;
                q.push(K);
            }
        }

        //merg la est
        lv=x; cv=y+1;
        if (bun (lv, cv) && !ap[lv][cv]) {
            if (! colt[x-1][y][2] && ! colt[x][y][0]) {
                K.first=lv; K.second=cv;
                ap[lv][cv]=1;
                q.push(K);
            }
        }

        //merg la sud
        lv=x+1; cv=y;
        if (bun (lv, cv) && !ap[lv][cv]) {
            if (! colt[x][y-1][1] && ! colt[x][y][3]) {
                K.first=lv; K.second=cv;
                ap[lv][cv]=1;
                q.push(K);
            }
        }

        //merg la west
        lv=x; cv=y-1;
        if (bun (lv, cv) && !ap[lv][cv]) {
            if (! colt[x-1][y-1][2] && ! colt[x][y-1][0]) {
                K.first=lv; K.second=cv;
                ap[lv][cv]=1;
                q.push(K);
            }
        }
    }
}
int main ()
{
    f>>n; f.get();
    f.getline (S+1, NR);

    X=1001; Y=1001;
    for (i=1; i<=n; ++i) {
        switch (S[i]) {
            case 'N': {colt[X][Y][0]=1; --X; break;}
            case 'E': {colt[X][Y][1]=1; ++Y; break;}
            case 'S': {colt[X][Y][2]=1; ++X; break;}
            case 'W': {colt[X][Y][3]=1; --Y; break;}
        }
    }

    for (i=0; i<=2005; ++i)
        for (j=0; j<=2005; ++j) {
            if (! ap[i][j]) {
                ++conexe;

                q.push(mp(i, j));
                lee ();
            }
        }
    g<<conexe-1<<"\n";

    return 0;
}
