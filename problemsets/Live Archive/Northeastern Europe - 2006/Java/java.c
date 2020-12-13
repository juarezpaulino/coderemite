/* Java vs C++ */

#include <stdio.h>
#include <ctype.h>

char str[150],  t[300];
char cpp, java, error;


int main() {
    
    int i, j;
    
    while (scanf("%s ", str) != EOF) {
        
        if (str[0] == '\0') break;
        
        if ((isupper(str[0])) || (str[0] == '_')) { printf("Error!\n"); continue; }
        cpp = java = 0;
        for (i = 0; str[i] != '\0'; i++)
            if (str[i] == '_') cpp = 1;
            else if (isupper(str[i])) java = 1;
        if (str[i-1] == '_') { printf("Error!\n"); continue; }
        
        j = 0; error = 0;
        if ((cpp) && (java)) { printf("Error!\n"); continue; }
        else if ((!cpp) && (!java)) { puts(str); continue; }
        else if (cpp) {
            for (i = 0; str[i] != '\0'; i++) {
                if (str[i] == '_') {
                    i++;
                    if (str[i] == '_')  { error = 1; break; }
                    else t[j++] = str[i]-'a'+'A';
                }
                else t[j++] = str[i];
            }
        }
        else {
            for (i = 0; str[i] != '\0'; i++)
                if (isupper(str[i])) { t[j++] = '_'; t[j++] = str[i]-'A'+'a'; }
                else t[j++] = str[i];
        }
        
        if (error) printf("Error!\n");
        else { t[j] = '\0'; printf("%s\n", t); }
    }
    
    return 0;   
}
