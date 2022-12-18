#include "config_parser.h"
#include <gtest/gtest.h>

TEST(UT__ConfigParser_F, WithValidJson) {
    constexpr std::size_t kExpectedSize{3};
    ConfigParser config_parser{"./etc/configuration.json"};
    std::optional<std::unordered_map<std::string, std::string>> text_intent_list{config_parser.GetTextAndIntent()};
    EXPECT_TRUE(text_intent_list.has_value());
    EXPECT_EQ(kExpectedSize, text_intent_list.value().size());
}

TEST(UT__ConfigParser_F, WithInValidJson) {
    constexpr std::size_t kExpectedSize{3};
    ConfigParser config_parser{"./etc/invalid_configuration.json"};
    std::optional<std::unordered_map<std::string, std::string>> text_intent_list{config_parser.GetTextAndIntent()};
    EXPECT_FALSE(text_intent_list.has_value());
}