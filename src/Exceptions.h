#pragma once
#include <exception>

class FatalException : public virtual std::exception
{
public:
    FatalException(int error);
    const char* what() const noexcept override { return "Fatal Exception"; }
    int errorCode;
};

class NonFatalException : public virtual std::exception
{
public:
    NonFatalException(int error);
    const char* what() const noexcept override { return "Nonfatal Exception"; }
    int errorCode;
};


