#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy, strcmp,
#include <conio.h>  //getch

// Teclas del código ASCII
#define ENTER 13
#define BORRAR 8

typedef struct
{
    char username[10];
    char password[10];
} LOGIN;

// Asignacion de usuarios
LOGIN asignacionCuenta();

// Funciones principales
int loginUsuario(int intentos, LOGIN cuenta);


int main()
{
    system("cls");
    int ingreso, intentos = 3;
    LOGIN cuenta;

    cuenta = asignacionCuenta();
    ingreso = loginUsuario(intentos, cuenta);

    if (ingreso == 0)
    {
        system("cls");
        printf("Bienvenido!");
    }
    else
    {
        system("cls");
        printf("Has llegado al limite de intentos.\nEl programa finalizara.\n");
    }
    return 0;
}

LOGIN asignacionCuenta() // Asignacion de la cuenta
{
    LOGIN account;
    strcpy(account.username, "admin");
    strcpy(account.password, "1234");
    return account;
}
int loginUsuario(int intentos, LOGIN cuenta)
{
    int contador, ingreso;
    char usuario[10 + 1]; // + 1 por el '\0'
    char password[10 + 1];
    char letra;

    printf("----- Login -----\n");
    printf("Usuario: ");
    gets(usuario);
    printf("Contrasena: ");

    contador = 0;
    while (1)
    {
        letra = getch();
        if (letra == ENTER)
        {
            password[contador] = '\0';
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
            if (contador <= 10)
            {
                printf("*");
                password[contador] = letra;
                contador++;
            }
        }
    }
    printf("\n");
    if (strcmp(usuario, cuenta.username) == 0 && strcmp(password, cuenta.password) == 0)
    {
        return 0;
    }
    else
    {
        intentos--;
        if (intentos == 0)
            return 1;
        else
        {
            system("cls");
            printf("Nombre de usuario y/o contrasena incorrecta.\n");
            printf("Intentos restantes: %d\n", intentos);
            return loginUsuario(intentos, cuenta);
        }
    }
}