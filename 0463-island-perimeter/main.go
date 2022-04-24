func islandPerimeter(grid [][]int) int {
	out_of_range := func(i, j int) bool {
		return i < 0 || j < 0 || len(grid) <= i || len(grid[0]) <= j
	}
	lines := 0
	for i, row := range grid {
		for j, e := range row {
			if e == 1 {
				if out_of_range(i-1, j) || grid[i-1][j] == 0 {
					lines++
				}
				if out_of_range(i+1, j) || grid[i+1][j] == 0 {
					lines++
				}
				if out_of_range(i, j-1) || grid[i][j-1] == 0 {
					lines++
				}
				if out_of_range(i, j+1) || grid[i][j+1] == 0 {
					lines++
				}
			}
		}
	}
	return lines
}