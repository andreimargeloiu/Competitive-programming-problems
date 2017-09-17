# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 1005
using namespace std;
ifstream f("zaharel.in");
ofstream g("zaharel.out");
struct solutie {
    int x, y;
}sol[3*NR];
int i,j,n,m,x,y,X,Y;
int R[NR], C[NR], ap[NR][NR];
char ch;
void solutie (int K, int n, int rest) {
    g<<(n-K+1)/2<<"\n";
    for (int i=K+rest; i<=n; i+=2)
        g<<sol[i].x<<" "<<sol[i].y<<" ";
    g<<"\n";
    for (int i=K+(rest+1)%2; i<=n; i+=2)
        g<<sol[i].x<<" "<<sol[i].y<<" ";
    g<<"\n";
}
int main ()
{
    // rosu -> linie
    // albastru -> coloana
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y; f.get(); f>>ch;
        if (ch=='A')  C[y]=x;
                else {R[x]=y; X=x; Y=y;}
    }

    // incepem din X, Y
    for (i=1; i<=2005; ++i) {
        ap[X][Y]=i; sol[i].x=X; sol[i].y=Y;

        if (i%2==1) X=C[Y]; // -> sunt pe rosu
               else Y=R[X]; // -> sunt pe albastru

        if (ap[X][Y]) {
            solutie (ap[X][Y], i, i%2);
            return 0;
        }
    }
    g<<"-1\n";
    return 0;
}
