class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    for(int i=S.length()-1; i!=-1; --i){
      if( S[i]=='-' ) S.erase( S.begin()+i );
      if( 'a'<=S[i] && S[i]<='z' ) S[i] += 'A'-'a';
    }
    reverse(S.begin(), S.end());
    string separated;
    for(int i=0; i<S.length(); ++i){
      separated += S[i];
      if( (i+1)%K==0 && i!=S.length()-1 ) separated += '-';
    }
    reverse(separated.begin(), separated.end());
    return separated;
  }
};