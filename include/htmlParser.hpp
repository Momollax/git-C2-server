// htmlParser.hpp
#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include <regex>
#include <string>
#include <iostream>
// Forward declaration de la classe Cmd
class Cmd;

class HtmlParser {
public:
    HtmlParser(Cmd& cmd); // Ajouter une référence à Cmd dans le constructeur
    std::string extractContent(const std::string& html);
    void setcmd_number(int i);  // Ajouter le type de retour 'void'
    int getcmd_number();
private:
    std::regex pattern;
    Cmd& cmd; // Ajouter une référence à Cmd
    int cmd_number;
};

#endif // HTMLPARSER_HPP
