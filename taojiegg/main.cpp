 #include <stdio.h>
#include<stdlib.h>
 #include <string.h>
   int main(){

          //id,姓名,语文,数学,英语
	  int temp=0;
          char str[]="2,张三,89,99,66";
          char* token=strtok(str,",");
	  temp=atoi(token);
          while(token!=NULL){

              printf("%s\n",token);

          token=strtok(NULL,",");
  	

      } 

      printf("%d\n",temp);

      return 0;

}
