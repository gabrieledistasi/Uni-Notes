def count_peaks(nums):

    n = len(nums)
    c = 0

    for i in range(1, n-1): 
        if nums[i] > nums[i-1] and nums[i] > nums[i+1]: 
            c+=1
    
    return c





nums = [1,5,2,7,3,4,1]
print(count_peaks(nums))

#complessità temporale O(n), spaziale O(1)