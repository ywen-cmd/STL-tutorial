#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
void display(string name,T& container){
    cout<<name;
    typename T::iterator it;
    for(it=container.begin();it!=container.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}

template<class T>
class Mult{
    T factor;
public:
    Mult(T val=1):factor(val){}
    void operator()(T& elem){ elem*=factor;}
    void SetVal(T val){factor=val;}
};

template<class T>
class A{
    typedef decltype(T()+T()) Rtype;
    Rtype sum;
public:
    A(T x=0):sum(x){}
    void operator()(T elem){ sum+=elem;}
    Rtype GetSum() const {return sum;}
};

int main(){
    vector<int> vt{-3,-2,-1,0,1};
    A<int> a1,a2;
    a2=for_each(vt.begin(),vt.end(),a1);
    cout<<a2.GetSum()<<endl;
    cout<<a1.GetSum()<<endl;
    return 0;
}