

def middle(a, b, c)
    return [a, b, c].sort[1]
end


def trap(height)
    if height.size() == 0 
        return 0
    end
    total = 0
    left = lp = 0
    right = rp = height.size()-1
    cmx = height[left] < height[right] ? height[left] : height[right]
    while lp != rp do
        if height[lp] > height[rp]
            rp -= 1
            total += (cmx > height[rp] ? (cmx - height[rp]) : 0)
            cmx = middle(cmx, height[lp], height[rp])
        else
            lp += 1
            total += (cmx > height[lp] ? (cmx - height[lp]) : 0)
            cmx = middle(cmx, height[lp], height[rp])
        end
    end
    return total
end

arr = [2, 1, 4, 3, 1, 2]
puts trap(arr)
