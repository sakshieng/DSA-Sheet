#include<stdlib.h>
#include<stdio.h>
#define M 10
// k is array with M no of elements
struct list
{
   int data;
   char ch;
   struct list *next;
}*k[M];
char ch[M];
/*
k[M] array of pointers 20 bytes 
struct -> 40 bytes cha ahe
global declaration *k[M] means we are giving address
*/
struct list *createNode(int d,char a)
{
   struct list *p;
   p=(struct list *)malloc(sizeof(struct list));
   p->data=d;
   p->ch=a;
   p->next=NULL;
   return p;
};
// func to create list
void createList()
{
   int i=1,d;
   struct list *p;
   char a;
   while(i<M)
   {
      printf("\nVertex: ");
      scanf("%d",&d);
      printf("\nEnter label: ");
      scanf(" %c",&a);//imp here space
      if(d == 0)
         break;
      k[i]=p=createNode(d,a);
      printf("\nAdjacent nodes\n");
      while (1)
      {
         scanf("%d",&d);
         if(d==0)
            break;
         p->next=createNode(d,' ');
         p=p->next;   
      }
      i++;
   }
}
