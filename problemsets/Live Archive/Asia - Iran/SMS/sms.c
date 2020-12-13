#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *sms[25];


int main() {
    
    char str[105];
    int i;
    
    sms[0] = "ACB"; sms[1] = "BAC"; sms[2] = "CBA";
    sms[3] = "DFE"; sms[4] = "EDF"; sms[5] = "FED";
    sms[6] = "GIH"; sms[7] = "HGI"; sms[8] = "IHG";
    sms[9] = "JLK"; sms[10] = "KJL"; sms[11] = "LKJ";
    sms[12] = "MON"; sms[13] = "NMO"; sms[14] = "ONM";
    sms[15] = "PSRQ"; sms[16] = "QPSR"; sms[17] = "RQPS"; sms[18] = "SRQP";
    sms[19] = "TVU"; sms[20] = "UTV"; sms[21] = "VUT";
    sms[22] = "WZYX"; sms[23] = "XWZY"; sms[24] = "YXWZ"; sms[25] = "ZYXW";
    
    while (gets(str)) {
        
        if (*str == '#') break;
        
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z')
                putchar(sms[str[i]-'A'][((i+1)%strlen(sms[str[i]-'A']))]);
            else
                putchar(sms[str[i]-'a'][((i+1)%strlen(sms[str[i]-'a']))]-'A'+'a');
        }
        
        putchar('\n');
    }
    
    return 0;
}
