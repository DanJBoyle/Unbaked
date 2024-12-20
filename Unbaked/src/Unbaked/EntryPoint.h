#ifdef UB_PlATFORM_WINDOWS

extern Unbaked::Application* Unbaked::CreateApplication();

int main(int argc, char** argv) {

	Unbaked::Log::Init();
	UB_CORE_WARN("Initialized Log!");
	UB_INFO("Hello!");


	auto app = Unbaked::CreateApplication();
	app->Run();
	delete app;
}

#endif