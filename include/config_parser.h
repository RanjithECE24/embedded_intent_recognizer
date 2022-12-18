#ifndef CONFIG_PARSER_H_
#define CONFIG_PARSER_H_

#include <fstream>
#include <optional>
#include <unordered_map>

/**
 * @brief The ConfigParser class parses the text and associated intent from json
 * file.
 */
class ConfigParser final {
public:
  /**
   * @brief Constructor
   *
   * @param config_file The configuration file path
   */
  ConfigParser(std::string const &config_file) noexcept;
  /**
   * @brief Destructor
   */
  ~ConfigParser() noexcept = default;
  ConfigParser(ConfigParser const &) noexcept = delete;
  ConfigParser(ConfigParser &&) noexcept = delete;
  ConfigParser &operator=(ConfigParser const &) noexcept = delete;
  ConfigParser &operator=(ConfigParser &&) noexcept = delete;
  /**
   * @brief Returns the list of text and associated intent in case of the
   * configuration file is successfully parsed
   *
   * @return std::optional<std::unordered_map<std::string, std::string>> The
   * optional that may contain the list of text and associated intent
   */
  std::optional<std::unordered_map<std::string, std::string>>
  GetTextAndIntent();

private:
  /**
   * @brief The configuration file to be parsed
   */
  std::ifstream config_file_;
};

#endif