#include <Unbaked.h> 

class Sandbox : public Unbaked::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Unbaked::Application* Unbaked::CreateApplication() {
	return new Sandbox();
}