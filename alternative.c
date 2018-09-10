#include <stdio.h>
#include <string.h>

short main(){
    short testCount;
    scanf("%hi", &testCount);

    while(testCount--){
        short tableLength, keyCount;
        scanf("%hi %hi", &tableLength, &keyCount);
        
        short matrix[tableLength][keyCount];
        memset(matrix, 0, sizeof(matrix[0][0]) * tableLength * keyCount);
        
        for(short i = 0; i < keyCount; i++){
            short key, hash;
            scanf("%hi", &key);

            hash = key % tableLength;
            for(short j = 0; j < keyCount; j++){
                if(matrix[hash][j] == 0){
                    matrix[hash][j] = key;
                    break;
                }
            }
        }
            
        for(short i = 0; i < tableLength; i++){
            printf("%hi -> ", i);
            for(short j = 0; j < keyCount; j++){
                if(matrix[i][j] == 0) break;
                printf("%hi -> ", matrix[i][j]);
                }
            printf("\\\n");
            }

        if(testCount) printf("\n");
    } 
    return 0;
}
