def find_combinations(nums, target):
    result = []
    nums.sort()
    
    def backtrack(start, path, target):
        if target == 0:
            result.append(path)
            return
        for i in range(start, len(nums)):
            if nums[i] > target:
                break
            if i > start and nums[i] == nums[i-1]:
                continue
            backtrack(i + 1, path + [nums[i]], target - nums[i])
    
    backtrack(0, [], target)
    return result

# Test with the numbers list and target values from 1 to 12
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14]
target_values = range(1, 105)

# Generate and print combinations for each target value
combinations_dict = {}

for target in target_values:
    combinations = find_combinations(numbers, target)
    combinations_dict[target] = combinations
    #print(f"Combinations that sum to {target}: {combinations}")
    print(f'target: {target} and len: {len(combinations)}')
