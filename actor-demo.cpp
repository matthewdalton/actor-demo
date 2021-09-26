// -*- mode: c++; c-file-style: "stroustrup" -*-

#include <iostream>
#include <memory>

#include "Actor.hpp"
#include "Instruction.hpp"
#include "ThreadsafeQueue.hpp"


int main() {
    ThreadsafeQueue<std::unique_ptr<Instruction>> queue;

    Actor actor;
    auto pw = actor.makeType("PrintWord");
    auto av = actor.makeType("AddValues");
    
    queue.emplace_back(new PrintWord("foo"));
    queue.emplace_back(new AddValues(3, 8));
    queue.emplace_back(pw.release());
    queue.emplace_back(av.release());

    while (!queue.empty()) {
        std::unique_ptr<Instruction> i = std::move(queue.front());
        queue.pop_front();
        i->doWork();
    }

    return 0;
}
