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


void fill_the_flag(int * flag){
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

void solver(int *flag){
  int array_size = 9;
  int low_index  = 0;
  int mid_index  = 0;
  int high_index = array_size - 1;
  int tmp = 0;
  while(mid_index <= high_index){
    switch(*(flag+mid_index)){
    case Red:
      tmp = *(flag+low_index);
      *(flag+low_index) = Red;
      *(flag+mid_index) = tmp;
      low_index +=1;
      mid_index +=1;
      break;
    case White:
      mid_index +=1;
      break;
    case Blue:
      tmp = *(flag+high_index);
      *(flag+high_index) = Blue;
      *(flag+mid_index) = tmp;
      high_index -=1;
      break;
    }
  }
}


int main(){
  int flag[9]= {0};
  //print_flag(flag);
  fill_the_flag(flag);
  solver(flag);
  print_flag(flag);
  //printf("%d\n",*(&flag +1) - flag);
}
