#pragma once
#include <appcenter/sdk/ingestion/device.hpp>
#include <appcenter/util/Date.hpp>
#include <libuuid/UUID.hpp>
//
#include <any>
#include <optional>
#include <set>
#include <string>
#include <string_view>

namespace appcenter::sdk::ingestion::model {
/**
 * @brief Log class.
 * @remark This interface needs to be JSON serializable.
 */
class Log {
	util::Date timestamp;
	libUUID::UUID sid;
	std::string distributionGroupId;
	std::string userID;
	Device device;

  public:
	/**
	 * @brief Get the Type value
	 *
	 * @return the Type value
	 */
	virtual const std::string_view getType() const = 0;
	/**
	 * @brief Get the Timestamp value
	 *
	 */
	const util::Date& getTimestamp() const;

	/**
	 * @brief Set the Timestamp value
	 *
	 * @param timestamp
	 */
	void setTimestamp(const util::Date &timestamp);

	/**
	 * @brief Get the Sid value
	 *
	 * @return util::UUID
	 */
	const libUUID::UUID& getSid() const;

	/**
	 * @brief Set the Sid value
	 *
	 * @param sid the Sid value to set
	 */
	void setSid(const libUUID::UUID &sid);

	/**
	 * @brief Get the DistributionGroupId value
	 *
	 * @return the DistributionGroupId value
	 */
	const std::string_view getDistributionGroupId() const;

	/**
	 * @brief Set the DistributionGroupId value
	 *
	 * @param distributionGroupId the DistributionGroupId value to set
	 */
	void setDistributionGroupId(const std::string &distributionGroupId);

	/**
	 * @brief Get the userId value
	 *
	 * @return the userId value
	 */
	const std::string_view getUserId() const;

	/**
	 * @brief Set the userId value
	 *
	 * @param userId the userId value to set
	 */
	void setUserId(const std::string &userId);

	/**
	 * @brief Get the Device value
	 *
	 * @return appcenter::common::Device
	 */
	const Device &getDevice() const;

	/**
	 * @brief Set the Device object
	 *
	 * @param device the Device value to set
	 */
	void setDevice(const Device &device);

	/**
	 * @brief Adds a transmissionTargetToken that this log should be sent to.
	 *
	 * @param transmissionTargetToken
	 */
	virtual void
	addTransmissionTargetToken(const std::string &transmissionTargetToken) = 0;

	/**
	 * @brief Gets all transmission targets that this log should be sent to.
	 *
	 * @return std::set<std::string>
	 */
	virtual const std::set<std::string>& getTransmissionTargetTokens() const = 0;

	/**
	 * @brief Get the internal tag for this log.
	 *
	 * @return std::any or nothing if not set
	 */
	virtual const std::optional<std::any> getTag() const = 0;

	/**
	 * @brief Set the internal tag for this log.
	 *
	 * @param tag tag value of nothing to reset the tag
	 */
	virtual void setTag(const std::optional<std::any> &tag) = 0;

	virtual ~Log() = 0;
};
} // namespace appcenter::sdk::ingestion::model