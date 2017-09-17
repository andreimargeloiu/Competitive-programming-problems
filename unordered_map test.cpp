# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
typedef pair <int, int> mapkey;
struct hashname {
    size_t operator()(const mapkey &key ) const {
        return hash<int>()(key.first) ^ hash<int>()(key.second);
    }
};
unordered_map <mapkey, int, hashname> M;

int i,j,n,m,x,VV;
int main () {
    M[mp(1, 2)]=5;
    g<<M[mp(1, 2)]<<"\n";
    g<<M[mp(4, 5)];

    return 0;
}
