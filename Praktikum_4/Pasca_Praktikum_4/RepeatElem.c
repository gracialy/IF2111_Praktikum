#include "RepeatElem.h"

void traverse(int x, int a, int n, List *L, List *B)
{
	boolean searching = true;
	for(int i = a+1; i < n; i++)
	{
		if(Get(*L, i) == x)
		{
			if(searching)
			{
				searching = false;
				Set(B, i, x);
			}
			Set(L, i, Mark);
		}
	}	
}

void simplify(List *L)
{
	int move = 0;
	for(int i = 0; i < 100; i++)
	{
		int cur = Get(*L, i);
		if(cur != Mark)
		{
			Set(L, i-move, cur);
			Set(L, i, (move? Mark : cur));
		}
		else {move++;}	 
	}
}

List RepeatElem(List *L)
{
	List B = MakeList();
	int n = Length(*L);
	for(int i = 0; i < n; i++)
	{
		int cur = Get(*L, i);
		if(cur == Mark) continue;
		traverse(cur, i, n, L, &B);
	}
	simplify(L); simplify(&B);
	return B;	
}   


