# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# define N 1505
# define M 4005
using namespace std;
struct elem2 {
    int y, i;
}E;
vector <elem2> v[N];
struct elem {
    int x, y;
}Muchie[M];

int i,j,n,m,x,y, Componenta, X, Y, VV1, VV2;
short ap[N], trecut[M], T[N], solX[N], solY[N], niv[N];
void DFS (int k, int tata, int nivel)
{
    ap[k]=Componenta; T[k]=tata; niv[k]=nivel;

    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i].y]) {
            trecut[v[k][i].i]=1;
            DFS (v[k][i].y, k, nivel+1);
        }
}
int main ()
{
    freopen ("police.in", "r", stdin);
    freopen ("police.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y); Muchie[i].x=x; Muchie[i].y=y;
        E.y=y; E.i=i; v[x].push_back(E);
        E.y=x; E.i=i; v[y].push_back(E);
    }

    for (i=1; i<=n; ++i)
         if (! ap[i]) {++Componenta; DFS(i, i, 1);}

    printf ("%d\n", m-n+Componenta);
    memset (ap, 0, sizeof(ap));
    memset (niv, 0, sizeof(niv));
    memset (T, 0, sizeof(T));
    memset (trecut, 0, sizeof(trecut));
    Componenta=0;

    for (i=1; i<=n; ++i) {
        if (! ap[i]) {
            ++Componenta;
            DFS (i, i, 1);

            //luam fiecare muchie si vedem daca are capatul in aceasta multime

            for (j=1; j<=m; ++j) {
                if (ap[Muchie[j].x]==Componenta && ap[Muchie[j].y]==Componenta && ! trecut[j]) {
                    //ambele sunt in aceiasi componenta

                    VV1=0; VV2=0; X=Muchie[j].x; Y=Muchie[j].y;

                    while (niv[X]>niv[Y]) {
                        solX[++VV1]=X;
                        X=T[X];
                    }
                    while (niv[Y]>niv[X]) {
                        solY[++VV2]=Y;
                        Y=T[Y];
                    }

                    if (X!=Y) {
                        while (X!=Y)
                        {
                            solX[++VV1]=X; solY[++VV2]=Y;
                            X=T[X]; Y=T[Y];
                        }

                        for (int o=1; o<=VV1; ++o)
                            printf ("%d ", solX[o]);
                        printf ("%d ", X);

                        for (int o=VV2; o>=1; --o)
                            printf ("%d ", solY[o]);

                        printf ("%d ", Muchie[j].x);
                    }
                    else {
                             if (VV1) {
                                          for (int o=1; o<=VV1; ++o)
                                              printf ("%d ", solX[o]);
                                          printf ("%d %d\n", X, Muchie[j].x);

                                      }
                             else {
                                      for (int o=1; o<=VV2; ++o)
                                          printf ("%d ", solY[o]);
                                      printf ("%d %d\n", Y, Muchie[j].y);
                                  }
                         }
                }
            }
        }
    }




    return 0;
}
