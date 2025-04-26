class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> map(obstacleGrid.size(),
                                vector<int>(obstacleGrid[0].size(), 0));
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] ==
            1) {
            return 0;
        }
        map[0][0] = 1;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i - 1][0] != 1) {
                map[i][0] = map[i - 1][0];
            }
        }
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i - 1] != 1) {
                map[0][i] = map[0][i - 1];
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j - 1] != 1) {
                    map[i][j] += map[i][j - 1];
                }
                if (obstacleGrid[i - 1][j] != 1) {
                    map[i][j] += map[i - 1][j];
                }
            }
        }
        return map[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};