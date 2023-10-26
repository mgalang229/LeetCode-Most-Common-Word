class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (char& c : paragraph) {
            c = tolower(c);
        }
        set<string> s;
        for (string& b : banned) {
            s.insert(b);
        }
        string word = "";
        map<string, int> mp;
        int mx = 0;
        for (char& c : paragraph) {
            if (isalpha(c)) {
                word += c;
            } else {
                if (word == "") {
                    continue;
                }
                mp[word]++;
                if (s.find(word) == s.end()) {
                    mx = max(mx, mp[word]);
                }
                word = "";
            }
        }
        if (word != "") {
            mp[word]++;
            if (s.find(word) == s.end()) {
                mx = max(mx, mp[word]);
            }
        }
        word = "";
        for (char& c : paragraph) {
            if (isalpha(c)) {
                word += c;
            } else {
                if (word == "") {
                    continue;
                }
                if (mp[word] == mx && s.find(word) == s.end()) {
                    return word;
                }
                word = "";
            }
        }
        if (word != "" && mp[word] == mx && s.find(word) == s.end()) {
            return word;
        }
        return "";
    }
};
