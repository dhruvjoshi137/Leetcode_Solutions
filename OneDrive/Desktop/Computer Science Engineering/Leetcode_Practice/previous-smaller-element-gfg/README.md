# Previous Smaller Element (GFG)

## Problem Description

Given an array of integers, find the previous smaller element for every element in the array. The previous smaller element of an element `x` is the first smaller element on the left side of `x` in the array.

For each element in the array, find the nearest element to its left which is smaller than it. If no such element exists, output `-1`.

**Example:**
```
Input: arr[] = [4, 5, 2, 10, 8]
Output: [-1, 4, -1, 2, 2]

Explanation:
- For 4: No smaller element on left → -1
- For 5: 4 is smaller → 4
- For 2: No smaller element on left → -1
- For 10: 2 is the nearest smaller → 2
- For 8: 2 is the nearest smaller → 2
```

## Approach

This solution uses a **monotonic stack** approach:
1. Traverse the array from **right to left**
2. Maintain a stack to keep track of elements
3. For each element:
   - If stack is empty, push `-1` (no smaller element)
   - If top of stack is smaller than current element, it's the answer
   - Otherwise, pop all elements from stack that are greater than or equal to current element
4. Push the current element to stack
5. Reverse the result array before returning

## Complexity

- **Time Complexity**: O(n) - Each element is pushed and popped from stack at most once
- **Space Complexity**: O(n) - For the stack and result array

## Tags
`Stack` `Monotonic Stack` `Array`
