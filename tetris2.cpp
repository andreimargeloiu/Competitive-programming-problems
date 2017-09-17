#include<stdio.h>
#define Mmax 506
#define Nmax 101
#define BASE 10001
using namespace std;
int A[Mmax][Mmax], B[Nmax][Nmax],N,M,sol,MIN[Mmax][Mmax],D[Mmax][Mmax],IND[2][Mmax],D_LIN[2][Mmax],d_lin_st,d_lin_fn;
//D[j][] = reprezinta un deque pt coloana j
//D[j][x] = linia pe care se afla elementul de pe coloana j

unsigned int n_lin[Mmax];//n_lin[i] reprezinta primele n elem de pe fiecare parte a matricii
unsigned int n_col[Mmax];
unsigned int piece_key;
unsigned int current_key;
unsigned int first_key;
unsigned int P,P_LIN,S,P_COL;//p = pow(base,n), S = base^0 + base^1 + ... + base^n, P_COL puterea maxima la care apare o coloana(base^(n-1))

void read_data()
{
    int i,j,maxim = -1,minim = BASE+2;

    FILE*f = fopen("tetris2.in","r");

    fscanf(f,"%d",&M);


    for(i=1;i<=M;++i)
        for(j=1;j<=M;++j)
            fscanf(f,"%d",&A[i][j]);

    fscanf(f,"%d",&N);

    for(i=1;i<=N;++i)//rastorn piesa si fac "modulo"
        for(j=1;j<=N;++j)
        {
            fscanf(f,"%d",&B[i][j]);
            if(B[i][j] > maxim)
                maxim = B[i][j];
        }
    ++maxim;
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
        {
             B[i][j] = maxim - B[i][j];
             if(B[i][j] < minim)
                minim = B[i][j];
        }

    --minim;
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
        {
            B[i][j] = B[i][j] - minim;
        }
    fclose(f);
}
void get_min()
{
    int i,j,st,fn,min_col;
    for(i=1;i<=M;++i)
        IND[1][i] = -1;
    for(i=1;i<=M;++i)
    {
        d_lin_fn = -1;
        d_lin_st = 0;
        for(j=1;j<=M;++j)
        {
            st = IND[0][j];
            fn = IND[1][j];
            //inserez in col j elem A[i][j]

            while(fn>=st && A[ D[j][fn] ][j]>=A[i][j])
                --fn;

            D[j][++fn] = i;

            if(i-N >= D[j][st])
                ++st;

            IND[0][j] = st;
            IND[1][j] = fn;
            //inserez minimul de pe col j in deque-ul liniilor
            min_col = A[ D[j][st] ][j];
            while(d_lin_fn >= d_lin_st && D_LIN[0][ d_lin_fn ] >= min_col)
                --d_lin_fn;

            ++d_lin_fn;
            D_LIN[0][d_lin_fn] = min_col;
            D_LIN[1][d_lin_fn] = j;

            if(j - N >= D_LIN[1][ d_lin_st ])
                ++d_lin_st;

            //salvez miniumul daca i,j>=N
            if(i>=N && j>=N)
                MIN[i][j] = D_LIN[0][ d_lin_st ];
        }
    }
}
void show_piece()
{
    int i,j;
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
            printf("%4d ",B[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
void show_base()
{
    int i,j;
    for(i=1;i<=M;++i)
    {
        for(j=1;j<=M;++j)
            printf("%4d ",A[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
void show_submatrix(int l,int c)
{
    int i,j;
    printf("\n\n\n");
    for(i=l-N+1;i<=l;++i)
    {
        for(j=c-N+1;j<=c;++j)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}
void get_n_lin()
{
    /*  pt m=6 si n=3 o sa am cheile respective
        xxx**
        xxx**
        xxx**
        xxx**
        xxx**
        xxx**
    */
    int i,cnt,j;
    for(i=1;i<=M;++i)
    {
        for(j=1;j<=N;++j)
            n_lin[i] = n_lin[i]*BASE + A[i][j];
    }
}
void get_n_col()
{
    /*
        pt m=6 si n=3 o sa am cheile respective
        xxxxxx
        xxxxxx
        xxxxxx
        ******
        ******
        ******
    */
    int i,j;
    unsigned int P_N = P;//pow(base,N)
    for(j=1;j<=M;++j)
    {
        for(i=1;i<=N;++i)//linia
        {
            n_col[j] = n_col[j]*P_N + A[i][j];
        }
    }
}
void get_stuff()
{
    //obtin base^n
    int i,exp;
    for(i=1,P=P_COL=1,S=0;i<=N;++i)
    {
        S += P;
        P*=BASE;

        if(i!=N)
            P_COL = P;
    }
    S += P;
    exp = N*(N-1);
    for(i=1,P_LIN=1;i<=exp;++i)
        P_LIN *= BASE;

    unsigned int c=1;
    for(i=0,S=0,exp=N*N;i<exp;++i)
    {
        S += c;
        c *= BASE;
    }
}
void get_piece_key()
{
    int i,j;
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
        {
            piece_key = piece_key*BASE + B[i][j];
        }
    }
}
void get_first_key()
{
    int i,j;//obtin cheia pt primul dreptunghi
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
        {
            current_key = current_key*BASE + A[i][j];
        }
    }
}
int main()
{
    read_data();
    get_min();
    get_stuff();
    get_n_col();
    get_n_lin();

    get_piece_key();
    get_first_key();
//    show_piece();
    //treuibe scazut S*(minim_dreptunghi-1)
    current_key -= S*(MIN[N][N] - 1);

    if(current_key == piece_key)
    {
        ++sol;
//        printf("first\n");
    }
    //adunam din nou la current_key S*MIN[N][N]
    current_key += S*(MIN[N][N] - 1);

    int i,j,pos;

    for(j=N+1, first_key = current_key, i=N;j<=M;++j)//fiecare coloana de la N+1 la M(obtin cheia in O(1))
    {
        if(i>N)//update la coloane
        {
            pos = j-N;
            if(pos < N+1)//daca nu am updatat deja
                n_col[pos] = (n_col[pos] - P_LIN * A[i-N][pos])*P + A[i][pos];

            pos = j;
            n_col[pos] = (n_col[pos] - P_LIN * A[i-N][pos])*P + A[i][pos];
        }
        current_key = (current_key - P_COL * n_col[j-N])*BASE + n_col[j];
        current_key -= S*(MIN[i][j] - 1);

        if(current_key == piece_key)
        {
             ++sol;
        //     printf("in\n");
        }

        current_key += S*(MIN[i][j] - 1);

        if(j == M)
        {
            if(i>=M)
            {
                j = M+10;
                continue;
            }
            j = N;

            first_key = (first_key - P_LIN*n_lin[i-N+1])*P + n_lin[i+1];

            first_key -= S*(MIN[i+1][j] - 1);
            if(first_key == piece_key)
            {
                ++sol;
            //    printf("line works\n");
            }
            first_key += S*(MIN[i+1][j] - 1);

            current_key = first_key;
            ++i;
        }
    }
    FILE*g = fopen("tetris2.out","w");
    fprintf(g,"%d\n",sol);
    fclose(g);
    return 0;
}
/*# include <cstdio>
# include <algorithm>
# include <cstring>
# define NR 505
using namespace std;
int i,j,n,m,x,y,ant,nou,VV,o,k;
int B[NR][NR], Bdif[NR][NR], P[NR][NR], Pdif[NR], pi[NR], mat[3][NR][NR];
void printare (int k) {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<n; ++j)
            printf ("%d ", mat[k][i][j]);
        printf ("\n");
    }
}
bool verif (int I, int J) {
    for (int i=1; i<m; ++i)
        if (P[m-i][m]+B[I-i][J] != P[m][m]+B[I][J]) return 0;
    return 1;
}
int main ()
{
    freopen ("tetris2.in", "r", stdin);
    freopen ("tetris2.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j) {
            scanf("%d", &B[i][j]);
            if (j>1) Bdif[i][j-1]=B[i][j] - B[i][j-1];
        }

    scanf ("%d", &m);
    if (m==1) {
        printf ("%d\n", n*n);
        return 0;
    }
    ant=0;
    for (i=1; i<=m; ++i) {
        nou=1-ant;
        for (j=1; j<=m; ++j) scanf("%d", &P[i][j]);
        for (j=1; j<m; ++j) Pdif[j]=P[i][j] - P[i][j+1];


        //KMP
        memset (pi, 0, sizeof(pi));
        k=0;
        for (j=2; j<m; ++j) {
            while (k>0 && Pdif[k+1]!=Pdif[j])
                k=pi[k];

            if (Pdif[k+1]==Pdif[j]) ++k;
            pi[j]=k;
        }

        for (o=1; o<=n; ++o) {//fiecare rand
            k=0;
            for (j=1; j<n; ++j) {
                while (k>0 && Pdif[k+1]!=Bdif[o][j])
                    k=pi[k];

                if (Pdif[k+1]==Bdif[o][j]) ++k;

                if (k==m-1) {
                    k=pi[k];
                    if (mat[ant][o-1][j]==i-1) mat[nou][o][j]=i;
                }
            }
        }
        //printare (nou); printf ("\n");
        ant=nou;
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (mat[nou][i][j]==m && verif(i, j+1)) ++VV;
        }
    }
    printf ("%d\n", VV);

    return 0;
}*/
