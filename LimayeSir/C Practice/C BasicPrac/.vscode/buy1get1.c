#include <stdio.h>
int main(void)
#define N 200
{
	// your code goes here
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[N];
		int cnt = 0;
		int i = 0;
		for (i = 0; i < N; i++)
		{
			if (s[i] == s[i + 1])
			{
				cnt = cnt + 2;
				i++;
			}
			else
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}