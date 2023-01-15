/*
 * fonctions_shell.h
 *
 *  Created on: 21 nov. 2022
 *      Author: quent & ali
 */

#ifndef SRC_FONCTIONS_SHELL_H_
#define SRC_FONCTIONS_SHELL_H_



#endif /* SRC_FONCTIONS_SHELL_H_ */

#include "basic_shell.h"
#include "stdlib.h"
#include "main.h"
#include "cmsis_os.h"

int fonction( int argc, char ** argv);
int addition( int argc, char ** argv);
int led();
int setLedRate( int argc, char ** argv);
int spammer( int argc, char ** argv);

void vApplicationStackOverflowHook( TaskHandle_t xTask, signed char *pcTaskName );


