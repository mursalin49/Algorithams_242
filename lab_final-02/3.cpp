
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int N) {
    if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] == 0) {
        return;
    }

    grid[i][j] = 0;


    dfs(grid, i - 1, j - 1, N);
    dfs(grid, i - 1, j, N);
    dfs(grid, i - 1, j + 1, N);
    dfs(grid, i, j - 1, N);
    dfs(grid, i, j + 1, N);
    dfs(grid, i + 1, j - 1, N);
    dfs(grid, i + 1, j, N);
    dfs(grid, i + 1, j + 1, N);
}

int countWarEagleColonies(vector<vector<int>>& grid) {
    int N = grid.size();
    int colonies = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                colonies++;
                dfs(grid, i, j, N);
            }
        }
    }

    return colonies;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    int colonies = countWarEagleColonies(grid);
    cout << colonies << endl;

    return 0;
}
