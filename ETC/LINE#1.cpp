#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

//Implement this class
//Please use stack only
class Queue {
private:
	//Stack의 기본성질은 LIFO이다. 즉 스택을 활용하면 하나의 데이터를 역순으로 배치한다는 의미이다.
	//따라서 스택 두개를 활용하면 역순으로 두번옮기는거고 이를 활용하면 FIFO인 큐를 만들 수 있다.
    stack<int> temp_stack;
    stack<int> main_stack;
public:
    /*
     * Description:
		 	데이터를 삽입시 temp_stack에 데이터 삽입
     * Time complexity:
		 	데이터추가는 O(1)
     * Space complexity:
		  O(n)
     */

    void enqueue(int v) {
        temp_stack.push(v);
    }

    /*
     * Description:
		 	데이터를 추출시에만 temp_stack의 모든 데이터를 main_stack에 옮긺
			main_stack의 최상위 데이터 하나만을 추출
			main_stack의 데이터 전부를 temp_stack으로 옮김
     * Time complexity:
     	O(n) // 스택자체를 전부 훑어봐야함
		 * Space complexity:
     *O(n)
		 */

    int dequeue() {
        int ret=0;
        while(!temp_stack.empty())
        {
            main_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        ret=main_stack.top();
        main_stack.pop();
        while(!main_stack.empty())
        {
            temp_stack.push(main_stack.top());
            main_stack.pop();
        }
        return ret;
    }
};

int main(int argc, const char *argv[]) {
    Queue queue;
    string line;
    getline(cin, line);
    int count = stoi(line);
    for (int i = 0; i < count; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        if (token == "ENQUEUE") {
            getline(ss, token, ' ');
            queue.enqueue(stoi(token));
        } else if (token == "DEQUEUE") {
            cout<<queue.dequeue()<<endl;
        }
    }
}
