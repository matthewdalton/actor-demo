// -*- mode: c++; c-file-style: "stroustrup" -*-

#include <memory>
#include <string>

#include "Actor.hpp"
#include "Instruction.hpp"
#include "Register.hpp"

Actor::Actor() {
    register_instructions();
}

Actor::~Actor() {
}

void Actor::register_instructions() {
    REGISTER_INSTRUCTION(_lookup, PrintWord);
    REGISTER_INSTRUCTION(_lookup, AddValues);
}

std::unique_ptr<Instruction> Actor::makeType(std::string const &type) {
    return _lookup[type]->create();
}
