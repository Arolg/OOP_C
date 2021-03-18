#include <iostream>
#include <vector>
void foo1(int &a)
{
    a++;
}
template<void (*T)(int &)>
void foo()
{
    int temp = 1;
    T(temp);
    std::cout << "Result is " << temp << std::endl;
}


class func
{
public:
    int operator()(int a)
    {
        if (ans[a] != 0)
            return ans[a];
        if(a < 0)
            return 0;
        if (a == 0)
            return 1;
        else
            return ans[a] = a * operator()(a - 1);
    }

private:
    std::vector<int> ans = {0};
};

int main() {
    func fact;
    fact(5);
    foo<foo1>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
