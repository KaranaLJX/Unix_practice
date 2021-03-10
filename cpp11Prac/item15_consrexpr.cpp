#include <iostream>
using namespace std;
/**
 *如果一个值在编译器就已知且为const，将他声明为constexpr，可减少运行时间，扩大这个值可用性
 * **/
constexpr int c = 8;
constexpr int pow(int base, int exp) { return exp == 0 ? 1 : base * pow(base, exp - 1); }
template <size_t N>
constexpr int arraySize(int (&)[N])
{
    return N;
}
int main()
{
    int d[c];
    int w[pow(3, c)];
    cout << arraySize(w);
    system("pause");
}