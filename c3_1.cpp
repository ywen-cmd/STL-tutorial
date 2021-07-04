#include<iostream>
using namespace std;

void test0(){
    cout<<"hello"<<endl;
    cout<<"hello"<<flush;
    cout<<"pigfs"<<ends;
    cout<<"ss"<<ends;
}

void test1(){
    bool flag = false;
    int a;
    cout<<"please input a int:\n";
    while(1){
        cin>>a;
        if(cin.fail()){
            if(!flag){
                cout<<"input error,clear non int part\n";
                flag = true;
            } 
            cin.clear();
            cin.ignore();
        }else
        {
            flag = false;
            cout<<a<<endl;
        }
    }
}

int main(){
    test1();
    return 0;
}