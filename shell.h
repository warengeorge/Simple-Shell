#ifndef SHELL_H
#define SHELL_H
#define HSHPATH "PATH"
#define ENVSIZE 33
#define NUM_TOKENS 50

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

/**
 * struct builtins_s - struct for matching command lines with functions
 * @command: builtin command
 * @f: associated function
 */
typedef struct builtins_s
{
	char *command;
	void (*f)();
} builtins_t;

/**
 * struct general_s - struct for shell
 * @isInteractive: flag for interactive mode
 * @_env: environment var
 * @bufferTokens: buffer for the tokens
 * @nonInteractiveBuffer: buffer for user input in NonInteractive mode
 * @interactiveBuffer: buffer for user input in Interactive mode
 * @builtins: table of builtins
 * @nCommands: number of commands run by user
 */
typedef struct general_s
{
	unsigned int isInteractive;
	unsigned int nCommands;
	char **_env;
	char **bufferTokens;
	char *nonInteractiveBuffer;
	char *interactiveBuffer;
	builtins_t *builtins;
} general_t;

builtins_t *initBuiltins(general_t *genHead);
general_t *initStruct(char **env);
char *mallocBuffer(size_t length, general_t *genHead);

int interactiveShell(general_t *genHead);
int nonInteractiveShell(char *buffer, general_t *genHead);
char **tokenize(char *str, char delim[], general_t *genHead);
unsigned int _strlen(const char *str);
char *__strcat(char *dest, char *source);
int _strcmp(char *s1, char *s2);
void _strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_itoa(unsigned int num);

char *getUserInput(char *buffer, size_t *length, general_t *genHead);
char **parseBuffer(char *buffer, general_t *genHead);

void printPrompt(char *prompt);
size_t correctAbsPath(char *token);
char *findCmd(char *b);
int createFork(char **bufferTokens, general_t *genHead);
char *createCWDFile(char *file);

char *_getenv(char *name);
void findBuiltin(general_t *vars, char *cmd);
void runEnv(general_t *genHead);
void runExit(general_t *genHead);
void runSetenv(void);
void runUnsetenv(void);

void freeStruct(general_t *genHead);
void freeEnv(general_t *genHead);
void freeBufferTokens(general_t *genHead);
void freeBuffer(char *buf);
void freeBuiltins(general_t *genHead);

void addMemNIBuffer(general_t *genHead, char *buf);
void addMemIBuffer(general_t *genHead, char *buf);
void addMemEnvBuffer(general_t *genHead, char **env);
void addMemBuiltins(general_t *genHead, builtins_t *builtins);
void addMemEnv(general_t *genHead, char **env);
void addMemBufferTokens(general_t *genHead, char **tokens);

#endif
