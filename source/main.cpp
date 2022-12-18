#include <iostream>
#include <array>
#include "config_parser.h"
#include "embedded_intent_recognizer.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Missing the configuration file!\n";
        std::cerr << "Usage: " << argv[0] << " <json_configuration_file>\n";
        return EXIT_FAILURE;
    }

    ConfigParser config_parser{argv[1]};
    std::optional<std::unordered_map<std::string, std::string>> text_intent_list{config_parser.GetTextAndIntent()};

    if (!text_intent_list.has_value()) {
        std::cerr << "The JSON configuration file is invalid!\n";
        return EXIT_FAILURE;
    }

    EmbeddedIntentRecognizer const intent_recognizer{std::move(text_intent_list.value())};
    std::array<std::string, 3> const texts{"What is the weather like today?", "What is the weather like in Paris today?", "Tell me an interesting fact."};
    for (auto const& text : texts) {
        std::optional<std::string> const intent{intent_recognizer.GetIntent(text)};
        if (intent.has_value()) {
            std::cout << text << " => " << "Intent: " << intent.value() << '\n';
        }
    }

    return EXIT_SUCCESS;
}