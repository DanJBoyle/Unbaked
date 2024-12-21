#include "ubpch.h"
#include "Application.h"

#include "Unbaked/Events/ApplicationEvent.h"
#include "Unbaked/Log.h"


namespace Unbaked {
	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		UB_TRACE(e.ToString());
		while (true);
	}
}