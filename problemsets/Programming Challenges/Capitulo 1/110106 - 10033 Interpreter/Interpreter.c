/* Interpreter.c - problem H */

#include <stdio.h>
#include <string.h>

#define MAX_REGISTERS 10
#define MAX_RAM 1000
#define ASCII_INT 48

int registers[MAX_REGISTERS];
char ram[MAX_RAM][4];
int operations;

void initialize() {
    int i;
    
    for (i = 0; i < MAX_REGISTERS; i++)
        *(registers + i) = 0;
}

int process(char *aux) {
    
    int num, i;

    switch (*aux) {
        
        case '1':
            if ((*(aux + 1) == '0') && (*(aux + 2) == '0')) {
                operations++;
                return (0);
            }
            break;
        case '2':
            registers[*(aux + 1) - ASCII_INT] = *(aux + 2) - ASCII_INT;
            operations++;
            break;
        case '3':
            registers[*(aux + 1) - ASCII_INT] += *(aux + 2) - ASCII_INT;
            registers[*(aux + 1) - ASCII_INT] %= 1000;
            operations++;
            break;
        case '4':
            registers[*(aux + 1) - ASCII_INT] *= *(aux + 2) - ASCII_INT;
            registers[*(aux + 1) - ASCII_INT] %= 1000;
            operations++;
            break;
        case '5':
            registers[*(aux + 1) - ASCII_INT] = registers[*(aux + 2) - ASCII_INT];
            operations++;
            break;
        case '6':
            registers[*(aux + 1) - ASCII_INT] += registers[*(aux + 2) - ASCII_INT];
            registers[*(aux + 1) - ASCII_INT] %= 1000;
            operations++;
            break;
        case '7':
            registers[*(aux + 1) - ASCII_INT] *= registers[*(aux + 2) - ASCII_INT];
            registers[*(aux + 1) - ASCII_INT] %= 1000;
            operations++;
            break;
        case '8':
            sscanf(ram[registers[*(aux + 2) - ASCII_INT]], "%d", &num);
            registers[*(aux + 1) - ASCII_INT] = num;
            operations++;
            break;
        case '9':
            sprintf(ram[registers[*(aux + 2) - ASCII_INT]], "%03d", registers[*(aux + 1) - ASCII_INT]);
            operations++;
            break;
        case '0':
            operations++;
            if (registers[*(aux + 2) - ASCII_INT] != 0) {
                num = 1;
                for(i = 0; num; i++)
                    num = process(ram[registers[*(aux + 1) - ASCII_INT]+i]);
                return (0);
            }
            break;
    }
    return(1);                   
    
}

int main() {
 
    int cases, num_ram, i, ret, aux;
    char cr;
 
    scanf("%d", &cases);
    
    aux = cases;
    getchar();
    getchar();
    while(cases) {
        
        initialize();
        num_ram = 0;
        operations = 0;
        
        cr = 48;
        while(1) {
            for (i = 0; i < 3; i++) { 
                cr = getchar();
                if ((cr == '\n') || (cr == EOF))
                    break;
                ram[num_ram][i] = cr;
            }
            if ((cr == '\n') || (cr == EOF))
                    break;
            ram[num_ram][i] = '\0';
            num_ram++;
            cr = getchar();
        }
        
        for (i = num_ram ; i < MAX_RAM; i++)
            strcpy(ram[i],"000");

        ret = 1;
        for(i = 0; ret; i++)
            ret = process(ram[i]);
        
        if (aux == 1)
            printf("%d\n", operations);
        else if (cases == aux)
            printf("%d\n", operations);
        else   
            printf("\n%d\n", operations);
        
        cases--;
    }
    getchar();
    return 0;
}
