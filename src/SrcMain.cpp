#include "SrcMain.h"
#include <iostream>
#include "Machine.h"

void ProcessCommandArgs(int argc, const char* argv[])
{
    std::string source = argv[1];
    Machine machine = Machine();
    machine.ReadFile(source);
    machine.Execute();
}
