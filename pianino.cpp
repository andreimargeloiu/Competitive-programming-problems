# include <fstream>
# include <iostream>
# include <algorithm>
# define NR 1000005
# define M 1LL*2000000000
using namespace std;
//ifstream f("pianino.in");
//ofstream g("pianino.out");
int i,n;
long long x, ant, P, sol[NR], dif, S, nrsol,maxx,auxmax,SOL;;
long double VV;
int main ()
{
    cin>>n>>x; ant=x; P=x; SOL=1;
    for (i=2; i<=n; ++i) {
        cin>>x;

             if (ant < x) ++dif;
        else if (ant > x) --dif;

        ant=x;

        if (dif==0) {
            if (x==P) ++SOL;
            continue;
        }

        VV=((long double)(x-P))/dif;
        if (VV>0) {
            if (VV==((long double)((long long)(VV))))
                sol[++nrsol]=((long long)VV);
        }
    }

    sort (sol+1, sol+nrsol+1);

    if (sol[1] <= M ) { maxx=1; S=sol[1]; }

    for (i=1; i<nrsol; i+=0) {
        if (sol[i]==sol[i+1]) {
            auxmax=1;
            while (i<nrsol && sol[i]==sol[i+1]) {
                ++auxmax;
                ++i;
            }
            if (sol[i] <= M && auxmax > maxx) {
                maxx=auxmax;
                S=sol[i];
            }
        }
        else ++i;
    }

    cout<<maxx+SOL<<"\n"<<S<<"\n";

    return 0;
}
