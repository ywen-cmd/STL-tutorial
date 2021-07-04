#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
    ostream_iterator<int> out_it(cout,",");
    vector<int> a{1,2,3,4,5};
    copy(a.begin(),a.end(),out_it);
    return 0;
}