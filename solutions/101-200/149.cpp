class Solution {
  public:
    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int gcd(int a, int b, int c) {
        int ab = gcd(a, b);
        return gcd(ab, c);
    }

    vector<int> tan(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return vector<int>({ 1, 0, a[0] });
        }
        int a1 = a[1] - b[1];
        int b1 = -a[0] + b[0];
        int c = b1 * a[1] + a1 * a[0];
        int g = gcd(a1, b1, c);
        if (a1 < 0) {
            g *= -1;
        }
        return vector<int>({ a1 / g, b1 / g, c / g });
    }

    int maxPoints(vector<vector<int>> &points) {
        if (points.size() == 1) {
            return 1;
        }
        const auto hash = [](std::vector<int> p) {
            return std::hash<int>{}(p[0]) ^ std::hash<int>{}(p[1]) ^
                   std::hash<int>{}(p[2]);
        };
        unordered_set<vector<int>, decltype(hash)> map;
        int max = 0;
        for (int aidx = 0; aidx < points.size() - 1; aidx++) {
            for (int bidx = aidx + 1; bidx < points.size(); bidx++) {
                vector<int> &a = points[aidx];
                vector<int> &b = points[bidx];
                vector<int> tup = tan(a, b);
                if (map.find(tup) != map.end()) {
                    continue;
                }
                // cout << tup[0] << "x+" <<tup[1] << "y=" << tup[2] << endl;
                map.insert(tup);
                int node_cnt = 0;
                for (int cidx = 0; cidx < points.size(); cidx++) {
                    if (tup[0] * points[cidx][0] + tup[1] * points[cidx][1] ==
                        tup[2]) {
                        node_cnt++;
                    }
                }
                if (node_cnt > max) {
                    max = node_cnt;
                }
            }
        }
        return max;
    }
};