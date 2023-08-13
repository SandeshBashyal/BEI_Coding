# include <stdio.h>
# include <stdlib.h>
// initialize a mutex to 1
int mutex = 1;
//No of full slots as 0
int full = 0;
// No of empty slots as size of buffer
int empty = 10, x = 0;
// Function to produce an item and add it to the buffer
void producer(){
--mutex;
++full;
--empty;
x++;
// Item produced
printf("\nProducer produces item %d",x);
++mutex;
}

// Function to consume an item and remove it from buffer
void consumer(){
--mutex;
--full;
++empty;
printf("\nConsumer consumes item %d",x);
x--;
++mutex;
}

// Driver code
int main(){
int n, i;
printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for exit");
for (i = 1; i>0;i++){
printf("\nEnter your choice:");
scanf("%d", &n);
switch(n){
case 1:
if ((mutex == 1) && (empty !=0)) {
producer();
}
else{
printf("Buffer is full!\n");
}
break;

case 2:
if((mutex == 1) && (full != 0)){
consumer();
}
else{
printf("Buffer is empty\n");
}
break;

case 3:
exit(0);
break;
}}}
