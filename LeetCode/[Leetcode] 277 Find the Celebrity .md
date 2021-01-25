# 【Leetcode】277 搜寻名人

### 题目描述

[来源](https://leetcode-cn.com/problems/find-the-celebrity)

假设你是一个专业的狗仔，参加了一个 n 人派对，其中每个人被从 0 到 n - 1 标号。
在这个派对人群当中可能存在一位 “名人”。

所谓 “名人” 的定义是：其他所有 n - 1 个人**都认识**他/她，而他/她并**不认识其他任何**人。

现在你想要确认这个 “名人” 是谁，或者确定这里没有 “名人”。

而你唯一能做的就是问诸如 “A 你好呀，请问你认不认识 B呀？” 的问题，以确定 A 是否认识 B。

你需要在（渐近意义上）**尽可能少**的问题内来确定这位 “名人” 是谁（或者确定这里没有 “名人”）。

在本题中，你可以使用辅助函数 `bool knows(a, b)` 获取到 A 是否认识 B。请你来实现一个函数 `int findCelebrity(n)`。

派对最多只会有一个 “名人” 参加。

若 “名人” 存在，请返回他/她的编号；若 “名人” 不存在，请返回 -1。

示例一：

<img src="C:\Users\14270\AppData\Roaming\Typora\typora-user-images\image-20210109172153597.png" alt="image-20210109172153597" style="zoom:50%;" />

```
输入: graph = [
  [1,1,0],
  [0,1,0],
  [1,1,1]
]
输出: 1
```

解析: 

​		有编号分别为 0、1 和 2 的三个人。 graph [i] [j] = 1 代表编号为 i 的人认识编号为 j 的人， 而 graph [i] [j] = 0 则代表编号为 i 的人不认识编号为 j 的人。 “名人” 是编号 1 的人，因为 0 和 2 均认识他/她，但 1 不认识任何人。

示例二：

<img src="C:\Users\14270\AppData\Roaming\Typora\typora-user-images\image-20210109172317128.png" alt="image-20210109172317128" style="zoom:50%;" />

```
输入: graph = [
  [1,0,1],
  [1,1,0],
  [0,1,1]
]
输出: -1
```

解析: 

​		没有 “名人”

注意: 

​		该有向图是以邻接矩阵的形式给出的，是一个 n × n 的矩阵，  a[i] [j] = 1 代表 i 与 j 认识，a[i] [j] = 0 则代表 i 与 j 不认识。 请记住，您是无法直接访问邻接矩阵的。

### 题意分析

判断一个派对上是否有名人（其他人都认识他，但他不认识其他人），且派对上名人个数≤1。

输入：数组graph[i] [j]，graph [i] [j] = 1 （或0）代表编号为 i 的人认识（或不认识）编号为 j 的人

输出：名人的编号（有名人）或-1（没有名人）

### 算法实现

#### 方法一：直接法

```java
class Solution {
public:int findCelebrity(int n) {
        int i, j, count, ans = -1;
        bool famous;
        for(i = 0; i < n; ++i)
        {
        	famous = true;
        	count = 1;//自己认识自己
        	for(j = 0; j < n; ++j)
        	{
        		if(i == j)
        			continue;
        		if(knows(j, i))//j 认识 i
        			count++;
        		if(count < j+1)//有人不认识 i
        			break;//不是名人
        		if(knows(i,j))//他还认识别人,不是名人
        		{
        			famous = false;
        			break;
        		}
        	}
        	if(famous && count == n)//都认识他
        	{
        		ans = i;
        		break;
        	}
        }
        return ans;
    }
};
```

#### 方法二：排除法

若A认识B，则A不是名人；若A不认识B，则B不是名人。

循环判断A 是否认识B。最后检查确认，是否其他人都认识这个“名人”，以及这个“名人”都不认识其他人。

##### 代码

```java
public class Solution extends Relation {
    public int findCelebrity(int n) {
        int celebrity = 0;
        for(int i=1; i<n; i++) {
            if (knows(celebrity, i)) celebrity = i;
        }
        for(int i=0; i<n; i++) {
            if (celebrity != i && knows(celebrity, i)) return -1;
            if (celebrity != i && !knows(i, celebrity)) return -1;
        }
        return celebrity;
    }
}
```

