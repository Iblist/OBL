#include "listManage.h"

//Lists of persons
	//There are two lists, a female list and a male list

//Create person
	//Add person to list of persons
	
//Kill person
	//Remove person from list of persons
	//A person incapable of procreating is "killed," and removed from the persons list.
		//This is in order to free up memory. 
		//It may be useful to store "killed" people as something else in order to
		//accurately calculate population

//Procreate
	//Males attempt to procreate with females x times per day/cycle
	//Pregnant females are excluded from procreation
	//Males and females below a specified age are excluded from procreation
	//?Should females have a cool down period before being elligible for procreation?
	
	
listHead * createList()
{
	listHead * newList = NULL;
	
	newList = malloc(sizeof(listHead));
	
	return newList;
}

/*
This function frees either a supplied male or female.
The function checks the sizeof the supplied void pointer
to decide whether person is male or female, and then frees
memory allocated to person based on that.

****NOTE****
Currently male and female structs don't contain any pointers
(aside from the next pointer) and thus this isn't really necessary
This is more of an effort to enable extensibility
**END NOTE**
*/
void killPerson(void * person)
{
	
	if(sizeof(person) == sizeof(female))
	{
		free(person);
	}
	else
	{
		free(person);
	}
}

/*
This function creates either a new male or female using the supplied
mother and father IDs. 
The 'sex' argument determines whether person is male or female.
0=Female
1=Male
****NOTE****
I'm going a little insane with void pointers here. The code is harder
to read this way, however I'm partially doing this to learn how to use
void pointers. I think there are some benefits to memory use doing it
this way, though it may be more computationally intensive, not sure.
**END NOTE**
*/
void * createPerson(int ID, int motherID, int fatherID, int sex)
{
	void * newPerson = NULL;
	
	if (sex == 0)
	{
		newPerson = malloc(sizeof(female));
		((female*)newPerson)->motherID = motherID;
		((female*)newPerson)->fatherID = fatherID;
		((female*)newPerson)->age = 0;
		((female*)newPerson)->ID = ID;
	}
	else
	{
		newPerson = malloc(sizeof(male));
		((male*)newPerson)->motherID = motherID;
		((male*)newPerson)->fatherID = fatherID;
		((male*)newPerson)->age = 0;
		((male*)newPerson)->ID = ID;
	}
	
	return newPerson;
}

/*
This function adds a new person to the head of the list
*/
void push(void * person, int sex, listHead * list)
{
	male * newMale = NULL;
	female * newFemale = NULL;
		
	
	if (sex == 0)
	{
		newFemale = (female*)person;
		newFemale->next = list->fListHead;
		list->fListHead = newFemale;
	}
	else
	{
		newMale = (male*)person;
		newMale->next = list->mListHead;
		list->mListHead = newMale;
	}
}

/*
This function removes a person from a list
*/
void removePerson(void * person, int sex, listHead * list)
{

}

/*
Swaps person from one linked list to another
*/
void swap(int tgtID, int sex, listHead * srcList, listHead * destList)
{
	int notDone = 1;
	
	fTracer fSearch;
	mTracer mSearch;
	
	female * fList = NULL;
	male * mList = NULL;
	
	void * person;
	
	/*
		NOTE
		This if statement should probably call some function instead of what it
		actually does. Hell, this whole function could probably be two functions
		however, for the sake of testing, I'm leaving it as 1 function.
	*/
	if (sex == 0)
	{
		fSearch.next = &srcList->fListHead;
		if(*fSearch.next == NULL)
		{
			//something with empty list
		}
		else
		{
			//First step is to loop through srcList and extract the person
			while(notDone)
			{	
				//Reached the end of the list without finding the tgtID
				if((*fSearch.next)->next == NULL)
				{
					notDone = 0;
				}
				else if((*fSearch.next)->next->ID == tgtID)
				{
					person = (*fSearch.next)->next;
					(*fSearch.next)->next = (*fSearch.next)->next->next;
					notDone = 0;
				
				}
				else
				{
					fSearch.next = &(*fSearch.next)->next;
				}
			}
			fSearch.next = &destList->fListHead;
			//Now we simply append the extracted person to the output list
			notDone = 1;
			while(notDone)
			{
				if(*fSearch.next == NULL)
				{
					*fSearch.next = (female*)person;
					((female*)person)->next = NULL;
					notDone = 0;
				}
				else
				{
					fSearch.next = &(*fSearch.next)->next;
				}
			}
		}
	}
	else
	{
		mSearch.next = &srcList->mListHead;
		if(*mSearch.next == NULL)
		{
			//something with empty list
		}
		else
		{
			//First step is to loop through srcList and extract the person
			while(notDone)
			{	
				//Reached the end of the list without finding the tgtID
				if((*mSearch.next)->next == NULL)
				{
					notDone = 0;
				}
				else if((*mSearch.next)->next->ID == tgtID)
				{
					person = (*mSearch.next)->next;
					(*mSearch.next)->next = (*mSearch.next)->next->next;
					notDone = 0;
				
				}
				else
				{
					mSearch.next = &(*mSearch.next)->next;
				}
			}
			mSearch.next = &destList->mListHead;
			//Now we simply append the extracted person to the output list
			notDone = 1;
			while(notDone)
			{
				if(*mSearch.next == NULL)
				{
					*mSearch.next = (male*)person;
					((male*)person)->next = NULL;
					notDone = 0;
				}
				else
				{
					mSearch.next = &(*mSearch.next)->next;
				}
			}
		}
	}
}




