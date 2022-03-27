#pragma once
#include <appcenter/sdk/service/internalService.hpp>
#include <appcenter/util/mixin/singleton.hpp>
#include <memory>
#include <string_view>

namespace SQLite {
class Database;
}

namespace appcenter::sdk::storage {
class StorageService : public util::mixin::Singleton<StorageService>,
                       public service::InternalService<StorageService> {
	friend class util::mixin::Singleton<StorageService>;
	StorageService() : InternalService("AppCenter") {}

  public:
	bool init(const std::string_view path);
	bool hasStarted();
	void stopService();

	~StorageService();

  private:
	SQLite::Database *database = nullptr;
	static constexpr std::string_view create_table_sql =
	    "CREATE TABLE IF NOT EXISTS "
	    "LogEntry ("
	    "Id INTEGER PRIMARY KEY AUTOINCREMENT,"
	    "Channel TEXT NOT NULL,"
	    "Log TEXT NOT NULL);";

	bool started = false;
};
} // namespace appcenter::sdk::storage