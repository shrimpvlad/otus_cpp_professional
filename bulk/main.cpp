#include <iostream>
#include <string>
#include "observer.hpp"
#include "observable.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "invalid number of args" << std::endl;
        exit(1);
    }

    std::size_t blockSize = std::stoi(argv[1]);
    CommandHandler commandHandler(blockSize);

    FileLog file{&commandHandler};
    ConsoleLog console{&commandHandler};

    std::string command;
    while (std::cin >> command) {
        commandHandler.addCommand(command);
    }
    commandHandler.finalize();
}
