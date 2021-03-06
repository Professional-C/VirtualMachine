#pragma once
#include "Ops.h"
#include "../img/bitmap_image.hpp"
#include <memory>
#include <vector>
#include <map>

class Machine
{
public:
	Machine();
    void ReadFile(std::string source);
    void SetReg(std::string name, int val);
    void SetFlag(std::string name, bool val);
    int GetRegVal(std::string name);
    bool GetFlagVal(std::string name);
    void Execute();
    void print(std::ofstream& output);
    void printStack(std::ofstream& output);
    int popStack();
    void pushStack(int val);
    int getStack(int index);
    void setStack(int index, int val);
    void fwd(int reg1);
    void setColor();

private:
	std::vector<std::shared_ptr<Op>> mOps;
    std::map<std::string, std::function<std::shared_ptr<Op>()>> opMap;
    std::map<std::string, int> reg;
    std::map<std::string, bool> flag;
    std::vector<int> stack;
    bitmap_image bImage;
    image_drawer iDrawer;
};

template <typename T>
std::shared_ptr<Op> CreateOp() {
    return std::make_shared<T>();
}
