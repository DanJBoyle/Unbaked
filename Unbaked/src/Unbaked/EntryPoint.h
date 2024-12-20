#ifdef UB_PlATFORM_WINDOWS

extern Unbaked::Application* Unbaked::CreateApplication();

int main(int argc, char** argv) {
	auto app = Unbaked::CreateApplication();
	app->Run();
	delete app;
}

#endif