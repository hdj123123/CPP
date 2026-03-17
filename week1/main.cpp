//main.cpp
#include <iostream>  // 包含输入输出流库，用于cout和cin
#include "add.h"     // 包含自定义头文件add.h，声明add函数

using namespace std;  // 使用标准命名空间，避免每次写std::

int main()  // 主函数，程序入口
{
    int num1 = 2147483647;  // 定义第一个整数变量，赋值为int类型的最大值
    int num2 = 1;           // 定义第二个整数变量，赋值为1
    int result = 0;         // 定义结果变量，初始化为0

    result = add(num1, num2);  // 调用add函数，将num1和num2相加，结果存入result

    cout << "The result is " << result << endl;  // 输出结果到控制台
    return 0;  // 返回0，表示程序正常结束
}