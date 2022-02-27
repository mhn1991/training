#include<stdio.h>

int handShackes(int size,char **list){
int numHandShakes = 0;
  //days
  for(int i=0; i< size;i++)
  {
    //int numHandShakes = 0;
    int offset = 0;
    while(*(list[i]+offset) != '\0'){
      int index  = 0;
      while(*(list[i]+index) != '\0'){
	if(*(list[i]+index) == *(list[i]+index+offset)){
	  numHandShakes +=1;
	}
	else{
	  break;
	}
	printf("%c",*(list[i]+index));
	index +=1;
      }
      offset +=1;
    }
    printf("\n");
  }
  return numHandShakes;
}


int main()
{
  char *list[] = {"abca","saf"};
  printf("%d\n",handShackes(2,list));
}
