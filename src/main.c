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
void test()
{
	listHead * src = createList();
	listHead * dest = createList();
	int i;
	for(i = 0; i < 10; i++)
	{
		push(createPerson(i, (i*2+100), (i*2+1)+100, 1), 1, src);
	}
	readList(src);
	
	swap(4, 1, src, dest);
	swap(5, 1, src, dest);
	swap(2, 1, src, dest);
	
	puts("SRC");
	readList(src);
	puts("DEST");
	readList(dest);
	
	swap(5, 1, dest, src);
	
	puts("SRC");
	readList(src);
	puts("DEST");
	readList(dest);
}

int main()
{
	test();
	return 0;
}
