func exist(board [][]byte, word string) bool {
	out_of_range := func(i, j int) bool {
		return i < 0 || j < 0 || len(board) <= i || len(board[0]) <= j
	}
	for i, row := range board {
		for j, _ := range row {
			var dfs func(int, int, string) bool
			dfs = func(i, j int, word string) bool {
				if out_of_range(i, j) {
					return false
				}
				if board[i][j] != word[0] {
					return false
				}
				if len(word) == 1 {
					return true
				}
				buf := board[i][j]
				board[i][j] = '-'
				if dfs(i-1, j, word[1:]) {
					return true
				}
				if dfs(i+1, j, word[1:]) {
					return true
				}
				if dfs(i, j-1, word[1:]) {
					return true
				}
				if dfs(i, j+1, word[1:]) {
					return true
				}
				board[i][j] = buf
				return false
			}
			if dfs(i, j, word) {
				return true
			}
		}
	}
	return false
}