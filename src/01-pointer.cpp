#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int *p = &a;

    // 打印地址
    cout << p << endl;
    cout << &a << endl;

    // 指针解引用
    *p = 1000;
    cout << a << endl;
    cout << sizeof(int *) << endl; // 64位指针占8个字节

    // 空指针
    // int *p1 = NULL;
    // *p1 = 100;

    // const修饰

    int x = 10, y = 20;

    // 常量指针
    const int *p1 = &x;
    // *p1 = 20; 报错
    p1 = &y;
    cout << *p1 << endl;

    // 指针常量
    int *const p2 = &x;
    // p2 = &y; 报错
    *p2 = 30;
    cout << *p2 << endl;

    // 指针遍历数组
    int arr[] = {1, 2, 3, 4, 5};
    int *p3 = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << *p3++ << endl;
    }

    system("pause");
    return 0;
}