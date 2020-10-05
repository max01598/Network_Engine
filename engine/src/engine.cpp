#include "engine/engine.hpp"
#include <atomic> //garanti des confilts sur W/R de var

namespace engine
{
	class EngineImpl
	{
	public :
		EngineImpl()
		{

		}

		~EngineImpl()
		{
			this->Stop();
		}

		void ParseCommandeLine(int argc, char* argv[])
		{

		}

		void Run()
		{
			if (!this->m_stop)
			{
				return;
			}
			this->m_stop = false;
			while (!m_stop)
			{
				
			}
		}
		void Stop()
		{
			this->m_stop = true;
		}
	private:
		std::atomic_bool m_stop = true;
	};

	Engine::Engine()
	{
		m_impl = std::make_unique<EngineImpl>();
	}

	Engine::~Engine() {
		m_impl = nullptr;
	}

	void Engine::ParseCommandeLine(int argc, char* argv[])
	{
		this->m_impl->ParseCommandeLine(argc, argv);
	}

	void Engine::Run()
	{
		this->m_impl->Run();
	}

	void Engine::Stop()
	{
		this->m_impl->Stop();
	}
}