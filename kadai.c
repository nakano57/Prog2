#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randm(void){
  int o;
  srand((unsigned)time(NULL));
  o=rand()%2+1;
  return o;
}

int ban(int men[8][8]){
  int p,q;

  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      if(men[p][q]==1){
        printf("|○");
      }else if(men[p][q]==10){
	printf("|●");
      }else{
	printf("| ");
      }
      /* //    printf("|%d",men[p][q]); */
    }
     printf("|\n");

  }
}

int canplace(int men[8][8],int inx,int iny){
  int q;

  if(men[iny-1][inx-1]){

  }else if(men[iny+1][inx-1]){

  }else if(men[iny+1][inx+1]){

  }else if(men[iny-1][inx+1]){

  }else{

  }
}


int main(void){

  int men[8][8];
  int p,q,inx,iny;

  /*盤面を初期化*/
  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      men[p][q]=0;
    }
  }
  men[3][3]=1;
  men[4][4]=1;
  men[3][4]=10;
  men[4][3]=10;

  ban(men);


 /*先攻後攻を決定*/
  if(randm()==1){
    printf("先攻です\n");
  }else{
    printf("後攻です\n");

  }



  //while(1){

  printf("変更箇所を入力してください\n横:");
  scanf("%d",&inx);
  printf("縦");
  scanf("%d",&iny);
  inx=inx-1;
  iny=iny-1;
  men[iny][inx]=1;
  ban(men);
  // }

}
