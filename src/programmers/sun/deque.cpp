/*
문제 설명
Problem statement
Given a window size, W and a stream of number, S. You can see only W numbers in the window. Each time you receive a number from stream S, print max numbers in sliding window.

*Please describe algorithm complexity as comment.

Input
[W]
[N1]
[N2]
...
Where W is the number of the window size, and Nn represents a element in the stream.

Note that, you can assume following things.

An element in the stream will be an integer in the range, -3,000,000,000 ≦ Nn ≦ 3,000,000,000.
the window size W will be an integer in the range, 0 < W ≦ 3,000,000,000.
Output
After you read first W + 1 lines, each time you read the number from the input, print max numbers in sliding window.

[V1]
[V2]
...
Input Example
(Window size W=2 and number stream is S = [2, 1, 2, -1, 3])

2
2
1
2
-1
3
Output Example
2
2
2
3
*/
#if 0

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

struct number_idx{
    ll number;
    ll idx;
    number_idx(ll n, ll idx):number(n),idx(idx){};
};

// O( N )
int main() {
    freopen("/home/joon/sources/algorithm/build/input.txt", "r", stdin);
    ll windows = 0;
    cin >> windows;
    ll idx = 0;
    ll value;
    deque<number_idx> dq;
    while (cin >> value) {
        while (dq.size() && dq.front().idx <= idx - windows)
            dq.pop_front();

        while (dq.size() && dq.back().number <= value)
            dq.pop_back();

        dq.push_back(number_idx( value, idx ));
        
        if( idx + 1 >= windows)
            cout << dq.front().number << "\n";
        idx++;
    }

    return 0;
}

#endif