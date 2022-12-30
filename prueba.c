#include <stdio.h>

int main()
{
    system("cls");
    int numTeclado = 1;
    char identificadorAsignado[7 + 1];
    snprintf(identificadorAsignado, 8, "TEC-%d", numTeclado);
    printf("%s", identificadorAsignado);
    return 0;
}