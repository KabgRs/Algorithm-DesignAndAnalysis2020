#include<stdio.h>
#include"Node.h"

void OP(E e) {
	printf("%c ", e);
}

//²Î¿¼ÍøÖ·https://blog.csdn.net/luoshixian099/article/details/51908175

int main() {

	int m[] = {
	INIT,    9,  INIT,  INIT,     7,  INIT,  INIT,
	9,    INIT,  INIT,  INIT,  INIT,     2,     3,
	INIT, INIT,  INIT,    15,     6,    16,  INIT,
	INIT, INIT,    15,  INIT,  INIT,  INIT,    5,
	7,    INIT,     6,  INIT,  INIT,    23,  INIT,
	INIT,    2,    16,  INIT,    23,  INIT,  INIT,
	INIT,    3,  INIT,     5,  INIT,  INIT,  INIT
	};
	char value[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	SGraph G = CreateSGraph(m, value, 7);
	Prim(G, 0);
	Prim(G, 3);



	return 0;
}