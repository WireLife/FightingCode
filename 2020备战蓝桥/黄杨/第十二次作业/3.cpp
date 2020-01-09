#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
 
int main(){
    int n, a;
    cin >> n;
    queue<int> num;
    for(int i = 1; i <= n; i++)
        num.push(i);
	cout<<"Discarded cards: ";
    while(num.size() > 1){
        a = num.front();
        num.pop();
        cout << a <<' ';
        a = num.front();
        num.pop();
        num.push(a);
    }
	
	cout<< endl <<"Remaining card: "<< a << endl;
 
    return 0;
}
