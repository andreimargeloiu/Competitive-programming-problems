#include <cstdio>
#include <cstring>

#define NMAX 200010
#define INF 666666666

int v[NMAX], tata[NMAX], sz[NMAX];
int stk[NMAX], lastSeen[NMAX], ndist[NMAX];
int i, j, k, N, T, top, sum_ndist, max_length;

int Find(int x)
{
	int y = x, z;

	while (tata[y] > 0)
		y = tata[y];

	// path compression
	while (x != y)
	{
		z = tata[x];
		tata[x] = y;
		x = z;
	}

	return y;
}

void Union(int x, int y)
{
	int tx, ty;

	tx = Find(x);
	ty = Find(y);

	if (sz[tx] <= sz[ty])
	{
		tata[tx] = ty;
		sz[ty] += sz[tx];
	}
	else
	{
		tata[ty] = tx;
		sz[tx] += sz[ty];
	}
}

int main()
{
	freopen("unique.in", "r", stdin);
	freopen("unique.out", "w", stdout);

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &v[i]);

		v[N + 1] = N+1;

		memset(tata, 0, sizeof(tata));
		memset(ndist, 0, sizeof(ndist));
		memset(lastSeen, 0, sizeof(lastSeen));

		for (i = 1; i <= N; i++)
			sz[i] = 1;

		top = 0;
		stk[0] = 0;
		max_length = 0;

		for (i = 1; i <= N + 1; i++)
		{
			sum_ndist = 0;
			while (top > 0 && v[stk[top]] < v[i])
			{
				sum_ndist += ndist[Find(stk[top])];

				if (sum_ndist == v[stk[top]] && (i - stk[top - 1] -1 > max_length))
				{
					max_length = i - 1 - stk[top - 1];
				}

				Union(stk[top], i);
				top--;
			}

			top++;
			stk[top] = i;
			ndist[Find(i)] = sum_ndist + 1;

			if (lastSeen[v[i]] > 0)
			{
				k = Find(lastSeen[v[i]]);
				ndist[k]--;
			}

			lastSeen[v[i]] = i;
		}

		printf("%d\n", max_length);
	}

	return 0;
}
