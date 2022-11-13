workspace "Kasumi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Kasumi/vendor/GLFW/include"
IncludeDir["Glad"] = "Kasumi/vendor/Glad/include"
IncludeDir["ImGui"] = "Kasumi/vendor/imgui"

include "Kasumi/vendor/GLFW"
include "Kasumi/vendor/Glad"
include "Kasumi/vendor/imgui"

project "Kasumi"
	location "Kasumi"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ksmpch.h"
	pchsource "Kasumi/src/ksmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++latest"
		systemversion "latest"

		defines
		{
			"KSM_PLATFORM_WINDOWS",
			"KSM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KSM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KSM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KSM_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kasumi/vendor/spdlog/include",
		"Kasumi/src"
	}

	links
	{
		"Kasumi"
	}

	filter "system:windows"
		cppdialect "C++latest"
		systemversion "latest"

		defines
		{
			"KSM_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "KSM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KSM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KSM_DIST"
		runtime "Release"
		optimize "On"