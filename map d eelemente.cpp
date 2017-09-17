# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("map.in");
ofstream g("map.out");
typedef pair <int, int> mapkey;
struct elem {
    int x, y;
}E;
struct mapcmp {
    bool operator()(const mapkey &x, const mapkey &y) {
        return x<y;
    }
};
int i;
int main ()
{
    map <mapkey, int, mapcmp> M;

    M[mp(2, 3)]=1;
    M[mp(2, 5)]=2;
    M[mp(1, 3)]=3;
    M[mp(1, 5)]=2;

    M.erase(mp(1, 3));

    for (auto x=M.begin(); x!=M.end(); ++x) {
        g<<(x->first).f<<" "<<(x->first).s<<" "<<(x->second)<<"\n";
    }

    return 0;
}
