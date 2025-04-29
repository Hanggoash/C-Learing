#include<bits/stdc++.h>
using namespace std;
class Matr
{
public:
    int a[10][10];
    Matr(int val=1)
    {
        for(int i=1;i<=5;++i)
            for(int j=1;j<=5;++j)a[i][j]=val;
    }
    Matr (const Matr &mat)//这个地方一定是引用，否则就会触发对象作参数的复制构造函数，自身无限递归。
    {
        for(int i=1;i<=5;++i)
            for(int j=1;j<=5;++j)a[i][j]=mat.a[i][j];
        puts("CopyDone");
    }
    inline void output()
    {
        for(int i=1;i<=5;++i)  
            for(int j=1;j<=5;++j)cout<<a[i][j]<<" \n"[j==5];
    }
};
/*构造函数被调用的三种情况
    1.直接尝试通过 Matr a(b) 在声明的同时进行拷贝 (注：这个操作和 Matr a=b 等价)
    2.对象作为函数的参数 可以理解为从实参到形参的复制构造函数
    3.对象作为函数的返回值 可以理解为从变量到函数返回值的复制构造函数

    2.3.对于引用的情况不生效，因为这个时候参数和返回值其实是一个对象的指针，而不是对象。
 */
Matr &func(Matr &tmp,Matr &tmp1){return tmp;}
int main()
{
    Matr a;//构造函数 缺省版本
    Matr c(11);//构造函数 
    Matr d(c);//复制构造函数 实际上如果自己不写 编译器会加上一个默认的复制函数
    Matr &b=func(c,c);//多参数是在测试复制构造函数的调用次数
    a.output(),b.output();
    return 0;
}
