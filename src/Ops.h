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
	// TODO: Fill in
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
