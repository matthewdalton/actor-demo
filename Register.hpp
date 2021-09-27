// -*- mode: c++; c-file-style: "stroustrup" -*-

#pragma once

#include <memory>

#include "Instruction.hpp"

class Factory {
public:
    virtual std::unique_ptr<Instruction> create() = 0;
    virtual std::string name() = 0;
};

template<typename T>
class InstructionFactory : public Factory {
private:
    std::string _name;

public:
    InstructionFactory(const std::string &name)
        : _name(name) {}

    virtual std::unique_ptr<Instruction> create() {
        std::unique_ptr<Instruction> i(new T());
        i->setName(_name);
        return i;
    }

    virtual std::string name() {
        return _name;
    }
};

#define REGISTER_INSTRUCTION(dict, name) dict[ std::string(#name) ] = std::unique_ptr<Factory>(new InstructionFactory<name>(#name))
#define REGISTER_ACTION(dict, name, fn) dict[ std::string(#name) ] = fn
