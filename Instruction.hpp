// -*- mode: c++; c-file-style: "stroustrup" -*-
#pragma once

#include <iostream>

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void doWork() const = 0;
};

class PrintWord : public Instruction {
private:
    std::string _word;
public:
    PrintWord()
        :_word("default word") {}

    explicit PrintWord(std::string const &word)
        :_word(word) {}

    virtual ~PrintWord() {
        std::cout << "PrintWord destructor called" << std::endl;
    }
    virtual void doWork() const override {
        std::cout << "Printing a word: " << _word << std::endl;
    }
};

class AddValues : public Instruction {
private:
    int _a;
    int _b;
public:
    AddValues()
        :_a(0), _b(0) {}

    AddValues(int a, int b)
        :_a(a), _b(b) {}

    virtual ~AddValues() {
        std::cout << "AddValues destructor called" << std::endl;
    }
    virtual void doWork() const override {
        std::cout << "Adding some values: "
                  << _a << " + " << _b << " = " << (_a + _b)
                  << std::endl;
    }
};
