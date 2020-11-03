## Work Setup

1. Prerequisite Installations 
    1. [vs code editor](https://code.visualstudio.com/Download)
    2. c/c++ extension(Optional)
    3. Update Linux Packages and Dependencies 
        sudo apt-get update
        sudo apt-get dist-upgrade
    4. Bulid Essentials(C/C++ Compiler and Dev. Tool)
        sudo apt update
        sudo apt install build-essential
    5. Debugger
        sudo apt-get install gdb
    6. Cpp Check(Static Analysis)
        sudo apt-get install cppcheck
    7. Valgrind(Dynamic Analysis)
        sudo apt-get install valgrind
    8. CI/CD
        [Git and Github Setup](../Github/Setup.md)
        [Git Actions](../Github/Actions.md)
    9. Unit Testing
        * Cmake 
            sudo apt-get install cmake
            sudo apt-get install build-essential cmake
        * Google Test
            sudo apt-get install libgtest-dev 
            cd /usr/src/gtest 
            sudo cmake CMakeLists.txt 
            sudo make 
            sudo cp *.a /usr/lib 
            sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a 
            sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a
    
### Tools Required
0. IDE or Compiler with Editor
1. Unit Testing Framework
2. Code Style Plugin(Clang or Google)
3. [Code Visualizer](http://www.pythontutor.com/cpp.html#mode=edit)
4. Code Explorer(SourceTrail)
5. Code Quality(Analysis -Staic(Codacy,cppcheck) and Dynamic(valgrind))
6. CI/CD (Genics,github)
7. Documentaion(doxygen)
8. Design Suite(UMl Diagram-draw.io)