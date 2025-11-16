#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;

const int length = 4;

int chess[length][length];
int compareChess[length][length];

int nums[] = {2, 2, 4};

void backupChess(){
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			compareChess[j][i] = chess[j][i];
		}
	}
	return;
}

bool compare(){
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			if(chess[j][i] != compareChess[j][i]){
				return false;
			}
		}
	}
	return true;
}

void addNum(){
	for(;;){
		int i = rand() % 4;
		int j = rand() % 4;
		if(chess[i][j] == 0){
			chess[i][j] = nums[rand() % 3];
			break;
		}
	}
	return;
}

bool decEnd(){
	int count = 0;
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			if(chess[j][i] == 0){
				return false;
			}
		}
	}
	
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			if (j + 1 < length && chess[j][i] == chess[j + 1][i]) {
				count++;
			}
			if (i + 1 < length && chess[j][i] == chess[j][i + 1]) {
				count++;
			}
		}
	}
	
	if(count == 0){
		cout << "game over!";
		system("pause");
		count = 0;
		return true;
	}
	return false;
}

void printChess(){
	system("cls");
	cout << "---------------------------------" << endl;
	for(int i=0;i<length;i++){
		cout << "|";
		for(int j=0;j<length;j++){
			if(chess[j][i] == 0){
				cout << "\t|";
			}
			else{
				cout << chess[j][i] << "\t|";
			}
		}
		cout << endl;
		cout << "---------------------------------" << endl;
	}	
	return;
}

int main(void){
	int key;
	int temp;
	int count = 1;	
	srand(time(NULL));	
	int random_num = nums[rand() % 3];
	int random_pot = rand() % 4;	
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			chess[j][i] = 0;
		}
	}
	chess[rand() % 4][rand() % 4] = nums[rand() % 3];
	printChess();
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 'w'){
				backupChess();
				for(int i=0;i<4;i++){
					for(int cot = 1; cot <= 3;cot++){
						for(int j=0;j<=2;j++){
							if(chess[i][j+1] == chess[i][j] && count == 1 && chess[i][j] != 0){
								count = 0;
								chess[i][j] += chess[i][j+1]; 
								chess[i][j+1] = 0;
							}
							if(chess[i][j] == 0){
								chess[i][j] = chess[i][j+1]; 
								chess[i][j+1] = 0;
							}
						}
					}
					count = 1;
				}
				if(!decEnd()){
					if(compare()){
						printChess();
					}
					else{
						addNum();
						printChess();
					}
				}
			}
			if(key == 'a'){
				backupChess();
				for(int i=0;i<4;i++){
					for(int cot = 1; cot <= 3;cot++){
						for(int j=0;j<=2;j++){
							if(chess[j+1][i] == chess[j][i] && count == 1 && chess[j][i] != 0){
								count = 0;
								chess[j][i] += chess[j+1][i]; 
								chess[j+1][i] = 0;
							}
							if(chess[j][i] == 0){
								chess[j][i] = chess[j+1][i]; 
								chess[j+1][i] = 0;
							}
						}
					}
					count = 1;
				}
				if(!decEnd()){
					if(compare()){
						printChess();
					}
					else{
						addNum();
						printChess();
					}
				}
			}
			if(key == 's'){
				backupChess();
				for(int i=0;i<4;i++){
					for(int cot = 1; cot <= 3;cot++){
						for(int j=3;j>=1;j--){
							if(chess[i][j-1] == chess[i][j] && count == 1  && chess[i][j] != 0){
								count = 0;
								chess[i][j] += chess[i][j-1]; 
								chess[i][j-1] = 0;
							}
							if(chess[i][j] == 0){
								chess[i][j] = chess[i][j-1]; 
								chess[i][j-1] = 0;
							}
						}
					}
					count = 1;
				}
				if(!decEnd()){
					if(compare()){
						printChess();
					}
					else{
						addNum();
						printChess();
					}
				}			
			}
			if(key == 'd'){
				backupChess();
				for(int i=0;i<4;i++){
					for(int cot = 1; cot <= 3;cot++){
						for(int j=3;j>=1;j--){
							if(chess[j-1][i] == chess[j][i] && count == 1  && chess[j][i] != 0){
								count = 0;
								chess[j][i] += chess[j-1][i]; 
								chess[j-1][i] = 0;
							}
							if(chess[j][i] == 0){
								chess[j][i] = chess[j-1][i]; 
								chess[j-1][i] = 0;
							}
						}
					}
					count = 1;
				}
				if(!decEnd()){
					if(compare()){
						printChess();
					}
					else{
						addNum();
						printChess();
					}
				}
			}
		}
	}
	return 0;
}
