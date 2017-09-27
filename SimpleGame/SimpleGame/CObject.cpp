#include "stdafx.h"
#include "CObject.h"

#include <iostream>


void CObject::Init(Pos pos, float size, Color color)
{
	m_pos = pos;
	m_size = size;
	m_color = color;

}