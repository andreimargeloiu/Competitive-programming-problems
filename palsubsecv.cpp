# include <bits/stdc++.h>
# define NR 1500000
# define N 35
# define INF 2000000000
using namespace std;
ifstream f("palsubsecv.in");
ofstream g("palsubsecv.out");
struct elem {
    int i, j, li, lj, L;
}Q[NR], E;
int i,j,n,m,sol,unu,doi,trei,T,a,b,C,li,lj,R,B,l,L,adaos,LI,LJ,aux;
int dp[3][N+2][N+2][N+2][N+2], st[N+2][N+2], dr[N+2][N+2], cost[N+2][N+2], P[N+2][N+2];
char s[N+2];
void InitNou () {
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j) {
            st[i][j]=0;
            dr[i][j]=0;
            cost[i][j]=0;
            P[i][j]=0;
        }
}
void minn(int &a, int b) {
    if (b < a)  a=b;
}
void init (int n, int X) {
    for (int i=1; i<=n; ++i)
        for (int li=0; li<=n; ++li)
            for (int lj=0; lj<=n; ++lj)
                for (int L=0; L<=n; ++L)
                    dp[X][i][li][lj][L]=INF;
}
int minLI (int X, int i, int lj, int L) {
    int sol=INF;

    for (int k=0; k<=n; ++k)
        sol=min(sol, dp[X][i][k][lj][L]);

    return sol;
}
int minLJ (int X, int i, int li, int L) {
    int sol=INF;

    for (int k=0; k<=n; ++k)
        sol=min(sol, dp[X][i][li][k][L]);

    return sol;
}
void faPalindroame () {
    for (int l=2; l<=n/2*2; ++l) {
        for (int i=1; i<=n-l+1; ++i) {
            int j=i+l-1;
            if (l==2) {
                if (s[i]==s[j]) P[i][j]=1;
            } else {
                if (s[i]==s[j]) P[i][j]=P[i+1][j-1];
            }
        }
    }
}
int main ()
{
    f>>T;
    while (T--) {
        f>>n>>R>>B; f.get(); InitNou();
        f.getline (s+1, N);
        faPalindroame();
        //st[a][b] - costul in care este implicat a in restrictiile din intervalul a, b
        for (i=1; i<=R; ++i) { // costurile
            f>>a>>b>>C;
            cost[a][b]+=C;
            for (j=b; j<=n; ++j) dr[a][j]+=C;
            for (j=1; j<=a; ++j) st[b][j]+=C;
        }
        //initializam starile in dinamica

        //dp[i][j][li][lj][L] - costul minim pentru a face un palindorm de lungime L
        //                      intre pozitiile i,j ai incat sa ajung pe poz i cu li caractere la dr
        //                      si pe pozitia j cu lj caractere de la stanga
        //dp[i][j][li][lj][L] | dp[i+1][j-1][li-1][lj-1][L-2] - daca s[i]==s[j]
        //   e minimul dintre | + cost[i][i+li-1] + cost[j-lj+1][j]
        //                    |
        //                    |
        //                    | minn[i+1][j][L] - maximul pe intervalul i, j, astfel incat
        //                    | minn[i][j+1][L]
        //                    |

        // acum trebuie sa initializez starea initiala, adica cea de lungime 2
        unu=0; doi=1; trei=2; sol=0;
        init (n, unu); init (n, doi);

        for (i=1; i<n; ++i) {
            dp[doi][i][0][0][0]=0;
            if (s[i]==s[i+1]) {
                dp[doi][i][2][2][2] = dr[i][i+1];
                if (dr[i][i+1] <= B) sol=2;
            }
        }

        for (l=3; l<=n; ++l) { // dinamica
            init(n, trei);
            for (i=1; i<=n-l+1; ++i) {
                j=i+l-1;

                for (li=0; li<=l; ++li)
                    for (lj=0; lj<=l; ++lj)
                        for (L=0; L<=l; L+=2) {

                            if (li==0) { // fara stanga
                                 minn (dp[trei][i][li][lj][L], minLI(doi, i+1, lj, L));
                            }
                            if (lj==0) { //fara dreapta
                                 minn (dp[trei][i][li][lj][L], minLJ(doi, i, li, L));
                            }

                            if (s[i]==s[j] && L>0) { // pun un palindrom
                                if (i==1 && j==6 && li==1 && lj==1 && L==4) {
                                    j+=0;
                                }
                                if (P[i][j] && L==l && (li!=l || lj!=l)) continue;
                                if (li>0 && lj>0) { //acum il pun
                                    adaos=0;
                                    if (i==1 && j==6 && li==4 && lj==4) {
                                        j+=0;
                                    }
                                    if (li==l) adaos=dr[i][j] + st[j][i] - cost[i][j], LI=l-2,  LJ=l-2;
                                          else adaos=dr[i][i+li-1] + st[j][j-lj+1],    LI=li-1, LJ=lj-1;

                                    minn (dp[trei][i][li][lj][L], dp[unu][i+1][LI][LJ][L-2] + adaos);
                                }
                            }
                            if (dp[trei][i][li][lj][L] <= B && L>sol) {
                                sol=L;
                            }
                        }
            }

            aux=unu;
            unu=doi;
            doi=trei;
            trei=aux;
        }

        g<<sol<<"\n";
    }

    return 0;
}
