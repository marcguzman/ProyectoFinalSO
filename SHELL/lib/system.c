/* 
 * File:   System.c
 * Author: <Carlos Sosa>
 *
 * Created:     <17/09/2017>
 * Modified:    <24/09/2017>
 */
 
/* Librerias a utilizar */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Header del sistema */
#include "system.h"

/*********************Tags del sistema**********************/

/**
*   Funcion que muestra el tag del sistema
*/
void sys_tag(void){
    printf("$ TeddOS>");
}

/**
*   Funcion que muestra la animacion inicial
*   del sistema
*/
void sys_init(void){
    // Animacion inicial de TeddOS
}

/**
*   Funcion que muestra el header del sistema
*/
void sys_header(void){
    // Header del sistema
}

/*******************Funciones del sistema*******************/

/**
*   Funcion que apaga el equipo
*/
void sys_shtdown(void){
    // Code to power off
    printf("%s \n", "Actualmente no disponible");
}

/**
*   Funcion que reproduce un 'bep'
*/
void sys_beep(int sound){
    // Code to make a bep sounds
    switch (sound)
    {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;
    }
}

/**
*   Funcion que muestra la version del sistema
*/
void sys_version(void)
{
    printf("%s \n", "TeddOS v-1.0");
}

/*******************Funciones de pantalla*******************/

/**
*   Funcion que imprime una linea en pantalla
*/
void c_printLine(char *str) {
    char *ch;
    unsigned short *vidmem = (unsigned short*) 0xb8000;
	unsigned i;
	for (ch = str, i = 0; *ch; ch++, i++) {
        vidmem[i] = (unsigned char) *ch | 0x0700;
    } 
}

/**
*   Funcion que limpia la pantalla
*/
void c_clear(void){
    printf("\e[2J\e[H");
}

/**
*   Funcion que lee una linea escrita por 
*   el usuario
*/
char *c_readLine(void)
{
    char *line = NULL;
    ssize_t bufferSize = 0;
    getline(&line, &bufferSize, stdin);

    return line;
}

/*******************Funciones del sistema*******************/
int sys_exec(char *act)
{
    if (!strcmp(act, "version")){
        sys_version();
        return 0;
    }

    if (!strcmp(act, "shutdown")){
        sys_shtdown();
        return 0;
    }
}
