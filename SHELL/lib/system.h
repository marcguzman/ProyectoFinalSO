#ifndef SYSTEM_H
#define SYSTEM_H

    /* Funciones */

        // TeddOS
        void sys_tag(void);
        void sys_init(void);
        void sys_header(void);            

        // Funciones de pantalla
        void c_clear(void);
        void c_printLine(char *line);
        char c_readChar(void);
        char *c_readLine(void);

        // Funciones del sistema
        void sys_shtdown(void);
        void sys_beep(int sound);
        void sys_version(void); 
        int sys_exec(char *act);

    /* Constantes */
    // EMPTY

    /* Funciones Shell */
    void shLoop(void);
    char *shReadLine(void);
    char **shParseLine(char *line);
    int shExecute(char **tokens);
    int shFindCmdID(char *cmd);

    /* Constantes Shell */
    #define TOKEN_BUF_SIZE 64
    #define TOKEN_DELIMITER " \t\r\n\a"

#endif