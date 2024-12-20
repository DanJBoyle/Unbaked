workspace "Unbaked"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Unbaked"
	location "Unbaked"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++23"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"UB_PlATFORM_WINDOWS",
			"UB_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "UB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Unbaked/vendor/spdlog/include",
		"Unbaked/src"
	}

	links {
		"Unbaked"
	}

	filter "system:windows"
		cppdialect "C++23"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"UB_PlATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UB_DIST"
		optimize "On"


