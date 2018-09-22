#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer=0;

void go(vector<int> people, vector<int> tshirts,vector<int> people_take, vector<bool> clothchoose, int personnumber)
{
    if(personnumber>=people.size())
    {
        int temp=0;
        for(int i=0;i<people_take.size();i++)
        {
            if(people_take[i]>=1)
                temp++;
        }
        answer = max(answer,temp);
    }
    for(int i=0;i<tshirts.size();i++)
    {
        if(clothchoose[i]==false&&people[personnumber]<=tshirts[i])
        {
            people_take[personnumber]=tshirts[i];
            clothchoose[i]=true;
            go(people,tshirts,people_take,clothchoose,personnumber+1);
        }
    }
    if(people_take[personnumber]==-1)
        go(people,tshirts,people_take,clothchoose,personnumber+1);
}

int solution(vector<int> people, vector<int> tshirts) {
    vector<int> people_take;
    vector<bool> clothchoose;
    for(int i=0;i<people.size();i++)
    {
        people_take.push_back(-1); // -1을 넣고 티셔츠를 불출받았으면 양수값설정
    }
    for(int i=0;i<tshirts.size();i++)
    {
        clothchoose.push_back(false);
    }
    go(people,tshirts,people_take,clothchoose,0);
    return answer;
}
