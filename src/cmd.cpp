#include "cmd.hpp"

void Cmd::addContent(const std::string& content) {
    allContent.push_back(content);
}

const std::vector<std::string>& Cmd::getAllContent() const {
    return allContent;
}

const std::string& Cmd::getLastContent() const {
    if (!allContent.empty()) {
        return allContent.back();
    } else {
        static const std::string emptyString;
        return emptyString;
    }
}