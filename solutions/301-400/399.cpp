class Solution {
  private:
    vector<vector<double>> matrix;
    unordered_map<string, int> name_map;

  public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        int sum = 0;
        for (auto &equation : equations) {
            auto a = equation[0];
            auto b = equation[1];
            if (this->name_map.find(a) == this->name_map.end()) {
                this->name_map[a] = sum++;
            }
            if (this->name_map.find(b) == this->name_map.end()) {
                this->name_map[b] = sum++;
            }
        }
        // build matrix
        for (int s = 0; s < sum; s++) {
            this->matrix.push_back(vector<double>(sum, -1.0));
        }
        for (int s = 0; s < sum; s++) {
            this->matrix[s][s] = 1;
        }
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            auto value = values[i];
            auto a = this->name_map[equation[0]];
            auto b = this->name_map[equation[1]];
            this->matrix[a][b] = value;
            this->matrix[b][a] = 1 / value;
        }
        for (int k = 0; k < sum; k++) {
            for (int i = 0; i < sum; i++) {
                for (int j = i + 1; j < sum; j++) {
                    if (this->matrix[i][k] != -1 && this->matrix[k][j] != -1) {
                        this->matrix[i][j] =
                            this->matrix[i][k] * this->matrix[k][j];
                        this->matrix[j][i] = 1 / this->matrix[i][j];
                    }
                }
            }
        }
        vector<double> ans;
        for (auto &query : queries) {
            auto a = query[0];
            auto b = query[1];
            if (this->name_map.find(a) == this->name_map.end() ||
                this->name_map.find(b) == this->name_map.end()) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(this->matrix[this->name_map[a]][this->name_map[b]]);
        }
        return ans;
    }
};