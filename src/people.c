#include "people.h"

/*
This function proceeds through the person list and accomplishes several operations, namely;

increments the age of each person,
checks for females that can give birth, resets them and creates a new person,
kills persons that are too old to procreate
mates suitable males with suitable females

****NOTE****
This function lends itself well to multithreading, and I'm half tempted to try this. We'll see.
**END NOTE**
*/
int simulate(listHead * list, conf * params)
{
	if(list->maleCount > 0 && list->femaleCount > 0)
	{
		
	}
	else
	{
		puts("Population has died");
	}
	
	return 0;
}

/*
	PSEUDO CODE
	For the male/female searching threads, we need to search through the list of males and females sequentially
	and add elligible males/females to the relevant queue. If the queue is full, the thread should wait
	until a space opens up in the queue.
	
	male thread start
	{
		for each in male list
		{
			if (queue is not done)
			{
				read and update male
				if(male can procreate AND que is not full)
				{
					add male to queue
				}
				else
				{
					wait until queue is not full
					if (queue is done) quit
				}
			}
			else
			{
				quit
			}
		}
		quit
		{
			empty queue
			finish searching through queue	
		}
	}
			
*/

void * maleHandler(void * arguments)
{
	p_args args = *(p_args*) arguments;
	listHead * que;
	mTracer tracer;
	int maxAge;
	
	que = (listHead*) args.queue;
	tracer.next = &(((male*)args.list)->next);
	maxAge = args.maxAge;
	
	if((*tracer.next)->age < maxAge)
	{
		swapN(*tracer.next, NULL, que, 1);
	}
	else
	{
		removePerson((*tracer.next), NULL, 1);
	}
	while((*tracer.next)->next != NULL)
	{
		if((*tracer.next)->next->age < maxAge)
		{
			swapN((*tracer.next)->next, NULL, que, 1);
		}
		else
		{
			removePerson((*tracer.next)->next, (*tracer.next), 1);
		}
		tracer.next = &((*tracer.next)->next);
	}
	
	return NULL;
}

void * femaleHandler(void * arguments)
{
	p_args args = *(p_args*) arguments;
	
	return NULL;	
}

/*
Honestly, this should be two functions, but part of the purpose of making this is to
learn void pointers and explicit type casting soooo...
EDIT I'm probably just going to make two functions, the function is less ugly that way.
*/
void *job(void * arguments)
{
	p_args args = *(p_args*) arguments;
	mQue * maleQue;
	fQue * femQue;
	
	male * mList;
	male * mSearch;
	
	female * fList;
	female * fSearch;
	
	//Male
	if (args.sex == 0)
	{
		maleQue = (mQue*) args.queue;
		mList = (male*) args.list;
	}
	//Female
	else
	{
	
	}

	return NULL;
}



