<h2><a href="https://leetcode.com/problems/next-permutation">31. Next Permutation</a></h2><h3>Medium</h3><hr><p>A <strong>permutation</strong> of an array of integers is an arrangement of its members into a sequence or linear order.</p>

<ul>
	<li>For example, for <code>arr = [1,2,3]</code>, the following are all the permutations of <code>arr</code>: <code>[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]</code>.</li>
</ul>

<p>The <strong>next permutation</strong> of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the <strong>next permutation</strong> of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).</p>

<ul>
	<li>For example, the next permutation of <code>arr = [1,2,3]</code> is <code>[1,3,2]</code>.</li>
	<li>Similarly, the next permutation of <code>arr = [2,3,1]</code> is <code>[3,1,2]</code>.</li>
	<li>While the next permutation of <code>arr = [3,2,1]</code> is <code>[1,2,3]</code> because <code>[3,2,1]</code> does not have a lexicographical larger rearrangement.</li>
</ul>

<p>Given an array of integers <code>nums</code>, <em>find the next permutation of</em> <code>nums</code>.</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a></strong> and use only constant extra memory.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> [1,2,3]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,5]
<strong>Output:</strong> [1,5,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

https://youtu.be/LuLCLgMElus?si=mXWZLbL6BdzB8VGv
https://youtu.be/quAS1iydq7U?si=PIsu74SbOJjt8ZSk


Traverse to Find the Pivot: We start by traversing the array from the end to the beginning. We look for the first index i where nums[i] < nums[i + 1]. This step locates the longest non-increasing suffix, and i is identified as the pivot. This is completed in O(n) time complexity, where n is the length of the array.

Find the Successor to the Pivot: If a pivot is found (the array is not entirely non-increasing), we again traverse the array from the end to find the first index j where nums[j] > nums[i]. The element at j is the smallest element greater than the pivot within the suffix. This step ensures we get the next permutation.

Swap the Pivot and its Successor: We swap the elements at i and j. Now, the pivot is at the place of its immediate successor which is the minimum necessary increment to the current permutation.

Reverse the Suffix: Finally, the suffix starting from i+1 till the end of the array is reversed. Since the suffix was in a non-increasing order, reversing it will change it to non-decreasing order. This ensures the remainder of the array is as low as possible to be the next permutation after the incremented pivot.

In-Place and Constant Space: The entire operation does not need any additional storage as all operations are performed on the input array itself. The space complexity is O(1) since no additional space is required regardless of the input size.
