#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector <int> vec;
int main()
{
    //scanf()를 이용해도 시간초과
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num, fd;
    int data;
    cin >> num >> fd;
    for(int i = 0; i < num; i++){
        cin >> data;
        vec.push_back(data);
    }
    nth_element(vec.begin(), vec.begin() + (fd - 1), vec.end());
    //단순히 sort()를 이용하면 시간초과
    cout << vec[fd - 1]<<"\n";
}
