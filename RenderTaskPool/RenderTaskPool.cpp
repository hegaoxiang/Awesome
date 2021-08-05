#include "RenderTaskPool.h"
#include <exception>
#include <iostream>

void RenderTasks::addRender(RendererPtr render)
{
	m_data.push_back(std::move(render));
}

void RenderTasks::render()
{
	for (int i = 0 ;i < m_data.size();i++)
	{
		try
		{
			m_data[i]->render();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			m_data.erase(m_data.begin() + i);
			break;
		}
	}
}
