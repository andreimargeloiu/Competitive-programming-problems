# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("map.in");
ofstream g("map.out");
typedef pair <int, int> mapkey;
struct mapcmp {
    size_t operator() (const mapkey &key) const {
        return hash<int>()(key.f) xor hash<int>()(key.s);
    }
};

int i;

int main ()
{
    unordered_map <string, int> M;

    M["ADA"]=2;
    M["MAIA"]=5;
    M["PANA"]=7;

    for (auto it=M.begin(); it!=M.end(); ++it)
        g<<it->first<<" "<<it->second<<"\n";

    return 0;
}
