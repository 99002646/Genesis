
# C++ Devlopment Commands

## PreRequisite 
* install google test packages before running this

## Step by step compiling Commands
    $ gcc/g++ <cfile_name(.c)> -c                             #Compile syntax
    $ gcc/g++ <cfile_name(.o)> -o <objfile_name> <lifile>     #Linking with other lib
    ./<objfile_name>                                          #Runnig outfile
    
    $ g++ test.cpp -c                                           #Compile cppfile1
    $ g++ pch.cpp -c                                            #Compile cppfile2
    $ g++ test.cpp pch.cpp -c                                   #Compile multiple files
    $ g++ test.o pch.o -lgtest -lgtest_main -lpthread -o out    #linking objt files with gtest
    $ ./out                                                     #execute file
    
## Commands to Run Google Test C++ Code using Cmake and terminal 
    0. Open terminal in the Project Directory

    1. Create cmake file "CMakeLists.txt" with below contents 
        $ touch CMakeLists.txt

    2. <change the testfile name>

    3. Create make file 
        $ cmake CMakeLists.txt
        $ cmake .

    3. Run Makefile to generate executable file 
        $ make

    4. run excutable file 
        $ ./out

#### C make file contents (Copy below contents to CMakeLists.txt )

    cmake_minimum_required(VERSION 2.6)
    
    # Locate GTest
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    # Link runTests with what we want to test and the GTest and pthread library
    add_executable(out test.cpp)   
    target_link_libraries(out ${GTEST_LIBRARIES} pthread)  
