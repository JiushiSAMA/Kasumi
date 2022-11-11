#pragma once

#ifdef KSM_PLATFORM_WINDOWS

extern Kasumi::Application* Kasumi::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kasumi::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // KSM_PLATFORM_WINDOES

