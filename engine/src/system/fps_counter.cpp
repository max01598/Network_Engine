#include "engine/system/fps_counter.hpp"


namespace engine::system
{
	class FPS_counterImpl
	{
	public:
		virtual void Update(std::chrono::milliseconds dt)
		{
			this->m_frames++;
			this->m_totalMilli+=dt;

			if (this->m_totalMilli >= 1s)
			{
				std::cout << "FPS : " << this->m_frames << std::endl;
				this->m_frames = 0;
				this->m_totalMilli = 0ms;
			}
		}

	private:
		int m_frames = 0;
		std::chrono::milliseconds m_totalMilli = 0ms;
	};


	FPS_counter::FPS_counter()
	{
		this->m_impl = std::make_unique<FPS_counterImpl>();
	}

	FPS_counter::~FPS_counter()
	{
		this->m_impl = nullptr;
	}

	void FPS_counter::Update(std::chrono::milliseconds dt)
	{
		this->m_impl->Update(dt);
	}

}