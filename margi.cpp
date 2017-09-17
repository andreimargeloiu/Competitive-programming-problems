// N*log(N)
# include <bits/stdc++.h>
# define NR 1050
using namespace std;
ifstream f("margi.in");
ofstream g("margi.out");
struct elem {
    int maxim, x, y;
}maxx1, maxx2;

int maxim, n, N;
int a[NR][NR], S[NR][NR];
char s[NR];

int suma_mat (int x, int y, int nivel) {
    int x2=x + (1<<nivel) - 1;
    int y2=y + (1<<nivel) - 1;

    return S[x2][y2] - S[x-1][y2] - S[x2][y-1] + S[x-1][y-1];
}
elem cauta_sol (int x, int y, int nivel, int sumaAnt) {
    int xmij=x + (1<<(nivel-1));
    int ymij=y + (1<<(nivel-1));

    // caut primele doua maxime
    elem sol; sol.maxim=-1;
    if (nivel >= 1) { // daca patratul se mai divide in continuare
        elem aux[5];
        aux[1] = cauta_sol (x, y, nivel-1, sumaAnt + suma_mat(x, y, nivel-1));
        aux[2] = cauta_sol (x, ymij, nivel-1, sumaAnt + suma_mat(x, y, nivel-1));
        aux[3] = cauta_sol (xmij, y, nivel-1, sumaAnt + suma_mat(x, y, nivel-1));
        aux[4] = cauta_sol (xmij, ymij, nivel-1, sumaAnt + suma_mat(x, y, nivel-1));

        for (int i=1; i<=4; ++i) {
            if (aux[i].maxim > sol.maxim) sol=aux[i];
            for (int j=i+1; j<=4; ++j) {
                if (sumaAnt + aux[i].maxim + aux[j].maxim > maxim) {
                    maxim = aux[i].maxim + aux[j].maxim + sumaAnt;
                    maxx1 = aux[i];
                    maxx2 = aux[j];
                }
            }
        }
        sol.maxim += suma_mat(x, y, nivel);
    } else { // am ajuns intr-un patratel
        if (sumaAnt > maxim) {
            maxim=sumaAnt;

            maxx1.maxim = sumaAnt; maxx1.x = x; maxx1.y = y;
            maxx2.maxim = 0;       maxx2.x = x; maxx2.y = y;
        }
        sol.maxim=a[x][y];
        sol.x=x; sol.y=y;
    }

    //functia returneaza suma maxima care se poate obtine de un jucator
    //daca ar incpe in acest patrat
    return sol;
}
void make_drum (int x, int y, int nivel, int X, int Y) {
    // if (nivel!=n) g<<(x-1) * N + y<<" ";

    if (nivel==0) {
        g<<"\n";
    } else {
        int xmij=x + (1<<(nivel-1));
        int ymij=y + (1<<(nivel-1));

        if (X<xmij && Y<ymij) {g<<"1 "; make_drum(x, y, nivel-1, X, Y);}
        if (X<xmij && Y>=ymij) {g<<"2 "; make_drum(x, ymij, nivel-1, X, Y);}
        if (X>=xmij && Y<ymij) {g<<"3 "; make_drum(xmij, y, nivel-1, X, Y);}
        if (X>=xmij && Y>=ymij) {g<<"4 "; make_drum(xmij, ymij, nivel-1, X, Y);}
    }
}
int main ()
{
    f>>n; f.get();
    N=(1<<n);

    for (int i=1; i<=N; ++i) {
        f.getline (s+1, NR);
        for (int j=1; j<=N; ++j) {
            a[i][j]=s[j] - '0';
            S[i][j]=S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }
    maxim=-1;
    cauta_sol (1, 1, n, 0);

    g<<maxim<<"\n";
    make_drum (1, 1, n, maxx1.x, maxx1.y);
    make_drum (1, 1, n, maxx2.x, maxx2.y);

    return 0;
}
