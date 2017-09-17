# include <fstream>
# include <algorithm>
# define NMAX 100005
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int i,j,n,m,x,y,k,Q,LG,ci,cs;
int RMQ[20][NMAX], lg[NMAX];
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
        f>>RMQ[0][i];

    for (i=2; i<=n; ++i)
        lg[i]=lg[i/2]+1;

    for (i=1; i<=lg[n]; ++i) {
        for (j=1; j<=n-(1<<(i-1))+1; ++j)
            if (RMQ[i-1][j] < RMQ[i-1][j+(1<<(i-1))]) RMQ[i][j]=RMQ[i-1][j];
                                                 else RMQ[i][j]=RMQ[i-1][j+(1<<(i-1))];
    }

    for (i=1; i<=Q; ++i){
        f>>ci>>cs;
        if (ci > cs) swap(ci, cs);
        LG=lg[cs-ci+1];

        if (RMQ[LG][ci] < RMQ[LG][cs-(1<<LG)+1]) g<<RMQ[LG][ci]<<"\n";
                                               else g<<RMQ[LG][cs-(1<<LG)+1]<<"\n";
    }

    return 0;
}
