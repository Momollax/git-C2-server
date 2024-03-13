#include "htmlParser.hpp"
#include "cmd.hpp"
HtmlParser::HtmlParser(Cmd& cmd) : pattern("<p dir=\"auto\">(.*?)</p>"), cmd(cmd) {}

std::string HtmlParser::extractContent(const std::string& html) {
    std::smatch matches;
    std::string extractedContent;

    auto words_begin = std::sregex_iterator(html.begin(), html.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        extractedContent += match.str(1);

        // Ajouter la commande extraite à la classe Cmd
        cmd.addContent(match.str(1));
        
        // Afficher la commande ajoutée pour débogage
        std::cout << "Added command to Cmd: " << match.str(1) << std::endl;
    }

    std::cout << "Number of matches: " << std::distance(words_begin, words_end) << std::endl;

    return extractedContent;
}