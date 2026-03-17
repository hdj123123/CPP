// week2/type_conversions.cpp
// 面向初学者的类型转换示例：隐式/显式转换、列表初始化、dynamic_cast、const_cast、字符串互转
#include <iostream>
#include <string>

struct Base { virtual ~Base() = default; };
struct Derived : Base { void f() {} };

int main() {
    // 隐式转换：int -> double（安全、宽化）
    int a = 5;
    double d = a; // 5 -> 5.0
    std::cout << "隐式: int a=5 -> double d = " << d << '\n';

    // 显式转换（截断）：double -> int
    double x = 3.9;
    int b = static_cast<int>(x); // 截断为 3
    std::cout << "显式: double 3.9 -> static_cast<int> -> " << b << '\n';

    // 列表初始化禁止缩窄：下面这行如果解除注释将导致编译错误
    // int bad{3.9}; // 错误：禁止缩窄
    int c = 3.9; // 允许但会截断
    std::cout << "常规赋值会截断: int c = 3.9 -> c = " << c << '\n';

    // dynamic_cast：在有多态（虚函数）的类层次里用于安全下转
    Base* pb = new Derived();
    Derived* pd = dynamic_cast<Derived*>(pb);
    std::cout << "dynamic_cast 下转结果: " << (pd ? "成功" : "失败") << '\n';
    delete pb;

    // const_cast：移除 const（仅作演示，不推荐修改原对象）
    const int ci = 10;
    const int* pci = &ci;
    int* pi = const_cast<int*>(pci); // 仅用于兼容老接口
    std::cout << "const_cast 读取值（不要修改）：" << *pi << '\n';

    // 字符串与数值互转
    std::string s = "42";
    int n = std::stoi(s);
    std::cout << "std::stoi(\"42\") = " << n << '\n';
    std::string t = std::to_string(3.1415);
    std::cout << "std::to_string(3.1415) = " << t << '\n';

    return 0;
}
