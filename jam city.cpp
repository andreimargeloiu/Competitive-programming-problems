#include <bits/stdc++.h>

using namespace std;

# define pb push_back
# define mp make_pair
# define FORN( a , b , c ) for ( int a = b ; a <= c ; ++ a )
# define FORNBACK( a , b , c ) for ( int a = b ; a >= c ; -- a )

int finish [ 3000 ] ;
int countt [ 3000 ], mutat[3000];
int p [ 3000 ] ;
int bagat [ 3000 ] ;

int main()
{
    freopen( "input.in" , "r" , stdin ) ;
    freopen( "output.out" , "w" , stdout ) ;
    int n ;
    scanf ( "%d\n" , &n ) ;
    int cate ;
    scanf ( "%d\n" , &cate ) ;
    for ( int i = 1 ; i <= cate ; ++ i ) {
        int a ;
        scanf ("%d,%d\n" , &a , &finish [ i ] ) ;
        p [a] = i ;
    }
   // for ( int i = 1 ; i <= n ; ++ i ) {
   //     printf ( "%d " , p [ i ] ) ;
   // }
    //printf ( "\n" ) ;
    int ok=0, scoase=0;
    do {
        ok=0; memset (mutat, 0, sizeof(mutat));
        for (int i=1 ; i<=n ; ++i) {
            if (mutat[p[i]]) continue;
            mutat[p[i]]=1;

            if (p[i]) {ok=1; ++countt[p[i]];}
            if (p[i] && p[i+1]==0) {p[i+1]=p[i]; p[i]=0;}
        }

        for (int i=1; i<=n; ++i)
            if (p[i] && finish[p[i]]==i) {
                p[i]=0;
                ++scoase;
            }

    }while ( ok ) ;
    for ( int i = 1 ; i <cate ; ++ i ) {
        printf ("%d," , 2+countt [ i ] ) ;
    }
    printf ( "%d\n" , 2+countt [ cate ] ) ;
    return 0 ;
}
