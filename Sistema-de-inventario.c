#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>  

// Teclas del código ASCII
#define ENTER 13
#define BORRAR 8

struct teclado
{
    char identificador[5 + 1];
    char marca[10 + 1];
    char modelo[15 + 1];
    char idioma[10 + 1];
};
struct mouse
{
    char identificador[5 + 1];
    char marca[10 + 1];
    char modelo[15 + 1];
};
struct monitor
{
    char identificador[5 + 1];
    char marca[10 + 1];
    char modelo[15 + 1];
    float tamano;
};
struct notebook
{
    char identificador[5 + 1];
    char marca[10 + 1];
    char modelo[15 + 1];
    int ram;
    char procesador[5 + 1];
    float pantalla;
};
struct PC
{
    char identificador[5 + 1];
    char marca[10 + 1];
    char modelo[15 + 1];
    int ram;
    char procesador[5 + 1];
    struct teclado tecladoPC;
    struct mouse mousePC;
    struct monitor monitorPC;
};

typedef struct
{
    char identificador[5 + 1];
    char username[5 + 1];
    char password[4 + 1];
    char nombres[15 + 1];
    char apellidoP[7 + 1];
    char apellidoM[5 + 1];
} LOGIN;

// Asignacion de usuario
LOGIN asignacionCuenta();

// Funciones principales
int loginUsuario(int intentos, LOGIN cuentaSistema);
void imprimirUsuario(LOGIN cuenta);

int main()
{
    system("cls");
    int ingreso, intentos = 3;
    LOGIN cuentaSistema = asignacionCuenta();

    ingreso = loginUsuario(intentos, cuentaSistema);

    if (ingreso == 0)
    {
        system("cls");
        printf("Bienvenido ");
        imprimirUsuario(cuentaSistema);
    }
    else
    {
        system("cls");
        printf("Has llegado al limite de intentos.\nEl programa finalizara.\n");
    }
    return 0;
}
LOGIN asignacionCuenta()
{
    LOGIN cuentaSistema;
    strcpy(cuentaSistema.identificador, "U-001");
    strcpy(cuentaSistema.username, "admin");
    strcpy(cuentaSistema.password, "1234");
    strcpy(cuentaSistema.nombres, "Cristobal Ariel");
    strcpy(cuentaSistema.apellidoP, "Alarcon");
    strcpy(cuentaSistema.apellidoM, "Perez");
    return cuentaSistema;
}
int loginUsuario(int intentos, LOGIN cuentaSistema)
{
    int contador = 0;
    char usernameIngresado[10 + 1];
    char passwordIngresada[10 + 1];
    char letra;

    printf("----- Login -----\n");
    printf("Usuario: ");
    gets(usernameIngresado);
    printf("Contrasena: ");

    while (1)
    {
        letra = getch();
        if (letra == ENTER)
        {
            passwordIngresada[contador] = '\0';
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
                passwordIngresada[contador] = letra;
                contador++;
            }
        }
    }
    printf("\n");
    if (strcmp(usernameIngresado, cuentaSistema.username) == 0 && strcmp(passwordIngresada, cuentaSistema.password) == 0)
        return 0;
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
            return loginUsuario(intentos, cuentaSistema);
        }
    }
}
void imprimirUsuario(LOGIN cuentaSistema)
{
    printf("%s %s %s\n----------------------------------------", cuentaSistema.nombres, cuentaSistema.apellidoP, cuentaSistema.apellidoM);
}
