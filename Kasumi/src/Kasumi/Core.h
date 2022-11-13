#pragma once

#ifdef KSM_PLATFORM_WINDOWS
	#ifdef KSM_BUILD_DLL
		#define KASUMI_API __declspec(dllexport)
	#else
		#define KASUMI_API __declspec(dllimport)
	#endif // KSM_BUILD_DLL
#else
	#error Kasumi only supports Windows!
#endif // KSM_PLATFORM_WINDOWS

#ifdef KSM_DEBUG
	#define KSM_ENABLE_ASSERTS
#endif // KSM_DEBUG

#ifdef KSM_ENABLE_ASSERTS
	#define KSM_ASSERT(x, ...) { if(!(x)) { KSM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KSM_CORE_ASSERT(x, ...) { if(!(x)) { KSM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KSM_ASSERT(x, ...)
	#define KSM_CORE_ASSERT(x, ...)
#endif // KSM_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define KSM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
