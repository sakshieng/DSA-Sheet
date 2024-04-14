// https://www.codechef.com/START122C/problems/ARYAGRID

#include <iostream>
using namespace std;
long long solve(long long N, long long M, long long X0, long long Y0, long long L)
{
    long long cnt = 1;
    if (L == 1) {
        return (long long)N * M;
    } else {
        int up = (X0 - 1) / L;
        int down = (N - X0) / L;
        int left = (Y0 - 1) / L;
        int right = (M - Y0) / L;

        cnt = 1LL + (up + down) + (left + right) + (up + down) * (long long)(left + right);
    }
    return cnt;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long N, M, X0, Y0, L;
        cin >> N >> M >> X0 >> Y0 >> L;
        long long result = solve(N, M, X0, Y0, L);
        cout << result << endl;
    }
    return 0;
}
int32_t main(){
    long long t;
    cin >> t;
    while (t--)
    {
    long long N, M, X0, Y0, L;
    cin >> N >> M >> X0 >> Y0 >> L;
    long long row = ((N-X0)/L)+((X0-1)/L+1);
    long long col = ((M-Y0)/L)+((Y0-1)/L+1);
    long long ans = row*col;
    cout << ans << endl;
    }
    return 0;
}