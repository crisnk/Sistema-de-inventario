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
    char marca[15 + 1];
    char modelo[15 + 1];
    char idioma[10 + 1];
    int stock;
};
struct mouse
{
    int identificador;
    char marca[15 + 1];
    char modelo[15 + 1];
    int stock;
};
struct monitor
{
    int identificador;
    char marca[15 + 1];
    char modelo[15 + 1];
    char tamano[4 + 1];
    int stock;
};
struct notebook
{
    int identificador;
    char marca[15 + 1];
    char modelo[15 + 1];
    char procesador[15 + 1];
    char ram[15 + 1];
    char pantalla[4 + 1];
    int stock;
};
struct PC
{
    int identificador;
    char marca[15 + 1];
    char modelo[15 + 1];
    char procesador[15 + 1];
    char ram[15 + 1];
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
void mensajeError();
void menu();

// Funciones menu
void agregarProducto();
void actualizarProducto();
void listarProducto();
void eliminarProducto();
void busqueda();

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
void listarSoloPC();

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
        printf("\t   Bienvenido\n");
        while (1)
            menu();
    }
    else
    {
        system("cls");
        printf("*---------------------------------------------*\n"
               "|                    ERROR                    |\n"
               "|---------------------------------------------|\n"
               "| Has llegado al maximo de intentos posibles, |\n"
               "|            el programa finalizara           |\n"
               "*---------------------------------------------*\n");
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

    printf("*---------------------------------------------*\n"
           "|                                             |\n"
           "|            Sistema de Inventario            |\n"
           "|                                             |\n"
           "*---------------------------------------------*\n"
           "|          Ingrese nombre de usuario          |\n"
           "*---------------------------------------------*\n"
           " Usuario: ");
    gets(usernameIngresado);
    fflush(stdin);
    printf("*---------------------------------------------*\n"
           "|              Ingrese contrasena             |\n"
           "*---------------------------------------------*\n"
           " Contrasena: ");
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
            printf("*---------------------------------------------*\n"
                   "|                    ERROR                    |\n"
                   "|---------------------------------------------|\n"
                   "| Nombre de usuario y/o contrasena incorrecta |\n"
                   "*---------------------------------------------*\n"
                   "|            Intentos restantes: %d            |\n"
                   "*---------------------------------------------*\n",
                   intentos);
            printf(" Presione cualquier tecla para reintentar...");
            getch();
            fflush(stdin);
            system("cls");
            return loginUsuario(intentos);
        }
    }
}
void imprimirUsuario()
{
    printf("*-------------------------------*\n"
           "| %s %s %s |\n"
           "*-------------------------------*",
           cuentaSistema.nombres, cuentaSistema.apellidoP, cuentaSistema.apellidoM);
}
void mensajeError()
{
    system("cls");
    imprimirUsuario();
    printf("\n"
           "*--------------------------------------*\n"
           "|                 ERROR                |\n"
           "*--------------------------------------*\n"
           "|   La opcion ingresada no es valida   |\n"
           "*--------------------------------------*\n");
    printf("Presione cualquier tecla para continuar...");
    getch();
    fflush(stdin);
    system("cls");
}
void menu()
{
    int opcion;
    do
    {
        imprimirUsuario();
        printf("\n"
               "*--------------------------------------*\n"
               "|                  MENU                |\n"
               "|--------------------------------------|\n"
               "| 1. Agregar producto                  |\n"
               "|--------------------------------------|\n"
               "| 2. Listar producto                   |\n"
               "|--------------------------------------|\n"
               "| 3. Actualizar producto               |\n"
               "|--------------------------------------|\n"
               "| 4. Eliminar producto                 |\n"
               "|--------------------------------------|\n"
               "| 5. Busqueda por marca                |\n"
               "|--------------------------------------|\n"
               "| 6. Finalizar programa                |\n"
               "*--------------------------------------*\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion < 1 || opcion > 6)
            mensajeError();
    } while (opcion < 1 || opcion > 6);

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
        system("cls");
        imprimirUsuario();
        busqueda();
        system("cls");
        break;
    case 6:
        system("cls");
        printf("*--------------------------------------*\n"
               "|             HASTA PRONTO             |\n"
               "*--------------------------------------*\n");
        exit(0);
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
        printf("\n"
               "*--------------------------------------*\n"
               "|            AGREGAR PRODUCTO          |\n"
               "|--------------------------------------|\n"
               "| 1. Teclado                           |\n"
               "|--------------------------------------|\n"
               "| 2. Mouse                             |\n"
               "|--------------------------------------|\n"
               "| 3. Monitor                           |\n"
               "|--------------------------------------|\n"
               "| 4. Notebook                          |\n"
               "|--------------------------------------|\n"
               "| 5. PC                                |\n"
               "|--------------------------------------|\n"
               "| 6. Regresar al menu                  |\n"
               "*--------------------------------------*\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion < 1 || opcion > 6)
            mensajeError();
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        system("cls");
        imprimirUsuario();
        agregarTeclado();
        system("cls");
        break;
    case 2:
        system("cls");
        imprimirUsuario();
        agregarMouse();
        system("cls");
        break;
    case 3:
        system("cls");
        imprimirUsuario();
        agregarMonitor();
        system("cls");
        break;
    case 4:
        system("cls");
        imprimirUsuario();
        agregarNotebook();
        system("cls");
        break;
    case 5:
        system("cls");
        imprimirUsuario();
        agregarPC();
        system("cls");
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
        printf("\n"
               "*--------------------------------------*\n"
               "|            LISTAR PRODUCTO           |\n"
               "|--------------------------------------|\n"
               "| 1. Teclado                           |\n"
               "|--------------------------------------|\n"
               "| 2. Mouse                             |\n"
               "|--------------------------------------|\n"
               "| 3. Monitor                           |\n"
               "|--------------------------------------|\n"
               "| 4. Notebook                          |\n"
               "|--------------------------------------|\n"
               "| 5. PC                                |\n"
               "|--------------------------------------|\n"
               "| 6. Regresar al menu                  |\n"
               "*--------------------------------------*\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion < 1 || opcion > 6)
            mensajeError();
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        system("cls");
        imprimirUsuario();
        listarTeclado();
        printf("Presione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;
    case 2:
        system("cls");
        imprimirUsuario();
        listarMouse();
        printf("Presione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;
    case 3:
        system("cls");
        imprimirUsuario();
        listarMonitor();
        printf("Presione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;
    case 4:
        system("cls");
        imprimirUsuario();
        listarNotebook();
        printf("Presione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;
    case 5:
        system("cls");
        listarPC();
        system("cls");
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
        printf("\n"
               "*--------------------------------------*\n"
               "|          ACTUALIZAR PRODUCTO         |\n"
               "|--------------------------------------|\n"
               "| 1. Teclado                           |\n"
               "|--------------------------------------|\n"
               "| 2. Mouse                             |\n"
               "|--------------------------------------|\n"
               "| 3. Monitor                           |\n"
               "|--------------------------------------|\n"
               "| 4. Notebook                          |\n"
               "|--------------------------------------|\n"
               "| 5. PC                                |\n"
               "|--------------------------------------|\n"
               "| 6. Regresar al menu                  |\n"
               "*--------------------------------------*\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion < 1 || opcion > 6)
            mensajeError();
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        system("cls");
        imprimirUsuario();
        actualizarTeclado();
        system("cls");
        break;
    case 2:
        system("cls");
        imprimirUsuario();
        actualizarMouse();
        system("cls");
        break;
    case 3:
        system("cls");
        imprimirUsuario();
        actualizarMonitor();
        system("cls");
        break;
    case 4:
        system("cls");
        imprimirUsuario();
        actualizarNotebook();
        system("cls");
        break;
    case 5:
        system("cls");
        imprimirUsuario();
        actualizarPC();
        system("cls");
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
        printf("\n"
               "*--------------------------------------*\n"
               "|          ELIMINAR PRODUCTO           |\n"
               "|--------------------------------------|\n"
               "| 1. Teclado                           |\n"
               "|--------------------------------------|\n"
               "| 2. Mouse                             |\n"
               "|--------------------------------------|\n"
               "| 3. Monitor                           |\n"
               "|--------------------------------------|\n"
               "| 4. Notebook                          |\n"
               "|--------------------------------------|\n"
               "| 5. PC                                |\n"
               "|--------------------------------------|\n"
               "| 6. Regresar al menu                  |\n"
               "*--------------------------------------*\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion < 1 || opcion > 6)
            mensajeError();
    } while (opcion < 1 || opcion > 6);

    switch (opcion)
    {
    case 1:
        system("cls");
        imprimirUsuario();
        eliminarTeclado();
        break;
    case 2:
        system("cls");
        imprimirUsuario();
        eliminarMouse();
        break;
    case 3:
        system("cls");
        imprimirUsuario();
        eliminarMonitor();
        break;
    case 4:
        system("cls");
        imprimirUsuario();
        eliminarNotebook();
        break;
    case 5:
        system("cls");
        imprimirUsuario();
        eliminarPC();
        break;
    case 6:
        system("cls");
        menu();
        break;
    }
}
void busqueda()
{
    FILE *teclados, *mouses, *monitores, *notebooks, *pcs;
    struct teclado tecladoBuscado;
    struct mouse mouseBuscado;
    struct monitor monitorBuscado;
    struct notebook notebookBuscado;
    struct PC pcBuscado;
    char marcaBuscada[16];
    teclados = fopen("teclados.txt", "r");
    mouses = fopen("mouses.txt", "r");
    monitores = fopen("monitores.txt", "r");
    notebooks = fopen("notebooks.txt", "r");
    pcs = fopen("pcs.txt", "r");

    printf("\n"
           "*-------------------------------*\n"
           "|      BUSQUEDA DE PRODUCTO     |\n"
           "*-------------------------------*\n");
    printf(" Ingrese la marca: ");
    gets(marcaBuscada);
    fflush(stdin);
    system("cls");
    imprimirUsuario();
    printf("\n"
           "*--------------------------------------------------------------------*\n"
           "|                   Resultados de la busqueda: %-15s       |\n"
           "*--------------------------------------------------------------------*\n"
           "|   Tipo   |   ID   |      Marca      |      Modelo     |   Stock    |\n"
           "*--------------------------------------------------------------------*\n",
           marcaBuscada);

    while (fread(&tecladoBuscado, sizeof(struct teclado), 1, teclados))
    {
        if (strcasecmp(tecladoBuscado.marca, marcaBuscada) == 0)
            printf("| Teclado  | %-6d | %-15s | %-15s | %-10d |\n", tecladoBuscado.identificador, tecladoBuscado.marca, tecladoBuscado.modelo, tecladoBuscado.stock);
    }
    while (fread(&mouseBuscado, sizeof(struct mouse), 1, mouses))
    {
        if (strcasecmp(mouseBuscado.marca, marcaBuscada) == 0)
            printf("| Mouse    | %-6d | %-15s | %-15s | %-10d |\n", mouseBuscado.identificador, mouseBuscado.marca, mouseBuscado.modelo, mouseBuscado.stock);
    }
    while (fread(&monitorBuscado, sizeof(struct monitor), 1, monitores))
    {
        if (strcasecmp(monitorBuscado.marca, marcaBuscada) == 0)
            printf("| Monitor  | %-6d | %-15s | %-15s | %-10d |\n", monitorBuscado.identificador, monitorBuscado.marca, monitorBuscado.modelo, monitorBuscado.stock);
    }
    while (fread(&notebookBuscado, sizeof(struct notebook), 1, notebooks))
    {
        if (strcasecmp(notebookBuscado.marca, marcaBuscada) == 0)
            printf("| Notebook | %-6d | %-15s | %-15s | %-10d |\n", notebookBuscado.identificador, notebookBuscado.marca, notebookBuscado.modelo, notebookBuscado.stock);
    }
    while (fread(&pcBuscado, sizeof(struct PC), 1, pcs))

        if (strcasecmp(pcBuscado.marca, marcaBuscada) == 0)
            printf("| PC       | %-6d | %-15s | %-15s | %-10d |\n", pcBuscado.identificador, pcBuscado.marca, pcBuscado.modelo, pcBuscado.stock);

    printf("*--------------------------------------------------------------------*\n");
    fclose(teclados);
    fclose(mouses);
    fclose(monitores);
    fclose(notebooks);
    fclose(pcs);

    printf("Presione cualquier tecla para volver al menu principal...");
    getch();
}
// Funciones agregar producto
void agregarTeclado() // ID (Random), marca[16], modelo[16], idioma[10], stock.
{
    FILE *teclados; // Declaro el puntero al archivo.
    struct teclado tecladoIngresado;
    int ID, encontrado, opcion, Stock;
    char Marca[15 + 1], Modelo[15 + 1], Idioma[10 + 1];

    teclados = fopen("teclados.txt", "r+"); // 'r+' abre el archivo para lectura y escritura.
    // Importante: Si el archivo no existe, devuelve NULL en vez de crearlo, puede ser utilizado "a+" para crearlo pero esto impide poder manejarse
    // con las ubicaciones de los productos y solo escribiría al final del archivo, por lo que debe ser creado el archivo de texto manualmente en caso de ser eliminado.
    if (teclados == NULL)
    {
        system("cls");
        printf("El archivo de texto no ha sido creado.\n");
    }
    else
    {
        // Generacion del ID aleatorio con validacion de que no haya otro igual.
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000;                                        // Genero un numero aleatorio entre 100000 y 999999 para que se vea más prolijo al mostrarlo.
            fseek(teclados, 0, SEEK_SET);                                         // Mueve el puntero al inicio del archivo.
            while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados)) // Mientras no llegue al final del archivo, lee cada registro de producto.
                if (ID == tecladoIngresado.identificador)
                {
                    encontrado = 1;
                    break;
                }
        } while (encontrado != 0);

        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|            AGREGAR TECLADO           |\n"
               "|--------------------------------------|\n"
               "|       Ingrese marca del teclado      |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(Marca);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|       Ingrese modelo del teclado     |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(Modelo);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|       Ingrese idioma del teclado     |\n"
               "*--------------------------------------*\n"
               " Idioma: ");
        gets(Idioma);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|       Ingrese stock del teclado      |\n"
               "*--------------------------------------*\n"
               " Stock: ");
        scanf("%d", &Stock);
        fflush(stdin);

        fseek(teclados, 0, SEEK_SET);
        // Lectura del archivo para verificar si el producto ya existe.
        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
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
        printf("\n"
               "*--------------------------------------*\n"
               "|    TECLADO REGISTRADO EXITOSAMENTE   |\n"
               "*--------------------------------------*\n");
        do
        {
            imprimirUsuario();
            printf("\n"
                   "*--------------------------------------*\n"
                   "| 1. Agregar otro teclado              |\n"
                   "| 2. Volver al menu principal          |\n"
                   "*--------------------------------------*\n"
                   "Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
                mensajeError();
        } while (opcion < 1 || opcion > 2);

        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarTeclado();
        }
    }
}
void agregarMouse() // ID (Random), marca[16], modelo[16], stock.
{
    FILE *mouses;
    struct mouse mouseIngresado;
    int ID, encontrado, opcion, Stock;
    char Marca[16], Modelo[16];

    mouses = fopen("mouses.txt", "r+");

    if (mouses == NULL)
    {
        system("cls");
        printf("El archivo de texto no ha sido creado.\n");
    }
    else
    {
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000;
            fseek(mouses, 0, SEEK_SET);
            while (fread(&mouseIngresado, sizeof(struct mouse), 1, mouses))
            {
                if (ID == mouseIngresado.identificador)
                {
                    encontrado = 1;
                    break;
                }
            }
        } while (encontrado != 0);

        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|             AGREGAR MOUSE            |\n"
               "|--------------------------------------|\n"
               "|        Ingrese marca del mouse       |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(Marca);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|        Ingrese modelo del mouse      |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(Modelo);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|        Ingrese stock del mouse       |\n"
               "*--------------------------------------*\n"
               " Stock: ");
        scanf("%d", &Stock);
        fflush(stdin);

        fseek(mouses, 0, SEEK_SET);

        while (fread(&mouseIngresado, sizeof(struct mouse), 1, mouses))
        {
            if (mouseIngresado.identificador == 0)
            {
                fseek(mouses, -sizeof(struct mouse), SEEK_CUR);
                mouseIngresado.identificador = ID;
                strcpy(mouseIngresado.marca, Marca);
                strcpy(mouseIngresado.modelo, Modelo);
                mouseIngresado.stock = Stock;
                fwrite(&mouseIngresado, sizeof(struct mouse), 1, mouses);
                encontrado = 1;
                break;
            }
            if (strcasecmp(Marca, mouseIngresado.marca) == 0 &&
                strcasecmp(Modelo, mouseIngresado.modelo) == 0)
            {
                fseek(mouses, -sizeof(struct mouse), SEEK_CUR);
                strcpy(mouseIngresado.marca, Marca);
                strcpy(mouseIngresado.modelo, Modelo);
                mouseIngresado.stock += Stock;
                fwrite(&mouseIngresado, sizeof(struct mouse), 1, mouses);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 0)
        {
            fseek(mouses, 0, SEEK_END);
            mouseIngresado.identificador = ID;
            strcpy(mouseIngresado.marca, Marca);
            strcpy(mouseIngresado.modelo, Modelo);
            mouseIngresado.stock = Stock;
            fwrite(&mouseIngresado, sizeof(struct mouse), 1, mouses);
        }
        fclose(mouses);

        system("cls");
        printf("\n"
               "*--------------------------------------*\n"
               "|     MOUSE REGISTRADO EXITOSAMENTE    |\n"
               "*--------------------------------------*\n");
        do
        {
            imprimirUsuario();
            printf("\n"
                   "*--------------------------------------*\n"
                   "| 1. Agregar otro mouse                |\n"
                   "| 2. Volver al menu principal          |\n"
                   "*--------------------------------------*\n"
                   "Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
                mensajeError();
        } while (opcion < 1 || opcion > 2);

        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarMouse();
        }
    }
}
void agregarMonitor() // ID (Random), marca[16], modelo[16], tamaño[5], stock.
{
    FILE *monitores;
    struct monitor monitorIngresado;
    int ID, encontrado, opcion, Stock;
    char Marca[16], Modelo[16], Tamano[5];

    monitores = fopen("monitores.txt", "r+");

    if (monitores == NULL)
    {
        system("cls");
        printf("El archivo de texto no ha sido creado.\n");
    }
    else
    {
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000;
            fseek(monitores, 0, SEEK_SET);
            while (fread(&monitorIngresado, sizeof(struct monitor), 1, monitores))
            {
                if (ID == monitorIngresado.identificador)
                {
                    encontrado = 1;
                    break;
                }
            }
        } while (encontrado != 0);

        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|            AGREGAR MONITOR           |\n"
               "|--------------------------------------|\n"
               "|        Ingrese marca del monitor     |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(Marca);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|        Ingrese modelo del monitor    |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(Modelo);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|        Ingrese tamaño del monitor    |\n"
               "*--------------------------------------*\n"
               " Tamaño: ");
        gets(Tamano);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|        Ingrese stock del monitor     |\n"
               "*--------------------------------------*\n"
               " Stock: ");
        scanf("%d", &Stock);
        fflush(stdin);

        fseek(monitores, 0, SEEK_SET);

        while (fread(&monitorIngresado, sizeof(struct monitor), 1, monitores))
        {
            if (monitorIngresado.identificador == 0)
            {
                fseek(monitores, -sizeof(struct monitor), SEEK_CUR);
                monitorIngresado.identificador = ID;
                strcpy(monitorIngresado.marca, Marca);
                strcpy(monitorIngresado.modelo, Modelo);
                strcpy(monitorIngresado.tamano, Tamano);
                monitorIngresado.stock = Stock;
                fwrite(&monitorIngresado, sizeof(struct monitor), 1, monitores);
                encontrado = 1;
                break;
            }
            if (strcasecmp(Marca, monitorIngresado.marca) == 0 &&
                strcasecmp(Modelo, monitorIngresado.modelo) == 0 &&
                strcasecmp(Tamano, monitorIngresado.tamano) == 0)
            {
                fseek(monitores, -sizeof(struct monitor), SEEK_CUR);
                strcpy(monitorIngresado.marca, Marca);
                strcpy(monitorIngresado.modelo, Modelo);
                strcpy(monitorIngresado.tamano, Tamano);
                monitorIngresado.stock += Stock;
                fwrite(&monitorIngresado, sizeof(struct monitor), 1, monitores);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 0)
        {
            fseek(monitores, 0, SEEK_END);
            monitorIngresado.identificador = ID;
            strcpy(monitorIngresado.marca, Marca);
            strcpy(monitorIngresado.modelo, Modelo);
            strcpy(monitorIngresado.tamano, Tamano);
            monitorIngresado.stock = Stock;
            fwrite(&monitorIngresado, sizeof(struct monitor), 1, monitores);
        }
        fclose(monitores);

        system("cls");
        printf("\n"
               "*--------------------------------------*\n"
               "|    MONITOR REGISTRADO EXITOSAMENTE   |\n"
               "*--------------------------------------*\n");
        do
        {
            imprimirUsuario();
            printf("\n"
                   "*--------------------------------------*\n"
                   "| 1. Agregar otro monitor              |\n"
                   "| 2. Volver al menu principal          |\n"
                   "*--------------------------------------*\n"
                   "Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
                mensajeError();
        } while (opcion < 1 || opcion > 2);
        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarMonitor();
        }
    }
}
void agregarNotebook() // ID (Random), marca[16], modelo[16], procesador[16], RAM[16], pantalla[5], stock.
{
    FILE *notebooks;
    struct notebook notebookIngresado;
    int ID, encontrado, opcion, Stock;
    char Marca[16], Modelo[16], Procesador[16], RAM[16], Pantalla[5];

    notebooks = fopen("notebooks.txt", "r+");

    if (notebooks == NULL)
    {
        system("cls");
        printf("El archivo de texto no ha sido creado.\n");
    }
    else
    {
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000;
            fseek(notebooks, 0, SEEK_SET);
            while (fread(&notebookIngresado, sizeof(struct notebook), 1, notebooks))
            {
                if (ID == notebookIngresado.identificador)
                {
                    encontrado = 1;
                    break;
                }
            }
        } while (encontrado != 0);

        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|           AGREGAR NOTEBOOK           |\n"
               "|--------------------------------------|\n"
               "|      Ingrese marca del notebook      |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(Marca);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|     Ingrese modelo del notebook      |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(Modelo);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|   Ingrese procesador del notebook    |\n"
               "*--------------------------------------*\n"
               " Procesador: ");
        gets(Procesador);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|      Ingrese RAM del notebook        |\n"
               "*--------------------------------------*\n"
               " RAM: ");
        gets(RAM);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|     Ingrese pantalla del notebook    |\n"
               "*--------------------------------------*\n"
               " Pantalla: ");
        gets(Pantalla);
        fflush(stdin);
        printf("*--------------------------------------*\n"
               "|      Ingrese stock del notebook      |\n"
               "*--------------------------------------*\n"
               " Stock: ");
        scanf("%d", &Stock);
        fflush(stdin);

        fseek(notebooks, 0, SEEK_SET);

        while (fread(&notebookIngresado, sizeof(struct notebook), 1, notebooks))
        {
            if (notebookIngresado.identificador == 0)
            {
                fseek(notebooks, -sizeof(struct notebook), SEEK_CUR);
                notebookIngresado.identificador = ID;
                strcpy(notebookIngresado.marca, Marca);
                strcpy(notebookIngresado.modelo, Modelo);
                strcpy(notebookIngresado.procesador, Procesador);
                strcpy(notebookIngresado.ram, RAM);
                strcpy(notebookIngresado.pantalla, Pantalla);
                notebookIngresado.stock = Stock;
                fwrite(&notebookIngresado, sizeof(struct notebook), 1, notebooks);
                encontrado = 1;
                break;
            }
            if (strcasecmp(Marca, notebookIngresado.marca) == 0 &&
                strcasecmp(Modelo, notebookIngresado.modelo) == 0 &&
                strcasecmp(Procesador, notebookIngresado.procesador) == 0 &&
                strcasecmp(RAM, notebookIngresado.ram) == 0 &&
                strcasecmp(Pantalla, notebookIngresado.pantalla) == 0)
            {
                fseek(notebooks, -sizeof(struct notebook), SEEK_CUR);
                strcpy(notebookIngresado.marca, Marca);
                strcpy(notebookIngresado.modelo, Modelo);
                strcpy(notebookIngresado.procesador, Procesador);
                strcpy(notebookIngresado.ram, RAM);
                strcpy(notebookIngresado.pantalla, Pantalla);
                notebookIngresado.stock += Stock;
                fwrite(&notebookIngresado, sizeof(struct notebook), 1, notebooks);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 0)
        {
            fseek(notebooks, 0, SEEK_END);
            notebookIngresado.identificador = ID;
            strcpy(notebookIngresado.marca, Marca);
            strcpy(notebookIngresado.modelo, Modelo);
            strcpy(notebookIngresado.procesador, Procesador);
            strcpy(notebookIngresado.ram, RAM);
            strcpy(notebookIngresado.pantalla, Pantalla);
            notebookIngresado.stock = Stock;
            fwrite(&notebookIngresado, sizeof(struct notebook), 1, notebooks);
        }
        fclose(notebooks);

        system("cls");
        printf("\n"
               "*--------------------------------------*\n"
               "|   NOTEBOOK REGISTRADO EXITOSAMENTE   |\n"
               "*--------------------------------------*\n");
        do
        {
            imprimirUsuario();
            printf("\n"
                   "*--------------------------------------*\n"
                   "| 1. Agregar otro notebook             |\n"
                   "| 2. Volver al menu principal          |\n"
                   "*--------------------------------------*\n"
                   " Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
                mensajeError();
        } while (opcion < 1 || opcion > 2);
        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarNotebook();
        }
    }
}
void agregarPC()
{
    int ID, StockPC, encontrado, opcion, TecladoID, MouseID, MonitorID;
    char Marca[16], Modelo[16], Procesador[16], RAM[16], MarcaTeclado[16], ModeloTeclado[16], IdiomaTeclado[11], MarcaMouse[16], ModeloMouse[16], MarcaMonitor[16], ModeloMonitor[16], TamanoMonitor[5];

    FILE *pcs;
    struct PC pcIngresado;
    pcs = fopen("pcs.txt", "r+");

    if (pcs == NULL)
    {
        system("cls");
        printf("El archivo de texto no ha sido creado.\n");
    }
    else
    {
        do
        {
            encontrado = 0;
            ID = 100000 + rand() % 900000;
            TecladoID = 100000 + rand() % 900000;
            MouseID = 100000 + rand() % 900000;
            MonitorID = 100000 + rand() % 900000;
            fseek(pcs, 0, SEEK_SET);
            while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
            {
                if (ID == pcIngresado.identificador ||
                    TecladoID == pcIngresado.tecladoPC.identificador ||
                    MouseID == pcIngresado.mousePC.identificador ||
                    MonitorID == pcIngresado.monitorPC.identificador)
                {
                    encontrado = 1;
                    break;
                }
            }
        } while (encontrado != 0);

        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|       AGREGAR PC DE ESCRITORIO       |\n"
               "*--------------------------------------*\n"
               "|         Ingrese marca del PC         |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(Marca);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|         Ingrese modelo del PC        |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(Modelo);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|       Ingrese procesador del PC      |\n"
               "*--------------------------------------*\n"
               " Procesador: ");
        gets(Procesador);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|          Ingrese RAM del PC          |\n"
               "*--------------------------------------*\n"
               " RAM: ");
        gets(RAM);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|        Ingrese stock del PC          |\n"
               "*--------------------------------------*\n"
               " Stock: ");
        scanf("%d", &StockPC);
        fflush(stdin);
        system("cls");

        imprimirUsuario();
        printf("\n"
               "*--------------------------------------*\n"
               "|          AGREGAR TECLADO PC          |\n"
               "*--------------------------------------*\n"
               "|       Ingrese marca del teclado      |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(MarcaTeclado);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|       Ingrese modelo del teclado     |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(ModeloTeclado);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|      Ingrese idioma del teclado      |\n"
               "*--------------------------------------*\n"
               " Idioma: ");
        gets(IdiomaTeclado);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|           AGREGAR MOUSE PC           |\n"
               "*--------------------------------------*\n"
               "|        Ingrese marca del mouse       |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(MarcaMouse);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|        Ingrese modelo del mouse      |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(ModeloMouse);
        fflush(stdin);
        system("cls");

        imprimirUsuario();
        printf("\n"
               "*--------------------------------------*\n"
               "|          AGREGAR MONITOR PC          |\n"
               "*--------------------------------------*\n"
               "|       Ingrese marca del monitor      |\n"
               "*--------------------------------------*\n"
               " Marca: ");
        gets(MarcaMonitor);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|       Ingrese modelo del monitor     |\n"
               "*--------------------------------------*\n"
               " Modelo: ");
        gets(ModeloMonitor);
        fflush(stdin);
        printf("\n"
               "*--------------------------------------*\n"
               "|       Ingrese tamano del monitor     |\n"
               "*--------------------------------------*\n"
               " Tamano: ");
        gets(TamanoMonitor);
        fflush(stdin);

        fseek(pcs, 0, SEEK_SET);

        while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
        {
            if (pcIngresado.identificador == 0)
            {
                fseek(pcs, -sizeof(struct PC), SEEK_CUR);

                // Asignaciones del PC
                pcIngresado.identificador = ID;
                strcpy(pcIngresado.marca, Marca);
                strcpy(pcIngresado.modelo, Modelo);
                strcpy(pcIngresado.procesador, Procesador);
                strcpy(pcIngresado.ram, RAM);
                pcIngresado.stock = StockPC;

                // Asignaciones del Teclado
                pcIngresado.tecladoPC.identificador = TecladoID;
                strcpy(pcIngresado.tecladoPC.marca, MarcaTeclado);
                strcpy(pcIngresado.tecladoPC.modelo, ModeloTeclado);
                strcpy(pcIngresado.tecladoPC.idioma, IdiomaTeclado);
                pcIngresado.tecladoPC.stock = 1;

                // Asignaciones del Mouse
                pcIngresado.mousePC.identificador = MouseID;
                strcpy(pcIngresado.mousePC.marca, MarcaMouse);
                strcpy(pcIngresado.mousePC.modelo, ModeloMouse);
                pcIngresado.mousePC.stock = 1;

                // Asignaciones del Monitor
                pcIngresado.monitorPC.identificador = MonitorID;
                strcpy(pcIngresado.monitorPC.marca, MarcaMonitor);
                strcpy(pcIngresado.monitorPC.modelo, ModeloMonitor);
                strcpy(pcIngresado.monitorPC.tamano, TamanoMonitor);
                pcIngresado.monitorPC.stock = 1;

                // Escritura en el archivo
                fwrite(&pcIngresado, sizeof(struct PC), 1, pcs);
                break;
            }
            if (strcasecmp(pcIngresado.marca, Marca) == 0 &&
                strcasecmp(pcIngresado.modelo, Modelo) == 0 &&
                strcasecmp(pcIngresado.procesador, Procesador) == 0 &&
                strcasecmp(pcIngresado.ram, RAM) == 0)
            {
                fseek(pcs, -sizeof(struct PC), SEEK_CUR);
                pcIngresado.stock += StockPC;
                fwrite(&pcIngresado, sizeof(struct PC), 1, pcs);
                break;
            }
        }
        if (encontrado == 0)
        {
            fseek(pcs, 0, SEEK_END);

            // Asignaciones del PC
            pcIngresado.identificador = ID;
            strcpy(pcIngresado.marca, Marca);
            strcpy(pcIngresado.modelo, Modelo);
            strcpy(pcIngresado.procesador, Procesador);
            strcpy(pcIngresado.ram, RAM);
            pcIngresado.stock = StockPC;

            // Asignaciones del Teclado
            pcIngresado.tecladoPC.identificador = TecladoID;
            strcpy(pcIngresado.tecladoPC.marca, MarcaTeclado);
            strcpy(pcIngresado.tecladoPC.modelo, ModeloTeclado);
            strcpy(pcIngresado.tecladoPC.idioma, IdiomaTeclado);
            pcIngresado.tecladoPC.stock = 1;

            // Asignaciones del Mouse
            pcIngresado.mousePC.identificador = MouseID;
            strcpy(pcIngresado.mousePC.marca, MarcaMouse);
            strcpy(pcIngresado.mousePC.modelo, ModeloMouse);
            pcIngresado.mousePC.stock = 1;

            // Asignaciones del Monitor
            pcIngresado.monitorPC.identificador = MonitorID;
            strcpy(pcIngresado.monitorPC.marca, MarcaMonitor);
            strcpy(pcIngresado.monitorPC.modelo, ModeloMonitor);
            strcpy(pcIngresado.monitorPC.tamano, TamanoMonitor);
            pcIngresado.monitorPC.stock = 1;

            // Escritura en el archivo
            fwrite(&pcIngresado, sizeof(struct PC), 1, pcs);
        }
        fclose(pcs);
        system("cls");

        imprimirUsuario();
        printf("\n"
               "*--------------------------------------*\n"
               "|      PC REGISTRADO EXISTOSAMENTE     |\n"
               "*--------------------------------------*\n");
        do
        {
            printf("\n"
                   "*--------------------------------------*\n"
                   "| 1. Registrar otro PC                 |\n"
                   "| 2. Regresar al menu principal        |\n"
                   "*--------------------------------------*\n"
                   " Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
                mensajeError();
        } while (opcion < 1 || opcion > 2);

        if (opcion == 1)
        {
            system("cls");
            imprimirUsuario();
            agregarPC();
        }
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
        printf("\n"
               "*----------------------------------------------------------------------*\n"
               "|                               TECLADOS                               |\n"
               "|----------------------------------------------------------------------|\n"
               "|   ID   |      Marca      |     Modelo      |   Idioma   |   Stock    |\n"
               "*----------------------------------------------------------------------*\n");
        while (fread(&tecladoIngresado, sizeof(struct teclado), 1, teclados))
        {
            if (tecladoIngresado.identificador != 0)
                printf("| %-6d | %-15s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
        }
        printf("*----------------------------------------------------------------------*\n");
    }
    fclose(teclados);
}
void listarMouse()
{
    FILE *mouses;
    struct mouse mouseIngresado;

    mouses = fopen("mouses.txt", "r");
    if (mouses == NULL)
        printf("\nSin existencias.\n");
    else
    {
        printf("\n"
               "*---------------------------------------------------------*\n"
               "|                         MOUSE                           |\n"
               "|---------------------------------------------------------|\n"
               "|   ID   |      Marca      |      Modelo     |   Stock    |\n"
               "*---------------------------------------------------------*\n");
        while (fread(&mouseIngresado, sizeof(struct mouse), 1, mouses))
        {
            if (mouseIngresado.identificador != 0)
                printf("| %-6d | %-15s | %-15s | %-10d |\n", mouseIngresado.identificador, mouseIngresado.marca, mouseIngresado.modelo, mouseIngresado.stock);
        }
        printf("*---------------------------------------------------------*\n");
    }
    fclose(mouses);
}
void listarMonitor()
{
    FILE *monitores;
    struct monitor monitorIngresado;

    monitores = fopen("monitores.txt", "r");
    if (monitores == NULL)
        printf("\nSin existencias.\n");
    else
    {
        printf("\n"
               "*------------------------------------------------------------------------*\n"
               "|                               MONITORES                                |\n"
               "|------------------------------------------------------------------------|\n"
               "|   ID   |      Marca      |      Modelo     |   Pantalla   |   Stock    |\n"
               "*------------------------------------------------------------------------*\n");
        while (fread(&monitorIngresado, sizeof(struct monitor), 1, monitores))
        {
            if (monitorIngresado.identificador != 0)
                printf("| %-6d | %-15s | %-15s | %+11s\" | %-10d |\n", monitorIngresado.identificador, monitorIngresado.marca, monitorIngresado.modelo, monitorIngresado.tamano, monitorIngresado.stock);
        }
        printf("*------------------------------------------------------------------------*\n");
    }
    fclose(monitores);
}
void listarNotebook()
{
    FILE *notebooks;
    struct notebook notebookIngresado;

    notebooks = fopen("notebooks.txt", "r");
    if (notebooks == NULL)
        printf("\nSin existencias.\n");
    else
    {
        printf("\n"
               "*------------------------------------------------------------------------------------------------------------*\n"
               "|                                          NOTEBOOKS                                                         |\n"
               "|------------------------------------------------------------------------------------------------------------|\n"
               "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Pantalla   |   Stock    |\n"
               "*------------------------------------------------------------------------------------------------------------*\n");
        while (fread(&notebookIngresado, sizeof(struct notebook), 1, notebooks))
        {
            if (notebookIngresado.identificador != 0)
                printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %+11s\" | %-10d |\n", notebookIngresado.identificador, notebookIngresado.marca, notebookIngresado.modelo, notebookIngresado.procesador, notebookIngresado.ram, notebookIngresado.pantalla, notebookIngresado.stock);
        }
        printf("*------------------------------------------------------------------------------------------------------------*\n");
    }
    fclose(notebooks);
}
void listarPC()
{
    FILE *pcs;
    struct PC pcIngresado;
    int ID, opcion, encontrado = 0;

    pcs = fopen("pcs.txt", "r");
    if (pcs == NULL)
        printf("\nSin existencias.\n");
    else
    {
        do
        {
            fseek(pcs, 0, SEEK_SET);
            imprimirUsuario();
            printf("\n"
                   "*---------------------------------------------------------------------------------------------*\n"
                   "|                                      PC's DE ESCRITORIO                                     |\n"
                   "|---------------------------------------------------------------------------------------------|\n"
                   "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Stock    |\n"
                   "*---------------------------------------------------------------------------------------------*\n");
            while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
            {
                if (pcIngresado.identificador != 0)
                    printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresado.identificador, pcIngresado.marca, pcIngresado.modelo, pcIngresado.procesador, pcIngresado.ram, pcIngresado.stock);
            }
            printf("*---------------------------------------------------------------------------------------------*\n");
            printf("*--------------------------------------*\n"
                   "| 1. Revisar perifericos del PC        |\n"
                   "| 2. Volver al menu principal          |\n"
                   "*--------------------------------------*\n"
                   "Seleccione una opcion: ");
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion < 1 || opcion > 2)
            {
                mensajeError();
            }
        } while (opcion < 1 || opcion > 2);

        if (opcion == 1)
        {
            do
            {
                fseek(pcs, 0, SEEK_SET);
                system("cls");
                imprimirUsuario();
                printf("\n"
                       "*---------------------------------------------------------------------------------------------*\n"
                       "|                                      PC's DE ESCRITORIO                                     |\n"
                       "|---------------------------------------------------------------------------------------------|\n"
                       "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Stock    |\n"
                       "*---------------------------------------------------------------------------------------------*\n");
                while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
                {
                    if (pcIngresado.identificador != 0)
                        printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresado.identificador, pcIngresado.marca, pcIngresado.modelo, pcIngresado.procesador, pcIngresado.ram, pcIngresado.stock);
                }
                printf("*---------------------------------------------------------------------------------------------*\n");
                printf("Ingrese el ID del PC que desea revisar: ");
                scanf("%d", &ID);
                fflush(stdin);
                fseek(pcs, 0, SEEK_SET);
                while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
                {
                    if (ID == pcIngresado.identificador)
                    {
                        system("cls");
                        imprimirUsuario();
                        printf("\n"
                               "*---------------------------------------------------------------------------------------------*\n"
                               "|                                       PC SELECCIONADO                                       |\n"
                               "|---------------------------------------------------------------------------------------------|\n"
                               "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Stock    |\n"
                               "|---------------------------------------------------------------------------------------------|\n");
                        printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresado.identificador, pcIngresado.marca, pcIngresado.modelo, pcIngresado.procesador, pcIngresado.ram, pcIngresado.stock);
                        printf("*---------------------------------------------------------------------------------------------*\n");

                        printf("\n"
                               "*-------------------------------------------------------*\n"
                               "|                  PERIFERICOS DEL PC                   |\n"
                               "|-------------------------------------------------------|\n"
                               "|   Tipo   |   ID   |      Marca      |      Modelo     |\n"
                               "|-------------------------------------------------------|\n");
                        printf("| Teclado  | %-6d | %-15s | %-15s |\n", pcIngresado.tecladoPC.identificador, pcIngresado.tecladoPC.marca, pcIngresado.tecladoPC.modelo);
                        printf("|-------------------------------------------------------|\n");
                        printf("| Mouse    | %-6d | %-15s | %-15s |\n", pcIngresado.mousePC.identificador, pcIngresado.mousePC.marca, pcIngresado.mousePC.modelo);
                        printf("|-------------------------------------------------------|\n");
                        printf("| Monitor  | %-6d | %-15s | %-15s |\n", pcIngresado.monitorPC.identificador, pcIngresado.monitorPC.marca, pcIngresado.monitorPC.modelo);
                        printf("*-------------------------------------------------------*\n");
                        encontrado = 1;
                        printf("Presione cualquier tecla para continuar...");
                        getch();
                    }
                }
                if (encontrado == 0)
                {
                    system("cls");
                    imprimirUsuario();
                    printf("\n"
                           "*--------------------------------------*\n"
                           "|                 ERROR                |\n"
                           "*--------------------------------------*\n"
                           "|       EL ID INGRESADO NO EXISTE      |\n"
                           "*--------------------------------------*\n");
                    printf("Presione cualquier tecla para continuar...");
                    getch();
                    system("cls");
                }
            } while (encontrado == 0);
        }
    }
    fclose(pcs);
}
void listarSoloPC()
{
    FILE *pcs;
    struct PC pcIngresado;

    pcs = fopen("pcs.txt", "r");
    if (pcs == NULL)
        printf("\nSin existencias.\n");
    else
    {
        printf("\n"
               "*---------------------------------------------------------------------------------------------*\n"
               "|                                      PC's DE ESCRITORIO                                     |\n"
               "|---------------------------------------------------------------------------------------------|\n"
               "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Stock    |\n"
               "*---------------------------------------------------------------------------------------------*\n");
        while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
        {
            if (pcIngresado.identificador != 0)
                printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresado.identificador, pcIngresado.marca, pcIngresado.modelo, pcIngresado.procesador, pcIngresado.ram, pcIngresado.stock);
        }
        printf("*---------------------------------------------------------------------------------------------*\n");
    }
    fclose(pcs);
}
// Funciones actualizar producto
void actualizarTeclado()
{
    FILE *teclados;
    struct teclado tecladoIngresado;
    int ID, encontrado = 0, opcion;

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
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "|                          TECLADO SELECCIONADO                        |\n"
                       "|----------------------------------------------------------------------|\n"
                       "|   ID   |      Marca      |      Modelo     |   Idioma   |   Stock    |\n"
                       "|----------------------------------------------------------------------|\n");
                printf("| %-6d | %-15s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
                printf("*----------------------------------------------------------------------*\n");
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del teclado                     |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(tecladoIngresado.marca);
                fflush(stdin);
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del teclado                    |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(tecladoIngresado.modelo);
                fflush(stdin);
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese el idioma del teclado                    |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Idioma: ");
                gets(tecladoIngresado.idioma);
                fflush(stdin);
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese el stock del teclado                     |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Stock: ");
                scanf("%d", &tecladoIngresado.stock);
                fflush(stdin);
                fwrite(&tecladoIngresado, sizeof(struct teclado), 1, teclados);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1)
        {
            system("cls");
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                  TECLADO ACTUALIZADO EXITOSAMENTE                    |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                imprimirUsuario();
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Actualizar otro teclado                                           |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                    mensajeError();
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarTeclado();
            }
        }
        if (encontrado == 0)
        {
            system("cls");
            imprimirUsuario();
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                      TECLADO NO ENCONTRADO                           |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Ingresar otro ID                                                  |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                {
                    mensajeError();
                    imprimirUsuario();
                }
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarTeclado();
            }
        }
        fclose(teclados);
    }
}
void actualizarMouse()
{
    FILE *mouses;
    struct mouse mouseIngresado;
    int ID, encontrado = 0, opcion;

    if (mouses == NULL)
        printf("\nSin existencias.");
    else
    {
        listarMouse();
        printf("Seleccione el ID del mouse que desea actualizar: ");
        scanf("%d", &ID);
        fflush(stdin);

        mouses = fopen("mouses.txt", "r+");
        fseek(mouses, 0, SEEK_SET);

        while (fread(&mouseIngresado, sizeof(struct mouse), 1, mouses))
        {
            if (ID == mouseIngresado.identificador)
            {
                fseek(mouses, -sizeof(struct mouse), SEEK_CUR);
                system("cls");
                imprimirUsuario();
                printf("\n"
                       "*---------------------------------------------------------*\n"
                       "|                    MOUSE SELECCIONADO                   |\n"
                       "|---------------------------------------------------------|\n"
                       "|   ID   |      Marca      |      Modelo     |   Stock    |\n");
                printf("| %-6d | %-15s | %-15s | %-10d |\n", mouseIngresado.identificador, mouseIngresado.marca, mouseIngresado.modelo, mouseIngresado.stock);
                printf("*---------------------------------------------------------*\n");
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del mouse                       |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(mouseIngresado.marca);
                fflush(stdin);
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del mouse                      |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(mouseIngresado.modelo);
                fflush(stdin);
                printf("*----------------------------------------------------------------------*\n"
                       "|                     Ingrese el stock del mouse                       |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Stock: ");
                scanf("%d", &mouseIngresado.stock);
                fflush(stdin);
                fwrite(&mouseIngresado, sizeof(struct mouse), 1, mouses);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1)
        {
            system("cls");
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                    MOUSE ACTUALIZADO EXITOSAMENTE                    |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                imprimirUsuario();
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Actualizar otro mouse                                             |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                    mensajeError();
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarMouse();
            }
        }
        if (encontrado == 0)
        {
            system("cls");
            imprimirUsuario();
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                      MOUSE NO ENCONTRADO                             |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Ingresar otro ID                                                  |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                {
                    mensajeError();
                    imprimirUsuario();
                }
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarMouse();
            }
        }
        fclose(mouses);
    }
}
void actualizarMonitor()
{
    FILE *monitores;
    struct monitor monitorIngresado;
    int ID, encontrado = 0, opcion;

    if (monitores == NULL)
        printf("\nSin existencias.");
    else
    {
        listarMonitor();
        printf("Seleccione el ID del monitor que desea actualizar: ");
        scanf("%d", &ID);
        fflush(stdin);

        monitores = fopen("monitores.txt", "r+");
        fseek(monitores, 0, SEEK_SET);

        while (fread(&monitorIngresado, sizeof(struct monitor), 1, monitores))
        {
            if (ID == monitorIngresado.identificador)
            {
                fseek(monitores, -sizeof(struct monitor), SEEK_CUR);
                system("cls");
                imprimirUsuario();
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                         MONITOR SELECCIONADO                            |\n"
                       "|-------------------------------------------------------------------------|\n"
                       "|   ID   |      Marca      |      Modelo     |   Pantalla   |   Stock     |\n"
                       "|-------------------------------------------------------------------------|\n");
                printf("| %-6d | %-15s | %-15s | % +11s\" | %-10d |\n", monitorIngresado.identificador, monitorIngresado.marca, monitorIngresado.modelo, monitorIngresado.tamano, monitorIngresado.stock);
                printf("*-------------------------------------------------------------------------*\n");
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del monitor                        |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(monitorIngresado.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del monitor                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(monitorIngresado.modelo);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el tamano del monitor                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Tamano: ");
                gets(monitorIngresado.tamano);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el stock del monitor                        |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Stock: ");
                scanf("%d", &monitorIngresado.stock);
                fflush(stdin);
                fwrite(&monitorIngresado, sizeof(struct monitor), 1, monitores);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1)
        {
            system("cls");
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                    MONITOR ACTUALIZADO EXITOSAMENTE                  |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                imprimirUsuario();
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Actualizar otro monitor                                           |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                    mensajeError();
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarMonitor();
            }
        }
        if (encontrado == 0)
        {
            system("cls");
            imprimirUsuario();
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                      MONITOR NO ENCONTRADO                           |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Ingresar otro ID                                                  |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                {
                    mensajeError();
                    imprimirUsuario();
                }
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarMonitor();
            }
        }
        fclose(monitores);
    }
}
void actualizarNotebook()
{
    FILE *notebooks;
    struct notebook notebookIngresado;
    int ID, encontrado = 0, opcion;

    if (notebooks == NULL)
        printf("\nSin existencias.");
    else
    {
        listarNotebook();
        printf("Seleccione el ID del notebook que desea actualizar: ");
        scanf("%d", &ID);
        fflush(stdin);

        notebooks = fopen("notebooks.txt", "r+");
        fseek(notebooks, 0, SEEK_SET);

        while (fread(&notebookIngresado, sizeof(struct notebook), 1, notebooks))
        {
            if (ID == notebookIngresado.identificador)
            {
                fseek(notebooks, -sizeof(struct notebook), SEEK_CUR);
                system("cls");
                imprimirUsuario();
                printf("\n"
                       "*------------------------------------------------------------------------------------------------------------*\n"
                       "|                                            NOTEBOOK SELECCIONADO                                           |\n"
                       "|------------------------------------------------------------------------------------------------------------|\n"
                       "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Pantalla   |   Stock    |\n"
                       "|------------------------------------------------------------------------------------------------------------|\n");
                printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %+11s\" | %-10d |\n", notebookIngresado.identificador, notebookIngresado.marca, notebookIngresado.modelo, notebookIngresado.procesador, notebookIngresado.ram, notebookIngresado.pantalla, notebookIngresado.stock);
                printf("*------------------------------------------------------------------------------------------------------------*\n");
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del notebook                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(notebookIngresado.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del notebook                      |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(notebookIngresado.modelo);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el procesador del notebook                  |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Procesador: ");
                gets(notebookIngresado.procesador);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la RAM del notebook                         |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " RAM: ");
                gets(notebookIngresado.ram);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la pantalla del notebook                    |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Pantalla: ");
                gets(notebookIngresado.pantalla);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el stock del notebook                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Stock: ");
                scanf("%d", &notebookIngresado.stock);
                fflush(stdin);
                fwrite(&notebookIngresado, sizeof(struct notebook), 1, notebooks);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1)
        {
            system("cls");
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                      NOTEBOOK ACTUALIZADO                            |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                imprimirUsuario();
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Actualizar otro notebook                                          |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                    mensajeError();
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarNotebook();
            }
        }
        if (encontrado == 0)
        {
            system("cls");
            imprimirUsuario();
            printf("\n"
                   "*----------------------------------------------------------------------*\n"
                   "|                      NOTEBOOK NO ENCONTRADO                          |\n"
                   "*----------------------------------------------------------------------*\n");
            do
            {
                printf("\n"
                       "*----------------------------------------------------------------------*\n"
                       "| 1. Ingresar otro ID                                                  |\n"
                       "| 2. Volver al menu principal                                          |\n"
                       "*----------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                {
                    mensajeError();
                    imprimirUsuario();
                }
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarNotebook();
            }
        }
        fclose(notebooks);
    }
}
void actualizarPC()
{
    FILE *pcs;
    struct PC pcIngresado;
    int ID, encontrado = 0, opcion;

    if (pcs == NULL)
        printf("\nSin existencias.");
    else
    {
        listarSoloPC();
        printf("Seleccione el ID de la PC que desea actualizar: ");
        scanf("%d", &ID);
        fflush(stdin);

        pcs = fopen("pcs.txt", "r+");
        fseek(pcs, 0, SEEK_SET);

        while (fread(&pcIngresado, sizeof(struct PC), 1, pcs))
        {
            if (ID == pcIngresado.identificador)
            {
                fseek(pcs, -sizeof(struct PC), SEEK_CUR);
                system("cls");
                imprimirUsuario();
                printf("\n"
                       "*---------------------------------------------------------------------------------------------*\n"
                       "|                                      PC SELECCIONADA                                        |\n"
                       "*---------------------------------------------------------------------------------------------*\n"
                       "|   ID   |      Marca      |      Modelo     |    Procesador   |       RAM       |   Stock    |\n"
                       "*---------------------------------------------------------------------------------------------*\n");
                printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresado.identificador, pcIngresado.marca, pcIngresado.modelo, pcIngresado.procesador, pcIngresado.ram, pcIngresado.stock);
                printf("*---------------------------------------------------------------------------------------------*\n");
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca de la PC                           |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                fflush(stdin);
                gets(pcIngresado.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo de la PC                          |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(pcIngresado.modelo);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el procesador de la PC                      |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Procesador: ");
                gets(pcIngresado.procesador);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la RAM de la PC                             |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " RAM: ");
                gets(pcIngresado.ram);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el stock de la PC                           |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Stock: ");
                scanf("%d", &pcIngresado.stock);
                fflush(stdin);
                system("cls");

                imprimirUsuario();
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                         ACTUALIZAR TECLADO PC                           |\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del teclado                        |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(pcIngresado.tecladoPC.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del teclado                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(pcIngresado.tecladoPC.modelo);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el idioma del teclado                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Idioma: ");
                gets(pcIngresado.tecladoPC.idioma);
                fflush(stdin);
                system("cls");

                imprimirUsuario();
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                         ACTUALIZAR MOUSE PC                             |\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del mouse                          |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(pcIngresado.mousePC.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del mouse                         |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(pcIngresado.mousePC.modelo);
                fflush(stdin);
                system("cls");

                imprimirUsuario();
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                         ACTUALIZAR MONITOR PC                           |\n"
                       "*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese la marca del monitor                        |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Marca: ");
                gets(pcIngresado.monitorPC.marca);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el modelo del monitor                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Modelo: ");
                gets(pcIngresado.monitorPC.modelo);
                fflush(stdin);
                printf("*-------------------------------------------------------------------------*\n"
                       "|                     Ingrese el tamano del monitor                       |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Tamano: ");
                gets(pcIngresado.monitorPC.tamano);
                fflush(stdin);

                fwrite(&pcIngresado, sizeof(struct PC), 1, pcs);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1)
        {
            system("cls");
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         PC ACTUALIZADA EXITOSAMENTE                     |\n"
                   "*-------------------------------------------------------------------------*\n");
            do
            {
                imprimirUsuario();
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "| 1. Actualizar otra PC                                                   |\n"
                       "| 2. Volver al menu principal                                             |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                    mensajeError();
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarPC();
            }
        }
        if (encontrado == 0)
        {
            system("cls");
            imprimirUsuario();
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         PC NO ENCONTRADA                                |\n"
                   "*-------------------------------------------------------------------------*\n");
            do
            {
                printf("\n"
                       "*-------------------------------------------------------------------------*\n"
                       "| 1. Ingresar otro ID                                                     |\n"
                       "| 2. Volver al menu principal                                             |\n"
                       "*-------------------------------------------------------------------------*\n"
                       " Seleccione una opcion: ");
                scanf("%d", &opcion);
                fflush(stdin);
                if (opcion < 1 || opcion > 2)
                {
                    mensajeError();
                    imprimirUsuario();
                }
            } while (opcion < 1 || opcion > 2);
            if (opcion == 1)
            {
                system("cls");
                imprimirUsuario();
                actualizarPC();
            }
        }
        fclose(pcs);
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
                    printf("\n"
                           "*----------------------------------------------------------------------*\n"
                           "|                          TECLADO SELECCIONADO                        |\n"
                           "|----------------------------------------------------------------------|\n"
                           "|   ID   |      Marca      |      Modelo     |   Idioma   |   Stock    |\n"
                           "*----------------------------------------------------------------------*\n");
                    printf("| %-6d | %-15s | %-15s | %-10s | %-10d |\n", tecladoIngresado.identificador, tecladoIngresado.marca, tecladoIngresado.modelo, tecladoIngresado.idioma, tecladoIngresado.stock);
                    printf("*----------------------------------------------------------------------*\n");
                    printf("Confirme la eliminacion del teclado seleccionado.\n"
                           "*----------------------------------------------------------------------*\n"
                           "| 1. Eliminar teclado                                                  |\n"
                           "| 2. Cancelar borrado                                                  |\n"
                           "*----------------------------------------------------------------------*\n"
                           " Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                        mensajeError();
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
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         TECLADO NO ENCONTRADO                           |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         TECLADO ELIMINADO                               |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         OPERACION CANCELADA                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(teclados);
    }
}
void eliminarMouse()
{
    FILE *mouses;
    struct mouse mouseIngresado;
    int ID, opcion, encontrado = 0;

    if (mouses == NULL)
        printf("\nSin existencias.\n");
    else
    {
        listarMouse();
        printf("Seleccione el ID del mouse que desea eliminar: ");
        scanf("%d", &ID);
        fflush(stdin);

        mouses = fopen("mouses.txt", "r+");
        fseek(mouses, 0, SEEK_SET);

        while (fread(&mouseIngresado, sizeof(struct mouse), 1, mouses))
        {
            if (ID == mouseIngresado.identificador)
            {
                fseek(mouses, -sizeof(struct mouse), SEEK_CUR);
                system("cls");
                do
                {
                    imprimirUsuario();
                    printf("\n"
                           "*---------------------------------------------------------*\n"
                           "|                     MOUSE SELECCIONADO                  |\n"
                           "|---------------------------------------------------------|\n"
                           "|   ID   |      Marca      |      Modelo     |   Stock    |\n"
                           "*---------------------------------------------------------*\n");
                    printf("| %-6d | %-15s | %-15s | %-10d |\n", mouseIngresado.identificador, mouseIngresado.marca, mouseIngresado.modelo, mouseIngresado.stock);
                    printf("*---------------------------------------------------------*\n");
                    printf("Confirme la eliminacion del mouse seleccionado.\n"
                           "*---------------------------------------------------------*\n"
                           "| 1. Eliminar mouse                                       |\n"
                           "| 2. Cancelar borrado                                     |\n"
                           "*---------------------------------------------------------*\n"
                           " Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                        mensajeError();
                } while (opcion < 1 || opcion > 2);
                if (opcion == 1)
                {
                    mouseIngresado.identificador = 0;
                    strcpy(mouseIngresado.marca, "");
                    strcpy(mouseIngresado.modelo, "");
                    mouseIngresado.stock = 0;
                    fwrite(&mouseIngresado, sizeof(struct mouse), 1, mouses);
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
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         MOUSE NO ENCONTRADO                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         MOUSE ELIMINADO                                 |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         OPERACION CANCELADA                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(mouses);
    }
}
void eliminarMonitor()
{
    FILE *monitores;
    struct monitor monitorIngresado;
    int ID, opcion, encontrado = 0;

    if (monitores == NULL)
        printf("\nSin existencias.\n");
    else
    {
        listarMonitor();
        printf("Seleccione el ID del monitor que desea eliminar: ");
        scanf("%d", &ID);
        fflush(stdin);

        monitores = fopen("monitores.txt", "r+");
        fseek(monitores, 0, SEEK_SET);

        while (fread(&monitorIngresado, sizeof(struct monitor), 1, monitores))
        {
            if (ID == monitorIngresado.identificador)
            {
                fseek(monitores, -sizeof(struct monitor), SEEK_CUR);
                system("cls");
                do
                {
                    imprimirUsuario();
                    printf("\n"
                           "*------------------------------------------------------------------------*\n"
                           "|                     MONITOR SELECCIONADO                               |\n"
                           "|------------------------------------------------------------------------|\n"
                           "|   ID   |      Marca      |      Modelo     |   Pantalla   |   Stock    |\n"
                           "*------------------------------------------------------------------------*\n");
                    printf("| %-6d | %-15s | %-15s | %+11s\" | %-10d |\n", monitorIngresado.identificador, monitorIngresado.marca, monitorIngresado.modelo, monitorIngresado.tamano, monitorIngresado.stock);
                    printf("*------------------------------------------------------------------------*\n");
                    printf("Confirme la eliminacion del monitor seleccionado.\n"
                           "*------------------------------------------------------------------------*\n"
                           "| 1. Eliminar monitor                                                    |\n"
                           "| 2. Cancelar borrado                                                    |\n"
                           "*------------------------------------------------------------------------*\n"
                           " Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                        mensajeError();
                } while (opcion < 1 || opcion > 2);
                if (opcion == 1)
                {
                    monitorIngresado.identificador = 0;
                    strcpy(monitorIngresado.marca, "");
                    strcpy(monitorIngresado.modelo, "");
                    strcpy(monitorIngresado.tamano, "");
                    monitorIngresado.stock = 0;
                    fwrite(&monitorIngresado, sizeof(struct monitor), 1, monitores);
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
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         MONITOR NO ENCONTRADO                           |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         MONITOR ELIMINADO                               |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         OPERACION CANCELADA                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(monitores);
    }
}
void eliminarNotebook()
{
    FILE *notebooks;
    struct notebook notebookIngresada;
    int ID, opcion, encontrado = 0;

    if (notebooks == NULL)
        printf("\nSin existencias.\n");
    else
    {
        listarNotebook();
        printf("Seleccione el ID del notebook que desea eliminar: ");
        scanf("%d", &ID);
        fflush(stdin);

        notebooks = fopen("notebooks.txt", "r+");
        fseek(notebooks, 0, SEEK_SET);

        while (fread(&notebookIngresada, sizeof(struct notebook), 1, notebooks))
        {
            if (ID == notebookIngresada.identificador)
            {
                fseek(notebooks, -sizeof(struct notebook), SEEK_CUR);
                system("cls");
                do
                {
                    imprimirUsuario();
                    printf("\n"
                           "*------------------------------------------------------------------------------------------------------------*\n"
                           "|                                           NOTEBOOK SELECCIONADO                                            |\n"
                           "|------------------------------------------------------------------------------------------------------------|\n"
                           "|   ID   |      Marca      |      Modelo     |   Procesador    |       RAM       |   Pantalla   |   Stock    |\n"
                           "*------------------------------------------------------------------------------------------------------------*\n");
                    printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %+11s\" | %-10d |\n", notebookIngresada.identificador, notebookIngresada.marca, notebookIngresada.modelo, notebookIngresada.procesador, notebookIngresada.ram, notebookIngresada.pantalla, notebookIngresada.stock);
                    printf("*------------------------------------------------------------------------------------------------------------*\n");
                    printf("Confirme la eliminacion del notebook seleccionado.\n"
                           "*------------------------------------------------------------------------------------------------------------*\n"
                           "| 1. Eliminar notebook                                                                                       |\n"
                           "| 2. Cancelar borrado                                                                                        |\n"
                           "*------------------------------------------------------------------------------------------------------------*\n"
                           " Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                        mensajeError();
                } while (opcion < 1 || opcion > 2);
                if (opcion == 1)
                {
                    notebookIngresada.identificador = 0;
                    strcpy(notebookIngresada.marca, "");
                    strcpy(notebookIngresada.modelo, "");
                    strcpy(notebookIngresada.procesador, "");
                    strcpy(notebookIngresada.ram, "");
                    strcpy(notebookIngresada.pantalla, "");
                    notebookIngresada.stock = 0;

                    fwrite(&notebookIngresada, sizeof(struct notebook), 1, notebooks);
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
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         NOTEBOOK NO ENCONTRADO                          |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         NOTEBOOK ELIMINADO                              |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:

            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         OPERACION CANCELADA                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(notebooks);
    }
}
void eliminarPC()
{
    FILE *pcs;
    struct PC pcIngresada;
    int ID, opcion, encontrado = 0;

    if (pcs == NULL)
        printf("\nSin existencias.\n");
    else
    {
        listarPC();
        printf("Seleccione el ID del PC que desea eliminar: ");
        scanf("%d", &ID);
        fflush(stdin);

        pcs = fopen("pcs.txt", "r+");
        fseek(pcs, 0, SEEK_SET);

        while (fread(&pcIngresada, sizeof(struct PC), 1, pcs))
        {
            if (ID == pcIngresada.identificador)
            {
                fseek(pcs, -sizeof(struct PC), SEEK_CUR);
                system("cls");
                do
                {
                    imprimirUsuario();
                    printf("\n"
                           "*---------------------------------------------------------------------------------------------*\n"
                           "|                                         PC SELECCIONADO                                     |\n"
                           "|---------------------------------------------------------------------------------------------|\n"
                           "|   ID   |      Marca      |      Modelo     |   Procesador    |       RAM       |   Stock    |\n"
                           "*---------------------------------------------------------------------------------------------*\n");
                    printf("| %-6d | %-15s | %-15s | %-15s | %-15s | %-10d |\n", pcIngresada.identificador, pcIngresada.marca, pcIngresada.modelo, pcIngresada.procesador, pcIngresada.ram, pcIngresada.stock);
                    printf("*---------------------------------------------------------------------------------------------*\n");
                    printf("Confirme la eliminacion del PC seleccionado.\n"
                           "*---------------------------------------------------------------------------------------------*\n"
                           "| 1. Eliminar PC                                                                               |\n"
                           "| 2. Cancelar borrado                                                                          |\n"
                           "*---------------------------------------------------------------------------------------------*\n"
                           " Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion < 1 || opcion > 2)
                        mensajeError();
                } while (opcion < 1 || opcion > 2);
                if (opcion == 1)
                {
                    pcIngresada.identificador = 0;
                    strcpy(pcIngresada.marca, "");
                    strcpy(pcIngresada.modelo, "");
                    strcpy(pcIngresada.procesador, "");
                    strcpy(pcIngresada.ram, "");
                    pcIngresada.stock = 0;
                    fwrite(&pcIngresada, sizeof(struct PC), 1, pcs);
                    encontrado = 1;
                    break;
                    // Los parametros de la estructura (monitor,teclado y mouse) no son "borrados" para optimizar el código
                    // ya que una vez se agregue un nuevo PC, los datos de la estructura serán sobreescritos con los nuevos datos.
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
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         PC NO ENCONTRADO                                |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 1:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         PC ELIMINADO                                    |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        case 2:
            printf("\n"
                   "*-------------------------------------------------------------------------*\n"
                   "|                         OPERACION CANCELADA                             |\n"
                   "*-------------------------------------------------------------------------*\n");
            printf("Presione cualquier tecla para volver al menu...");
            getch();
            system("cls");
            break;
        }
        fclose(pcs);
    }
}
