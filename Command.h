#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    int args[7];
    Command()
    {
        for (int i = 0; i<7; i++)
        args[i] = -1;
    }
};




#endif // COMMAND_H
