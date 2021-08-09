class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(costs.begin(), costs.end());
      int tip = 0;
      for (int i=0; i<costs.size(); ++i) {
        tip += costs[i];
        if (tip > coins) return i;
      }
      return costs.size();
    }
};