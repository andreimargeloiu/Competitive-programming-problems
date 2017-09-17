# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
# define NR 1100000
# define f first
# define s second
using namespace std;

multimap <int, int> M;
int i,j,n,m,L,U;
int cod[NR];
unsigned int A[NR];
// numarul de secvente cu pana la L elemente diferite
int main ()
{
    M.insert(make_pair(5, 7));
    M.insert(make_pair(9, 7));
    M.insert(make_pair(5, 10));

    std::multimap<int,int>::iterator it = M.find(std::pair<int,int>(5,10));

    M.erase(it);
    for (it=M.begin(); it!=M.end(); ++it)
        cout<<it->first<<" "<<it->second<<"\n";


    return 0;
}
