#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int xor128(void){
static unsigned long int x = 123456789;
static unsigned long int y = 362436069;
static unsigned long int z = 528388629;
static unsigned long int w = 88675123;
long unsigned int t;

t = x ^ (x << 11);
x = y; y = z; z = w;
return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}


int main(int argc, char const *argv[]) {
  long long int i,j,tmp,zan;
  long long unsigned int r=1,p,q,num=atoi(argv[1]);
  long int w[num][num];
  int **x;
  int *result;
//  long long int x[num][r];
//  long long int result[r];

//準備
  for(i=0;i<=num-1;i++){
    r=r*2;
  }

  for(p=0;p<=num-1;p++){
    for(q=0;q<=num-1;q++){
      w[p][q]=xor128()%num+1;
    //  printf("%d", w[p][q]);
    }
  //  printf("\n");
  }
//  printf("\n");


  printf("passed3\n");
  //long long int result[r];
  result = (int *)calloc(r, sizeof(int));
  printf("passed4\n");

  x = (int**)calloc(num, sizeof(int));
	for (i=0; i<num; i++) {
		x[i] = (int*)calloc(r, sizeof(int));
	}
//  long long int x[num][r];


//  for(q=0;q<=r;q++){
//    result[q]=0;
//  }
  printf("passed2\n");
  for(q=0;q<=r-1;q++){
    for( i = num-1; i >= 0; i-- ) {
        x[i][q]=(( q >> i ) & 1);

        if(x[i][q]==0){
          x[i][q]=-1;
        }
        printf("%d",x[i][q] );
    }
    printf("\n");
  }
  printf("\n");

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

  free(x[0]);
  free(x);
  free(result);
  return 0;
}
