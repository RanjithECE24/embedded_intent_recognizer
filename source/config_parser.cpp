#include "config_parser.h"
#include <jsoncpp/json/json.h>
#include <algorithm>
#include <iostream>

namespace {

std::string const kText{"Text"};
std::string const kIntent{"Intent"};
std::string const kIntents{"Intents"};

/**
 * @brief Removes the braces from the given string
 * 
 * @param str The input string
 * @return std::string The string does not contain the braces
 */
std::string RemoveBraces(std::string&& str) {
    char characters[]{"{}"};
    for (std::size_t index{0}; index < strlen(characters); index++) {
        str.erase(std::remove(str.begin(), str.end(), characters[index]), str.end());
    }
    return std::move(str);
}

}

ConfigParser::ConfigParser(std::string const& config_file) noexcept : config_file_{config_file} {}

std::optional<std::unordered_map<std::string, std::string>> ConfigParser::GetTextAndIntent() {
    bool valid_configuration{true};
    std::optional<std::unordered_map<std::string, std::string>> result{};
    std::unordered_map<std::string, std::string> text_intent{};
    Json::Reader reader{};
    Json::Value root{};
    reader.parse(config_file_, root);
    std::size_t const size{root[kIntents].size()};
    text_intent.reserve(size);
    Json::Value const intents_texts{root[kIntents]};
    for (Json::Value::ArrayIndex index{0}; index < size; index++) {
        std::string actual_text{intents_texts[index][kText].asString()};
        std::string text{RemoveBraces(std::move(actual_text))};
        std::string intent{std::move(intents_texts[index][kIntent].asString())};
        if (!text.empty() && !intent.empty()) {
            text_intent.insert({std::move(text), std::move(intent)});
        } else {
            std::cerr << "Invalid JSON configuration!\n";
            valid_configuration = false;
            break;
        }
    }

    if (!text_intent.empty() && valid_configuration) {
        result.emplace(std::move(text_intent));
    }
    
    return result;
}