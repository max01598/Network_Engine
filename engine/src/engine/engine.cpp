#include "engine/engine/engine.hpp"
#include <atomic> //garanti des confilts sur W/R de var
#include <chrono>
#include <vector>
#include "engine/system/system.hpp"
#include "engine/system/fps_counter.hpp"

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

		void StartUp()
		{
			this->m_systems.emplace_back(std::make_unique<system::FPS_counter>());
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
				for (auto& system : m_systems)
				{
					system->Update(dt);
				}
			
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
		std::vector<std::unique_ptr<system::ISystem>> m_systems;// on utilise les pointeur car on doit avoir des pointeurs hors ISystem = classe abstraite
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

	void Engine::StartUp()
	{
		this->m_impl->StartUp();
	}
}