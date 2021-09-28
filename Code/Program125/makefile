#target: dependencies[Syntax]
#   action

# main: main.o Ford.o # This method is prefereed because sometimes we only change one of the cpp files and we don't have to compile every single cpp file each time we run make.
#   g++ main.o Ford.o -o main

# main.o: main.cpp
#   g++ -c main.cpp

# Ford.o: Ford.cpp Ford.hpp
#   g++ -c Ford.cpp

# clean: # Inorder to delete all the generated files.
#   del *.o, main.exe

main: main.cpp Ford.cpp Ford.hpp # This method prevents all the intermediate object files from showing up, but compiles every single cpp file each time we run make.
    g++ -Wall -std=c++17 main.cpp Ford.cpp -o main

clean:
    del main.exe