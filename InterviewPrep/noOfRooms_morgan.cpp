#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://maang.in/mocks/attempts/2183?problem_id=49
#define ll long long
#define mod (int)(1e9 + 7)

int countRooms(vector<vector<char>> &map, int n, int m)
{
    cin.tie(NULL);
    int rooms = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m && map[x][y] == '.' && !visited[x][y];
    };

    function<void(int, int)> dfs = [&](int x, int y)
    {
        visited[x][y] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
            {
                dfs(nx, ny);
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.' && !visited[i][j])
            {
                rooms++;
                dfs(i, j);
            }
        }
    }

    return rooms;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int rooms = countRooms(map, n, m);
    cout << rooms << endl;
}
