# Introduction

* [Basics Terms](https://www.futurehosting.com/blog/linux-basics-terminal-shell-console-what-is-the-difference/)

* [Shell](http://linuxcommand.org/lc3_lts0010.php)

    Shell is a program which processes commands and returns output , like bash in Linux . Terminal is a program that run a shell , in the past it was a physical device (Before terminals were monitors with keyboards, they were teletypes) and then its concept was transferred into software , like Gnome-Terminal

# Commands
* use tab to predict the full commands

* clear

* $ find [where to start searching from] [expression determines what to find] [-options] [what to find]

* The > sign is used for redirecting the output of a program to something other than stdout (standard output, which is the terminal by default). The >> appends to a file or creates the file if it doesn't exist. The > overwrites the file if it exists or creates it if it doesn't exist.

* alias
* unalias


## Command syntax 
* Command  [options] [arguments]
* Symbols
    * "-"   # Single letter options start with
    * --    # Multi lettered options start with
    * \     # To continue command is next line
    * /     # To escape  spaces in the arguments
    * Note:Shell is case sensitive
    * Backtick (`) symbol in Linux Shell Scripting allows you to assign the output of a shell command to a variable.

## To check current Shell
    $ echo $SHELL                      
    $ ps
    $ ps -p $$
     
## [/etc/passwd](https://linuxize.com/post/etc-passwd-file/)
    $ cat /etc/passwd  
    $ cat /etc/shells                   Available shells 


# References
    https://www.howtogeek.com/269509/how-to-run-two-or-more-terminal-commands-at-once-in-linux
    
    