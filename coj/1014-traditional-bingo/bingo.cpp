#include <iostream>

using namespace std;

bool marks[5][5];
int card[5][5];

void clear(){
	for(int i = 0; i < 5; i ++){
		for(int j = 0; j < 5; j ++){
			marks[i][j] = false;
		}
	}
	marks[2][2] = true;
}

bool bingo(int i, int j){
	bool hor = true;
	bool vert = true;
	bool diag1 = true;
	bool diag2 = true;
	for(int k = 0; k < 5; k++){
		if(!marks[i][k])
			hor = false;
		if(!marks[k][j])
			vert = false;
	}
	for(i = 0; i < 5; i++){
		if(!marks[i][i])
			diag1 = false;
		if(!marks[4 - i][i])
			diag2 = false;
	}
	return hor || vert || diag1 || diag2;
}

bool check(int n){
	int i;
	//B
	if(n < 16){
		i = 0;
	}
	//I
	else if(n < 31){
		i = 1;
	}
	//N
	else if(n < 46){
		i = 2;
	}
	//G
	else if(n < 61){
		i = 3;
	}
	//O
	else{
		i = 4;
	}
	for(int j = 0; j < 5; j++){
		if(card[j][i] == n){
			marks[j][i] = true;
			return bingo(j, i);
		}
	}
	return false;
}


int main(int argsc, char** args){
	int t;
	int n;
	int res;
	card[2][2] = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		clear();
		for(int j = 0; j < 25; j++){
            if(j == 12)
				continue;
			cin >> card[j/5][j%5];
		}
		res = 0;
		for(int j = 0; j < 75; j++){
			cin >> n;
			if(!res && check(n))
				res = j + 1;
		}
		cout << "BINGO after " << res << " numbers announced" << endl;
	}
}

