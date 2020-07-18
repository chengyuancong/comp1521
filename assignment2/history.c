// CP1521 mysh ... command history
// Implements an abstract data object

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// This is defined in string.h
// BUT ONLY if you use -std=gnu99
//extern char *strdup(const char *s);

// Command History
// array of command lines
// each is associated with a sequence number

#define MAXHIST 20
#define MAXSTR  200
#define MAXLINE (MAXSTR+6)

#define HISTFILE ".mymysh_history"

typedef struct _history_entry {
   int seqNumber;
   char commandLine[MAXSTR];
} HistoryEntry;

typedef struct _history_list {
   int nEntries;
   HistoryEntry commands[MAXHIST];
} HistoryList;

HistoryList CommandHistory;

// initCommandHistory()
// - initialise the data structure
// - read from .mymysh_history if it exists

int initCommandHistory()
{
   FILE *hisf = fopen(HISTFILE, "r");
   CommandHistory.nEntries = 0;
   if (hisf != NULL) {
      char buffer[MAXLINE];
      while (fgets(buffer, MAXLINE, hisf) != NULL) {
         sscanf(buffer, " %3d  %s", 
               &(CommandHistory.commands[CommandHistory.nEntries].seqNumber),
               CommandHistory.commands[CommandHistory.nEntries].commandLine);
         CommandHistory.nEntries++;
      }
   }
   fclose(hisf);
   return CommandHistory.nEntries;
}

// addToCommandHistory()
// - add a command line to the history list
// - overwrite oldest entry if buffer is full

void addToCommandHistory(char *cmdLine, int seqNo)
{
   // TODO
}

// showCommandHistory()
// - display the list of 

void showCommandHistory(FILE *outf)
{
   // TODO
}

// getCommandFromHistory()
// - get the command line for specified command
// - returns NULL if no command with this number

char *getCommandFromHistory(int cmdNo)
{
   // TODO
}

// saveCommandHistory()
// - write history to $HOME/.mymysh_history

void saveCommandHistory()
{
   // TODO
}

// cleanCommandHistory
// - release all data allocated to command history

void cleanCommandHistory()
{
   // TODO
}
