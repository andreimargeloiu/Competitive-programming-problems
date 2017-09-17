# include <fstream>
# include <algorithm>
# include <cstring>
# include <deque>
# define NR 20000
using namespace std;
ifstream f("trans.in");
ofstream g("trans.out");
deque <int> d0, d1;
int i,j,n,m,x,y,cap,C,Q;
int unu[NR], zero[NR], sum[NR], tip[NR], cost[NR];
int ZERO (int ci, int cs)
{
    return zero[cs]-zero[ci];
}
int UNU (int ci, int cs)
{
    return unu[cs]-unu[ci];
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>tip[i]>>cost[i];

        zero[i]=zero[i-1];
        unu[i]=unu[i-1];

        if (tip[i]==0) zero[i]+=cost[i];
                  else unu[i]+=cost[i];
    }
    f>>Q;
    for (i=1; i<=Q; ++i)
    {
        memset (sum, 0, sizeof(sum));
        d0.clear(); d1.clear();

        f>>cap>>C;
        //rezolvam
        for (j=1; j<=n; ++j)
        {
            while (! d0.empty() && sum[j-1] + ZERO(j-1, j) <= sum[d0.back()] + ZERO(d0.back(), j))
                d0.pop_back();
            d0.push_back(j-1);
            if (d0.front()==j-cap-1) d0.pop_front();


            while (! d1.empty() && sum[j-1] + UNU(j-1, j) <= sum[d1.back()] + UNU(d1.back(), j))
                d1.pop_back();
            d1.push_back(j-1);
            if (d1.front()==j-cap-1) d1.pop_front();



            sum[j]=min (sum[d0.front()] + ZERO(d0.front(), j), sum[d1.front()] + UNU(d1.front(), j)) + C;
        }

        // afisam
        g<<sum[n]<<"\n";
    }
    return 0;
}
