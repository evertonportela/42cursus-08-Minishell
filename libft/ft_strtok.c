#include "libft.h"

char *ft_strtok(char *str, const char *delim) {
    // Mantém o rastreamento da última posição encontrada
    static char *lastToken = NULL;

    // Se a chamada é com uma nova string, redefine o ponteiro
    if (str != NULL)
    {
        lastToken = str;
    }
    else
    {
        // Se a chamada é sem uma nova string, continua da última posição encontrada
        if (lastToken == NULL)
            return NULL;  
        // Já chegamos ao final da string
    }

    // Procura pelo próximo delimitador na string
    char *tokenStart = lastToken;
    char *delimPos = ft_strpbrk(lastToken, delim);

    if (delimPos != NULL)
    {
        // Se um delimitador foi encontrado, substitui por '\0'
        *delimPos = '\0';
        lastToken = delimPos + 1;  // Atualiza a última posição encontrada
    }
    else
        lastToken = NULL;
        // Se nenhum delimitador foi encontrado, chegamos ao final da string

    return tokenStart;
}