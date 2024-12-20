#include "Core.h"

namespace Unbaked {

	class UNBAKED_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}