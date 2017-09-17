# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 1005
# define INF 999999999
# define M 50000
using namespace std;
ifstream f("sobo.in");
ofstream g("sobo.out");
int i,j,n,m,x,y,L;
int v0[NR], v1[NR], cost[NR], minn[M];
char s[20][NR];
int main ()
{
    f>>n>>L; f.get();
    for (i=0; i<n; ++i) {
        f.getline (s[i], NR);
        // il transform in numar
    }
    for (i=0; i<L; ++i)
        f>>cost[i];

    // v[i] - numerele care ai acelasi bit pe pozitia i
    for (i=0; i<L; ++i) { //fiecare bit
        for (j=0; j<n; ++j) {
            if (s[j][i]=='0') v0[i]+=(1<<j);
                        else  v1[i]+=(1<<j);
        }
    }

    //init
    for (j=1; j<=(1<<n)-1; ++j) //fiecare stare
        minn[j]=INF;
    for (j=0; j<n; ++j)
        minn[1<<j]=0;

    //dinamica
    for (j=1; j<=(1<<n)-1; ++j) {//fiecare stare
        for (i=0; i<L; ++i) {//fiecare bit
            if ((v0[i] & j) && (v1[i] & j)) {//daca se imparte multimea in doua
                minn[j]=min(minn[j], max(minn[v0[i] & j], minn[(v1[i] & j)]) + cost[i]);
            }
        }
    }

    g<<minn[(1<<n)-1]<<"\n";

    return 0;
}
