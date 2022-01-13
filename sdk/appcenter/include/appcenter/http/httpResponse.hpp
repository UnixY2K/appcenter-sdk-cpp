#pragma once
#include <unordered_map>
#include <string>

namespace appcenter {
namespace http {
/**
 * @brief HTTP response.
 *
 */
class HttpResponse {
	/**
	 * @brief HTTP status code.
	 */
	int statusCode;

	/**
	 * @brief HTTP payload.
	 */
	std::string payload;

	/**
	 * @brief HTTP headers.
	 */
	std::unordered_map<std::string, std::string> headers;

  public:
	/**
	 * @brief Init with empty response body.
	 *
	 * @param status HTTP status code.
	 */
	HttpResponse(int status);

	/**
	 * @brief Init.
	 *
	 * @param status  HTTP status code.
	 * @param payload HTTP payload.
	 */
	HttpResponse(int status, std::string payload);

	/**
	 * Init.
	 *
	 * @param status  HTTP status code.
	 * @param payload HTTP payload.
	 * @param headers HTTP responseHeaders.
	 */
	HttpResponse(int status, std::string payload,
	             std::unordered_map<std::string, std::string> headers);

	/**
	 * Get the HTTP status code.
	 *
	 * @return HTTP status code.
	 */
	int getStatusCode();

	/**
	 * Get the HTTP payload (response body).
	 *
	 * @return HTTP payload. Can be empty string.
	 */
	std::string getPayload() { return payload; }

	/**
	 * Get the HTTP headers (response headers).
	 *
	 * @return HTTP headers.
	 */
	std::unordered_map<std::string, std::string> getHeaders() { return headers; }

	bool operator==(const HttpResponse &other);

	std::size_t hashCode();
};
} // namespace http
} // namespace appcenter