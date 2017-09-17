# include <fstream>
# include <algorithm>
# define LB(p) ((-p)&p)
# define NR 100005
using namespace std;
ifstream f("secventak.in");
ofstream g("secventak.out");
int i,j,n,m,K,ind;
int AIB[NR];
long long a[NR], var[NR], S[NR], aux, sol;
int query (int poz) {
    int sol=0;
    for (int i=poz; i>=1; i-=LB(i))
        sol+=AIB[i];
    return sol;
}
void update (int poz) {
    for (int i=poz; i<=n+1; i+=LB(i))
        ++AIB[i];
}
int main ()
{
    f>>n>>K;

    // Sb - k*b >= Sa - k*a
    for (i=2; i<=n+1; ++i) {
        f>>a[i]; S[i]=S[i-1] + a[i];
        var[i]=S[i] - 1LL*K*i;
    }

    sort (var+1, var+n+2);

    for (i=1; i<=n+1; ++i) {
        aux=S[i] - 1LL*K*i;
        ind=lower_bound(var+1, var+n+2, aux) - var;

        sol+=query(ind);
        update (ind);
    }
    g<<sol<<"\n";

    return 0;
}
