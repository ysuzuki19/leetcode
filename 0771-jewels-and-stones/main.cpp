class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int collections['z'-'A'+1] = {0};
        for(const auto& c : S) collections[c-'A']++;
        int counter = 0;
        for(const auto& c : J) counter += collections[c-'A'];
        return counter;
    }
};