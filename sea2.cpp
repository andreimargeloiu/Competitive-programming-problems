# include <cstdio>
# include <algorithm>
# define NR 260005
# define inf 999999999
using namespace std;
struct elem {
    int y, I;
}MIN[3*NR];
int i,j,n,m,x,y,vii,maxx,minn,N,I;
int MAX[3*NR];
void init ()
{
    for (int i=1; i<=3*NR; ++i)
        MIN[i].y=inf;
}
void Qmaxim (int nod, int ci, int cs, int CI, int CS)
{
    if (CI<=ci && cs<=CS) maxx=max(maxx, MAX[nod]);
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij) Qmaxim (2*nod, ci, mij, CI, CS);
             if (mij<CS) Qmaxim (2*nod+1, mij+1, cs, CI, CS);

             MAX[nod]=max(MAX[2*nod], MAX[2*nod+1]);
         }
}
void Qminin (int nod, int ci, int cs, int CI, int CS)
{
    if (CI<=ci && cs<=CS) {
        if (MIN[nod].y < minn) {
            minn=MIN[nod].y; I=MIN[nod].I;
        }
    }
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij) Qminin (2*nod, ci, mij, CI, CS);
             if (mij<CS) Qminin (2*nod+1, mij+1, cs, CI, CS);
         }
}
void update (int nod, int ci, int cs, int NOD) //scoatem barcile moarte
{
    if (ci==NOD && NOD==cs) {MIN[nod].y=inf; MAX[nod]=0;}
    else {
             int mij=(ci+cs)/2;
             if (NOD<=mij) update (2*nod, ci, mij, NOD);
                      else update (2*nod+1, mij+1, cs, NOD);

             MAX[nod]=max(MAX[2*nod], MAX[2*nod+1]);

             if (MIN[2*nod].y < MIN[2*nod+1].y) MIN[nod]=MIN[2*nod];
                                           else MIN[nod]=MIN[2*nod+1];
         }
}
void actualizare (int nod, int ci, int cs, int NOD, int val)
{
    if (ci==NOD && NOD==cs) {MIN[nod].y=val; MIN[nod].I=ci; MAX[nod]=val;}
    else {
             int mij=(ci+cs)/2;
             if (NOD<=mij) actualizare (2*nod, ci, mij, NOD, val);
                      else actualizare (2*nod+1, mij+1, cs, NOD, val);

             MAX[nod]=max(MAX[2*nod], MAX[2*nod+1]);
             if (MIN[2*nod].y < MIN[2*nod+1].y) MIN[nod]=MIN[2*nod];
                                           else MIN[nod]=MIN[2*nod+1];
         }
}
int main ()
{
    freopen ("sea2.in", "r", stdin);
    freopen ("sea2.out", "w", stdout);
    scanf ("%d", &n);

    N=260000; init ();

    for (i=1; i<=n; ++i) {
        scanf ("%d%d", &x, &y);
        //vedem daca moare sau nu
        maxx=0;
        if (x!=N)
        {
            Qmaxim (1, 1, N, x+1, N);

            if (y<maxx) {printf ("-1\n"); continue;} // a murit
        }

        //daca nu moarte trebuie sa calculam cate mai raman vii
        ++vii; // barca actuala

        while (1 && x!=1) {
            minn=inf;
            Qminin (1, 1, N, 1, x-1); //gasim minimul

            if (minn<y) {
                --vii;
                update (1, 1, N, I);
            }
            else break;
        }
        printf ("%d\n", vii);


        actualizare (1, 1, N, x, y);
    }



    return 0;
}
