# Outline

## Commands

* Usage of `more`, `less` commands
  * How to display a file one screenful at a time using (paginated output)
  * piping outut of other commands using `more`, `less`
  * How `less` command is better than `more`
    > less is more, more is less!! 
* `head` command usage
  * Display first 10 lines
  * Display first n lines only
* `tail` command usage
  * Display last 10 lines 
  * Display last n lines only
  * Display from Nth line onwards
* In a file with more than 20 lines, how to print line no.s 11 - 20
* Refer the [sample data](data/emp.lst) for further commands
* `cut` command usage
  * Display column no.s 1-4 (i.e. emp id only)
  * Display column no.s 6-22, 34-42 (i.e. name, dept) 
  * Display particular field only, say 2nd(name), 3rd(designation), 4th(dept) etc.
  * Display two or more fields
  * Store all employee names in a file called `enames`
  * Display only year values from 5th field
* `paste` command usage
  * paste 2 or more files (What's the default delimiter)
  * paste with a custom delimiter
* `sort` command usage
  * sort the lines in a simple file
  * sort the file in reverse order
  * sort the [employee data](data/emp.lst) by name (2nd field)
  * sort the data by designation as primary field, dept as secondary
  * sort the data by designation as primary field, name as secondary
  * sort the data by designation as primary field, empid as secondary
  * sort the data by year value in 5th field
  * Store the output of sort in different file
  * Perform numeric sort, [sample data](data/numbers.dat)
* `uniq` command usage
  * Eliminate adjacent duplicate lines
  * Display unique designations from [employee data](data/emp.lst)
  * Display unique department from [employee data](data/emp.lst)
* `tr` command usage
  * Replace | by any char of your choice in [employee data](data/emp.lst)
  * Replace | by : and / by -
  * Remove all occurences of a) 0 b) space
  * Remove both space and pipe from the data
  * Truncate/squeeze multiple chars by single, e.g. space or 0
  * How to remove blank lines from a file
* `grep` command usage
  * Display all lines having the pattern/keyword director
  * Display line no. also when pattern found
  * Count the no.of lines having the pattern
  * Display the lines not having the pattern
  * Count the no.of lines not having the pattern
  * Display the lines having two or more patterns (either)
  * Display the lines matching for a multi word pattern
  * Display the lines with whole word match, i.e. int in printf shouldn't match ( Refer [test.c](data/test.c) from here )
  * Display lines starting with a pattern, say #inc
  * Display lines ending with a pattern, say {
  * Match exact line (starting & ending with)
  * Match blank lines
  * Perform recursive search with `-r` or `-R` options
* `sed` command usage
  * Substitute one word by other, say manager by supervisor
  * Display a particular range of lines only, say 1-4, 6-10 etc.
  * Remove a particular range of lines
  * Display all lines having a keyword, say sales
  * Remove all lines having a keyword, say sales
  * Substitute manager by supervisor only in line no.s 6-10
  * Substitute manager by supervisor only in sales dept 
    (lines saving sales keyword)
  * Replace int by int32_t in a c file, sample code [test.c](data/test.c)
  * Replace count by kvar in sample code
  * Replace all occurences of a pattern, e.g. 3 occurences of count in for syntax 
  * Replace only second or third occurence

## Activity

> Prepare some other dataset like student information/fligh details and apply mot of the commands

> [Click Here](README.md) to go back to main page
