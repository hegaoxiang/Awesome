#include "RenderTaskPool.h"
#include <exception>
#include <iostream>
#include <assert.h>


void RenderTasks::loadRender(RendererPtr render)
{
	if (auto it = m_data.find(render->getName()); it == m_data.end())
	{
		m_data.insert(std::make_pair<std::string, RendererPtr>(render->getName(), std::move(render)));
	}
}

void RenderTasks::render()
{
	for (auto& i : m_data)
	{
		try
		{
			if (i.second->m_use)
			{
				i.second->render();
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			m_data.erase(i.second->getName());
			break;
		}
	}
}

void RenderTasks::activeRender(const std::string& name)
{
	assert(m_data.find(name) != m_data.end());
	m_data[name]->m_use = true;
}

void RenderTasks::stopRender(const std::string& name)
{
	assert(m_data.find(name) != m_data.end());
	m_data[name]->m_use = false;
}

void RenderTasks::unloadRender(const std::string& name)
{
	assert(m_data.find(name) != m_data.end());
	m_data.erase(name);
}
