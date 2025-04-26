class Solution {
  private:
    std::vector<std::vector<int>> is_visited;
    std::unordered_map<int, bool> map;

  public:
    bool dfs(std::vector<std::vector<char>> &board, int x, int y, int id) {
        // std::cout << x << " " << y << " " << id << std::endl;
        this->is_visited[x][y] = id;
        bool flag = (x != 0 && board[x - 1][y] == 'O' &&
                             this->is_visited[x - 1][y] == 0 ?
                         dfs(board, x - 1, y, id) :
                         false);
        flag |= (x != board.size() - 1 && board[x + 1][y] == 'O' &&
                         this->is_visited[x + 1][y] == 0 ?
                     dfs(board, x + 1, y, id) :
                     false);
        flag |= (y != 0 && board[x][y - 1] == 'O' &&
                         this->is_visited[x][y - 1] == 0 ?
                     dfs(board, x, y - 1, id) :
                     false);
        flag |= (y != board[0].size() - 1 && board[x][y + 1] == 'O' &&
                         this->is_visited[x][y + 1] == 0 ?
                     dfs(board, x, y + 1, id) :
                     false);
        return flag || (x == 0 || y == 0 || x == board.size() - 1 ||
                        y == board[0].size() - 1);
    }
    void solve(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            this->is_visited.push_back(std::vector<int>(board[0].size(), 0));
        }
        int cnt = 1;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == 'O' && this->is_visited[x][y] == 0) {
                    bool ans = dfs(board, x, y, cnt);
                    // std::cout << "dfs: " << x << " " << y << "  " << ans <<
                    // std::endl;
                    this->map[cnt] = ans;
                    cnt += 1;
                }
            }
        }
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (!this->map[this->is_visited[x][y]]) {
                    board[x][y] = 'X';
                }
            }
        }
    }
};