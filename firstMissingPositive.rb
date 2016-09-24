# @param# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
    nums.insert(0, 0)
    count = nums.size
    tmp = 0
    for i in 0...count do
        if i > 0 && nums[i] != i then
            tmp = nums[i]
            while tmp > 0 && tmp < count && nums[tmp] != tmp do
                tt = nums[tmp]
                nums[tmp] = tmp
                tmp = tt
            end
        end
    end
    for i in 1...count do
        if nums[i] != i then
            return i
        end
    end
    return count
end

puts  first_missing_positive([0])
