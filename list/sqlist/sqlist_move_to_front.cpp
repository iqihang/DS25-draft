#include "sqlist.h"

void MoveToFront(SqList& va, ElemType x) {
    int cnt = 0;
    for (int i = va.length - 1, j = va.length - 1; i >= 0; --i) {
        if (va.data[i] == x) {
            ++cnt;  // 记录x的个数
        } else {
            va.data[j--] = va.data[i];  // 非x元素循环右移
        }
    }
    for (int i = 0; i < cnt; ++i) {
        va.data[i] = x;  // 前cnt个位置赋值为x
    }
}

int main() {
    SqList l;
    ElemType a[] = {6, 2, 3, 4, 6, 7, 8, 6};

    CreateList(l, a, 8);
    PrintList(l);

    MoveToFront(l, 6);  // 测试一般情况+边界数据
    PrintList(l);

    MoveToFront(l, 8);  // 测试一般情况
    PrintList(l);

    MoveToFront(l, 1);  // 测试特殊情况
    PrintList(l);

    return 0;
}