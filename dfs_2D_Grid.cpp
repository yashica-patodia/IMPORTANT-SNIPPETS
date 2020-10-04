#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[1001][1001];
int grid[1001][1001];

bool isValid(int x, int y)
{
    // case when the co-ordinates are out of index
    if (x < 0 || x > N - 1 || y < 0 || y > M - 1)
    {
        return false;
    }

    // If the point is already visited
    if (visited[x][y] == true)
        return false;

    return true;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    visited[x][y] = true;
    cout << grid[x][y] << endl;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));

    cout << "enter the dimension of the grid ";
    cin >> N >> M;
    cout << "Enter the content of the grid" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    dfs(0, 0);

    return 0;
}
