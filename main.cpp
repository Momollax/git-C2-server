#include "include/httpRequest.hpp"
#include "include/fileManager.hpp"
#include "include/htmlParser.hpp"
#include "include/cmd.hpp"
#include <iostream>

int main() {
    HttpRequest httpRequest;

    std::string url = "https://github.com/Momollax/git-C2-server/issues/1";
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36";

    Cmd cmd;
    HtmlParser htmlParser(cmd); // Passer une instance de Cmd au HtmlParser

    std::string response = httpRequest.get(url, userAgent);
    std::string extractedContent = htmlParser.extractContent(response);

    // Afficher tous les contenus extraits
    const std::vector<std::string>& allContent = cmd.getAllContent();
    std::cout << "All extracted content:\n";
    for (const auto& content : allContent) {
        std::cout << content << std::endl;
    }

    // Afficher le dernier contenu extrait
    const std::string& lastContent = cmd.getLastContent();
    std::cout << "Last extracted content:\n" << lastContent << std::endl;

    FileManager fileManager;
    fileManager.saveToFile(response, "response.txt");

    return 0;
}
