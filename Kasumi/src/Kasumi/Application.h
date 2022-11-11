#pragma once

#include "Core.h"

namespace Kasumi {

	class KASUMI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

