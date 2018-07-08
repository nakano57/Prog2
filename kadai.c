#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randm(void){
  int o;
  srand((unsigned)time(NULL));
  o=rand()%2+1;
  return o;
}



int main(void){
  int men[8][8];
  int p,q;

  /*盤面を初期化*/
  for(p=0;p<=2;p++){
    for(q=0;q<=2;q++){
      men[p][q]=0;
      //printf("|%d",ban[p][q]);
    }
    // printf("|\n");
  }

  if(randm()==1){
    printf("先攻です\n");
  }else{
    printf("後攻です\n");
  }

  while(1){
  }

}
