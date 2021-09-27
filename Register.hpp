// -*- mode: c++; c-file-style: "stroustrup" -*-

#pragma once

#include <memory>

#include "Instruction.hpp"

class Factory {
public:
    virtual std::unique_ptr<Instruction> create() = 0;
};

template<typename T>
class InstructionFactory : public Factory {
public:
    virtual std::unique_ptr<Instruction> create() {
        std::unique_ptr<Instruction> i(new T());
        return i;
    }
};

#define REGISTER_INSTRUCTION(dict, name) dict[ std::string(#name) ] = std::unique_ptr<Factory>(new InstructionFactory<name>)
