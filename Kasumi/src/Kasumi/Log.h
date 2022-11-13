#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Kasumi {

	class KASUMI_API Log
	{
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
#define KSM_CORE_TRACE(...) ::Kasumi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KSM_CORE_INFO(...)  ::Kasumi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KSM_CORE_WARN(...)  ::Kasumi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KSM_CORE_ERROR(...) ::Kasumi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KSM_CORE_CRITICAL(...) ::Kasumi::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define KSM_TRACE(...) ::Kasumi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KSM_INFO(...)  ::Kasumi::Log::GetClientLogger()->info(__VA_ARGS__)
#define KSM_WARN(...)  ::Kasumi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KSM_ERROR(...) ::Kasumi::Log::GetClientLogger()->error(__VA_ARGS__)
#define KSM_CRITICAL(...) ::Kasumi::Log::GetClientLogger()->critical(__VA_ARGS__)
