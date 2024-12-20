#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace Unbaked {
	class UNBAKED_API Log {

	public:
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define UB_CORE_TRACE(...)	::Unbaked::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UB_CORE_INFO(...)	::Unbaked::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UB_CORE_WARN(...)	::Unbaked::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UB_CORE_ERROR(...)	::Unbaked::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UB_CORE_FATAL(...)	::Unbaked::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define UB_TRACE(...)		::Unbaked::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UB_INFO(...)		::Unbaked::Log::GetClientLogger()->info(__VA_ARGS__)
#define UB_WARN(...)		::Unbaked::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UB_ERROR(...)		::Unbaked::Log::GetClientLogger()->error(__VA_ARGS__)
#define UB_FATAL(...)		::Unbaked::Log::GetClientLogger()->fatal(__VA_ARGS__)
