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
	until a space opens up in the queue. QUEUE IS CIRCULAR FIFO
	
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

/*
Honestly, this should be two functions, but part of the purpose of making this is to
learn void pointers and explicit type casting soooo...
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



