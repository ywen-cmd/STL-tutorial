#include<iostream>
#include<unordered_set>
using namespace std;

template<class T>
void display(char const* name,T& s){
    cout<<name;
    unordered_multiset<int>::iterator it = s.begin();
    while(it != s.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

int main(){
    int a[] = {9,3,9,7,10,3};
    int size = sizeof(a)/sizeof(int);
    unordered_multiset<int> s;
    for(int i=0;i<size;i++) s.insert(a[i]);
    display("set:",s);
    cout<<"++find(3):"<<*(++s.find(3))<<endl;
    cout<<"equal_range(9):"<<*(++s.equal_range(9).first)/*<<","<<*s.equal_range(9).second*/<<endl;
    cout<<"s.erase(3):"<<s.erase(3)<<endl;
    display("set:",s);
    s.erase(s.find(9));
    display("set:",s);
    s.erase(*s.find(7));
    display("set:",s);
    s.clear();
    cout<<"size:"<<s.size()<<endl;
    return 0;
}
