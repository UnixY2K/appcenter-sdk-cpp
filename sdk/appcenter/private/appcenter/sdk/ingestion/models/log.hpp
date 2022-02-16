#pragma once
#include <appcenter/sdk/ingestion/device.hpp>
#include <appcenter/sdk/util/Date.hpp>
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
	util::date::Date timestamp;
	libUUID::UUID sid;
	std::string distributionGroupId;
	std::string userID;
	Device device;
	std::any tag;
	std::set<std::string> transmissionTargetTokens;

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
	const util::date::Date &getTimestamp() const;

	/**
	 * @brief Set the Timestamp value
	 *
	 * @param timestamp
	 */
	void setTimestamp(const util::date::Date &timestamp);

	/**
	 * @brief Get the Sid value
	 *
	 * @return util::UUID
	 */
	const libUUID::UUID &getSid() const;

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
	 * @brief Get the internal tag for this log.
	 *
	 * @return std::any or nothing if not set
	 */
	const std::any &getTag() const;

	/**
	 * @brief Set the internal tag for this log.
	 *
	 * @param tag tag value of nothing to reset the tag
	 */
	void setTag(const std::any &tag);

	/**
	 * @brief Adds a transmissionTargetToken that this log should be sent to.
	 *
	 * @param transmissionTargetToken
	 */
	void addTransmissionTargetToken(const std::string &transmissionTargetToken);

	/**
	 * @brief Gets all transmission targets that this log should be sent to.
	 *
	 * @return std::set<std::string>
	 */
	const std::set<std::string> &getTransmissionTargetTokens() const;

	/**
	 * @brief compare two logs
	 *
	 * @param other the other log to compare to
	 * @return true if the logs are equal
	 * @return false if the logs are not equal
	 */
	virtual const bool operator==(const Log &other) const = 0;

	virtual ~Log();
};
} // namespace appcenter::sdk::ingestion::model