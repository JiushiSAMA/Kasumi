#pragma once

#ifdef KSM_PLATFORM_WINDOWS

extern Kasumi::Application* Kasumi::CreateApplication();

int main(int argc, char** argv)
{
	Kasumi::Log::Init();
	KSM_CORE_WARN("Initialized Log!");
	int a = 5;
	KSM_INFO("Hello! Var={0}", a);

	auto app = Kasumi::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // KSM_PLATFORM_WINDOES

