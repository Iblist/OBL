#include "main.h"


void readList(listHead * in)
{
	male * ptr = in->mListHead;
	while(ptr != NULL)
	{
		printf("ID: %d\n", ptr->ID);
		ptr = ptr->next;
	}
	puts("******************");
}

void killTest(listHead * in, int ID)
{
	int notDone = 1;
	male * ptr = in->mListHead;
	while(notDone)
	{
		if(ptr == NULL)
		{
			notDone = 0;
		}
		else if(ptr->ID == ID)
		{
			removePerson(ptr->next, ptr, 1);
			notDone = 0;
		}
		else
		{
			ptr = ptr->next;
		}
	}
}
void test()
{
	listHead * src = createList();
	listHead * dest = createList();
	male * prev;
	male * target;
	
	int i;
	for(i = 0; i < 10; i++)
	{
		push(createPerson(NULL, NULL, 1), 1, src);
	}
	readList(src);
	prev = src->mListHead;
	for(i = 0; i < 4; i++)
	{
		prev = prev->next;
	}
	target = prev->next;
	swapN(target, prev, dest, 1);
	//killTest(src, 3);
	readList(src);
	readList(dest);
}

int main()
{
	test();
	return 0;
}
