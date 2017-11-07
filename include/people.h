#ifndef PEOPLE_H
#define PEOPLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "listManage.h"

//Parameters for program start sent to main thread, finish later
typedef struct configuration {
	int dummy;
} conf;

/*
These two queues (the mQue and fQue) should be structured and accessed as a circular first in first out
data structure. The que should be accessed starting at 0, ending at the max size and then looping back
to zero. The accessing thread will continue doing this until the 'done' flag is set.
****NOTE****
Small change, can use a linked list and then just concatenate the finished que when done
**END NOTE**
*/
typedef struct maleQueue {
	int size; 			//Size of the list
	male * head;		//Contains a linked list of males to be accessed by the procreation thread
} mQue;

typedef struct femaleQueue {
	int size;			//Same as in maleQueue, but for females.
	female * head; 	//Same as in maleQueue, but for females.
} fQue;

/*
Arguments for pthreads
*/
typedef struct pthread_arguments {
	int sex;			//Sex of queue and list, 0 is female, 1 is male
	void * queue;
	void * list;
} p_args;

#endif
