// chi cong tru nhan chia... voi cac so tu 0 den 9 
// khi nhap thi nhap so nguyen nhung kq co tren tra ve float
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct NODE{
	int data;
	NODE *pNext;
};

struct STACK{
	NODE *pTop;
};

void InitStack(STACK &s){
	s.pTop = NULL;
}

NODE *InitNode(int x){
	NODE *p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void OutputList(STACK s){
	if (s.pTop == NULL){
		printf ("\nDanh sach rong");
		return;
	}
	for (NODE *k = s.pTop; k != NULL; k = k->pNext){
		printf ("%d ", k->data);
	}
}
bool PushStack(STACK &s, NODE *p){
	if (s.pTop == NULL){
		s.pTop = p;
		return true;
	}
	p->pNext = s.pTop;
	s.pTop = p;
	return true;
}
//---------------------
bool PopStack(STACK &s, int &result){
	if (s.pTop == NULL){
		return false;
	}
	NODE *temp = s.pTop;
	s.pTop = s.pTop->pNext;
	result = temp->data;
	delete(temp);
	return true;
}

void TowerOfHaNoi(int n, STACK &source, STACK &target, STACK &temp){
//	printf ("\nn : %d \n", n);
	int x;
	if ( n == 1 ){
//		printf ("\nIF Move disk from: %d to %d", source, target);
//		printf ("\n----\n");
		
		PopStack(source,x);
		NODE *p = InitNode(x);
		PushStack(target,p);
		printf ("\n----------------------------\n");
		printf ("\nSTACK trong source: ");
		OutputList(source);
		printf ("\nSTACK trong temp: ");
		OutputList(temp);
		printf ("\nSTACK trong target: ");
		OutputList(target);
		printf ("\n---------------------------------\n");
		return;
	}
	TowerOfHaNoi(n-1, source, temp, target);
//	printf ("\n1Move disk from: %d to %d", source, target);
	
	PopStack(source,x);
	NODE *p = InitNode(x);
	PushStack(target,p);
	
	printf ("\n----------------------------\n");
	printf ("\nSTACK trong source: ");
	OutputList(source);
	printf ("\nSTACK trong temp: ");
	OutputList(temp);
	printf ("\nSTACK trong target: ");
	OutputList(target);
	printf ("\n---------------------------------\n");
	TowerOfHaNoi(n-1, temp, target, source);
}


int main(){
	int n;
	STACK source;
	STACK temp;
	STACK target;
	InitStack(source);
	InitStack(temp);
	InitStack(target);
	printf ("\nNhap so luong disk: ");
	scanf ("%d", &n);
	printf ("\nGia tri stack source");
	for (int i = 1; i <= n; i++){
		NODE *p = InitNode(i);
		PushStack(source,p);
	}
	printf ("\n--------------------------\n");
	OutputList(source);
	
	
	TowerOfHaNoi(n, source, target, temp);
	printf ("\nKet qua\n");
	OutputList(target);
	return 0;
}
