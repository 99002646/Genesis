# Outline

> Capabilities of a shell beyond command interpreter

## Shell Features

* Escaping & Quoting
  * How to nullify special chars like $, ;, >, < etc  
* Wild characters
  * \* represents any no.of any type of characters
  * ? represents any type of single character
* Redirection, storing stdout/stderr in a file
  * command > ofile
  * command 2> efile
  * command > ofile 2> efile
  * command >> afile
  * command &> oefile
  * command 2>> efile  
* Feeding file contents as stdin
  * command < file

  ```sh
  bc <  exprfile
  rev < sample.txt
  ```

* Piping, stdout one command as stdin of other command
  * command1 | command2

  ```sh
  ls | wc
  echo 2+3 | bc
  echo $a > $b | bc
  ```

* Command line substitution, paste output of command back in command line

  ```sh
  cal `date +%m` 2020
  p1=`pwd`
  ```

* Feeding stdin inline
  * cmd <<< input

  ```sh
  bc <<< "$a + $b"
  bc <<< "$a / 7"
  rev <<< "abcdxyz"
  ```

* Shell variables

  ```sh
  x=100         #no space before/after =
  echo $x
  ```

* Arithmetic in shell
  * Using expr command

    ```sh
    expr $a + $b
    expr $a / 5
    c=`expr $a + $b`
    ```

  * Using let command

    ```sh
    let c=a+b
    let d=a*5
    ```

  * Using bc command

    ```sh
    echo "scale=4;$a/$b" | bc
    bc <<< "scale=4;$a/$b
    ```

* Combining commands
  * cmd1 && cmd2
  * cmd1 || cmd2
  * cmd1 ; cmd2

## Additional Concepts

* std files opened by every process
  * stdin
  * stdout
  * stderr
* which all commands operate on stdin
* which commands generate stdout, which don't provide any?
* special files - /dev/null, typically used to vanish errors

  `cmd 2> /dev/null`

* tee command `cmd | tee file`
* logging techniques
* Monitoring log files `tail -f logfile`

> [Click Here](README.md) to go back to main page
