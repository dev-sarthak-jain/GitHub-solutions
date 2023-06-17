class Solution {
public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        unordered_map<char, int> map;
        
        for (const char c : magazine) {
            map[c]++;
        }
        
        for (const char c : ransomNote) {
            auto it = map.find(c);
            if (it == map.end() || it->second <= 0) {
                return false;
            }
            it->second--;
        }
        
        return true;
    }
};