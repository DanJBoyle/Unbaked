
#ifdef UB_PlATFORM_WINDOWS
	#ifdef UB_BUILD_DLL
		#define UNBAKED_API __declspec(dllexport)
	#else
		#define UNBAKED_API __declspec(dllimport)
	#endif
#else
	#error Unbaked only supports Windows!
#endif

