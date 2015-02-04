#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int compare(const int x, const int y)
{
	if(!x) return 1;
	if(!y) return -1;
	if(x == 1) return 1;
	if(y == 1) return -1;
	if(x == 2 && y == 3) return 1;
	if(x == 3 && y == 2) return -1;
    return x - y;
}

struct comp {
	bool operator()
		(const int x, const int y) const
	{
		if(!x) return false;
		if(!y) return true;
		if(x == 1) return false;
		if(y == 1) return true;
		if(x == 2 && y == 3) return false;
		if(x == 3 && y == 2) return true;
		return x < y;
	}
};

int main(){
	priority_queue<int, vector<int>, comp> q;
	int probs;
	int amps;
	int amp;
	cin >> probs;
	for(int i = 0; i < probs; i++){
		cin >> amps;
		for(int j = 0; j < amps; j++){
			cin >> amp;
			q.push(amp);
		}
		while(!q.empty()){
			cout << q.top();
			q.pop();
			if(q.size() > 0) cout << " ";
			else cout << endl;
	    }
	}
}