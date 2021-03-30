#include "Machine.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Machine::Machine()
{
    opMap.emplace("movi", &CreateOp<MovI>);
    opMap.emplace("exit", &CreateOp<Exit>);
    opMap.emplace("add", &CreateOp<Add>);
    opMap.emplace("mov", &CreateOp<Mov>);
    opMap.emplace("sub", &CreateOp<Sub>);
    opMap.emplace("mul", &CreateOp<Mul>);
    opMap.emplace("div", &CreateOp<Div>);
    opMap.emplace("inc", &CreateOp<Inc>);
    opMap.emplace("dec", &CreateOp<Dec>);
    opMap.emplace("jmp", &CreateOp<Jmp>);
    opMap.emplace("cmpeq", &CreateOp<Cmpeq>);
    opMap.emplace("cmplt", &CreateOp<Cmplt>);
    opMap.emplace("jt", &CreateOp<Jt>);
    opMap.emplace("jnt", &CreateOp<Jnt>);
    
    reg.emplace("r0", 0);
    reg.emplace("r1", 0);
    reg.emplace("r2", 0);
    reg.emplace("r3", 0);
    reg.emplace("r4", 0);
    reg.emplace("r5", 0);
    reg.emplace("r6", 0);
    reg.emplace("r7", 0);
    reg.emplace("pc", 0);
    reg.emplace("sc", 0);
    reg.emplace("ex", 0);
    reg.emplace("tx", 0);
    reg.emplace("ty", 0);
    reg.emplace("tr", 0);
    reg.emplace("tc", 0);
    
    flag.emplace("exit", false);
    flag.emplace("test", false);
    flag.emplace("pen", false);
    
}

void Machine::ReadFile(const std::string source)
{
    std::ifstream file(source, std::ios::in);
    std::string line;
    std::string opName;
    std::string params;
    if(file.is_open()){
        while(getline(file,line)){
            std::stringstream ss(line);
            getline(ss, opName, ' ');
            std::shared_ptr<Op> ptr = opMap.at(opName)();
            getline(ss,params, ' ');
            ptr->Parse(params);
            mOps.emplace_back(ptr);
        }
        
    }
}

void Machine::SetReg(std::string name, int val){ reg[name] = val; }

void Machine::SetFlag(std::string name, bool val) { flag[name] = val; }

int Machine::GetRegVal(std::string name) { return reg.at(name); }

bool Machine::GetFlagVal(std::string name) { return flag.at(name); }

void Machine::Execute()
{
    std::ofstream output("log.txt");
    print(output);
    while(flag.at("exit") == false){
        int pcVal = reg.at("pc");
        std::shared_ptr<Op> ptr = mOps.at(pcVal);
        reg["pc"] = pcVal+1;
        output << "Executing: " << ptr->GetName() << std::endl;
        ptr->Execute(*this);
        print(output);
    }
}

void Machine::print(std::ofstream& output)
{

    output << "********************" << std::endl;
    output << "r0=" << reg.at("r0") << std::endl;
    output << "r1=" << reg.at("r1") << std::endl;
    output << "r2=" << reg.at("r2") << std::endl;
    output << "r3=" << reg.at("r3") << std::endl;
    output << "r4=" << reg.at("r4") << std::endl;
    output << "r5=" << reg.at("r5") << std::endl;
    output << "r6=" << reg.at("r6") << std::endl;
    output << "r7=" << reg.at("r7") << std::endl;
    output << "pc=" << reg.at("pc") << std::endl;
    output << "sc=" << reg.at("sc") << std::endl;
    output << "ex=" << reg.at("ex") << std::endl;
    output << "tx=" << reg.at("tx") << std::endl;
    output << "ty=" << reg.at("ty") << std::endl;
    output << "tr=" << reg.at("tr") << std::endl;
    output << "tc=" << reg.at("tc") << std::endl;
    output << "exit=" << flag.at("exit") << std::endl;
    output << "test=" << flag.at("test") << std::endl;
    output << "pen=" << flag.at("pen") << std::endl;
    
}
