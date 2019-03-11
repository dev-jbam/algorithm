/*

Problem statement
Implement a FIFO queue with limited size.

It should support the following commands:

SIZE
OFFER x
TAKE
x can be any string.

*Please describe algorithm complexity as comment.

Input
N C
command 1
command 2...
Where N is the number of commands (1 <= N <= 10000) and C the capacity of the queue (0 <= C <= 10000).

Output
For SIZE command, the number of items currently in the queue followed by a newline.
For TAKE command, the item taken followed by a newline if the queue was not empty. Nothing otherwise.
For OFFER command, true if the item was accepted by the queue, or false otherwise, followed by a newline.
Input example
5 2
OFFER hello
OFFER world
OFFER !
TAKE
SIZE
Output example
For the above input,

true
true
false
hello
1
*/

#if 0

#include <iostream>
#define QMAX 10000
using namespace std;

template <typename T>

struct _Queue {
    T val[QMAX];
	int front, rear;
    int limit;

    _Queue(int C){
        init();
        limit = C + 1;
    }
    void init() {
		front = rear = 0;
	}  
    int size(){
        return rear < front ? limit + rear - front : rear - front; 
    };
	bool full() {
		return front == (rear + 1) % limit;
	}
	bool empty() {
		return front == rear;
	}

	bool offer(T nval) {
		if (full()) {
			return false;
		}
		val[rear] = nval;
		rear = (rear + 1) % limit;
        return true;
	}

    T take() {
		if (empty()) {
			T error;
			return error;
		}
		T ret = val[front];
		front = (front + 1) % limit;
		return ret;
	}
};


void run_queue_program(){
    int N, C;
    cin >> N >> C;

    string answer = "";

    _Queue<string> str_queue(C);
    string cmd ="", value="";
    while(N){
        cin >> cmd;
        if(cmd == "SIZE"){
            answer += (to_string(str_queue.size()) + "\n");
        } else if(cmd == "OFFER"){
            cin >> value;
            bool ret = str_queue.offer(value);
            answer += ( ret ? "true\n" : "false\n"); 
        } else if(cmd == "TAKE" && !str_queue.empty()){            
            answer += ( str_queue.take() + "\n");
        }
        --N;
    }
    cout << answer;
}
int main() {
    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);
    run_queue_program();
    return 0;
}

#endif