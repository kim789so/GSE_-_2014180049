#include "stdafx.h"
#include "CObject.h"

#include <iostream>


void CObject::Init(Pos pos, float size, Color color)
{
	m_pos = pos;
	m_size = size;
	m_color = color;

}
void CObject::Update()
{
	Pos pos(0, 1, 0);
	float time = 1.0f / 1000.0f;
	m_pos.x = m_pos.x + pos.x * time;
	m_pos.y = m_pos.y + pos.y * time;
	//std::cout << pos.y * (1 / 1000) << std::endl;
	m_pos.z = m_pos.z + pos.z * time;
}