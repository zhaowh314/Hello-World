//枚举思想与递归算法
//下台阶问题
#include <iostream>
using namespace std;

/// 楼梯高度: 使用“整型常量”存储，既有类型信息，也不可更改（可以防止误操作）。
const int TARGET_H = 4;  // 固定了楼梯高度 – 方便算法测试和验证

/// 方案总数、方案内容
int num, path[TARGET_H]; // 常量可以用于数组大小的定义

/// 第step步，从高度height开始，继续下楼
void Try(int height, int step);

int main() {
    /// 总方案数初值为0【楼梯高度设置成了常量TARGET_H，无需用户输入】
    num = 0;

    /// 第0步，从高度TARGET_H出发
    Try(TARGET_H, 0); // 函数形参：height = TARGET_H, step = 0

    return 0;
}
/// 第step步，从高度height开始，继续下楼
void Try(int height, int step) {
    /// 递归中止条件：到达楼梯底层
    if (height == 0) {
        num++;
        cout << num << ": ";
        for (int i = 0; i < step; i++) cout << path[i] << ' ';
        cout << endl;
        return;
    }
    /// 依次尝试不同的下楼步数(循环变量i是可能的步数)
    for (int i = 1; i <= 3; i++) {
        /// 1. 计算新高度
        int new_height = height - i;
        /// 2. 高度是否可行？
        if (new_height < 0) break; /// 这里能用continue吗?
        /// 3. 记录当前步数
        path[step] = i;
        /// 4. 继续向目标前进
        Try(new_height, step + 1);
    }
}

//跳马问题
#include <iostream>        // 优化方向：（编程经验）用结构数组代替平行数组
using namespace std;

int dx[] = { 1, 2, 2, 1 }, dy[] = { 2, 1, -1, -2 };
int num, path[100][2];

void Jump(int x, int y, int step);

int main() {
    // 初始方案数置0
    num = 0;

    // 从位置(0,0)出发，第0步
    Jump(0, 0, 0);

    return 0;
}
void Jump(int x, int y, int step) {
    // 是否到达目标？
    if ((x == 8) && (y == 4)) {
        num++;    // 方案数加1
        cout << num << ": ";
        for (int i = 0; i < step; i++) // 从起点开始输出各步的坐标
            cout << "(" << path[i][0] << ", " << path[i][1] << ") ";
        cout << endl;

        return;
    }
    // 遍历四种跳步方向
    for (int k = 0; k < 4; k++) {
        int x1 = x + dx[k], y1 = y + dy[k];

        // 若(x1, y1)不可行，则放弃当前测试，转至下一个跳步方案
        if ((x1 < 0) || (x1 > 8) || (y1 < 0) || (y1 > 4)) continue;

        path[step][0] = x1;
        path[step][1] = y1;

        /// 从(x1, y1)出发到目标点，有多少种跳法？--- 问题性质相同，规模缩小：递归！
        Jump(x1, y1, step + 1);
    }
}


//每次尝试一个方案后，都要退回到初始状态
#include <iostream>       
using namespace std;
/// 读者与书本的编号都是基于0的
int like[5][5] = { {0, 0, 1, 1, 0},
                    {1, 1, 0, 0, 1},
                    {0, 1, 1, 0, 1},
                    {0, 0, 0, 1, 0},
                    {0, 1, 0, 0, 1} };
int num; /// 方案数
int assigned[5]; /// assigned[book_id] = reader_id，值为-1表示没有被分配
void Try(int reader);

int main() {
    // 设置分书方案数初始值为0
    num = 0;

    /// 设置书本初始状态为未分配
    for (int book = 0; book < 5; book++) assigned[book] = -1;

    /// 从第0个读者开始，寻找所有分书方案
    Try(0);

    return 0;
}
void Try(int reader) {
    /// 递归中止条件：所有读者均已分配合适书籍
    if (reader == 5) {
        num++;
        cout << "第" << num << "个方案（5本书的读者编号）: ";
        for (int i = 0; i < 5; i++) cout << assigned[i] << ' ';
        cout << endl;
        return;
    }
    /// 逐一为每本书找到合适的读者
    for (int book = 0; book < 5; book++) {
        /// 是否满足分书条件
        if ((like[reader][book] != 1) || assigned[book] != -1) continue;
        /// 记录当前这本书的分配情况
        assigned[book] = reader;
        /// 从下一位读者开始，分配剩余书籍的所有方案
        Try(reader + 1);
        /// 尝试下一种分书方案前，需要将本次分配的书退还（回溯），即恢复“未分配”状态
        assigned[book] = -1;
    }
}

//八皇后问题
void Try(int col) {
    /// 递归中止条件：所有列均已放上皇后了
    if (col == 9) {
        Num++;

        cout << "方案" << Num << "：";
        for (int k = 1; k <= 8; k++) cout << Q[k] << " ";
        cout << endl;

        return;
    }

    /// 依次尝试当前列的 8 行位置
    for (int row = 1; row <= 8; row++) {
        /// 判断拟放置皇后的位置是否安全
        if (!S[row] || !R[col + row] ||
            !L[col - row + OFFSET]) continue;

        /// 记录位置信息（行号)
        Q[col] = row;

        /// 修改三个方向的安全性标记
        S[row] = false;
        L[col - row + OFFSET] = false;
        R[col + row] = false;

        /// 递归尝试放下一列
        Try(col + 1);

        /// 回溯：恢复三个方向原有安全性
        S[row] = true;
        L[col - row + OFFSET] = true;
        R[col + row] = true;
    }

}

