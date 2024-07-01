# Minishell

## As beautiful as a shell

### Summary

This project is about creating a simple shell, akin to your own little bash.

## Contents

- [Introduction](#introduction)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#Description)

## Introduction

The existence of shells is linked to the very existence of IT. Developers agreed that communicating with a computer using aligned 1/0 switches was irritating, leading to the creation of software to communicate with computers using interactive command lines. Thanks to Minishell, you can experience the challenges faced before the advent of Windows.

## Common Instructions

- The project must be written in C.
- Functions should not quit unexpectedly (e.g., segmentation fault, bus error).
- All heap-allocated memory space must be properly freed.
- The Makefile contain rules for `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Description

Writing a shell that:

- Displays a prompt when waiting for a new command.
- Has a working history.
- Searches and launches the correct executable (based on the PATH variable or using a relative or absolute path).
- Uses no more than one global variable.
- Handles unclosed quotes or special characters correctly.
- Handles single (`'`) and double (`"`) quotes appropriately.
- Implements redirections:
  - `<` redirects input.
  - `>` redirects output.
  - `<<` reads input until a line containing a given delimiter is seen.
  - `>>` redirects output in append mode.
- Implements pipes (`|` character).
- Handles environment variables (`$` followed by a sequence of characters).
- Handles `$?` to expand to the exit status of the most recently executed foreground pipeline.
- Handles `ctrl-C`, `ctrl-D`, and `ctrl-\` as in bash.
- In interactive mode:
  - `ctrl-C` displays a new prompt on a new line.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.
- Implements the following built-ins:
  - `echo` with option `-n`
  - `cd` with a relative or absolute path
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options

## Team Members

  - speranos: Responsible for creating the lexer and parsing.
  - MrBihe: Handled execution.
