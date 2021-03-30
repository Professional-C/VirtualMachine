#pragma once
#include "Parser.hpp"
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>


struct Op // NOLINT
{
	virtual const char* GetName() const = 0;
	virtual void Parse(const std::string& params) = 0;
	virtual void Execute(class Machine& machine) = 0;
	virtual ~Op() = default;
};

template <typename... Args>
struct OpBase : Op
{
    void Parse(const std::string& params) override
    {
        std::vector<std::string> paramV = Split(params);
        std::reverse(paramV.begin(), paramV.end());
        mParameters = ParseStr<Args...>(paramV);
    }

    std::tuple<Args...> mParameters;
};

struct Exit : OpBase<>
{
	const char* GetName() const override { return "exit"; }
	void Execute(class Machine& machine) override;
};

struct MovI : OpBase<std::string, int>
{
	const char* GetName() const override { return "movi"; }
	void Execute(class Machine& machine) override;
};

struct Add : OpBase<std::string, std::string, std::string>
{
    const char* GetName() const override { return "add"; }
    void Execute(class Machine& machine) override;
};

struct Mov : OpBase<std::string, std::string>
{
    const char* GetName() const override { return "mov"; }
    void Execute(class Machine& machine) override;
};

struct Sub : OpBase<std::string, std::string, std::string>
{
    const char* GetName() const override { return "sub"; }
    void Execute(class Machine& machine) override;
};

struct Mul : OpBase<std::string, std::string, std::string>
{
    const char* GetName() const override { return "mul"; }
    void Execute(class Machine& machine) override;
};

struct Div : OpBase<std::string, std::string, std::string>
{
    const char* GetName() const override { return "div"; }
    void Execute(class Machine& machine) override;
};

struct Inc : OpBase<std::string>
{
    const char* GetName() const override { return "inc"; }
    void Execute(class Machine& machine) override;
};

struct Dec : OpBase<std::string>
{
    const char* GetName() const override { return "dec"; }
    void Execute(class Machine& machine) override;
};

struct Jmp : OpBase<std::string>
{
    const char* GetName() const override { return "jmp"; }
    void Execute(class Machine& machine) override;
};

struct Cmpeq : OpBase<std::string, std::string>
{
    const char* GetName() const override { return "cmpeq"; }
    void Execute(class Machine& machine) override;
};

struct Cmplt : OpBase<std::string, std::string>
{
    const char* GetName() const override { return "cmplt"; }
    void Execute(class Machine& machine) override;
};

struct Jt : OpBase<std::string>
{
    const char* GetName() const override { return "jt"; }
    void Execute(class Machine& machine) override;
};

struct Jnt : OpBase<std::string>
{
    const char* GetName() const override { return "jnt"; }
    void Execute(class Machine& machine) override;
};
