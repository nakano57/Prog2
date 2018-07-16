#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*int randm(int i){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  int o,p;
  p=2*i;
  srand((unsigned int)tv.tv_sec * ((unsigned int)tv.tv_usec + 1));
  o=rand()%p+1;
  return o-i;
} */

unsigned int xor128(void){
static unsigned int x = 123456789;
static unsigned int y = 362436069;
static unsigned int z = 521288629;
static unsigned int w = 88675123;
unsigned int t;

t = x ^ (x << 11);
x = y; y = z; z = w;
return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}


int main(int argc, char const *argv[]) {
  int num=atoi(argv[1]),p,q,i,j,r=1,tmp,zan;
  int w[num][num];

//準備
  for(p=0;p<=num-1;p++){
    for(q=0;q<=num-1;q++){
      w[p][q]=xor128()%num+1;
  //    printf("%d", w[p][q]);
    }
  //  printf("\n");
  }
  //printf("\n");

  for(i=0;i<=num-1;i++){
    r=r*2;
  }

  int x[num][r];
  int result[r];


  for(q=0;q<=r-1;q++){
    result[q]=0;
  }

  for(q=0;q<=r-1;q++){
    for( i = num-1; i >= 0; i-- ) {
        x[i][q]=(( q >> i ) & 1);
        if(x[i][q]==0){
          x[i][q]=-1;
        }
        //printf("%d",x[i][q] );
    }
  //  printf("\n");
  }
//  printf("\n");

  for(q=0;q<=r-1;q++){
    for(i=0;i<=num-1;i++){
      for(j=0;j<=num-1;j++){
        result[q]=result[q]+w[i][j]*x[i][q]*x[j][q];
      }
    }
  //  printf("%d\n",result[q] );
  }

  for(q=0;q<=r-1;q++){
    if(q==0){
        zan=0;
    }else{
      if(result[q]<=result[zan]){
        zan=q;
      }
    }
  }

  printf("f(x)=%d\nx=(",result[zan]);
  for(i=0;i<=num-1;i++){
    printf("%d,",x[i][zan]);
  }
  printf(")\n");

  return 0;
}
