#include <stdio.h>
#include <string.h>
  
char field[40][40];
  
int main(void){
  
    for(int i=0; i<40; i++){
        for(int j=0; j<40; j++){
            field[i][j] = '.';
        }
    }
  
    char str1[40], str2[40];
    scanf("%s %s", str1, str2);
    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
  
    int x, y;
    bool find = false;
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            if(str1[i] == str2[j]){
                x = j;
                y = i;
                find = true;
                break;
            }
        }
        if(find){
            break;
        }
    }
  
    for(int i=0; i<len1; i++){
        field[x][i] = str1[i];
    }
    for(int i=0; i<len2; i++){
        field[i][y] = str2[i];
    }
  
    for(int i=0; i<len2; i++){
        for(int j=0; j<len1; j++){
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}
