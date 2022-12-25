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
struct LOGIN
{
    char identificador[5 + 1];
    char username[5 + 1];
    char password[4 + 1];
    char nombres[15 + 1];
    char apellidoP[7 + 1];
    char apellidoM[5 + 1];
};
// Asignacion de usuario
struct LOGIN asignacionCuenta();

// Funciones principales
int loginUsuario(int intentos);
void imprimirUsuario();
void menu();

// Funciones menu
void agregarProducto();
void actualizarProducto();
void listarProducto();
void eliminarProducto();

// Funciones agregar producto
void agregarTeclado();
void agregarMouse();
void agregarMonitor();
void agregarNotebook();
void agregarPC();

// Funciones actualizar producto
void actualizarTeclado();
void actualizarMouse();
void actualizarMonitor();
void actualizarNotebook();
void actualizarPC();

// Funciones listar producto
void listarTeclado();
void listarMouse();
void listarMonitor();
void listarNotebook();
void listarPC();

// Funciones eliminar producto
void eliminarTeclado();
void eliminarMouse();
void eliminarMonitor();
void eliminarNotebook();
void eliminarPC();

// Funciones de busqueda
int buscarTeclado(char identificador[5 + 1]);
int buscarMouse(char identificador[5 + 1]);
int buscarMonitor(char identificador[5 + 1]);
int buscarNotebook(char identificador[5 + 1]);
int buscarPC(char identificador[5 + 1]);

// Variables globales
struct LOGIN cuentaSistema; // Variable global para evitar ser entregada como parametro en multiples funciones

int main()
{
    system("cls");
    int ingreso, intentos = 3, opcion;
    cuentaSistema = asignacionCuenta();

    ingreso = loginUsuario(intentos);

    if (ingreso == 0)
    {
        system("cls");
        printf("Bienvenido ");
        imprimirUsuario();
        menu();
    }
    else
    {
        system("cls");
        printf("Has llegado al limite de intentos.\nEl programa finalizara.\n");
    }
    return 0;
}
// Funciones importantes
struct LOGIN asignacionCuenta()
{
    struct LOGIN cuentaSistema;
    strcpy(cuentaSistema.identificador, "U-001");
    strcpy(cuentaSistema.username, "admin");
    strcpy(cuentaSistema.password, "1234");
    strcpy(cuentaSistema.nombres, "Cristobal Ariel");
    strcpy(cuentaSistema.apellidoP, "Alarcon");
    strcpy(cuentaSistema.apellidoM, "Perez");
    return cuentaSistema;
}
int loginUsuario(int intentos)
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
            return loginUsuario(intentos);
        }
    }
}
void imprimirUsuario()
{
    printf("%s %s %s", cuentaSistema.nombres, cuentaSistema.apellidoP, cuentaSistema.apellidoM);
}
void menu()
{
    int opcion;
    do
    {
        printf("\n--------- Menu ---------"
               "\n1. Agregar producto"
               "\n2. Actualizar producto"
               "\n3. Listar producto"
               "\n4. Eliminar producto"
               "\n5. Finalizar programa"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 5)
        {
            system("cls");
            imprimirUsuario();
            printf("\nLa opcion ingresada no es correcta.");
        }
    } while (opcion < 1 || opcion > 5);

    switch (opcion)
    {
    case 1:
        agregarProducto();
        break;
    case 2:
        actualizarProducto();
        break;
    case 3:
        listarProducto();
        break;
    case 4:
        eliminarProducto();
        break;
    case 5:
        system("cls");
        printf("------- Fin del programa -------\n");
        return 0;
    }
}

// Funciones principales
void agregarProducto()
{
    system("cls");
    int opcion;
    do
    {
        imprimirUsuario();
        printf("\n----- Agregar producto -----"
               "\n1. Teclado"
               "\n2. Mouse"
               "\n3. Monitor"
               "\n4. Notebook"
               "\n5. PC"
               "\n6. Volver al menu principal"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 6)
        {
            system("cls");
            printf("La opcion ingresada no es correcta.\n");
        }
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        // agregarTeclado();
        break;
    case 2:
        // agregarMouse();
        break;
    case 3:
        // agregarMonitor();
        break;
    case 4:
        // agregarNotebook();
        break;
    case 5:
        // agregarPC();
        break;
    case 6:
        system("cls");
        imprimirUsuario();
        menu();
        break;
    }
}
void actualizarProducto()
{
    system("cls");
    int opcion;
    do
    {
        imprimirUsuario();
        printf("\n----- Actualizar producto -----"
               "\n1. Teclado"
               "\n2. Mouse"
               "\n3. Monitor"
               "\n4. Notebook"
               "\n5. PC"
               "\n6. Volver al menu principal"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 6)
        {
            system("cls");
            printf("La opcion ingresada no es correcta.\n");
        }
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        // actualizarTeclado();
        break;
    case 2:
        // actualizarMouse();
        break;
    case 3:
        // actualizarMonitor();
        break;
    case 4:
        // actualizarNotebook();
        break;
    case 5:
        // actualizarPC();
        break;
    case 6:
        system("cls");
        imprimirUsuario();
        menu();
        break;
    }
}
void listarProducto()
{
    system("cls");
    int opcion;
    do
    {
        imprimirUsuario();
        printf("\n----- Listar producto -----"
               "\n1. Teclado"
               "\n2. Mouse"
               "\n3. Monitor"
               "\n4. Notebook"
               "\n5. PC"
               "\n6. Volver al menu principal"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 6)
        {
            system("cls");
            printf("La opcion ingresada no es correcta.\n");
        }
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        // listarTeclado();
        break;
    case 2:
        // listarMouse();
        break;
    case 3:
        // listarMonitor();
        break;
    case 4:
        // listarNotebook();
        break;
    case 5:
        // listarPC();
        break;
    case 6:
        system("cls");
        imprimirUsuario();
        menu();
        break;
    }
}
void eliminarProducto()
{
    system("cls");
    int opcion;
    do
    {
        imprimirUsuario();
        printf("\n----- Eliminar producto -----"
               "\n1. Teclado"
               "\n2. Mouse"
               "\n3. Monitor"
               "\n4. Notebook"
               "\n5. PC"
               "\n6. Volver al menu principal"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 6)
        {
            system("cls");
            printf("La opcion ingresada no es correcta.\n");
        }
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        // eliminarTeclado();
        break;
    case 2:
        // eliminarMouse();
        break;
    case 3:
        // eliminarMonitor();
        break;
    case 4:
        // eliminarNotebook();
        break;
    case 5:
        // eliminarPC();
        break;
    case 6:
        system("cls");
        imprimirUsuario();
        menu();
        break;
    }
}

// Funciones agregar producto
