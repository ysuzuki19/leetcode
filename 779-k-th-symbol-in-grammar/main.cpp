class Solution {
public:
  int kthGrammar(int N, int K) {
    //return K==1? 0 : 1<<(N-2)>=K? kthGrammar(N-1, K): kthGrammar(N-1, K-(1<<(N-2)))? 0 : 1;
    if (K == 1) return 0;
    if (1<<(N-2) >= K) {
      return kthGrammar(N-1, K);
    } else {
      return kthGrammar(N-1, K - (1<<(N-2)))? 0 : 1;
    }
  }
};