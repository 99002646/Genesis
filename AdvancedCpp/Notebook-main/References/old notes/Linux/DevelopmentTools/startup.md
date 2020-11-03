Alias Commands:

    alias compileDir='g++ -c src/*.c* && mkdir -p obj && mv *.o obj'
    alias compile='g++ -c *.c* && mkdir -p obj && mv *.o obj'
    alias compileTest='g++ -c src/*.c* && g++ -c test/test.cpp && mkdir -p obj && mv *.o obj'
    alias link='mkdir -p bin && g++ obj/*.o -o bin/out'
    alias linkGtest='mkdir -p bin && g++ obj/*.o -lgtest -lgtest_main -lpthread -o bin/out'
    alias run='bin/out'

    alias genMake='cd build && cmake . && cd ..'
    alias build='cd build && make && ./out && cd ..'
    alias runB='build/out'

# how write Alias Name permanently
* code ~/.bashrc
* update the rame
* reopen the terminal

* Example project file Guide [link](../TestProject/README.md)
* Guide to write alias commands[link](../Commands/9_aliasName.md)
