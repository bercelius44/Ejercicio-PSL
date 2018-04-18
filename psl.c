#include <stdio.h>
#include <string.h>

void size();
void printLDC();

char num[100], endProgram[]="0,0", ban=1, ban1=1;
unsigned int tam_f, tam_c, ind, ind1, numeros;

int main(){
  int i=0, indice=0;

  for(i=0;i<100;i++){
    num[i]=0;
  }
  ind=0;
  ind1=0;
  ban1=1;

  printf("Hi, this program show a series of numbers in LCD format.\n");
  printf("Enter the sizes and numbers you want to visualize:\n");
  while(ban==1){
      scanf("%[^\n]", num+indice);
      getchar();
      indice=strlen(num);
      num[indice]=' ';
      indice++;
      if(strstr(num,endProgram)){
        ban=0;
        indice=0;
        while(ban1==1){
          size();
          printLDC();
          if(num[ind1]==0 || (num[ind1+1]=='0' && num[ind1+2]==',' && num[ind1+3]=='0')){
            ban1=0;
          }
        }
      }else{
        ban=1;
      }
  }
}

void size(){
  int i=0;

  for(i=ind1;i<100;i++){
    if(num[i]==','){
      ind=i;
      if(num[i-1]=='0'){
        tam_c=((int)num[i-2]-48)*10+((int)num[i-1]-48);
        tam_f=((int)num[i-2]-48)*10+((int)num[i-1]-48);
      }else{
        tam_c=((int)num[i-1]-48);
        tam_f=((int)num[i-1]-48);
      }
      i=100;
    }
  }
  
  for(i=ind;i<100;i++){
    if(num[i]==' ' || num[i]== 0){
      ind1=i;
      numeros=i-ind-1;
      i=100;
    }
  }
}

void printLDC(){
  int i,j,k=1,l=1,a=0;

  while(k<6){
    for(j=0;j<numeros;j++){
      a=(int)num[ind+1+j]-48;
      switch(k){
          case 1:
            if(a==0 || a==2 || a==3 || a==5 || a==6 || a==7 || a==8 || a==9 ){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf("-");
              }
              printf("  ");
            }else if(a==1 || a==4){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf(" ");
              }
              printf("  ");
            }
          break;

          case 2:
              if(a==0 || a==4 || a==8 || a==9){
                printf("|");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("| ");
              }else if(a==1 || a==2 || a==3 || a==7){
                printf(" ");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("| ");
              }else if(a==5 || a==6 ){
                printf("|");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("  ");
              }
          break;

          case 3:
            if(a==1 || a==7){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf(" ");
              }
              printf("| ");
            }else if(a==2 || a==3 || a==4 || a==5 || a==6 || a==8 || a==9){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf("-");
              }
              printf("  ");
            }else if(a==0){
              printf("|");
              for(i=0;i<tam_c;i++){
                printf(" ");
              }
              printf("| ");
            }
          break;

          case 4:
              if(a==0 || a==6 || a==8){
                printf("|");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("| ");
              }else if(a==1 || a==3 || a==4 || a==5 || a==7 || a==9){
                printf(" ");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("| ");
              }else if(a==2){
                printf("|");
                for(i=0;i<tam_c;i++){
                  printf(" ");
                }
                printf("  ");
              }
          break;

          case 5:
            if(a==1 || a==4 || a==7){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf(" ");
              }
              printf("  ");
            }else if(a==0 || a==2 || a==3 || a==5 || a==6 || a==8 || a==9){
              printf(" ");
              for(i=0;i<tam_c;i++){
                printf("-");
              }
              printf("  ");
            }
          break;
      }
    }
    if((k==2 && l<tam_f) || (k==4 && l<tam_f)){
      l++;
      printf("\n");
    }else{
      k++;
      printf("\n");
      l=1;
    }
  }
}
