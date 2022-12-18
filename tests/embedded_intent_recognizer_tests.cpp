#include "embedded_intent_recognizer.h"
#include "config_parser.h"
#include <gtest/gtest.h>

TEST(UT__EmbeddedIntentRecognizer_F, GetValidIntent) {
    constexpr std::size_t kExpectedIntentsSize{3};
    std::vector<std::string> const kExpectedIntents{"Get Weather", "Get Weather City", "Get Fact"};
    std::vector<std::string> const texts{"What is the weather like today?", "What is the weather like in Paris today?", "Tell me an interesting fact."};
    ConfigParser config_parser{"./etc/configuration.json"};
    std::optional<std::unordered_map<std::string, std::string>> text_intent_list{config_parser.GetTextAndIntent()};
    ASSERT_TRUE(text_intent_list.has_value());
    EXPECT_EQ(3, text_intent_list.value().size());
    EmbeddedIntentRecognizer const intent_recognizer{std::move(text_intent_list.value())};
    for (std::size_t index{0}; index < kExpectedIntentsSize; index++) {
        ASSERT_EQ(kExpectedIntents[index], intent_recognizer.GetIntent(texts[index]));
    }
}

TEST(UT__EmbeddedIntentRecognizer_F, IntentNotExist) {
    std::string const text{"Tell me how to use mictophone?."};
    ConfigParser config_parser{"./etc/configuration.json"};
    std::optional<std::unordered_map<std::string, std::string>> text_intent_list{config_parser.GetTextAndIntent()};
    ASSERT_TRUE(text_intent_list.has_value());
    EXPECT_EQ(3, text_intent_list.value().size());
    EmbeddedIntentRecognizer const intent_recognizer{std::move(text_intent_list.value())};
    EXPECT_FALSE(intent_recognizer.GetIntent(text).has_value());
}