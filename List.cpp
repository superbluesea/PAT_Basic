#include<stdio.h>
#include<stdlib.h>
#include"List.h"

struct Node{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P&&P->Element != X)
		P = P->Next;
	return P;
}

void Delete(ElementType X, List L)
{
	Position Prev = FindPrevious(X, L), TmpCell;
	if (!IsLast(Prev, L))
	{
		TmpCell = Prev->Next;
		Prev->Next = TmpCell->Next;
		free(TmpCell);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while (P->Next&&P->Next->Element != X)
		P = P->Next;
	return P;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (struct Node*)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("MALLOC ERROR");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (P)TmpCell = P->Next; else return;
	P->Next = TmpCell->Next;
	free(TmpCell);
}

void DeleteList(List L)
{
	Position P = L->Next,TmpCell = NULL;
	L->Next = NULL;
	while (P)
	{
		Position TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}



int main()
{

	return 0;
}