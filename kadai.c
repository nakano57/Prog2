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
      }else if(men[p][q]==-1){
        printf("|x");
      }else{
	printf("| ");
      }
      /* //    printf("|%d",men[p][q]); */
    }
     printf("|\n");

  }
}

int deban(int omomi[8][8]){
  int p,q;
  printf("| |1|2|3|4|5|6|7|8|\n");
  for(p=0;p<=7;p++){
    printf("|%d",p+1);
    for(q=0;q<=7;q++){
    printf("|%d",omomi[p][q]);
    }
     printf("|\n");

  }
}

int canplace(int men[8][8],int inx,int iny,int player){
   int q=0,aite,jibun,mukiy,mukix,i;

   if(player==1){
     aite=100;
     jibun=1;
   }else if(player==0){
     aite=1;
     jibun=100;
   }

   if(men[inx][iny]!=0){
     return q;
   }


 //方向をチェック
   if(men[iny-1][inx-1]==aite){ //左上6
     for(i=1;;i++){
       if(men[iny-i][inx-i]==jibun){
         q=6;
         break;
       }else if(iny-i<0 || inx-i<0){
         break;
       }
     }
     /*
     for (mukiy=iny-1;mukiy>=0;mukiy--){
       for(mukix=inx-1;mukix>=0;mukix--){
         if (men[mukiy][mukix]==jibun) {
           q=6;
           break;
         }
       }
     } */
   }
   if(men[iny+1][inx-1]==aite){ //左下8
     for(i=1;;i++){
       if(men[iny+i][inx-i]==jibun){
         q=8;
         break;
       }else if(iny+i>7 || inx-i<0){
         break;
       }
     }
     /*
     for (mukiy=iny+1;mukiy<=7;mukiy++){
       for(mukix=inx-1;mukix>=0;mukix--){
         if (men[mukiy][mukix]==jibun) {
           q=8;
           break;
         }
       }
     } */
   }
   if(men[iny+1][inx+1]==aite){ //右下2
     for(i=1;;i++){
       if(men[iny+i][inx+i]==jibun){
         q=2;
         break;
       }else if(iny+i>7 || inx+i>7){
         break;
       }
     }
     /*
     for (mukiy=iny+1;mukiy<=7;mukiy++){
       for(mukix=inx+1;mukix<=7;mukix++){
         if (men[mukiy][mukix]==jibun) {
           q=2;
           break;
         }
       }
     } */
   }
   if(men[iny-1][inx+1]==aite){ //右上4
     for(i=1;;i++){
       if(men[iny-i][inx+i]==jibun){
         q=4;
         break;
       }else if(iny-i<0 || inx+i>7){
         break;
       }
     }
     /*
     for (mukiy=iny-1;mukiy>=0;mukiy--){
       for(mukix=inx+1;mukix<=7;mukix++){
         if (men[mukiy][mukix]==jibun) {
           q=4;
           break;
         }
       }
     } */
   }
   if(men[iny+1][inx]==aite){ //下1
     for(mukiy=iny+1;mukiy<=7;mukiy++){
       if(men[mukiy][inx]==jibun){
         q=1;
         break;
       }
     }
   }
   if(men[iny-1][inx]==aite){ //上5
     for(mukiy=iny-1;mukiy>=0;mukiy--){
       if(men[mukiy][inx]==jibun){
         q=5;
         break;
       }
     }
   }
   if(men[iny][inx+1]==aite){ //右3
     for(mukix=inx+1;mukix<=7;mukix++){
       if(men[iny][mukix]==jibun){
         q=3;
         break;
       }
     }
   }
   if(men[iny][inx-1]==aite){ //左7
     for(mukix=inx-1;mukix>=0;mukix--){
       if(men[iny][mukix]==jibun){
         q=7;
         break;
       }else{
         q=0;
       }
     }
   }

    return q;
  }

int uragaesi(int men[8][8],int inx,int iny,int q,int player){
  int jibun,aite,mukix,mukiy,i;
  printf("case:%d\n",q);
  if(player==1){
    aite=100;
    jibun=1;
  }else if(player==0){
    aite=1;
    jibun=100;
  }

  switch (q) {
    case 1: //下
      for(mukiy=iny+1;mukiy<=7;mukiy++){
        if(men[mukiy][inx]==aite){
          men[mukiy][inx]=jibun;
        }else{
          break;
        }
      }
      break;

    case 2: //右下
      for(i=0;;i++){
        if(men[iny+i][iny+i]==aite){
          men[iny+i][iny+i]=jibun;
        }
      }
      break;

    case 3: //右
      for(mukix=inx+1;mukix<=7;mukix++){
        if(men[iny][mukix]==aite){
          men[iny][mukix]=jibun;
        }else{
          break;
        }
      }
      break;

    case 4: //右上
      for(i=1;;i++){
        if(men[iny-i][inx+i]==aite){
          men[iny-i][inx+i]=jibun;
        }else{
          break;
        }
      }
      break;

    case 5: //上
      for(mukiy=iny-1;mukiy>=0;mukiy--){
        if(men[mukiy][inx]==aite){
          men[mukiy][inx]=jibun;
        }else{
          break;
        }
      }
      break;

    case 6: //左上
      for(i=1;;i++){
        if(men[iny-i][inx-i]==aite){
          men[iny-i][inx-i]=jibun;
        }else{
          break;
        }
      }
      break;

    case 7: //左
      for(mukix=inx-1;mukix>=0;mukix--){
        if(men[iny][mukix]==aite){
          men[iny][mukix]=jibun;
        }else{
          break;
        }
      }
      break;

    case 8: //左下
      for(i=1;;i++){
        if(men[iny+i][inx-i]==aite){
          men[iny+i][inx-i]=jibun;
        }else{
          break;
        }
      }
      break;

    case 0:;

      break;
  }
}

int dokoniokerukana(int men[8][8],int okumen[8][8],int player){
  int p,q;
  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      okumen[p][q]=men[p][q];
      if (canplace(men,q,p,player)!=0) {
        okumen[p][q]=-1;
      }
    }
  }
}

/*struct complace{
  int okuy;
  int okux;
  int uray;
  int urax;
}; */
/*
int compuragaesi(int men[8][8],int inx,int iny,int q,int omomi[8][8]){
  int jibun=100,aite=1,mukix,mukiy;
    // struct complace cp;

  switch (q) {
    case 1:
      for(mukiy=iny+1;mukiy<=7;mukiy++){
        if(men[mukiy][inx]==aite){
          omomi[mukiy][inx]=omomi[mukiy][inx]+1;
        }else{
          break;
        }
      }
      break;
    case 2:
      for (mukiy=iny-1;mukiy>=0;mukiy--){
        for(mukix=inx+1;mukix<=7;mukix++){
          if (men[mukiy][mukix]==aite) {
            omomi[mukiy][mukix]=omomi[mukiy][mukix]+1;
          }else{
          break;
          }
        }
      }
      break;

    case 3:
      for(mukix=inx+1;mukix<=7;mukix++){
        if(men[iny][mukix]==aite){
          omomi[iny][mukix]=omomi[iny][mukix]+1;
        }else{
          break;
        }
    }
    break;

    case 4:
      for (mukiy=iny+1;mukiy<=7;mukiy++){
        for(mukix=inx+1;mukix<=7;mukix++){
          if (men[mukiy][mukix]==aite) {
          omomi[mukiy][mukix]=omomi[mukiy][mukix]+1;
          }else{
            break;
          }
        }
      }
      break;

    case 5:
      for(mukiy=iny-1;mukiy>=0;mukiy--){
        if(men[mukiy][inx]==aite){
          omomi[mukiy][inx]=omomi[mukiy][inx]+1;
        }else{
          break;
        }
      }
      break;

    case 6:
      for (mukiy=iny+1;mukiy<=7;mukiy++){
        for(mukix=inx-1;mukix>=0;mukix--){
          if (men[mukiy][mukix]==aite) {
            omomi[mukiy][mukix]=omomi[mukiy][mukix]+1;
          }else{
            break;
          }
        }
      }
      break;

    case 7:
      for(mukix=inx-1;mukix>=0;mukix--){
        if(men[iny][mukix]==aite){
          omomi[iny][mukix]=omomi[iny][mukix]+1;
        }else{
          break;
        }
      }
      break;

    case 8:
      for (mukiy=iny-1;mukiy>=0;mukiy--){
        for(mukix=inx-1;mukix>=0;mukix--){
          if (men[mukiy][mukix]==aite) {
            omomi[mukiy][mukix]=omomi[mukiy][mukix]+1;
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
*/

int main(void){

  int men[8][8];
  int okumen[8][8];
  int comen[8][8]; //コンピュータ用
  int omomi[8][8]; //コンピュータ用
  int p,q,inx,iny,cap,end;

  /*盤面を初期化*/
  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      men[p][q]=0;
      comen[p][q]=0;
      omomi[p][q]=0;
    }
  }
  men[3][3]=1;
  men[4][4]=1;
  men[3][4]=100;
  men[4][3]=100;

 /*先攻後攻を決定　交互にやるなら要らない気もする*/
  if(randm()==1){
    printf("先攻です\n");
  }else{
    printf("後攻です\n");
  }


  while(1){
        /*プレイヤー1の操作*/
    dokoniokerukana(men,okumen,1);
    ban(okumen);
    ban(men);

    while(1){
      printf("プレイヤー1:●\n変更箇所を入力してください\n横:");
      scanf("%d",&inx);
      printf("縦:");
      scanf("%d",&iny);
      inx=inx-1;
      iny=iny-1;


      cap=canplace(men,inx,iny,1);
      if(cap==0){
        ban(men);
        printf("この場所には置けません\n");
      }else{
        men[iny][inx]=1;
        while (1) {
          uragaesi(men,inx,iny,cap,1);
          cap=canplace(men,inx,iny,1);
          if(cap==0){
            break;
          }
        }
        break;
      }
    }
    /*プレイヤー1ここまで*/

    /*プレイヤー2*/
    dokoniokerukana(men,okumen,0);
    ban(okumen);
    ban(men);

    while(1){
      printf("プレイヤー2:○\n変更箇所を入力してください\n横:");
      scanf("%d",&inx);
      printf("縦:");
      scanf("%d",&iny);
      inx=inx-1;
      iny=iny-1;


      cap=canplace(men,inx,iny,0);
      if(cap==0){
        ban(men);
        printf("この場所には置けません\n");
      }else{
        men[iny][inx]=100;
        while (1) {
          uragaesi(men,inx,iny,cap,0);
          cap=canplace(men,inx,iny,0);
          if(cap==0){
            break;
          }
        }
        ban(men);
        break;
      }
    }

    /*ゲーム終了の判定*/
    end=0;
    for(p=0;p<=7;p++){
      for(q=0;q<=7;q++){
        if(men[p][q]==0){
          end=end+1;
        }
      }
    }
    if(end==0){
      break;
    }
  }


  /*コンピューター
  for(p=0;p<=7;p++){
    for(q=0;q<=7;q++){
      cap=canplace(men,p,q,0);
      if(cap!=0){
        printf("置けるよ！\n");
        comen[p][q]=cap;
    //    compuragaesi(men,p,q,cap,omomi);
      }
    }
  }
  deban(comen);
  deban(omomi);
  // }*/

}
