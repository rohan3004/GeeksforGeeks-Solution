class Solution {
  public:
    string URLify(string &s) {
        // code here
        string t="";
        t.reserve(s.length());
        for (auto i : s) {
            if (i == ' ') { 
                t += "%20";
            } else {
                t += i;
            }
        }
        return t;
    }
};