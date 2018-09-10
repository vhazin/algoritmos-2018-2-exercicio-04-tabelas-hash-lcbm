#include <stdio.h>
#include <string.h>

short main(){
    short n;
    scanf("%hi", &n);

    while(n--){
        short m, c;
        scanf("%hi %hi", &m, &c);
        
        short matriz[m][c];
        memset(matriz, 0, sizeof(matriz[0][0]) * m * c);
        
        for(short i = 0; i < c; i++){
            short cValor, hash;
            scanf("%hi", &cValor);

            hash = cValor % m;
            for(short j = 0; j < c; j++){
                if(matriz[hash][j] == 0){
                    matriz[hash][j] = cValor;
                    break;
                }
            }
        }
            
        for(short i = 0; i < m; i++){
            printf("%hi -> ", i);
            for(short j = 0; j < c; j++){
                if(matriz[i][j] == 0) break;
                printf("%hi -> ", matriz[i][j]);
                }
            printf("\\\n");
            }

        if(n) printf("\n");
    } 
    return 0;
}