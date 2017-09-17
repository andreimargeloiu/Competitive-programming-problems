#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <cassert>
#define MAXN 1005
#define MAXM 500005

using namespace std;

int N, S, nrsol, A[MAXN], B[MAXN];
int SL[MAXM], SR[MAXM];

inline void remove_r(int pos){
    B[0] = 0;
    for (int i = pos + 1; i <= N; ++i)
        B[++B[0]] = A[pos] + A[i];

    int cnt = SR[0], p = 1;
    SR[0] = 0;

    for (int i = 1; i <= cnt; ++i)
        if (B[p] != SR[i] || p > B[0]) SR[++SR[0]] = SR[i];
        else if (p <= B[0]) ++p;
}

inline void add_l(int pos){
    int k = pos - 1, end = SL[0];
    for (int i = SL[0] + pos - 1; i; --i){
        if (!k) break;

        if (end && SL[end] > A[k] + A[pos]) SL[i] = SL[end--];
        else SL[i] = A[k--] + A[pos];
    }
    SL[0] += pos - 1;
}

int solve(int S){
    int l = 1, r = SR[0], nrsol = 0, nextR, nextL;

    while (l <= SL[0] && r > 0){
        while (r && SR[r] + SL[l] > S) --r;
        if (!r) break;

        if (SR[r] + SL[l] == S){
            nextR = r, nextL = l;
            while (nextR && SR[r] == SR[nextR]) --nextR;
            while (nextL <= SL[0] && SL[l] == SL[nextL]) ++nextL;

            nrsol += (r - nextR) * (nextL - l);
            l = nextL, r = nextR;
        }
        else for (++l; SL[l] == SL[l - 1] && l <= SL[0]; ++l);
    }
    return nrsol;
}

int main() {
    freopen("take5.in", "r", stdin);
    freopen("take5.out", "w", stdout);

    scanf("%d %d", &N, &S);
    for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);

    if (N < 5){
        printf("0\n");
        return 0;
    }
    sort(A + 1, A + N + 1);


    // sumele din cate 2 elemente
    for (int i = 4; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            SR[++SR[0]] = A[i] + A[j];

    // le sorteaza crescator
    sort(SR + 1, SR + SR[0] + 1);

    add_l(2);

    for (int i = 3; i <= N - 2; ++i){
        //if (A[i] + SR[SR[0]] + SL[SL[0]] < S) break;
        nrsol += solve(S - A[i]);

        remove_r(i + 1);
        add_l(i);
    }
    printf("%d", nrsol);

    return 0;
}

