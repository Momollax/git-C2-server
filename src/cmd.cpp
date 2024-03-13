#include "cmd.hpp"

Cmd::Cmd() : lastContent(""), htmlParser(*this) {}

void Cmd::addContent(const std::string& content) {
    allContent.push_back(content);
}

const std::vector<std::string>& Cmd::getAllContent() const {
    return allContent;
}

const std::string& Cmd::getLastContent() const {
    return lastContent;
}

bool Cmd::addContentIfChanged(const std::string& content) {
    if (content != lastContent) {
        lastContent = content;
        allContent.push_back(content);
        return true;
    }
    return false;
}
