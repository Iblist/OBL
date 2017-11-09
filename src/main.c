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
	int i;
	for(i = 0; i < 10; i++)
	{
		push(createPerson(i, (i*2+1000000), (i*2+1)+1000000, 1), 1, src);
	}
	readList(src);
	killTest(src, 3);
	readList(src);
}

int main()
{
	test();
	return 0;
}
