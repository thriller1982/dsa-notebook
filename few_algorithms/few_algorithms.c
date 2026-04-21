#include "few_algorithms.h"

int BinarySearch(const int arr[], int x, int n) {
    int mid, high, low;
    high = n - 1;
    low = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x > arr[mid]) {
            low = mid + 1;
        } else if (x < arr[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int gcd(int m, int n) {
    while (n > 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

long int pow(long int x, long int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return pow(x * x, n / 2);
    } else {
        return pow(x * x, n / 2) * x;
    }
}

long long pow2(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res *= base;
        }
        base *= base;
        exp /= 2;
    }
    return res;
}

#include <stdio.h>

/**
 * 经典二分查找：寻找目标值 target 的确切位置
 * 模式：【闭区间 [l, r]】
 * 原理：将区间当作盲盒 [l, r]，每次打开中间的盲盒看是不是 target。
 *       如果是，直接游戏结束。如果不是，就排除掉一半的盲盒。
 */
int classicBinarySearch(const int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return -1;

    int l = 0;
    int r = numsSize - 1; // 【闭区间】l 和 r 都是可以被检查的合法下标

    // 只要 l <= r，说明区间内至少还有一个盲盒没被检查
    while (l <= r) {
        int mid = l + (r - l) / 2; // 防溢出求中点

        if (nums[mid] == target) {
            return mid;     // 【一击必杀】运气好，直接命中，立刻返回！
        }
        else if (nums[mid] < target) {
            l = mid + 1;    // target 更大，说明 mid 及左边全废了，左推土机推到 mid + 1
        }
        else {
            r = mid - 1;    // target 更小，说明 mid 及右边全废了，右推土机推到 mid - 1
        }
    }

    // 循环结束（l > r），说明所有盲盒都查过了也没有 target
    return -1;
}

/**
 * 万能二分查找：寻找“第一个 >= target 的元素位置”
 * 模式：【闭区间 [l, r]】 + 存档机制
 * 原理：不追求一击必杀，而是遇到符合要求的数字先“存档（ans）”，
 *       然后继续向更优的方向搜索，直到把区间 [l, r] 压缩到空为止。
 */
int universalBinarySearch(const int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return -1;

    int l = 0;
    int r = numsSize - 1; // 依然是【闭区间 [l, r]】
    int ans = -1;         // 【核心】定义一个存档变量，默认值为找不到

    while (l <= r) {      // 焊死：只要区间还有数，就继续榨干它
        int mid = l + (r - l) / 2;

        if (nums[mid] >= target) {  // 发现了一个符合条件的数（>= target）
            ans = mid;              // 【存档】先把它记下来！
            r = mid - 1;            // 【逼近】因为要找“第一个”，所以哪怕当前 mid 达标，
            // 也要往左边看看，把右边界收缩到 mid - 1。
        }
        else {
            l = mid + 1;            // nums[mid] < target，连条件都不满足，左边界无情推进
        }
    }

    // 循环结束时 l > r，ans 里存的就是最后一次达标的最优记录。
    return ans;
}

/**
 * 左闭右开二分查找：寻找“第一个 >= target 的元素位置”
 * 模式：【左闭右开区间 [l, r)】
 * 原理：手里拿着刀切蛋糕，l 是起刀处（包含），r 是落刀的刻度（不包含）。
 *       这种写法不需要单独的 ans 存档变量，最后 l 和 r 会重合在答案上。
 */
int leftClosedRightOpenSearch(const int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return -1;

    int l = 0;
    int r = numsSize; // 【核心区别1】r 是越界位置，不代表实际元素，代表区间的终点刻度

    // 【核心区别2】判断条件是 l < r（或者 l != r）。
    // 只要起刀点和落刀点不是同一个位置，就说明区间里还有元素可以切。
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] >= target) {
            // 【核心区别3】右边界收缩时，r 变成 mid，而不是 mid - 1！
            // 因为 r 本身就是“不包含”的开边界。让 r = mid，
            // 恰好就把 mid 排除在下一次的搜索区间 [l, mid) 之外了。
            r = mid;
        }
        else {
            // 左边界 l 依然是闭边界，所以推土机正常推到 mid + 1
            l = mid + 1;
        }
    }

    // 循环结束时，l 和 r 必然相等（两指针相遇）。
    // 此时的 l（或 r）就是我们要找的位置。
    // 如果 l == numsSize，说明数组里所有元素都小于 target。
    if (l == numsSize) {
        return -1; // 没找到符合要求的数
    }

    return l;
}

#include <stdio.h>

/**
 * 左右边界收缩流：寻找“最后一个 <= target 的元素位置”
 * 模式：【闭区间 [l, r]】 + while(l < r)
 * 原理：不断斩断不可能的区间，直到 l 和 r 相遇（l == r），相遇点就是答案。
 */
int rightBoundarySearch(const int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) return -1;

    int l = 0;
    int r = numsSize - 1; // 依然是闭区间

    // 【核心区别1】条件是 l < r。因为我们要让 l 和 r 相遇作为结束条件。
    while (l < r) {
        // 【核心区别2】这里必须 +1 ！
        // 为什么？因为整数除法是“向下取整”的。
        // 假设只剩下两个元素，比如 l = 0, r = 1。
        // 如果不加 1：mid = (0 + 1) / 2 = 0。
        // 此时如果走到了 l = mid 分支，l 会被赋值为 0。
        // 下一轮循环，l 还是 0，r 还是 1，mid 还是 0，无限死循环！
        // 加上 1 后：mid = (0 + 1 + 1) / 2 = 1。l 会被赋值为 1，l 和 r 相遇，循环结束！
        int mid = l + (r - l + 1) / 2;

        if (nums[mid] <= target) {
            // 当前 mid 满足条件，说明“最后一个 <= target 的数”可能就是 mid，也可能在 mid 右边。
            // 既然 mid 可能是答案，我们绝对不能越过它，所以 l = mid，而不是 l = mid + 1。
            l = mid;
        }
        else {
            // nums[mid] > target，条件不满足，mid 及它右边的全废了。
            // 因为 mid 绝对不可能是答案，所以放心大胆地让 r = mid - 1。
            r = mid - 1;
        }
    }

    // 循环结束时必定有 l == r。
    // 但是，万一整个数组的数都 > target，我们依然没找到满足 <= target 的数。
    // 所以最后需要做一次打补丁的校验。
    if (nums[l] <= target) {
        return l;
    }

    return -1; // 没找到
}