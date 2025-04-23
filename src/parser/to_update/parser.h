
#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minishell.h"

# define FALSE 0
# define TRUE 1

/*	Este archivo es parte de un programa tipo shell (como Bash).
Su trabajo es tomar una línea que alguien escribe (como "ls -l | grep txt")
y organizarla en una estructura que el programa pueda entender.
Divide la línea en comandos, los separa por |, y los guarda en una lista de
nodos. También tiene funciones para contar palabras, revisar espacios y
limpiar memoria.	*/

// ** COMMAND PARSER **
shell_line_t	*command_struct(char *line);
/*	Esta función toma una línea que puede tener varios comandos separados
por | (el símbolo de "pipe" en los shells) y crea una lista de nodos, uno
por cada comando.	*/

shell_line_t	*command_node(char *line);
/*	Crea un "nodo" (una cajita) que guarda información sobre un comando.
Este nodo tiene:
* La línea completa (copiada con ft_strdup).
* Los pedazos del comando (usando command_chopper).
* Un enlace al siguiente nodo (como una lista encadenada).	*/

char			**command_chopper(char *line);
/*	Esta función tiene como objetivo dividir una línea en pedazos
(como palabras o comandos), pero está incompleta. Solo maneja el caso
en que hay una sola palabra. No asigna memoria para seg correctamente
ni maneja múltiples palabras. Está en progreso.	*/

// ** MAIN **
int				main(int argc, char **argv);

// ** PARSING MEMMORY HANDLING **
void			free_double_char(char **str);
/*	Esta función es como un "limpiador" que libera memoria.
Cuando tienes un arreglo de cadenas (como una lista de palabras),
esta función se asegura de borrar cada palabra y luego borrar la
lista completa para que no ocupe espacio en la memoria.	*/

// ** PARSING UTILS **
int				words_counter(char *str);
int				no_space_finder(char *str);
/*	Esta función busca en una cadena de texto el primer carácter que no
sea un espacio en blanco. Devuelve la posición de ese carácter. Es útil
para ignorar espacios al principio de una línea o palabra.	*/
int				is_space(char c);
/*	Esta función revisa si un carácter (una letra o símbolo) es un
espacio en blanco. Un espacio en blanco puede ser el espacio normal
(como el que haces con la barra espaciadora) o cosas como tabulaciones.	*/

char			*ft_strndup(const char *str, size_t init);
/*	Esta función toma una cadena de caracteres (str) y crea una nueva
cadena que contiene los primeros 'init' caracteres de 'str'. Es útil
cuando necesitas copiar solo una parte de una cadena.	*/

#endif