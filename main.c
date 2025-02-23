#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv){
  char mode;
  int t = 0, n = 0;
  char buffer[50];
  FILE *txt;
  FILE *total;
  txt = fopen("log.txt","a");
  total = fopen("total.txt", "r");
  char total_buffer[50];
  fgets(total_buffer, sizeof(total_buffer), total);
  t = atoi(total_buffer);
  
  printf("type the mode h for list \n");
  scanf("%c", &mode);
  if(mode == 'h'){
    printf("s for total\na to add money\n d to discount money\n");
  }else if(mode == 'p'){
    printf("Total = $%d\n", t);
    return 0;
   }else if(mode == 'a'){
    printf("Type the amount\n");
    scanf("%d", &n);
    printf("Type the concept: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(txt, "+%d\n", n);
    fprintf(txt, "%s\n", buffer);
    t += n;
    fclose(total);
    total = fopen("total.txt", "w");
    fprintf(total ,"%d", t);
    fclose(total);
  }else if(mode = 'd'){ 
    printf("Type the amount\n");
    scanf("%d", &n);
    printf("Type the concept: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(txt, "-%d\n", n);
    fprintf(txt, "%s\n", buffer);
    t -= n;
    fclose(total);
    total = fopen("total.txt", "w");
    fprintf(total ,"%d", t);
    fclose(total);
  }
  fclose(txt);
  return 0;
}
