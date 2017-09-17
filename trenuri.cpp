# include <algorithm>
# include <fstream>
# include <cstring>
# include <vector>
# include <set>
# define mp make_pair
# define NR 100005
using namespace std;
struct elem {
    int dest, i, t;
}E,E2;
struct comp {
    bool operator () (const elem &x, const elem &y) {
        if (x.dest <= y.dest) return 0;
                         else return 1;
    }
};
struct comp2 {
    bool operator () (const elem &x, const elem &y) {
        if (x.dest >= y.dest) return 0;
                         else return 1;
    }
};


struct elem2 {
    int dest, aux, i;
}tren[NR], om[NR];

int i,j,n,m,nrT,capacitate,destinatie,inceput,sfarsit,H;
int FREE,Free,nrsol,VV,T,maxx,OM;
int locuri[NR], sol[NR];
bool cmp (elem2 x, elem2 y) {
    if (x.dest <= y.dest) return 0;
                     else return 1;
}
int main ()
{
    freopen ("trenuri3.in", "r", stdin);
    freopen ("trenuri3.out", "w", stdout);
    scanf ("%d%d", &n, &m);

    for (i=1; i<=n; ++i) {
        scanf ("%d%d", &destinatie, &capacitate);

        maxx=max(maxx, destinatie);

        tren[i].dest=destinatie; tren[i].aux=capacitate;
        tren[i].i=i;
    }
    // sortam descrescator dupa statie de destinatie
    sort (tren+1, tren+n+1, cmp);

    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &inceput, &sfarsit);
        om[i].dest=sfarsit; om[i].aux=inceput;
        om[i].i=i;
    }
    // sortam descrescator dupa sfarsit
    sort (om+1, om+m+1, cmp);
    while (om[OM+1].dest > maxx) ++OM;

    multiset <elem, comp> SET;
    multiset <elem, comp2> SET2;

    // VV-nivelul in stiva cu locuri goale
    for (i=maxx; i>=1; --i) {
        //incepe un nou tren
        while (tren[T+1].dest==i) {
            ++T;
            // adaugam numarul de locuri ale acestui tren
            while (FREE < m && tren[T].aux) {
                ++FREE;
                locuri[++Free]=tren[T].i;
                --tren[T].aux;
            }
        }

        //vedem cine iese acum
        while (SET.size() && (*SET.begin()).dest==i) {
            E=*SET.begin();
            SET.erase(SET.find(E));
            SET2.erase (SET2.find(E));

            ++nrsol; sol[E.i]=E.t;
            locuri[++Free]=E.t;
        }

        //punem oamenii in set
        while (om[OM+1].dest==i) {
            ++OM;
            //daca avem locuri libere
            if (Free) {
                E.dest=om[OM].aux;
                E.i=om[OM].i;
                E.t=locuri[Free];
                --Free;

                SET.insert (E);
                SET2.insert (E);
            }
            else {
                //vedem daca sunt trenuri care ies dupa el
                //-> suntem greedy si il inlocuim cu asta

                if (SET2.size() && (*SET2.begin()).dest < om[OM].aux) {
                    E=*SET2.begin();
                    SET.erase(SET.find(E));
                    SET2.erase(SET2.find(E));

                    E.i=om[OM].i;
                    E.dest=om[OM].aux;

                    SET.insert(E);
                    SET2.insert(E);
                }
            }
        }
    }
    printf ("%d\n", nrsol);
    for (i=1; i<=m; ++i)
        printf ("%d\n", sol[i]);


    return 0;
}
