#pragma comment(lib, "rpcrt4.lib") // UuidCreate - Minimum supported OS Win 2000
#include <iostream>
#include <string>
#include <windows.h>

namespace appcenter::util::impl {
std::string generateUUID() {
	UUID uuid;
	UuidCreate(&uuid);
	char *str;
	UuidToStringA(&uuid, (RPC_CSTR *)&str);
	std::string uuid_str(str);
	RpcStringFreeA((RPC_CSTR *)&str);
	return uuid_str;
}
} // namespace appcenter::util::impl
