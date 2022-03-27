#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Transaction.h>
#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/storage/storageService.hpp>
#include <filesystem>
#include <string>

namespace appcenter::sdk::storage {
bool StorageService::init(const std::string_view path) {
	if (!hasStarted()) {
		getLogger().verbose(logTag, "Initializing storage service");
		std::string dbPath =
		    std::string(path) + "/" + std::string(constants::database_name);

		// open/create the database file
		database = new SQLite::Database(dbPath, SQLite::OPEN_READWRITE |
		                                            SQLite::OPEN_CREATE);
		// init the database if it is empty
		try {
			SQLite::Transaction transaction(*database);
			database->exec(create_table_sql.data());
			transaction.commit();
			getLogger().verbose(logTag, "Storage service initialized");
			return true;
		} catch (const SQLite::Exception &e) {
			getLogger().error(logTag, "Failed to initialize database: " +
			                              std::string(e.what()));
			return false;
		}
	}
	return false;
}
bool StorageService::hasStarted() { return started; }
void StorageService::stopService() {
	if (hasStarted()) {
		getLogger().verbose(logTag, "Stopping storage service");
		if (database) {
			delete database;
			database = nullptr;
			started = false;
		}
	}
}

StorageService::~StorageService() { stopService(); }
} // namespace appcenter::sdk::storage