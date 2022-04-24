class Solution {
  class Checker {
    array<bool, ':'> field_; // ':' is next to '9'
    public:
      void reset() {
        for (int i='0'; i<':'; ++i) {
          field_[i] = false;
        }
      }
      bool set(int key) {
        if (key == '.') return true; // not count empty grid
        if (field_[key]) return false;
        field_[key] = true;
        return true;
      }
  };

  Checker checker;
  
  // (i, j) is left-top corner of 3x3 matrix!
  bool checkMatrix(vector<vector<char>> const& board, size_t i, size_t j) {
    checker.reset();
    for (int i_=0; i_<3; i_++) {
      for (int j_=0; j_<3; j_++) {
        if (!checker.set(board[i+i_][j+j_])) return false;
      }
    }
    return true;
  }
  
  bool checkRow(vector<vector<char>> const& board, size_t i) {
    checker.reset();
    for (int j=0; j<board[i].size(); ++j) {
      if (!checker.set(board[i][j])) return false;
    }
    return true;
  }
  
  bool checkCol(vector<vector<char>> const& board, size_t j) {
    checker.reset();
    for (int i=0; i<board.size(); ++i) {
      if (!checker.set(board[i][j])) return false;
    }
    return true;
  }
  
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i=0; i<board.size(); ++i) {
      if (!checkRow(board, i)) return false;
    }
    for (int j=0; j<board.size(); ++j) {
      if (!checkCol(board, j)) return false;
    }
    for (int i=0; i<board.size(); i+=3) {
      for (int j=0; j<board[i].size(); j+=3) {
        if (!checkMatrix(board, i, j)) return false;
      }
    }
    return true;
  }
};