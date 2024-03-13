#ifndef EXECCMD_HPP
#define EXECCMD_HPP

#include "cmd.hpp"

class ExecCmd {
public:
    ExecCmd(const Cmd& cmd);  // Constructeur prenant une référence constante à une instance de Cmd
    void executeLastCmd();

private:
    const Cmd& cmdInstance;  // Référence constante à une instance de Cmd
};

#endif // EXECCMD_HPP