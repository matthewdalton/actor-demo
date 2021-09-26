// -*- mode: c++; c-file-style: "stroustrup" -*-

#pragma once

#include <deque>
#include <mutex>

template<typename T>
class ThreadsafeQueue {
private:
    std::deque<T> _data;
    std::mutex _mtx;


public:
    ThreadsafeQueue() {}
    ~ThreadsafeQueue() {}

    bool empty() const {
        return _data.empty();
    }

    T& front() {
        std::lock_guard<std::mutex> lock(_mtx);
        return _data.front();
    }

    const T& front() const {
        std::lock_guard<std::mutex> lock(_mtx);
        return _data.front();
    }

    void push_back( const T& value ) {
        std::lock_guard<std::mutex> lock(_mtx);
        _data.push_back(value);
    }

    template<class... Args>
    void emplace_back(Args&&... args) {
        std::lock_guard<std::mutex> lock(_mtx);
        _data.emplace_back(args...);
    }

    void pop_front() {
        std::lock_guard<std::mutex> lock(_mtx);
        _data.pop_front();
    }
};
