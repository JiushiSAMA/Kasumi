#include <Kasumi.h>

class Sandbox :public Kasumi::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

private:

};

Kasumi::Application* Kasumi::CreateApplication()
{
	return new Sandbox();
}