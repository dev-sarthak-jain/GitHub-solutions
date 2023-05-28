class Solution {
public:
    unordered_map<string,string> map;
    string s = "";
    string encode(string longUrl) {
        s = s+"a";
        map[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));