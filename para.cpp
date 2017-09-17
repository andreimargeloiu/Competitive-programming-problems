# include <fstream>
# include <vector>
# include <cstring>
# include <algorithm>
# include <queue>
# define mod 30011
# define NR 105
using namespace std;
ifstream f("para.in");
ofstream g("para.out");
struct elem
{
    int i, k, unu, zero, tip;
}E;
queue <elem> q[NR];
int
void combinari ()
{
    for (i=2; i<=NR; ++i)
        C2[i]=i*(i+1)/2;
}
int main ()
{
    combinari ();
    f>>n>>m>>K;

    // a[j][k][unu][zero][tip] - numarul de posibilitati de a amplasa k caini pe primele j randuri
    //                           astfel incat sa ramana UNU coloane cu pe care mai pot pune un caine
    //                           si ZERO coloane fara niciun element
    E.i=1; E.k=0; E.unu=0; E.zero=m; E.tip=0; a
    q[1].push(E);

    E.i=1; E.k=1; E.unu=1; E.zero=m-1; E.tip=0;
    q[1].push(E);

    E.i=1; E.k=0; E.unu=0; E.zero=m; E.tip=0;
    q[1].push(E);
    for (i=1; i<n; ++i)
    {

    }


    return 0;
}
