#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	stack<string> s;
	queue<string> q;
	for(int i=0;i<5;i++){
		string x;
		cout << "dose onoma: ";
		cin >> x;
		s.push(x);
		q.push(x);
	}
	cout << "QUEUE" << endl;
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	cout << "STACK" << endl;
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}