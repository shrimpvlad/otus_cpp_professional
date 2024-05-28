#pragma once

#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <stack>
#include "interface.hpp"

class CommandHandler : public Observable {
public:
    CommandHandler(size_t n) : N(n) {}

    void addCommand(std::string command);
    
    void subscribe(Observer *obs);

    void setTime();

    std::string getTime();

    std::vector<std::string> getOutput();

    void notify();

    void finalize();
private:
    size_t N;
    long long time = -1;
    std::vector<std::string> outputData;
    std::vector<Observer *> m_subs;
    const std::string startDynamicBlock = "{";
    const std::string endDynamicBlock = "}";
    std::stack<std::string> brackets;
};


void CommandHandler::addCommand(std::string command) {
    if (time < 0) setTime();
    if (command == startDynamicBlock) {
        if (brackets.empty()) {
            notify();
        }
        brackets.push(startDynamicBlock);
    }
    else if (command == endDynamicBlock) {
        if (brackets.empty() || brackets.top() != startDynamicBlock) {
            throw std::runtime_error("wrong bracket sequence");
        }
        brackets.pop();
        if (brackets.empty()) {
            notify();
        }
    }
    else {
        outputData.push_back(command);
        if (brackets.empty() && outputData.size() == N) {
            notify();
        }
    }
}

void CommandHandler::subscribe(Observer *obs) {
    m_subs.push_back(obs);
}

void CommandHandler::setTime() {
    time = std::time(nullptr);
}

std::string CommandHandler::getTime() {
    return std::to_string(time);
}

std::vector<std::string> CommandHandler::getOutput() {
    return outputData;
}

void CommandHandler::notify() {
    if (outputData.empty()) return;
    for (auto s : m_subs) {
        s->update();
    }
    outputData.clear();
    time = -1;
}

void CommandHandler::finalize() {
    if (brackets.empty()) {
        notify();
    }
}