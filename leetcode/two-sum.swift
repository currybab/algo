class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict: [Int : Int] = [:]
        for i in 0 ..< nums.count {
            dict[nums[i]] = i
        }
        for i in 0 ..< nums.count {
            if let j = dict[target - nums[i]], i != j {
                return [i, j]
            }
        }
        return [];
    }
}
