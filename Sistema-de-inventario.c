#include <stdio.h>
#include <string.h> //strcpy, strcmp,
#include <conio.h>  //getch

#define USUARIOS 5
#define LONGITUD 10
// Teclas del código ASCII
#define ENTER 13
#define BORRAR 8

typedef struct cuentaDelSistema
{
    char username[LONGITUD];
    char password[LONGITUD];
} LOGIN;

int main()
{
    system("cls");
    char username[USUARIOS][LONGITUD + 1];
    char password[USUARIOS][LONGITUD + 1];
    char letra, userIngresado[LONGITUD + 1], passIngresada[LONGITUD + 1];
    int contador, j, intentos = 0;

    LOGIN account[USUARIOS];
    // Cuenta declarada por defecto.
    strcpy(account[0].username, "admin");
    strcpy(account[0].password, "admin");

    while (intentos < 3)
    {
        contador = 0;
        printf("Nombre de usuario: ");
        gets(userIngresado);
        printf("Contrasena: ");
        while (1)
        {
            letra = getch();
            if (letra == ENTER)
            {
                passIngresada[contador] = '\0';
                break;
            }
            else if (letra == BORRAR)
            {
                if (contador > 0)
                {
                    printf("\b \b");
                    contador--;
                }
            }
            else
            {
                if (contador < LONGITUD)
                {
                    printf("*");
                    passIngresada[contador] = letra;
                    contador++;
                }
            }
        }
        for (j = 0; j < USUARIOS; j++)
        {
            if (strcmp(account[j].username, userIngresado) == 0 && strcmp(account[j].password, passIngresada) == 0)
            {
                printf("\nBienvenido al sistema!");
                break;
            }
            else
            {
                printf("\nNombre de usuario y/o contrasena incorrecta.\n");
                intentos++;
                break;
            }
        }
    }

    return 0;
}