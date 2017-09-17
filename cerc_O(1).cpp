// O(N)
# include <fstream>
# define MOD 666013
using namespace std;
ifstream f("cerc.in");
ofstream g("cerc.out");
int k;
long long sol,N,x1,x2,x3;
int main ()
{
    f>>N;
    for (k=4; k<=N; ++k) {
        x1=k-3; x2=k-2; x3=k-1;

        if (x1%3==0) x1/=3;
        else if (x2%3==0) x2/=3;
        else if (x3%3==0) x3/=3;

        sol=(sol +x1%MOD*x2%MOD*x3%MOD)%MOD;
    }

    g<<(sol+N)%MOD<<"\n";

    return 0;
}
