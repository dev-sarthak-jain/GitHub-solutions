class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alpha(26, 0);
        int n = word.size();

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            alpha[word[i] - 'a']++;
        }

        // Use a max-heap to keep track of the highest frequencies
        priority_queue<int> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 0) {
                maxHeap.push(alpha[i]);
            }
        }

        int ans = 0;
        int multiplier = 1;

        // Calculate the minimum pushes
        while (!maxHeap.empty()) {
            for (int i = 0; i < 8 && !maxHeap.empty(); i++) {
                int freq = maxHeap.top();
                maxHeap.pop();
                ans += freq * multiplier;
            }
            multiplier++;
        }

        return ans;
    }
};
