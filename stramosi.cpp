#include <cstdio>
#include <vector>

using namespace std;

const int N = 250010, M = 300010;

struct Lista {
    int q, ind;
};

int n, m;
int st [N], ans [M], t [N];
bool used [N];
vector <Lista> L [N];
vector <int> graph [N];

void dfs (int x) {
    int a;
    vector <int> :: iterator it;
    vector <Lista> :: iterator jt;

    st [++ st [0]] = x;
    for (jt = L [x].begin (); jt != L [x].end (); ++ jt) {
        a = st [0] - (*jt).q;
        if (a <= 0)
            ans [(*jt).ind] = 0;
        else ans [(*jt).ind] = st [a];
    }
    used [x] = 1;
    for (it = graph [x].begin (); it != graph [x].end (); ++it)
        if (!used [*it])
            dfs (*it);
    st [0] --;
}

int main () {
    int i, q, x;
    Lista temp;

    freopen ("stramosi.in", "r", stdin);
    freopen ("stramosi.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i = 1; i <= n; i ++) {
        scanf ("%d", &t [i]);
        graph [t [i]].push_back (i);
    }
    for (i = 1; i <= m; i ++) {
        scanf ("%d%d", &x, &q);
        temp.q = q;
        temp.ind = i;
        L [x].push_back (temp);
    }
    for (i = 1; i <= n; i ++)
        if (t [i] == 0) {
            st [0] = 0;
            dfs (i);
        }
    for (i = 1; i <= m; i ++)
        printf ("%d\n", ans [i]);
    return 0;
}
