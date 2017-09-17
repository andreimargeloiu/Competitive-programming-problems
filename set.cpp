# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("set.in");
ofstream g("set.out");
vector <int> HEAP;
int i,j,n,m;
/*struct cmpset {
    bool operator() (const int &x, const int &y) {
        return x < y;
    }
};
struct cmpsetstring {
    bool operator() (const string &x, const string &y) {
        return x < y;
    }
};*/
struct cmppair {
    size_t operator() (const pair <int, int> &x, const pair <int, int> &y) {
        if (x.f!=y.f) return x.f < y.f;
                 else return x.s < y.s;
    }
};
int main ()
{
    // SET @@@@@@@@@@@@@@@@@
    multiset <pair<int, int>, cmppair> M;

    g<<"SET ";
    M.insert (mp(1, 2));
    M.insert (mp(2, 1));
    M.insert (mp(2, 2));
    M.insert (mp(2, 2));
    M.insert (mp(2, 2));
    M.insert (mp(2, 2));
    M.insert (mp(2, 2));
    M.insert (mp(2, 3));
    M.insert (mp(3, 7));
    M.insert (mp(3, 7));

    for (auto it=M.begin(); it!=M.end(); ++it)
        g<<(*it).f<<" "<<(*it).s<<", ";

    g<<"\n";
    /*auto L=M.lower_bound(mp(2, 0));
    g<<distance(M.begin(), L)+1;*/

    g<<distance(M.lower_bound(mp(2, 7)), M.upper_bound(mp(2, 7)));

    return 0;
}
