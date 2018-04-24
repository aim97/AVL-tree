#include <bits/stdc++.h>
#include "avl.h"
using namespace std;

int op, k;
string value;

void showOps(){
	printf("opcode\t:\toperation\n\
1\t:\tinsert a key-value pair in the tree\n\
2\t:\tset the value of some key\n\
3\t:\tlookup the value associated with some key\n\
4\t:\tdisplay the tree\n\
5\t:\tmodify the value associated with some key\n\
6\t:\tshow this list\n\
7\t:\tterminate program\n");
}
int main(){
	avl<int, string>* a = new avl<int, string>();
	showOps();
	while(1){
		cout << "enter the opcode for the operation you want\n";
		cin >> op;
		
		switch(op){
			case 1: 
				cout << ">> enter key value pair to insert in tree\n";
				cout << ">> enter key : ";cin >> k;
				cout << ">> enter value : "; cin >> value;
				try{a->insert(k, value);}catch(const char* msg){printf(">> %s\n", msg);}
				break;
			case 2: 
				cout << ">> enter key value pair to set in tree\n";
				cout << ">> enter key : ";cin >> k;
				cout << ">> enter value : "; cin >> value;
				a->set(k, value);
				break;
			case 3: 
				cout << ">> enter key to lookup in tree\n";
				cout << ">> enter key : ";cin >> k;
				try{
					cout << ">> the value of that key is : " << a->lookUp(k);
				}catch(const char* msg){printf(">> %s\n", msg);}
				break;
			case 4: 
				cout << ">> here is the tree\n";
				a->display();
				break;
			case 5: 
				cout << ">> enter the key to update with the given value\n";
				cout << ">> enter key : ";cin >> k;
				cout << ">> new value : "; cin >> value;
				try{a->modify(k, value);}catch(const char* msg){printf(">> %s\n", msg);}
				break;
			case 6:
				showOps();
				break;
			case 7:
				return 0;
				break;
		}
		cout << "\n==================================\n";
	}
	return 0;
}
