/* 
 * File:   Shell.c
 * Author: <Carlos Sosa>
 *
 * Created:     <28/08/2017>
 * Modified:    <17/09/2017>
 */

/* Librerias a utilizar */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Header del sistema */
#include "system.h"

/* Headers de aplicaciones */
// #include "calc.h"
// #include "media.h"

/**
* Loop que administra el funcionamiento del shell
*/
void shLoop(void)
{
    char *line;
    char **tokens;
    int status;

    do {

        /*Texto en pantalla*/
        sys_tag();

        /*Leer una linea ingresada por el usuario*/
        line = shReadLine();

        /*Volver la linea ingresada en tokens*/
        tokens = shParseLine(line);

        /*Ejecutar las acciones requeridas por el usuario*/
        status = shExecute(tokens);

        /*Limpia los valores en memoria*/
        free(line);
        free(tokens);

        /*Mientras el proceso no se concluya*/
    } while (!status);
}

/**
* Funcion que lee una linea escrita por 
* el usuario
*/
char *shReadLine(void)
{
    /*Inicializar el contenedor de la linea*/
    char *line = NULL;
    ssize_t bufferSize = 0;

    /*Obtener linea ingresada*/
    getline(&line, &bufferSize, stdin);

    /*Retornar conjunto de caracteres*/
    return line;
}

/**
* Funcion que parsea la linea ingresada 
* y la convierte en un conjunto de tokens
*/
char **shParseLine(char *line)
{
    // Inicializar el espacio en memoria del arreglo
    int bufferSize = TOKEN_BUF_SIZE, position = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "ERROR\n");
        exit(EXIT_FAILURE);
    }

    /*Divide la linea en tokens*/
    token = strtok(line, TOKEN_DELIMITER);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        /*Asigna mas especio en memoria al arreglo*/
        if (position >= bufferSize) {
            bufferSize += TOKEN_BUF_SIZE;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "ERROR\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }

    /*Llena el arreglo*/
    tokens[position] = NULL;

    /*Retorna el arreglo*/
    return tokens;
}

/**
* Funcion que realiza acciones en base a los tokens
*/
int shExecute(char **tokens)
{
    char *cmd = tokens[0];
    char *action = tokens[1];

    switch (shFindCmdID(cmd))
    {
        /*DISPLAY*/
        case 0:
            c_clear();
            return 0;
        
        /*SYSTEM*/
        case 1:
            return sys_exec(action);
            
        /*CALC*/
        case 2:
            printf("%s \n", "No esta instalada la calculadora");
            return 0;

        /*MUSIC*/
        case 3:
            printf("%s \n", "No esta instalado el reproductor de media");
            return 0;

        default:
            printf("\nNo se reconoce el comando ingresado.\n\n");
            return 0;
    }
}

/**
* Funcion que busca el ID del comando ejecutado
*/
int shFindCmdID(char *cmd) 
{
    /*Limpia la pantalla*/
    if (!strcmp(cmd, "clear")){
        return 0;
    }

    /*Informacion del sistema*/
    if (!strcmp(cmd, "system")){
        return 1;
    }
    
    /*Calculadora*/
    if (!strcmp(cmd, "calc")){
        return 2;
    }
        
    /*Reproductor de musica*/
    if (!strcmp(cmd, "music")){
        return 3;
    }

    /*Default return*/
    return 0;
}