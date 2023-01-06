// Created by Cristóbal Alarcón Pérez   Rut: 21.185.417-0   Fecha de término: 06/01/2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// Teclas del código ASCII
#define ENTER 13
#define BORRAR 8

struct teclado
{
    int identificador;
    char marca[10 + 1];
    char modelo[15 + 1];
    char idioma[10 + 1];
    int stock;
};
struct mouse
{
    int identificador;
    char marca[10 + 1];
    char modelo[15 + 1];
    int stock;
};
struct monitor
{
    int identificador;
    char marca[10 + 1];
    char modelo[15 + 1];
    float tamano;
    int stock;
};
struct notebook
{
    int identificador;
    char marca[10 + 1];
    char modelo[15 + 1];
    int ram;
    char procesador[5 + 1];
    float pantalla;
    int stock;
};
struct PC
{
    int identificador;
    char marca[10 + 1];
    char modelo[15 + 1];
    int ram;
    char procesador[5 + 1];
    struct teclado tecladoPC;
    struct mouse mousePC;
    struct monitor monitorPC;
    int stock;
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
// void volverMenu();

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

// Funciones listar producto
void listarTeclado();
void listarMouse();
void listarMonitor();
void listarNotebook();
void listarPC();

// Funciones actualizar producto
void actualizarTeclado();
void actualizarMouse();
void actualizarMonitor();
void actualizarNotebook();
void actualizarPC();

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
struct LOGIN cuentaSistema; // Variable global para evitar ser entregada como parametro en multiples funciones.

int main()
{
    srand(time(NULL));
    system("cls");
    int ingreso, intentos = 3;
    cuentaSistema = asignacionCuenta();

    ingreso = loginUsuario(intentos);

    if (ingreso == 0)
    {
        system("cls");
        printf("Bienvenido ");
        while (1)
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
        imprimirUsuario();
        printf("\n--------- Menu ---------"
               "\n1. Agregar producto"
               "\n2. Listar producto"
               "\n3. Actualizar producto"
               "\n4. Eliminar producto"
               "\n5. Finalizar programa"
               "\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 5)
        {
            system("cls");
            printf("\nLa opcion ingresada no es correcta.");
        }
    } while (opcion < 1 || opcion > 5);

    switch (opcion)
    {
    case 1:
        agregarProducto();
        break;
    case 2:
        listarProducto();
        break;
    case 3:
        actualizarProducto();
        break;
    case 4:
        eliminarProducto();
        break;
    case 5:
        printf("------- Fin del programa -------\n");
        exit(0);
    }
}
/*
void volverMenu()
{
    int opcion;
    do
    {
        printf("\n"
               "1. Si\n"
               "2. No\n"
               "Volver al menu: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 2)
        {
            system("cls");
            printf("La opcion ingresada no es correcta.");
            imprimirUsuario();
        }
    } while (opcion < 1 || opcion > 2);
    if (opcion == 1)
    {
        system("cls");
        return menu();
    }
    printf("------- Fin del programa -------\n");
}
*/
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
        system("cls");
        imprimirUsuario();
        agregarTeclado();
        // volverMenu();
        break;
    case 2:
        system("cls");
        imprimirUsuario();
        agregarMouse();
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
        system("cls");
        imprimirUsuario();
        listarTeclado();
        printf("Presione una tecla para volver al menu principal...");
        getch();
        system("cls");
        // volverMenu();
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
        system("cls");
        imprimirUsuario();
        actualizarTeclado();
        // volverMenu();
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
        system("cls");
        imprimirUsuario();
        eliminarTeclado();
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
        menu();
        break;
    }
}

// Funciones agregar producto
void agregarTeclado() // ID (Random), marca[10+1], modelo[15+1], idioma[10], stock.
{
    srand(time(NULL)); // Inicializo el generador de numeros aleatorios.
    FILE *teclados;    // Declaro el puntero al archivo.
    struct teclado tecladoIngresado;
    int ID, encontrado, opcion, Stock;
    char Marca[10 + 1], Modelo[15 + 1], Idioma[10 + 1];

    teclados = fopen("teclados.txt", "r+"); // 'r+' abre el archivo para lectura y escritura.
    // Importante: Si el archivo no existe, devuelve NULL en vez de crearlo, puede ser utilizado "a+" para crearlo pero esto impide poder manejarse
    // con las ubicaciones de los productos y solo escribiría al final del archivo, por lo que debe ser creado el archivo de texto manualmente en caso de ser eliminado.
    if (teclados == NULL)
        printf("El archivo de texto no ha sido creado.\n");
    else
    {
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000; // Genero un numero aleatorio entre 100000 y 999999 para que se vea más prolijo al mostrarlo.
            fseek(teclados, 0, SEEK_SET);  // Mueve el puntero al inicio del archivo.
            while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados)) // Mientras no llegue al final del archivo, lee cada registro de producto.
            {
                if (tecladoIngresado.identificador == ID)
                    encontrado = 1;
            }
        } while (encontrado != 0);

        printf("\n----- Agregar teclado -----\n");
        printf("Ingrese marca del teclado: ");
        scanf("%s", Marca);
        fflush(stdin);
        printf("Ingrese modelo del teclado: ");
        scanf("%s", Modelo);
        fflush(stdin);
        printf("Ingrese idioma del teclado: ");
        scanf("%s", Idioma);
        fflush(stdin);
        printf("Ingrese unidades del producto: ");
        scanf("%d", &Stock);
        fflush(stdin);

        encontrado = 0;
        fseek(teclados, 0, SEEK_SET);
        // Lectura del archivo para verificar si el producto ya existe.
        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
            // Si el producto ya existe, se actualiza el stock.
            if (strcasecmp(Marca, tecladoIngresado.marca) == 0 && // strcasecmp compara dos cadenas sin importar mayúsculas ni minúsculas.
                strcasecmp(Modelo, tecladoIngresado.modelo) == 0 &&
                strcasecmp(Idioma, tecladoIngresado.idioma) == 0)
            {
                fseek(teclados, -sizeof(struct teclado), SEEK_CUR);
                strcpy(tecladoIngresado.marca, Marca);
                strcpy(tecladoIngresado.modelo, Modelo);
                strcpy(tecladoIngresado.idioma, Idioma);
                tecladoIngresado.stock += Stock;
                fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
                encontrado = 1;
                break;
            }
            // Si hay un espacio con ID "0" (significa que fue borrado recientemente), se reemplaza por el producto ingresado.
            // El programa como tal no imprime los productos con ID "0", pero esa posicion se conserva como vacia y se rellena al momento de agregar un producto
            // para ahorrar memoria y que no se que queden con espacios o "basura" en el archivo.
            if (tecladoIngresado.identificador == 0)
            {
                fseek(teclados, -sizeof(struct teclado), SEEK_CUR);
                tecladoIngresado.identificador = ID;
                strcpy(tecladoIngresado.marca, Marca);
                strcpy(tecladoIngresado.modelo, Modelo);
                strcpy(tecladoIngresado.idioma, Idioma);
                tecladoIngresado.stock = Stock;
                fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
                encontrado = 1;
                break;
            }
        }
        // Si el producto no existe, se agrega al final del archivo.
        if (encontrado == 0)
        {
            fseek(teclados, 0, SEEK_END);
            tecladoIngresado.identificador = ID;
            strcpy(tecladoIngresado.marca, Marca);
            strcpy(tecladoIngresado.modelo, Modelo);
            strcpy(tecladoIngresado.idioma, Idioma);
            tecladoIngresado.stock = Stock;
            fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
        }
        fclose(teclados);

        system("cls");
        imprimirUsuario();
        printf("\n--- Teclado registrado exitosamente ---\n");
        do
        {
            printf("Agregar otro teclado\n"
                   "1. Si\n"
                   "2. No\n"
                   "Seleccione una opcion: ");
            scanf("%d", &opcion);
            if (opcion < 1 || opcion > 2)
            {
                system("cls");
                imprimirUsuario();
                printf("\nLa opcion seleccionada no es correcta.\n");
            }
        } while (opcion < 1 || opcion > 2);
        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarTeclado();
        }
        else
            system("cls");
    }
}

// Funciones listar producto
void listarTeclado()
{
    FILE *teclados;
    struct teclado tecladoIngresado;

    teclados = fopen("teclados.txt", "r");
    if (teclados == NULL)
        printf("\nSin existencias.\n");
    else
    {
        printf("\n ----------------------------- Teclados --------------------------\n"
               "| - ID - | - Marca -  |    - Modelo -   | - Idioma - | - Stock -  |\n");
        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
            if (tecladoIngresado.identificador != 0)
                printf("| %-6d | %-10s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
        }
        printf(" -----------------------------------------------------------------\n");
    }
    fclose(teclados);
}
// Funciones actualizar producto
void actualizarTeclado()
{
    FILE *teclados;
    struct teclado tecladoIngresado;
    int ID, encontrado = 0;

    if (teclados == NULL)
        printf("\nSin existencias.");
    else
    {
        listarTeclado();
        printf("Seleccione el ID del teclado que desea actualizar: ");
        scanf("%d", &ID);
        fflush(stdin);

        teclados = fopen("teclados.txt", "r+");
        fseek(teclados, 0, SEEK_SET);

        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
            if (ID == tecladoIngresado.identificador)
            {
                fseek(teclados, -sizeof(struct teclado), SEEK_CUR);
                system("cls");
                imprimirUsuario();
                printf("\n ----------------------- Teclado seleccionado --------------------\n"
                       "| - ID - | - Marca -  |    - Modelo -   | - Idioma - | - Stock -  |\n");
                printf("| %-6d | %-10s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
                printf(" -----------------------------------------------------------------\n");
                printf("Ingrese marca del teclado: ");
                scanf("%s", tecladoIngresado.marca);
                fflush(stdin);
                printf("Ingrese modelo del teclado: ");
                scanf("%s", tecladoIngresado.modelo);
                fflush(stdin);
                printf("Ingrese idioma del teclado: ");
                scanf("%s", tecladoIngresado.idioma);
                fflush(stdin);
                printf("Ingrese unidades del producto: ");
                scanf("%d", &tecladoIngresado.stock);
                fflush(stdin);
                fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
                encontrado++;
                break;
            }
        }
        if (encontrado == 0)
            printf("El ID ingresado no existe.");
        fclose(teclados);
    }
}
// Funciones eliminar producto
void eliminarTeclado()
{
    FILE *teclados;
    struct teclado tecladoIngresado;
    int ID, opcion, encontrado = 0;

    if (teclados == NULL)
        printf("\nSin existencias.\n");
    else
    {
        listarTeclado();
        printf("Seleccione el ID del teclado que desea eliminar: ");
        scanf("%d", &ID);
        fflush(stdin);

        teclados = fopen("teclados.txt", "r+");
        fseek(teclados, 0, SEEK_SET);

        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
            if (ID == tecladoIngresado.identificador)
            {
                fseek(teclados, -sizeof(struct teclado), SEEK_CUR);
                system("cls");
                do
                {
                    imprimirUsuario();
                    printf("\n ----------------------- Teclado seleccionado --------------------\n"
                           "| - ID - | - Marca -  |    - Modelo -   | - Idioma - | - Stock -  |\n");
                    printf("| %-6d | %-10s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
                    printf(" -----------------------------------------------------------------\n");
                    printf("Esta seguro que desea eliminar el teclado seleccionado?\n"
                           "1. Si\n"
                           "2. No\n"
                           "Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                    {
                        system("cls");
                        printf("Opcion incorrecta. Intente nuevamente.\n");
                    }
                } while (opcion < 1 || opcion > 2);
                if (opcion == 1)
                {
                    tecladoIngresado.identificador = 0;
                    strcpy(tecladoIngresado.marca, "");
                    strcpy(tecladoIngresado.modelo, "");
                    strcpy(tecladoIngresado.idioma, "");
                    tecladoIngresado.stock = 0;
                    fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
                    encontrado = 1;
                    break;
                }
                else
                {
                    encontrado = 2;
                    break;
                }
            }
        }
        switch (encontrado)
        {
        case 0:
            printf("\nEl ID ingresado no existe.\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\nEl teclado ha sido eliminado con exito.\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:
            printf("\nLa operacion fue cancelada.\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(teclados);
    }
}