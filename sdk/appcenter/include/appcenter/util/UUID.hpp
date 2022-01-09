#pragma once
#include <string>

namespace appcenter {
namespace util {
class UUID {
	std::string m_uuid;

  public:
	/**
	 * @brief Construct a new UUID object with an empty uuid
	 *
	 */
	UUID() = default;
	/**
	 * @brief Construct a new UUID object, doens't check if the uuid is valid
	 *
	 * @param uuid the string representation of the uuid
	 */
	UUID(const std::string &uuid);
	/**
	 * @brief check if the uuid is valid
	 *
	 * @param uuid the uuid string representation to check
	 * @return true  if the uuid is valid
	 * @return false  if the uuid is invalid
	 */
	static bool is_valid(const std::string &uuid);

	/**
	 * @brief generate a new type 4 pseudorandom UUID
	 *
	 * @return UUID the new UUID
	 */
	static UUID generate();
	/**
	 * @brief return the UUID from the string
	 *
	 * @param uuid the string representation of the UUID
	 * @return UUID the UUID
	 * @throws std::invalid_argument if the string is not a valid UUID
	 */
	static UUID from_string(const std::string &uuid);
	/**
	 * @brief return the string representation of the UUID
	 *
	 * @return std::string the string representation of the UUID
	 */
	const std::string &to_string() const;
};
} // namespace util
} // namespace appcenter