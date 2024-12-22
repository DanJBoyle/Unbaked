#pragma once
#include "ubpch.h"
#include "Unbaked/Core.h"
#include "Unbaked/Events/Event.h"

namespace Unbaked {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Unbaked Engine",
					unsigned int width = 1280, unsigned int height = 720)
					: Title(title), Width(width), Height(height) {}
	};

	// An Interface representing a desktop system based Window
	class UNBAKED_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}