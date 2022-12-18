#include "embedded_intent_recognizer.h"

EmbeddedIntentRecognizer::EmbeddedIntentRecognizer(std::unordered_map<std::string, std::string> text_intent) noexcept : text_intent_{std::move(text_intent)} {}

std::optional<std::string> EmbeddedIntentRecognizer::GetIntent(std::string const& text) const noexcept {
    std::optional<std::string> result{};
    auto const itr{text_intent_.find(text)};
    if (itr != text_intent_.end()) {
        result.emplace(itr->second);
    }
    return result;
}