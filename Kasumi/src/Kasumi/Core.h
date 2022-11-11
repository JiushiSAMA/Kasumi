#pragma once

#ifdef KSM_PLATFORM_WINDOWS
	#ifdef KSM_BUILD_DLL
		#define KASUMI_API _declspec(dllexport)
	#else
		#define KASUMI_API _declspec(dllimport)
	#endif // KSM_BUILD_DLL
#else
	#error Kasumi only supports Windows!
#endif // KSM_PLATFORM_WINDOWS

