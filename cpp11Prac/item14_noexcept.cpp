#include <iostream>
using namespace std;
/**
 * 当你设计的接口是不抛出异常的时候，加上noexcept
 **/
auto noexceptFinc = []() noexcept {};
auto execeptFunc = [] {};
int main()
{
    cout << noexcept(noexceptFinc()) << endl;
    cout << noexcept(execeptFunc()) << endl;
    system("pause");
}