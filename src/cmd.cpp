#include "cmd.hpp"

Cmd::Cmd() : lastContent(""), htmlParser(*this) {}

void Cmd::addContent(const std::string& content) {
    allContent.push_back(content);
    lastContent = content;  // Met à jour lastContent avec la dernière commande ajoutée
}

const std::vector<std::string>& Cmd::getAllContent() const {
    return allContent;
}

const std::string& Cmd::getLastContent() const {
    return lastContent;
}

bool Cmd::addContentIfChanged(const std::string& content) {
    if (content != lastContent) {
        allContent.push_back(content);
        lastContent = content;  // Met à jour lastContent avec la nouvelle commande
        return true;
    }
    return false;
}