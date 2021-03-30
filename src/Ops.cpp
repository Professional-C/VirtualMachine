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

void Push::Execute(Machine &machine)
{
    machine.pushStack(machine.GetRegVal(std::get<0>(mParameters)));
    machine.SetReg("sc", machine.GetRegVal("sc")+1);
}

void Pop::Execute(Machine &machine)
{
    machine.SetReg(std::get<0>(mParameters), machine.popStack());
    machine.SetReg("sc", machine.GetRegVal("sc")-1);
}

void Load::Execute(Machine &machine)
{
    int val = machine.getStack(machine.GetRegVal(std::get<1>(mParameters)));
    machine.SetReg(std::get<0>(mParameters), val);
}

void Store::Execute(Machine &machine)
{
    int val = machine.GetRegVal(std::get<1>(mParameters));
    machine.setStack(machine.GetRegVal(std::get<0>(mParameters)), val);
}

void Loadi::Execute(Machine &machine)
{
    int val = machine.getStack(std::get<1>(mParameters));
    machine.SetReg(std::get<0>(mParameters), val);
}

void Storei::Execute(Machine &machine)
{
    int val = machine.GetRegVal(std::get<1>(mParameters));
    machine.setStack(std::get<0>(mParameters), val);
}

void Loadsc::Execute(Machine &machine)
{
    int sc = machine.GetRegVal("sc");
    int reg2 = machine.GetRegVal(std::get<1>(mParameters));
    int index = sc - reg2 - 1;
    int val = machine.getStack(index);
    machine.SetReg(std::get<0>(mParameters), val);
}

void Storesc::Execute(Machine &machine)
{
    int sc = machine.GetRegVal("sc");
    int reg1 = machine.GetRegVal(std::get<0>(mParameters));
    int index = sc - reg1 - 1;
    int val = machine.GetRegVal(std::get<1>(mParameters));
    machine.setStack(index, val);
}
