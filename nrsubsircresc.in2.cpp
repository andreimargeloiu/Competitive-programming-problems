# include <fstream>
# include <algorithm>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 105
using namespace std;
ifstream f("nrsubsircresc2.in");
ofstream g("nrsubsircresc2.out");
int i,j,n,m,x,y,act,nou,nr[4*NR+5],P;
long long AIB[NR+5], moduri[3][4*NR+5], S;
long long query (int poz) {
    long long S=0;
    for (int i=poz; i>=1; i-=LB(i))
        S+=AIB[i];
    return S;
}
void update (int poz, long long val) {
    for (int i=poz; i<=NR; i+=LB(i))
        AIB[i]+=val;
}
int main ()
{
    f>>n>>P;
    for (i=1; i<=n; ++i)
        { f>>nr[i]; nr[i]+=2;}

    // pentru fiecare lungime parcurg sirul in ordine
    // iar numarul de moduri de a face siruri de lungime p pana la pozitia i
    // este egal cu suma tuturor modurilor de a face siruri de lungime p-1
    // la pozitiile anterioare, mai mici decat valoare nr[i]
    // -> tin minte in AIB[i] - suma tuturor modurilor de a face siruri de
    // lungime p, cu inaltimea i.

    //AIB[valoare]

    act=0;
    for (i=1; i<=n; ++i) moduri[act][i]=1;

    for (int p=2; p<=P; ++p) {
        nou=1-act;
        memset(AIB, 0, sizeof(AIB));
        memset (moduri[nou], 0, sizeof(moduri[nou]));
        for (i=1; i<=n; ++i) {
            S=query (nr[i]-1);
            moduri[nou][i]=S;
            update (nr[i], moduri[act][i]);
        }
        act=nou;
    }
    S=0;
    for (i=1; i<=n; ++i)
        S+=moduri[act][i];
    g<<S<<"\n";

    return 0;
}
