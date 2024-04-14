#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K, B;
        cin >> N >> M >> K >> B;

        vector<vector<int>> grid(N, vector<int>(M));
        vector<vector<int>> dp(N, vector<int>(M, -INF)); // Initialize with negative infinity
        dp[0][0] = 0; // Start at the upper-left corner

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = i; k >= max(0, i - K + 1); k--) {
                    for (int l = j; l >= max(0, j - K + 1); l--) {
                        int total_ice_cubes = 0;
                        bool impossible = false;

                        for (int a = k; a <= i; a++) {
                            for (int b = l; b <= j; b++) {
                                total_ice_cubes += grid[a][b];
                                if (grid[a][b] < B) {
                                    impossible = true;
                                    break;
                                }
                            }
                            if (impossible) {
                                break;
                        }

                        if (!impossible) {
                            dp[i][j] = max(dp[i][j], dp[k][l] + total_ice_cubes);
                        }
                    }
                }
            }
        }

        if (dp[N - 1][M - 1] < 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << dp[N - 1][M - 1] << endl;
        }
    }
    }
    return 0;
}
