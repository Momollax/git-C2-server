#include "execCmd.hpp"
#include <iostream>
#include <cstdlib>  // Pour la fonction système

ExecCmd::ExecCmd(const Cmd& cmd) : cmdInstance(cmd) {}

void ExecCmd::executeLastCmd() {
    const std::string& lastCmd = cmdInstance.getLastContent();

    if (!lastCmd.empty()) {
        std::cout << "Executing last command: " << lastCmd << std::endl;
        // Utilisez ici une méthode appropriée pour exécuter la commande (par exemple, std::system)
        int result = std::system(lastCmd.c_str());

        if (result == 0) {
            std::cout << "Command executed successfully." << std::endl;
        } else {
            std::cerr << "Error executing command." << std::endl;
        }

    } else {
        std::cout << "No commands to execute." << std::endl;
    }
}