#include <stdio.h>                   
#include <stdlib.h>                 
#include "QueueInterface.h"         


void SystemError(char *errorMsg) {fprintf(stderr,errorMsg);}

void InitializeQueue(Queue *Q)
{
  Q->Front = NULL;
  Q->Rear  = NULL;
}

int Empty(Queue *Q)
{
  return (Q->Front == NULL);
}

int Insert(ItemType R, Queue *Q)
{   
  QueueNode *Temp;
                                               /* attempt to allocate */
  Temp = (QueueNode *) malloc(sizeof(QueueNode));       /* a new node */

  if (Temp == NULL) {               /* Temp = NULL signals allocation */
     SystemError("system storage is exhausted");           /* failure */
     return 0;
  } else {
     Temp->Item = R;
     Temp->Link = NULL;
     if ( Q->Rear == NULL ) {
        Q->Front = Temp;
        Q->Rear = Temp;
     } else {
        Q->Rear->Link = Temp;
        Q->Rear = Temp;
     }
   }
   return 1;
}