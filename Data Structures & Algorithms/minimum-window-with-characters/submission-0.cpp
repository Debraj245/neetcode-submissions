class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;

        for (char ch : t) {
            tMap[ch]++;
        }

        int windowStart = 0;
        int matched = 0;
        int minLength = INT_MAX;
        int start = 0;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char currChar = s[windowEnd];

            if (tMap.count(currChar)) {
                tMap[currChar]--;
                if (tMap[currChar] >= 0)
                    matched++;
            }

            while (matched == t.size()) {
                if (windowEnd - windowStart + 1 < minLength) {
                    minLength = windowEnd - windowStart + 1;
                    start = windowStart;
                }

                char leftChar = s[windowStart];

                if (tMap.count(leftChar)) {
                    if (tMap[leftChar] == 0)
                        matched--;

                    tMap[leftChar]++;
                }

                windowStart++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};