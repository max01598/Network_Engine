#pragma once
#include "engine/common.hpp"

namespace engine::system
{
	class ISystem
	{
	public:
		virtual void Update(std::chrono::milliseconds dt) = 0;
	};
}