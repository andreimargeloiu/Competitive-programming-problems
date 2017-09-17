#include <algorithm>
#include <stdio.h>
#include <vector>

#define MAX 100010
#define bit(x) (x & (x ^ (x - 1)))
#define mp make_pair
#define f first
#define s second

using namespace std;

int n, m;
int on[MAX], pozF[MAX];
pair <int, int> x[MAX];
vector <int> aibAInt[4 * MAX];
vector <int> normAInt[4 * MAX];

inline int cautaBin(int fr, int ls, int nod, int key)
{
    if (fr > ls)
        return 0;

    int med = (fr + ls) / 2;

    if (normAInt[nod][med] <= key && (med == ls || normAInt[nod][med + 1] > key))
        return med;
    if (normAInt[nod][med] <= key)
        return cautaBin(med + 1, ls, nod, key);
    return cautaBin(fr, med - 1, nod, key);
}

inline void addAib(int nod, int loc, int val, int l)
{
    for (int i = loc; i <= l; i += bit(i))
        aibAInt[nod][i] += val;
}

inline int queryAib(int nod, int loc, int l)
{
    int rez = 0;
    for (int i = loc; i; i -= bit(i))
        rez += aibAInt[nod][i];

    return rez;
}

inline void buildAInt(int nod, int fr, int ls)
{
    int med = (fr + ls) / 2;

    aibAInt[nod].resize(ls - fr + 2);
    normAInt[nod].resize(ls - fr + 2);

    if (fr == ls)
        return;

    buildAInt(nod * 2, fr, med);
    buildAInt(nod * 2 + 1, med + 1, ls);
}

inline void formAInt(int nod, int fr, int ls)
{
    int med = (fr + ls) / 2;

    for (int i = fr; i <= ls; i++)
        normAInt[nod][1 + i - fr] = x[i].s;
    sort(normAInt[nod].begin() + 1, normAInt[nod].end());

    if (fr == ls)
        return;

    formAInt(nod * 2, fr, med);
    formAInt(nod * 2 + 1, med + 1, ls);
}

inline void updateAInt(int nod, int fr, int ls, int loc, int val)
{
    int med = (fr + ls) / 2;

    int poz = cautaBin(1, ls - fr + 1, nod, loc);

    addAib(nod, poz, val, ls - fr + 1);

    if (fr == ls)
        return;

    if (pozF[loc] <= med)
        updateAInt(nod * 2, fr, med, loc, val);
    else updateAInt(nod * 2 + 1, med + 1, ls, loc, val);
}

inline int queryAInt(int nod, int fr, int ls, int st, int dr, int k)
{
    if (fr == ls)
        return x[fr].f;

    int med = (fr + ls) / 2;

    int poz1 = cautaBin(1, med - fr + 1, nod * 2, st - 1);
    int poz2 = cautaBin(1, med - fr + 1, nod * 2, dr);

    int ct = queryAib(nod * 2, poz2, med - fr + 1) - queryAib(nod * 2, poz1, med - fr + 1);

    if (ct >= k)
        return queryAInt(nod * 2, fr, med, st, dr, k);
    else return queryAInt(nod * 2 + 1, med + 1, ls, st, dr, k - ct);
}

int main()
{
    freopen("mess.in", "r", stdin);
    freopen("mess.out", "w", stdout);

    scanf("%d %d", &n, &m);

    buildAInt(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i].f);

        x[i].s = i;
    }

    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; i++)
        pozF[x[i].s] = i;

    formAInt(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        on[x[i].s] = 1;
        updateAInt(1, 1, n, x[i].s, on[x[i].s]);
    }

    for (int i = 1; i <= m; i++)
    {
        int caz;
        scanf("%d", &caz);

        if (caz == 1)
        {
            int loc;
            scanf("%d", &loc);

            if (on[loc] == 1)
                on[loc] = -1;
            else on[loc] = 1;
            updateAInt(1, 1, n, loc, on[loc]);
        }
        else
        {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);

            printf("%d\n", queryAInt(1, 1, n, x, y, k));
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
