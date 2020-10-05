#pragma once
#include "engine/common.hpp"
#include "system.hpp"

namespace engine::system
{
	class FPS_counterImpl;
	class FPS_counter : public ISystem
	{
	public:
		FPS_counter();
		virtual ~FPS_counter();

		FPS_counter(const FPS_counter& other) = delete;
		FPS_counter(FPS_counter&& other) = delete;

		virtual void Update(std::chrono::milliseconds dt) override;

	private:
		std::unique_ptr<FPS_counterImpl> m_impl;

	};
}