#ifndef EMBEDDED_INTENT_RECOGNIZER_H_
#define EMBEDDED_INTENT_RECOGNIZER_H_

#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

/**
 * @brief The EmbeddedIntentRecognizer class provides the intent for the given
 * text.
 */
class EmbeddedIntentRecognizer final {
public:
  /**
   * @brief Constructor
   *
   * @param text_intent List that contains the text and associated intent
   */
  EmbeddedIntentRecognizer(
      std::unordered_map<std::string, std::string> text_intent) noexcept;
  /**
   * @brief Destructor
   */
  ~EmbeddedIntentRecognizer() noexcept = default;
  EmbeddedIntentRecognizer(EmbeddedIntentRecognizer const &) noexcept = delete;
  EmbeddedIntentRecognizer(EmbeddedIntentRecognizer &&) noexcept = delete;
  EmbeddedIntentRecognizer &
  operator=(EmbeddedIntentRecognizer const &) noexcept = delete;
  EmbeddedIntentRecognizer &
  operator=(EmbeddedIntentRecognizer &&) noexcept = delete;
  /**
   * @brief Returns the intent
   *
   * @param text The text from which the intent to be extracted.
   * @return std::optional<std::string>
   */
  std::optional<std::string> GetIntent(std::string const &text) const noexcept;

private:
  /**
   * @brief The list contains the text and associated intent.
   */
  std::unordered_map<std::string, std::string> text_intent_;
};

#endif