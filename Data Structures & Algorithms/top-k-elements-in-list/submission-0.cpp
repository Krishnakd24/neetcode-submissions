
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }

        std::vector<std::vector<int>> buckets(n + 1);
        for (auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }

        std::vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};