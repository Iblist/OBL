#ifndef LIST_MANAGE
#define LIST_MANAGE
#include <stdlib.h>
#include <stdio.h>

typedef struct femaleStructure female;
typedef struct maleStructure male;

struct femaleStructure {
	int ID;				//ID may be removed in future iterations, and should NOT be used currently.
	female * mother;
	male * father;	 	//This is the ID of the male responsible for pregnancy, used for creating child
	int age;
	int coolDown; 		//This is the time period before a pregnancy can be confirmed
	int pregnancyDuration;
	
	female * next;
};

struct maleStructure {
	int ID;			//ID may be removed in future iterations, and should NOT be used currently.
	female * mother;
	male * father;
	int age;
	int sexCount; 	//How many times the male has had sex in one day/cycle
	
	male * next;
};

typedef struct populationListsHead {
	int femaleCount;	//Number of females in the population
	int maleCount;		//Number of males in the population
	int pregnancies;	//Number of active pregnancies in the population
	
	female * fListHead;	//List of females
	male * mListHead;	//List of males
}listHead;

typedef struct femaleListTracer {
	female ** next;
}fTracer;

typedef struct maleListTracer {
	male ** next;
}mTracer;

//FUNCTION DEFINITIONS

listHead * createList();
void removePerson(void * tgt, void * prev, int sex);
void killPerson(void*person);
void * createPerson(female * mother, male * father, int sex);
void push(void * person, int sex, listHead * list);
void swap(int tgtID, int sex, listHead * srcList, listHead * destList);
void swapN(void*, void*, listHead*, int);
#endif //LIST_MANAGE
