Project: OBL - Operation Baby Limit
Goal: Simulate sexual reproduction in a population to determine the smallest population of male and female organisms
needed to ensure genetic diversity and prevent incestuous reproduction.

Description:
The program should accept a starting male and female population count, and will run a breeding simulation using provided breeding factors.
Factors for breeding should include;

The chance of pregnancy,
Duration of pregnancy,
Chance of complications resulting in termination of pregnancy, - Note, this may be split into several independant factors
Chance offspring will be male or female,
Frequency of male reproduction attempts,
Minimum age required for reproduction.
More to be added.

The program will run through a 'cycle' representing one day, repeating for a specified time frame.
During each cycle, the program will;

Increment the age of all living organisms,
Breed elligible male and female organisms,
Update active pregnancies,
Create new organisms once a pregnancy has ended,
Remove organisms which can no longer breed.
More to be added.

Technical Details:
The program stores living organisms in two linked lists; a male list and a female list. Linked lists are used due to ease of dynamic
list expansion, and ease of removing items at arbitrary indexes.

Two queues are used to store organisms which are elligible for breeding; a male queue and a female queue. These queues are linked lists
created by moving a member of the population list to the respective breeding queue. The purpose of the queue is to avoid having to search
through the entire female population list for each male organism. 

Two child threads are used for handling the male and female population lists. These two threads will be referred to as fThread and mThread.
mThread is responsible for aging males, removing males too old to breed, and selecting elligible males for breeding.
The fThread is responsible for the same actions as the mThread, in addition to updating pregnant females, and creating new organisms.
Newly created are added to the head of their respective lists.

The parent thread is responsible for breeding organisms in the aformentioned queues. A male organism is paired with an elligible female organism.
The male has his breeding counter incremented, and the female organism is removed from the female queue. The male continues breeding until either there
are no elligible females or his breeding counter reaches his breeding limit. The male is then removed from the queue, and the next male repeats the process.
If either queue is empty, or no male has an elligible female breeding partner, the parent thread joins both child threads, updates any tracked variables,
and starts the cycle again.

As a rule, any time an organism is swapped between lists, it should be added to the head of the list. 



***********Working notes*******************
Got confused and muddled, so here's some pseudo code.


There are two threads working with the main thread.

The main thread organizes the two child threads and handles procreation.
Basically, it should only edit whether a female is pregnant or not.

The two child threads edit things like the age of a person and criteria updated
with each simulation cycle.

The child threads also take people from person lists and add them to a second list,
the procreation list. The procreation list is where the parent thread gets candidates
for procreation. Some pseudo code for the two threads and parent thread.

PARENT THREAD.

Create male thread;
Create female thread;

while (both threads are alive)
{
	choose male from maleQue
	choose female from femaleQue
	
	if(male or female list is empty)
	{
		while (neither thread is dead)
		{
			check if male or female thread is dead
		}
		if (either thread is dead)
		{
			kill the other thread
			return males and females to lists
		}
	}
	
	if(male and female are not related)
	{
		mate male and female
		return female to femaleList
		if(male cannot procreate further)
		{
			return male to maleList
		}
	}	
}
