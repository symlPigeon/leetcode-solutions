class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            a.swap(b);
        }
        // make sure a is longer than b
        b.insert(0, a.length() - b.length(), '0');
        string c = "";
        int carrier = 0;
        for (int idx = a.length() - 1; idx >= 0; idx--) {
            int bit = a[idx] - '0' + b[idx] - '0' + carrier;
            c = ((bit & 1) == 1 ? "1" : "0") + c;
            carrier = bit >> 1;
        }
        if (carrier != 0) {
            c = "1" + c;
        }
        return c;
    }
};