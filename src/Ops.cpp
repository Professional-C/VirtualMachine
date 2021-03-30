#include "Ops.h"
#include "Machine.h"

void Exit::Execute(Machine& machine)
{
    machine.SetFlag("exit", true);
}

void MovI::Execute(Machine& machine)
{
    std::string reg = std::get<0>(mParameters);
    int val = std::get<1>(mParameters);
    machine.SetReg(reg, val);
}

void Add::Execute(Machine &machine)
{
    std::string reg1 = std::get<0>(mParameters);
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    int val3 = machine.GetRegVal(std::get<2>(mParameters));
    machine.SetReg(reg1, val2+val3);
}

void Mov::Execute(Machine &machine)
{
    int val = machine.GetRegVal(std::get<1>(mParameters));
    machine.SetReg(std::get<0>(mParameters), val);
}

void Sub::Execute(Machine &machine)
{
    std::string reg1 = std::get<0>(mParameters);
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    int val3 = machine.GetRegVal(std::get<2>(mParameters));
    machine.SetReg(reg1, val2-val3);
}

void Mul::Execute(Machine &machine)
{
    std::string reg1 = std::get<0>(mParameters);
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    int val3 = machine.GetRegVal(std::get<2>(mParameters));
    machine.SetReg(reg1, val2*val3);
}

void Div::Execute(Machine &machine)
{
    std::string reg1 = std::get<0>(mParameters);
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    int val3 = machine.GetRegVal(std::get<2>(mParameters));
    machine.SetReg(reg1, val2/val3);
}

void Inc::Execute(Machine &machine)
{
    std::string reg = std::get<0>(mParameters);
    int val = machine.GetRegVal(reg);
    machine.SetReg(reg, val+1);
}

void Dec::Execute(Machine &machine)
{
    std::string reg = std::get<0>(mParameters);
    int val = machine.GetRegVal(reg);
    machine.SetReg(reg, val-1);
}

void Jmp::Execute(Machine &machine)
{
    std::string reg = std::get<0>(mParameters);
    int val = machine.GetRegVal(reg);
    machine.SetReg("pc", val);
}

void Cmpeq::Execute(Machine &machine)
{
    int val1 = machine.GetRegVal(std::get<0>(mParameters));
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    machine.SetFlag("test", (val1 == val2));
}

void Cmplt::Execute(Machine &machine)
{
    int val1 = machine.GetRegVal(std::get<0>(mParameters));
    int val2 = machine.GetRegVal(std::get<1>(mParameters));
    machine.SetFlag("test", (val1 < val2));
}

void Jt::Execute(Machine &machine)
{
    bool test = machine.GetFlagVal("test");
    if(test){
        machine.SetReg("pc", machine.GetRegVal(std::get<0>(mParameters)));
    }
}

void Jnt::Execute(Machine &machine)
{
    bool test = machine.GetFlagVal("test");
    if(!test){
        machine.SetReg("pc", machine.GetRegVal(std::get<0>(mParameters)));
    }
}
