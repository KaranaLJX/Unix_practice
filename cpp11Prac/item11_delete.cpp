#include <iostream>
using namespace std;

/**
 2021/03/10
 优先使用=delete来禁用函数，而不是priavte
 **/
bool isLucky(int num) { return num == 1; }
bool isLucky(double) = delete;  //同时拒绝double和float
bool isLucky(bool) = delete;
bool isLucky(char) = delete;

template <typename T>
void processPointer(T* ptr)
{
    return;
}
template <>
void processPointer(void* ptr) = delete;

class Widget
{
   public:
    template <typename T>
    void processPointer(T* ptr)
    {
        return;
    }
    Widget() {}

    Widget(const Widget&) = delete;
    Widget& operator=(const Widget) = delete;
};
template <>
void Widget::processPointer(void* ptr) = delete;

int main()
{
    cout << isLucky(11);
    // cout << isLucky(true); 出错
    // cout << isLucky(33.33); 出错
    Widget widget;
    // Widget widget2=widget; x
    // Widget widget2（widget); x
    int c;
    // widget.processPointer((void*)&c); x
    widget.system("pause");
}