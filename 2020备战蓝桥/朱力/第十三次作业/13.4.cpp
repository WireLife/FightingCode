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

//给图形四周围上一圈由-1；
//判断每个0的四周（上下左右）是否存在-1，
//若存在-1，把0变为为-1。最后只要计算0的个数就行了。
//以上过程就是不断缩小墙
//13.4
int a[12][12];//围墙给定确定的才能确定初始条件统一，防止原数组边缘上有点

int main()
{
    int count = 0;//统计点的个数
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < 12; i++) {//围墙赋值
        a[i][0] = -1;
        a[0][i] = -1;
        a[i][11] = -1;
        a[11][i] = -1;
    }
    cout << "请输入数据，从左到右，从上到下：" << endl;
      
    for (int i = 1; i < 11; i++) {//输入数据到数组
        for (int j = 1; j < 11; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < 11; i++) {//逐步缩小围墙
        for (int j = 1; j < 11; j++) {
            if (a[i][j] == 0 && a[i][j - 1] == -1)
                a[i][j] = -1;
            if (a[i][j] == 0 && a[i][j + 1] == -1)
                a[i][j] = -1;
            if (a[i][j] == 0 && a[i - 1][j] == -1)
                a[i][j] = -1;
            if (a[i][j] == 0 && a[i + 1][j] == -1)
                a[i][j] = -1;
        }
    }

    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; i++) {
            if (a[i][j] == 0)
                count++;
        }
    }
    cout << "个数是" << count << endl;
    return 0;
}
