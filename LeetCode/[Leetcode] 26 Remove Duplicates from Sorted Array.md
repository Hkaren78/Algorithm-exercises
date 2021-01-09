# [Leetcode] 26 Remove Duplicates from Sorted Array

### 题目

给定一个排序数组，你需要在 **原地** 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 **O(1) 额外空间**的条件下完成。

示例 1:

```
给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
```

示例 2:

```
给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
```


说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以**「引用」**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```java
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

### 题意分析

目标：移出数组中重复元素

输入：给定数组nums（已排序）

输出：移除后数组的新长度



####  **O(1) 额外空间的意思：**

**额外空间复杂度**，是指一个算法运行过程中额外申请的空间。O(1)额外空间，就是算法再运行过程中额外申请的空间为C（C为常数）

**空间复杂度**，是指一个算法运行的过程占用的空间，这个空间包括输入参数的占用空间和额外申请的空间。



### 解题思路

#### 方法1 ：双指针法

#### [参考](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shuang-zhi-zhen-shan-chu-zhong-fu-xiang-dai-you-hu/)

首先注意数组是有序的，那么重复的元素一定会相邻。

要求删除重复元素，实际上就是将不重复的元素移到数组的左侧。

考虑用 2 个指针，一个在前记作 p，一个在后记作 q，算法流程如下：

1.比较 p 和 q 位置的元素是否相等。

如果相等，q 后移 1 位

如果不相等，将 q 位置的元素复制到 p+1 位置上，p 后移一位，q 后移 1 位

重复上述过程，直到 q 等于数组长度。

返回 p + 1，即为新数组长度。

![1.png](https://pic.leetcode-cn.com/0039d16b169059e8e7f998c618b6c2b269c2d95b02f43415350bde1f661e503a-1.png)

代码

```java
 public int removeDuplicates(int[] nums) {
    if(nums == null || nums.length == 0) return 0;
    int p = 0;
    int q = 1;
    while(q < nums.length){
        if(nums[p] != nums[q]){
            nums[p + 1] = nums[q];
            p++;
        }
        q++;
    }
    return p + 1;
}
```

**复杂度分析：**

时间复杂度：O(n)。
空间复杂度：O(1)。

**优化：**

考虑如下数组：

![2.png](https://pic.leetcode-cn.com/06e80bea0bfa0dadc6891407a237fef245f950cab74d050027ac3beecb65d778-2.png)

此时数组中没有重复元素，按照上面的方法，每次比较时 nums[p] 都不等于 nums[q]，因此就会将 q 指向的元素原地复制一遍，这个操作其实是不必要的。

因此我们可以添加一个小判断，当 q - p > 1 时，才进行复制。

**代码**

```java
public int removeDuplicates(int[] nums) {
    if(nums == null || nums.length == 0) return 0;
    int p = 0;
    int q = 1;
    while(q < nums.length){
        if(nums[p] != nums[q]){
            if(q - p > 1){
                nums[p + 1] = nums[q];
            }
            p++;
        }
        q++;
    }
    return p + 1;
}
```

**复杂度分析：**

时间复杂度：O(n)。
空间复杂度：O(1)。