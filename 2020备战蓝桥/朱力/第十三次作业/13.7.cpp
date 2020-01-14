#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include<deque>
using namespace std;
//13.7      并查集思想
#define MAXSIZE 1000
void init(int, int[]);
int getf(int);
int dis(int, int);
int f[MAXSIZE] = { 0 };  //不知道如何把递归函数中不用全局变量
int main() {
    int n; //元素个数
    int m;
    int x, y;
    int sum = 0;
    scanf_s("%d %d", &n, &m);
    init(n, f);
    for (int i = 1; i <= m; i++) {
        scanf_s("%d %d", &x, &y);
        dis(x, y); //两个元素各自所属的集合的合并
    }

    for (int i = 1; i < n; i++) {
        if (f[i] == i) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
//数组初始化
void init(int n, int f[]) {
    for (int i = 1; i <= n; i++) f[i] = i;
    return;
}

//寻找根节点递归函数
int getf(int v) {
    if (f[v] = v) return v;
    else {
        // 路径压缩，提高以后寻找根节点的速度
        f[v] = getf(f[v]);
        return f[v];
    }
}
//合并两个子集
int dis(int v, int u) {
    int t1, t2;  //t1,t2分别为v，u的根节点
    t1 = getf(v);
    t2 = getf(u);
    if (t1 != t2) {
        f[t2] = t1;  //t2为t1的祖先
        return 1;
    }
    return 0;
}