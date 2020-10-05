#include "engine/engine/engine.hpp"
#include <atomic> //garanti des confilts sur W/R de var
#include <chrono>

namespace engine::engine
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
			std::chrono::milliseconds dt(0);
			while (!m_stop)
			{
				auto start = std::chrono::high_resolution_clock::now();
				//Update 


				//Calcul dt
				auto end = std::chrono::high_resolution_clock::now();
				dt = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

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