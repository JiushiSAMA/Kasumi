#include <Kasumi.h>

class ExampleLayer : public Kasumi::Layer
{
public:
	ExampleLayer()
		: Layer("Example") { }

	void OnUpdate() override
	{
		KSM_INFO("ExampleLayer::Update");
	}

	void OnEvent(Kasumi::Event& event) override
	{
		KSM_TRACE("{0}", event);
	}
};

class Sandbox :public Kasumi::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Kasumi::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Kasumi::Application* Kasumi::CreateApplication()
{
	return new Sandbox();
}