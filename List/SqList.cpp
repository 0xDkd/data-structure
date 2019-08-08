#include <iostream>
#include <malloc.h>
#include <string>
#include <stdlib.h>
#define MAX_SIZE 100 
using namespace std;

//顺序表

typedef struct SqList{
	int data[MAX_SIZE];
	int length;	
}list;


void createList(list &L); 
void printList(list L); 
void insertElem(list &L,int e ,int x);
//delete element by element data
int deleteElem(list &L,int e);
//find element 
int findElem(list L,int e);
bool checkFull(list L);
bool checkEmpty(list L);


int main(){
	list L;
	
	L.length = 0;
	createList(L);
	printList(L);
	//cout << L.length << "\r\n";
	insertElem(L,233,50);
	printList(L);
	deleteElem(L,72);
	printList(L);
	return 0;	
}

//Init
void createList(list &L){
	//预留出10个空位 
	for(int i = 0;i<MAX_SIZE-11;i++){
		++L.length;
		L.data[i] = i;		
	}	
	
}

//打印 
void printList(list L){
	for(int i = 0;i<L.length;i++){		
		cout  << L.data[i] << "\r" <<endl;
	}
}

//checkFull
bool checkFull(list L){
	if (L.length >= MAX_SIZE-1) return false;
	return true;
}
//checkEmpty
bool checkEmpty(list L){
	if(L.length <= 0) return false;
	return true;
}

//Insert
void insertElem(list &L,int e , int x){
	if (!checkFull(L))
		return;
	 
	for(int i=L.length;i>=x;i--)
		L.data[i+1] = L.data[i];
	L.data[x] = e;
	++L.length;			
}

//Delete

int deleteElem(list &L,int e){
	if (!checkEmpty)
		return -1;
	
	int p,x;
	x = findElem(L,e);
	if (x == -1)
		return -1;
	
	p = L.data[x];
	for(int i= x;i<L.length;i++)
		L.data[i] = L.data[i+1];
		
	--L.length;	
} 

//find
int findElem(list L,int e){
	if(!checkEmpty)
		return -1;
	for(int i = 0;i<L.length;i++){
		if (L.data[i] == e)
			return i;			
	}
	
	return -1;
} 
