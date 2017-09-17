# include <vector>
# include <algorithm>
# include <fstream>
# define NR 150
# define INF 999999999
using namespace std;
ifstream f("judete.in");
ofstream g("judete.out");
vector <int> v[NR];
int i,j,n,m,K,x,y;
int dp[NR][NR];
// dp[i][j] = marimea maxima T a unui judet din subarborele lui i
//            astfel incat sa fie bine repartizat, iar in i sa ajungem
//            cu j orase 'libere de judet'
void init (int a[]) {
    for (int i=0; i<=n; ++i)
        a[i]=INF;
}
void DFS (int k, int tata) {
    // initial in pot pune doar pe el in multiem
    int aux[NR];
    init(dp[k]); dp[k][1]=0;

    for (int q=0; q<v[k].size(); ++q) {
        int x=v[k][q];
        if (x!=tata) {
            DFS (x, k); init (aux);

            //acum incerc sa vad cum fac dinamica
            for (int T=0; T<=n; ++T) { //iau fiecare stare a copilului
                if (dp[x][T]!=INF) { //daca am ajuns din fiu in starea T
                    for (int i=n; i>=T; --i) {
                        aux[i]=min(aux[i], max(dp[x][T], dp[k][i-T]));
                    }
                }
            }
            for (int i=0; i<=n; ++i)
                dp[k][i]=aux[i];
        }
    }
    //acum starile care sunt mai mari ca si K, le putem pune in dp[k][0]
    for (int i=K; i<=n; ++i)
        dp[k][0]=min(dp[k][0], max(dp[k][i], i));
}
int main ()
{
    f>>n>>K;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS (1, 0);
    g<<dp[1][0]<<"\n";

    return 0;
}
