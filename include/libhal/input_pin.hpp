#pragma once

#include "error.hpp"
#include "units.hpp"

namespace hal {
/**
 * @brief Digital input pin hardware abstraction interface.
 *
 * Use this to read a pin and determine if the voltage on it is HIGH or LOW.
 *
 */
class input_pin
{
public:
  /// Generic settings for input pins
  struct settings
  {
    /// pull resistor for an input pin
    pin_resistor resistor = pin_resistor::pull_up;
  };

  /**
   * @brief Configure the input pin to match the settings supplied
   *
   * @param p_settings - settings to apply to input pin
   * @return status
   * @throws std::errc::invalid_argument if the settings could not be achieved.
   */
  [[nodiscard]] status configure(const settings& p_settings)
  {
    return driver_configure(p_settings);
  }

  /**
   * @brief Read the state of the input pin
   *
   * @return result<bool> - true indicates HIGH voltage level and false
   * indicates LOW voltage level
   */
  [[nodiscard]] result<bool> level()
  {
    return driver_level();
  }

  virtual ~input_pin() = default;

private:
  virtual status driver_configure(const settings& p_settings) = 0;
  virtual result<bool> driver_level() = 0;
};
}  // namespace hal
