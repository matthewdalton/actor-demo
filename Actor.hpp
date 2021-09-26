// -*- mode: c++; c-file-style: "stroustrup" -*-

#pragma once

#include <map>
#include <memory>

class Factory;
class Instruction;

class Actor {
private:
    std::map<const std::string, std::unique_ptr<Factory>> _lookup;

public:
    Actor();
    ~Actor();

    void register_instructions();
    std::unique_ptr<Instruction> makeType(std::string const &type);
};
