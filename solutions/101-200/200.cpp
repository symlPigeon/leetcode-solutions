class Solution {
  private:
    vector<vector<bool>> is_visited;

  public:
    void bfs(vector<vector<char>> map, int x, int y) {
        int max_x = map.size();
        int max_y = map[0].size();
        std::queue<std::tuple<int, int>> q;
        q.push({ x, y });
        while (!q.empty()) {
            const auto [x, y] = q.front();
            if (!this->is_visited[x][y]) {
                // std::cout << "(x,y) = " << x << "," << y << std::endl;
                this->is_visited[x][y] = true;
                if (x > 0) {
                    if (map[x - 1][y] == '1' && !this->is_visited[x - 1][y]) {
                        q.push({ x - 1, y });
                    }
                }
                if (y > 0) {
                    if (map[x][y - 1] == '1' && !this->is_visited[x][y - 1]) {
                        q.push({ x, y - 1 });
                    }
                }
                if (x < max_x - 1) {
                    if (map[x + 1][y] == '1' && !this->is_visited[x + 1][y]) {
                        q.push({ x + 1, y });
                    }
                }
                if (y < max_y - 1) {
                    if (map[x][y + 1] == '1' && !this->is_visited[x][y + 1]) {
                        q.push({ x, y + 1 });
                    }
                }
            }
            q.pop();
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0;
        for (int x = 0; x < grid.size(); x++) {
            this->is_visited.push_back(
                std::vector<bool>(grid[0].size(), false));
        }
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == '1' && !this->is_visited[x][y]) {
                    cnt++;
                    this->bfs(grid, x, y);
                }
            }
        }
        return cnt;
    }
};