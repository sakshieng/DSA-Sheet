#include <iostream>
#include <vector>

using namespace std;

int max_interval_size(long long n)
{
    int max_interval = 0;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int interval_size = n / i - i + 1;
            max_interval = max(max_interval, interval_size);
        }
    }
    return max_interval;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        int result = max_interval_size(n);
        cout << result << endl;
    }

    return 0;
}
