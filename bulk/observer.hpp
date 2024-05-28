#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "observable.hpp"

class FileLog : public Observer {
public:
    FileLog(CommandHandler *handler) : comandHandler{handler} {
        comandHandler->subscribe(this);
    }

    void update() override;
private:
    CommandHandler* comandHandler;
};

class ConsoleLog : public Observer {
public:
    ConsoleLog(CommandHandler *handler) : comandHandler{handler} {
        comandHandler->subscribe(this);
    }

    void update() override;
private:
    CommandHandler* comandHandler;
};


void FileLog::update() {
    std::string filename = "bulk" + comandHandler->getTime() + ".log";
    auto text = comandHandler->getOutput();
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        for (const auto& cmd : text)
            outFile << cmd << "\n";
        outFile.close();
    } else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }
}

void ConsoleLog::update() {
    auto text = comandHandler->getOutput();
    for (const auto& cmd : text)
        std::cout << cmd << std::endl;
}