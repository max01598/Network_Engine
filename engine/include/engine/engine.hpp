#pragma once //only once include
#include <memory>

namespace engine
{
	class EngineImpl;
	class Engine
	{
	public:
		static Engine& Instance()
		{
			static Engine m_engine;
			return m_engine;
		}
		~Engine();
		Engine(const Engine& other) = delete;
		Engine(Engine&& other) = delete;

		void ParseCommandeLine(int argc, char* argv[]);
		void Run();
		void Stop();

	private:
		Engine();
		std::unique_ptr<EngineImpl> m_impl;
	};

	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
	}
}