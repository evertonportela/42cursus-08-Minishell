#include "../../minishell.h"

t_token *create_token(char *content) {
    t_token *token = (t_token *)malloc(sizeof(t_token));
    if (!token) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }

    token->content = strdup(content);
    if (!token->content) {
        perror("Strdup error");
        exit(EXIT_FAILURE);
    }

    token->next = NULL;

    return token;
}

void add_token(t_token **head, char *content) {
    t_token *new_token = create_token(content);
    new_token->next = *head;
    *head = new_token;
}

void tokenize_and_add(t_token **head, char *command_line) {
    char *token_content = strtok(command_line, " ");
    while (token_content != NULL) {
        add_token(head, token_content);
        token_content = strtok(NULL, " ");
    }
}