#include "ubpch.h"
#include "Application.h"

namespace Unbaked {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}