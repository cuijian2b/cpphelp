#include <iostream>
using namespace std;

class classA
{
public:
    classA(int data) : a(data) {
        cout << "classA()" << endl;
    }
    ~classA() {
        cout << "~classA()" << endl;
    }

    static int getState() {
        return st;
    }
private:
    static int st;
private:
    int a;
};
int classA::st = 0;

class classB : public classA
{
public:
    classB() : classA(1) {
        cout << "classB()" << endl;
    }
    ~classB() {
        cout << "~classB()" << endl;
    }

private:
    char a;
};

int main()
{
    cout << "hello world" << endl;
    
    classA a(10);
    cout << "size of a " << sizeof(a) << endl;
    // cout << "data of a " << a.a << endl;
    
    classB b;
    cout << "size of b " << sizeof(b) << endl;
    // cout << "data of b " << b.a << endl;
    /*
    classA * pA = new classB();
    delete pA;
    */
    return 0;
}