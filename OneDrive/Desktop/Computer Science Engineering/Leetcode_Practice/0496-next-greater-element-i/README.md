# [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

## Problem Description

The next greater element of some element `x` in an array is the first greater element that is to the right of `x` in the same array.

You are given two distinct 0-indexed integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the next greater element of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return an array `ans` of length `nums1.length` such that `ans[i]` is the next greater element as described above.

## Approach

This solution uses a monotonic stack approach:
- Traverse the array from right to left
- Maintain a stack to keep track of elements
- For each element, pop all smaller elements from stack
- The top of stack (if exists) is the next greater element
- Push current element to stack

## Complexity

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
