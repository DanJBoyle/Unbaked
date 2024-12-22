#ifdef UB_PlATFORM_WINDOWS
	#ifdef UB_BUILD_DLL
		#define UNBAKED_API __declspec(dllexport)
	#else
		#define UNBAKED_API __declspec(dllimport)
	#endif
#else
	#error Unbaked only supports Windows!
#endif

#ifdef UB_ENABLE_ASSERTS
	#define UB_ASSERT(x, ...) { if(!(x)) { UB_ERROR("Assertion Faid: {0}", __VA_ARGS__); __debugbreak(); } }
	#define UB_CORE_ASSERT(x, ...) { if(!(x)) { UB_CORE_ERROR("Assertion Faid: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define UB_ASSERT(x, ...)
	#define UB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

