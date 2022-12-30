#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    system("cls");
    int numTeclado = rand() %1000;
    char identificadorAsignado[7 + 1];
    snprintf(identificadorAsignado, 8, "TEC-%d", numTeclado);
    printf("%s", identificadorAsignado);
    return 0;
}