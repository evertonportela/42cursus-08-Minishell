#include "libft.h"

char *ft_strpbrk(const char *str, const char *charset) {
    while (*str != '\0') {
        // Itera sobre os caracteres de 'str'
        const char *charInCharset = charset;
        
        while (*charInCharset != '\0') {
            // Itera sobre os caracteres de 'charset'
            if (*str == *charInCharset) {
                // Retorna o ponteiro para a primeira ocorrência encontrada
                return (char *)str;
            }
            charInCharset++;
        }
        str++;
    }
    return NULL;  // Nenhum caractere encontrado
}