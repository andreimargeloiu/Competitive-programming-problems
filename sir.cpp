# include <fstream>
# include <algorithm>
# include <deque>
# define NR 100005
using namespace std;
ifstream f("sir.in");
ofstream g("sir.out");
deque <int> m, M;
int n,X,Y,Z,l,sol,L,ci,i;
int a[NR];
void adauga (int i)
{
    while (m.size() && a[m.back()] > a[i])
        m.pop_back();
    m.push_back(i);

    while (M.size() && a[M.back()] < a[i])
        M.pop_back();
    M.push_back(i);
}
int main ()
{
    f>>n>>X>>Y>>Z;
    ci=1;
    for (i=1; i<=n; ++i) {
        f>>a[i]; adauga (i);

        if (i>=X) {
            while ((ci+Y<=i || a[M.front()]-a[m.front()]>Z) && ci+X<=i+1) {
                if (m.front()==ci) m.pop_front();
                if (M.front()==ci) M.pop_front();
                ++ci;
            }
            if (ci+X<=i+1 && a[M.front()]-a[m.front()]<=Z) {
                l=i-ci+1;
                if (l>L) sol=ci, L=l;
                else if (l==L) sol=ci;
            }
        }
    }

    if (sol==0) g<<"-1\n";
    else g<<L<<" "<<sol<<" "<<sol+L-1<<"\n";

    return 0;
}
