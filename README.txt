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
