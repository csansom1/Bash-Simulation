Name: Connor Sansom
ID: 0871933
Date: 30/01/2017
Course: CIS 3110
Assignment: A1

**********
*Overview*
**********

myshell was designed to simulate the behaviour of a Linux shell. It reads in a string from the command line and interprets it using a
parser provided by the course instructor, which has been modified to read expressions in double quotes ("). It then executes the command
it has read in, be it a Linux command or a myshell command (see below). myshell also allows the user to write to a file instead of stdout
(> <filename>), read input from a file (< <filename>), and execute commands in the background (&).

***********
*Compiling*
***********

To compile the shell, "cd" into the a1 directory and type "make".
- requires make, gcc, and flex
- required files: lex.c, myshell.c, myshell.h, Makefile

**********
*Executon*
**********

To start the shell, type "./myshell" in bash. "myshell$" should pop up, at this point you may enter commands.

myshell supports the following commands:

	exit
	- Terminate the shell
	- Example: exit
	- Output: myshell has been terminated
	  - all background operations are terminated upon exit

	add
	- Add all integers (decimal or hex) and print sum to stdout
	- Example: add 100 210 0xa
	  - any input that is a not decimal or hex number will be read as 0
	- Output: 100 + 210 + 0xa = 320
	  - sum is always printed in base 10

	args
	- Count and list all arguments
	- Example: args 1 2 3 4 5 "six, seven"
	- Output: argc = 6, args = 1, 2, 3, 4, 5, "six, seven"

        reverse
        - Reverse and print all arguments
        - Example: reverse first second "third, fourth" fifth
	- Output: reverse(first) = tsrif, reverse(second) = dnoces, reverse("third, fourth") = "htruof ,driht", reverse(fifth) = htfif

	bash commands
	- Enter as you would in bash
	  - The & flag, if used, must be the last argument
	    - The background process will be indicated by the process ID that appears upon using the & flag
	  - The < and > flags followed by a file name, must appear at the end of the command line and may only be followed by a &
	- Example: ls -l
	- Output: <all files in the active directory and their size, permisions, and creation date>

*******************
*Known Limitations*
*******************

	- Background operations will not indicate when they pause, finish, or terminate, use the "ps" command to find this information
	- Any command that opens a new screen (e.g. vim, nano) cannot be run tin the background
	  - They will still run with the & flag, but will open in the foreground
	- After running a background process, the curser can sometimes be separated from "myshell$", type "sleep 1" to fix this
	- If a "sleep" is run in the background, only 1 process may be run until the sleep has ended.