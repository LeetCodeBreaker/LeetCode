class Solution {
	func subsets(_ nums: [Int]) -> [[Int]] {

		let nums = nums.sorted()
			let n = nums.count
			let subsetCount = 1 << n
			var result = [[Int]](repeatElement([Int](), count: subsetCount))

			for i in 0..<subsetCount {
				for j in 0..<n {
					if ( i & (1 << j)) != 0 {
						result[i].append(nums[j])
					}
				}
			}
		return result   
	}
}
