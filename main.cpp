#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
    int input;
    while (cin >> input) {
        stack<int> struc_stac;
        queue<int> struc_que;
        priority_queue<int> priority;
        bool is_stack = true;
        bool is_queue = true;
        bool is_prior = true;
        for (int i = 1; i <= input; i++) {
            int q; int n;
            cin >> q >> n;
            if (q == 1) {
                struc_stac.push(n);
                struc_que.push(n);
                priority.push(n);
            } else if (q == 2) {
                if (struc_stac.empty() or struc_que.empty() or priority.empty()) {
                    is_stack = false;
                    is_queue = false;
                    is_prior = false;
                } else {
                    if (struc_stac.top() == n) {
                        struc_stac.pop();
                    } else {
                        is_stack = false;
                    }
                    if (struc_que.front() == n) {
                        struc_que.pop();
                    } else {
                        is_queue = false;
                    }
                    if (priority.top() == n) {
                        priority.pop();
                    } else {
                        is_prior = false;
                    }
                }
            }
        }
        if (is_stack and !(is_queue or is_prior))
            cout << "stack" << endl;
        else if (is_queue and !(is_stack or is_prior))
            cout <<"queue" << endl;
        else if (is_prior and !(is_queue or is_stack))
            cout << "priority queue" << endl;
        else if (!(is_stack or is_queue or is_prior))
            cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }
}