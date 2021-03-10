#include<iostream>
using namespace std;
/**
 * 模板参数推导
 * 1 条件推导 T* T& const T* 
 * 2 副本推导忽略const 引用 指针 T
 * 3 万能推导 T &&
 * 4 数组推导 T (&) []
 **/
template <typename T>
void f(T c)
{
    c->print();
}

template <typename T>
void f1(T&& param)
{
    param.c = 1;
}

template <typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

class Mytype
{
   public:
    int c;
    void print()
    {
        cout << c <<endl;
        return;
    }
};

int main()
{
    Mytype a;
    a.c = 5;
    f(&a);
    f1(a);
    f(&a);
    int A[30];
    cout << arraySize(A) << endl;
    system("pause");
}