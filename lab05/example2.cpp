/*
Να γράψετε πρόγραμμα που να δέχεται 5 ακέραιες τιμές 
από τον χρήστη. Να τις τοποθετεί σε μια στοίβα και σε
μια ουρά. Να εμφανίζει το άθροισμα των 3 πρώτων αριθμών 
που εισήχθησαν και το άθροισμα των 3 τελευταίων τιμών
που εισήχθησαν
π.χ. ο χρήστης εισάγει: 23, 11, 5, 16, 7

ουρά: 	23 + 11 + 5
στοίβα:  7 + 16 + 5
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main(){
	stack<int> astack;
	queue<int> aqueue;
	for(int i=0;i<5;i++){
		int x;
		cout << "dose timh ";
		cin >> x;
		astack.push(x);
		aqueue.push(x);
	}
	int sum1=0, sum2=0;
	for(int i=0;i<3;i++){
		sum1 += astack.top();
		astack.pop();
		sum2 += aqueue.front();
		aqueue.pop();
	}
	cout << "SUM1=" << sum1 << " SUM2="<< sum2 << endl; 
}
