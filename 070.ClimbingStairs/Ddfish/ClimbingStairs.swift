func climbStairs(_ n: Int) -> Int {

	if (n <= 2) { return n }
	var stairs : [Int] = [0,1,2]

		for i in 3...n{
			stairs.append(stairs[i-1]+stairs[i-2])
		}

	return stairs[n]
}
