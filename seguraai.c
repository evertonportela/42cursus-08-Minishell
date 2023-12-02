#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct s_token {
    char *content;
    struct s_token *next;
} t_token;

typedef struct s_minishell
{
    t_token *tokens;
}   t_minishell;

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

int    main(void)
{
    char        *command_line;
    t_minishell *minishell;

    command_line = strdup("str01 str02 str03");
    minishell = (t_minishell *)malloc(sizeof(t_minishell));
    if (!minishell) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    minishell->tokens = NULL;

    tokenize_and_add(&minishell->tokens, command_line);
    return (EXIT_SUCCESS);
}