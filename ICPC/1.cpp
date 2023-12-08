#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int ans = 0;
        int seconds = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] >= K)
            {
                ans++;
                A[i] -= K;
                seconds++;
            }
            if (seconds >= N)
                break;
        }
        cout << ans << endl;
    }

    return 0;
}
