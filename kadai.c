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
  printf("| |1|2|3|4|5|6|7|8|\n");
  for(p=0;p<=7;p++){
    printf("|%d",p+1);
    for(q=0;q<=7;q++){
      if(men[p][q]==1){
        printf("|●");
      }else if(men[p][q]==100){
	printf("|○");
      }else{
	printf("| ");
      }
      /* //    printf("|%d",men[p][q]); */
    }
     printf("|\n");

  }
}

int canplace(int men[8][8],int inx,int iny){
  int q,aite,jibun,mukiy,mukix;
  aite=100;
  jibun=1;

//方向をチェック
  if(men[iny-1][inx-1]==aite){
    q=6; //左上
  }else if(men[iny+1][inx-1]==aite){
    q=8; //左下
  }else if(men[iny+1][inx+1]==aite){
    q=2; //右下
  }else if(men[iny-1][inx+1]==aite){
    q=4; //右上
  }else if(men[iny+1][inx]==aite){
    q=1; //下
  }else if(men[iny-1][inx]==aite){
    q=5; //上
  }else if(men[iny][inx+1]==aite){
    q=3; //右
  }else if(men[iny][inx-1]==aite){
    q=7; //左
  }else{
    q=0;
  }

  //その先をチェック
  switch (q) {
    case 1:
      for(mukiy=iny+2;mukiy<=7;mukiy++){
        if(men[mukiy][inx]==jibun){
          q=1;
          break;
        }else{
          q=0;
        }
      }
      break;
    case 2:
      for (mukiy=iny+2;mukiy>=0;mukiy--){
        for(mukix=inx+2;mukix<=7;mukix++){
          if (men[mukiy][mukix]==jibun) {
            q=2;
            break;
          }else{
            q=0;
          }
        }
      }
      break;

    case 3:
      for(mukix=inx+2;mukix<=7;mukix++){
        if(men[iny][mukix]==jibun){
          q=3;
          break;
        }else{
          q=0;
        }
    }
    break;

    case 4:
      for (mukiy=iny+2;mukiy<=7;mukiy++){
        for(mukix=inx+2;mukix<=7;mukix++){
          if (men[mukiy][mukix]==jibun) {
            q=4;
            break;
          }else{
            q=0;
          }
        }
      }
      break;

    case 5:
      for(mukiy=iny+2;mukiy>=0;mukiy--){
        if(men[mukiy][inx]==jibun){
          q=5;
          break;
        }else{
          q=1;
        }
      }
      break;

    case 6:
      for (mukiy=iny+2;mukiy<=7;mukiy++){
        for(mukix=inx+2;mukix>=0;mukix--){
          if (men[mukiy][mukix]==jibun) {
            q=6;
            break;
          }else{
            q=0;
          }
        }
      }
      break;

    case 7:
      for(mukix=inx+2;mukix>=0;mukix--){
        if(men[iny][mukix]==jibun){
          q=7;
          break;
        }else{
          q=0;
        }
      }
      break;

    case 8:
      for (mukiy=iny+2;mukiy>=0;mukiy--){
        for(mukix=inx+2;mukix>=0;mukix--){
          if (men[mukiy][mukix]==jibun) {
            q=8;
            break;
          }else{
            q=0;
          }
        }
      }
      break;

    case 0:;
      break;
  }

  return q;
}

int uragaesi(int men[8][8],int inx,int iny,int q){
  int jibun=1,aite=100,mukix,mukiy;

  switch (q) {
    case 1:
      for(mukiy=iny+1;mukiy<=7;mukiy++){
        if(men[mukiy][inx]==aite){
          men[mukiy][inx]=jibun;
        }else{
          break;
        }
      }
      break;
    case 2:
      for (mukiy=iny+1;mukiy>=0;mukiy--){
        for(mukix=inx+1;mukix<=7;mukix++){
          if (men[mukiy][mukix]==aite) {
            men[mukiy][mukix]=jibun;
          }else{
          break;
          }
        }
      }
      break;

    case 3:
      for(mukix=inx+1;mukix<=7;mukix++){
        if(men[iny][mukix]==aite){
          men[iny][mukix]=jibun;
        }else{
          break;
        }
    }
    break;

    case 4:
      for (mukiy=iny+2;mukiy<=7;mukiy++){
        for(mukix=inx+2;mukix<=7;mukix++){
          if (men[mukiy][mukix]==aite) {
          men[mukiy][mukix]=jibun;
          }else{
            break;
          }
        }
      }
      break;

    case 5:
      for(mukiy=iny+2;mukiy>=0;mukiy--){
        if(men[mukiy][inx]==aite){
          men[mukiy][inx]=jibun;
        }else{
          break;
        }
      }
      break;

    case 6:
      for (mukiy=iny+2;mukiy<=7;mukiy++){
        for(mukix=inx+2;mukix>=0;mukix--){
          if (men[mukiy][mukix]==aite) {
            men[mukiy][mukix]=jibun;
          }else{
            break;
          }
        }
      }
      break;

    case 7:
      for(mukix=inx+2;mukix>=0;mukix--){
        if(men[iny][mukix]==aite){
          men[iny][mukix]=jibun;
        }else{
          break;
        }
      }
      break;

    case 8:
      for (mukiy=iny+2;mukiy>=0;mukiy--){
        for(mukix=inx+2;mukix>=0;mukix--){
          if (men[mukiy][mukix]==aite) {
            men[mukiy][mukix]=jibun;
          }else{
            break;
          }
        }
      }
      break;

    case 0:;
      break;
  }
}


int main(void){

  int men[8][8];
  int p,q,inx,iny,cap;

  /*盤面を初期化*/
  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      men[p][q]=0;
    }
  }
  men[3][3]=1;
  men[4][4]=1;
  men[3][4]=100;
  men[4][3]=100;

  ban(men);

 /*先攻後攻を決定*/
  if(randm()==1){
    printf("先攻です\n");
  }else{
    printf("後攻です\n");
  }


  //while(1){
while(1){
  printf("変更箇所を入力してください\n横:");
  scanf("%d",&inx);
  printf("縦:");
  scanf("%d",&iny);
  inx=inx-1;
  iny=iny-1;


  cap=canplace(men,inx,iny);
  if(cap==0){
    ban(men);
    printf("この場所には置けません\n");
  }else{
    men[iny][inx]=1;
    uragaesi(men,inx,iny,cap);
    ban(men);
    break;
  }

}
  // }

}
