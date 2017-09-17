# include <cstdio>
# include <vector>
# define NR 100
using namespace std;
vector <int> v[NR];
int i,j,n,K,J,I,buckets,rest,x1,x2,aux;
int m[NR][NR];
int main ()
{
    freopen ("kreg.in", "r", stdin);
    freopen ("kreg.out", "w", stdout);
    scanf ("%d%d", &K, &n);

    for (i=1; i<=K/2; ++i)  //muchiile dintre primele 2 bucketuri
        for (j=K/2+1; j<=K; ++j)
            m[i][j]=1;

    for (i=1; i<=K/2; ++i) {//muchiile virtuale dintre primele 2 bucketuri
        for (j=i+K/2; j<=K; ++j)
            v[i].push_back(j);
        for (j=K/2+1; j<i+K/2; ++j)
            v[i].push_back(j);
    }

    buckets=(n-1)/(K/2); I=K/2;
    for (aux=3; aux<=buckets; ++aux) { //muchiile dintre bucketuri
        for (i=I+1; i<=I+K/2; ++i)
            for (j=I+K/2+1; j<=I+K; ++j)
                printf ("%d %d\n", i, j);

        I+=(K/2);
    }

    I=(K/2)*(buckets-1);
    for (i=1; i<K/2; ++i) //muchii de pe laterale
        for (j=i+1; j<=K/2; ++j) {
            printf ("%d %d\n", i, j);
            printf ("%d %d\n", I+i, I+j);
        }

    I=(K/2)*(buckets-1);
    for (i=1; i<=K/2; ++i) {//leg ultimul element
        printf ("%d %d\n", i, n);
        printf ("%d %d\n", I+i, n);
    }

    //punem restul de noduri nelegate
    rest=n - (K/2)*buckets;

    for (i=n-rest+1; i<n; ++i) {
        //leg la primul graf bipartit
        for (j=1; j<=K/2; ++j) {
            x1=j; x2=v[j][J];

            m[x1][x2]=0;
            printf ("%d %d\n", x1, i);
            printf ("%d %d\n", x2, i);
        }
        ++J;
    }

    for (i=1; i<=K; ++i)
        for (j=i+1; j<=K; ++j)
            if (m[i][j]) printf ("%d %d\n", i, j);

    return 0;
}
