#pragma once
#include <appcenter/common/Device.hpp>
#include <appcenter/util/Date.hpp>
#include <appcenter/util/UUID.hpp>
//
#include <any>
#include <optional>
#include <set>
#include <string>

namespace appcenter {
namespace ingestion {
namespace model {
/**
 * @brief Log class.
 * @remark This interface needs to be JSON serializable.
 */
class Log {
  public:
	/**
	 * @brief Get the Type value
	 *
	 * @return the Type value
	 */
	virtual std::string getType() = 0;
	/**
	 * @brief Get the Timestamp value
	 *
	 */
	virtual util::Date getTimestamp() = 0;

	/**
	 * @brief Set the Timestamp value
	 *
	 * @param timestamp
	 */
	virtual void setTimestamp(util::Date timestamp) = 0;

	/**
	 * @brief Get the Sid value
	 *
	 * @return util::UUID
	 */
	virtual util::UUID getSid() = 0;

	/**
	 * @brief Set the Sid value
	 *
	 * @param sid the Sid value to set
	 */
	virtual void setSid(util::UUID sid) = 0;

	/**
	 * @brief Get the DistributionGroupId value
	 *
	 * @return the DistributionGroupId value
	 */
	virtual std::string getDistributionGroupId() = 0;

	/**
	 * @brief Set the DistributionGroupId value
	 *
	 * @param distributionGroupId the DistributionGroupId value to set
	 */
	virtual void setDistributionGroupId(std::string distributionGroupId) = 0;

	/**
	 * @brief Get the userId value
	 *
	 * @return the userId value
	 */
	virtual std::string getUserId() = 0;

	/**
	 * @brief Set the userId value
	 *
	 * @param userId the userId value to set
	 */
	virtual std::string setUserId(std::string userId) = 0;

	/**
	 * @brief Get the Device value
	 *
	 * @return appcenter::common::Device
	 */
	virtual appcenter::common::Device getDevice() = 0;

	/**
	 * @brief Set the Device object
	 *
	 * @param device the Device value to set
	 */
	virtual void setDevice(appcenter::common::Device device) = 0;

	/**
	 * @brief Adds a transmissionTargetToken that this log should be sent to.
	 *
	 * @param transmissionTargetToken
	 */
	virtual void
	addTransmissionTargetToken(std::string transmissionTargetToken) = 0;

	/**
	 * @brief Gets all transmission targets that this log should be sent to.
	 *
	 * @return std::set<std::string>
	 */
	virtual std::set<std::string> getTransmissionTargetTokens() = 0;

	/**
	 * @brief Get the internal tag for this log.
	 *
	 * @return std::any or nothing if not set
	 */
	virtual std::optional<std::any> getTag() = 0;

	/**
	 * @brief Set the internal tag for this log.
	 *
	 * @param tag tag value of nothing to reset the tag
	 */
	virtual void setTag(std::optional<std::any> tag) = 0;

	virtual ~Log() = 0;
};
} // namespace model
} // namespace ingestion
} // namespace appcenter