#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include <regex>
#include <string>

// Forward declaration de la classe Cmd
class Cmd;

class HtmlParser {
public:
    HtmlParser(Cmd& cmd); // Ajouter une référence à Cmd dans le constructeur
    std::string extractContent(const std::string& html);

private:
    Cmd& cmd; // Ajouter une référence à Cmd
    std::regex pattern;
};

#endif // HTMLPARSER_HPP
