#include <cstdio>
#define MaxN 100010

int par[MaxN], v[MaxN];

int root(int a)
{
    if (par[a] == a) return a;
    return par[a] = root(par[a]);
}

int main()
{
    freopen ("clues.in", "r", stdin);
    freopen ("clues.out", "w", stdout);
    int n, m, MOD, a, b;
    scanf("%d%d%d", &n, &m, &MOD);

        for (int i = 1; i <= n; ++i) par[i] = i, v[i] = 0;
        // practic fac componentele conexe
        while (m--)
        {
            scanf("%d%d", &a, &b);
            a = root(a), b = root(b);
            if (a != b) par[a] = b;
        }
        // marimea componentei conexe
        for (int i = 1; i <= n; ++i) v[root(i)]++;
        long long ans = 1;
        int cnt = 0;

        for (int i = 1; i <= n; ++i)
            if (v[i]) ans = ans * v[i] % MOD, ++cnt;
        if (cnt == 1) ans = 1 % MOD;

        for (int i = 1; i <= cnt-2; ++i)
            ans = ans * n % MOD;

        printf("%d\n", (int)ans);

    return 0;
}
