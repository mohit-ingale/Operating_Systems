#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#include<stdlib.h>


struct stack{
	int data;
	struct stack *next;
};

struct stack* push(struct stack *,int);
struct stack* pop(struct stack *);


struct stack *top;




#define MAX 4
enum id {a,b,c,d};
int count[4]={0,0,0,0};
int i=0;
sem_t s,s1;
void * thread1(void * data)
{
  sem_wait(&s);
  i=top->data;
  //i=data;
  top=pop(top);
 
  *(count+i)=*(count+i)+1;
  printf("%d\n",i);

  //printf("%d\n",i);
  printf("Count from Thread1=%d\n",count[i]);
  sleep(1);
  top=push(top,i);
//  sleep(1);
  sem_post(&s);
}
void * thread2(void *data)
{
  sem_wait(&s);
  i=top->data;
  top=pop(top);

  *(count+i)=*(count+i)+1;
printf("%d\n",i);
//sem_post(&s1);
//printf("%d\n",i);
  printf("Count from Thread2=%d\n",*(count+i));
  sleep(2);
  top=push(top,i);
//  sleep(1);
  sem_post(&s);
}
void * thread3(void *data)
{
  sem_wait(&s);
	i=top->data;
	top=pop(top);
	//i=data;
  *(count+i)=*(count+i)+1;
printf("%d\n",i);
//sem_post(&s1);

  printf("Count from Thread3=%d\n",*(count+i));
  top=push(top,i);
  //  sleep(1);
  sem_post(&s);
}
void * thread4(void *data)
{
  sem_wait(&s);
  i=top->data;
  top=pop(top);

  *(count+i)=*(count+i)+1;
  printf("%d\n",i);
//  sem_post(&s1);
//  printf("%d\n",i);
  printf("Count from Thread4=%d\n",*(count+i));
  top=push(top,i);
  //  sleep(1);
  sem_post(&s);
}
void * thread5(void *data)
{
  sem_wait(&s);
  i=top->data;
//  i=data;
top=pop(top);
  *(count+i)=*(count+i)+1;
printf("%d\n",i);
//sem_post(&s1);
//printf("%d\n",i);
  printf("Count from Thread5=%d\n",*(count+i));
  top=push(top,i);
  sem_post(&s);
}

int main(int argc, char const *argv[]) {

	top=push(top,0);
	top=push(top,1);
	top=push(top,2);
	top=push(top,3);
  pthread_t td1,td2,td3,td4,td5;
  sem_init(&s,0,4);
  sem_init(&s1,0,1);
  pthread_create(&td1,NULL,thread1,NULL);
  pthread_create(&td2,NULL,thread2,NULL);
  pthread_create(&td3,NULL,thread3,NULL);
  pthread_create(&td4,NULL,thread4,NULL);
  pthread_create(&td5,NULL,thread5,NULL);
  pthread_join(td1,NULL);
  pthread_join(td2,NULL);
  pthread_join(td3,NULL);
  pthread_join(td4,NULL);
  pthread_join(td5,NULL);



  return 0;
}





struct stack* push(struct stack *top,int x)
{
	struct stack *temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=x;
	temp->next=NULL;
	if(top==NULL)
	{      
		return temp;
	}
	temp->next=top;
	return temp;
}

struct stack* pop(struct stack *top)
{
	struct stack *temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack Underflow");
		return top;
	}
	else
	{
		top=top->next;
		temp->next=NULL;
		free(temp);
		return top;
	}
}
