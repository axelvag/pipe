# pipex

42 project:

The main goal of this project is to recreate the functionality of the "pipe" shell command by using multiple processes and redirecting data flows between them.

Here is a general presentation of the Pipex project:

Project Name: Pipex

Objective: Recreate the functionality of the "pipe" shell command using processes and redirects.

Skills assessed:

  - System programming under Unix.
  - Manipulation of files and processes.
  - Management of errors and function returns.
  - Understanding the concepts of tubes (pipes).

Description: The Pipex project involves creating a C language program that supports redirecting data flow between two shell commands using pipes. Students are faced with the task of efficiently managing processes, pipes, and redirection operations to achieve the same result as the "pipe" shell command.

Main Features:

  - Parsing arguments: The program must be able to parse arguments passed on the command line, including input/output file names.
  - Process Creation: The program must create two child processes that execute the two user-specified commands.
  - Flow Redirection: The output flow of the first process must be redirected to the input of the second process using a tube.
  - File Handling: The specified input/output files must be properly handled by the processes.
