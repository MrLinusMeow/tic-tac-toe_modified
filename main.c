#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(){
 unsigned char table[9] = {'1','2','3','4','5','6','7','8','9'};
 printf("%c%c%c\n", table[0], table[1], table[2]);
 printf("%c%c%c\n", table[3], table[4], table[5]);
 printf("%c%c%c\n", table[6], table[7], table[8]);
 char memX[3] = {'0','0','0'};
 char memY[3] = {'0','0','0'};
 char c;
 char isX = 2;
 int ix = 3;
 int iy = 3;
 while(read(0, &c, 1) > 0){
  if( !isdigit(c) ) continue;
  if( c == '0' ) break;
  if( (table[c-49] != 'X') || (table[c-49] != 'Y') ){
   table[c-49] = ((isX++)%2) ? 'X' : 'Y';
   if(memX[(ix-0)%3] != '0'){
    table[(int)memX[(ix-0)%3]] = (char)memX[(ix-0)%3]+49;
   }
   if(memY[(iy-0)%3] != '0'){
    table[(int)memY[(iy-0)%3]] = (char)memY[(iy-0)%3]+49;
   }
   if(table[c-49] == 'X'){
    memX[(ix++)%3] = c-49;
   }
   if(table[c-49] == 'Y'){
    memY[(iy++)%3] = c-49;
   }
  }else{
   printf("%c is already placed.", table[c-49]);
  }

  printf("%c%c%c\n", table[0], table[1], table[2]);
  printf("%c%c%c\n", table[3], table[4], table[5]);
  printf("%c%c%c\n", table[6], table[7], table[8]);

  if((table[0] == table[1]) && (table[1] == table[2])){
   printf("%c won.\n", table[0]);
   break;
  }else if((table[3] == table[4]) && (table[4] == table[5])){
   printf("%c won.\n", table[3]);
   break;
  }else if((table[6] == table[7]) && (table[7] == table[8])){
   printf("%c won.\n", table[6]);
   break;
  }else if((table[0] == table[3]) && (table[3] == table[6])){
   printf("%c won.\n", table[0]);
   break;
  }else if((table[1] == table[4]) && (table[4] == table[7])){
   printf("%c won.\n", table[1]);
   break;
  }else if((table[2] == table[5]) && (table[5] == table[8])){
   printf("%c won.\n", table[2]);
   break;
  }else if((table[0] == table[4]) && (table[4] == table[8])){
   printf("%c won.\n", table[0]);
   break;
  }else if((table[2] == table[4]) && (table[4] == table[6])){
   printf("%c won.\n", table[2]);
   break;
  }
  continue;
 }
 return 0;
}
