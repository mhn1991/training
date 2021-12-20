#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#define Red 1
#define White 2
#define Blue 3


void print_flag(int *flag){
  for(int i=0;i<9;i++){
    printf("%d,",*(flag+i));
  }
  printf("\n");
}


int * fill_the_flag(int * flag){
  int color = 1;
  int counter   = 0;
  int *first = flag;
  srand(time(NULL));
  int rand_index = 0;
  for(int i =0;i <9;i++){
    //printf("%d\n",i);
    print_flag(flag);
    if(counter == 3){
      counter =0;
      color +=1;
    }
  rand_again:
    rand_index = rand()%10;
    //printf("rand_index: %d\n",rand_index);
    if(*(flag+rand_index) != 0 ){
      flag = first;
      goto rand_again;
    }
    *(flag+rand_index) = color;
    flag = first;
    counter +=1;
  }
  print_flag(flag);
}

int main(){
  int flag[9]= {0};
  //print_flag(flag);
  fill_the_flag(flag);
}
