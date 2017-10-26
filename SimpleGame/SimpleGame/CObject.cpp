#include "stdafx.h"
#include "Define.h"

void CObject::Init(Pos pos, float size, Color color)
{
	m_pos = pos;
	m_size = size;
	m_color = color;
	m_life = LIFE;
	m_lifeTime = LIFE_TIME;
	switch (rand() % 8) {
		case 0: m_vPos.x = SPEED; break;
		case 1: m_vPos.x = -SPEED; break;
		case 2: m_vPos.y = SPEED; break;
		case 3: m_vPos.y = -SPEED; break;
		case 4: m_vPos.x = SPEED; m_vPos.y = SPEED; break;
		case 5: m_vPos.x = SPEED; m_vPos.y = -SPEED; break;
		case 6: m_vPos.x = -SPEED; m_vPos.y = SPEED; break;
		case 7: m_vPos.x = -SPEED; m_vPos.y = -SPEED; break;
		
	}


}

bool CObject::CheckCollision(CObject* other)
{
	if (((m_pos.x + (m_size / 2)) > (other->GetPos().x - (m_size / 2))) && // Right 
		((m_pos.x - (m_size / 2)) < (other->GetPos().x + (m_size / 2))) && // Left 
		((m_pos.y + (m_size / 2)) > (other->GetPos().y - (m_size / 2))) && // Top 
		((m_pos.y - (m_size / 2)) < (other->GetPos().y + (m_size / 2)))) { // Bottom 
		this->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
		other->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
		return true;
	}
	
	return false;
}
void CObject::Update(float time)
{

	if ((m_pos.x + (m_size / 2) > WINDOW_WIDTH / 2) || // End of Right 
		((m_pos.x - (m_size / 2) <  WINDOW_WIDTH / 2.0 * -1.0f))) // End of Left 
		m_vPos.x = -m_vPos.x;
	
	if ((m_pos.y + (m_size / 2) > WINDOW_HEIGHT / 2) || // End of Top 
		((m_pos.y - (m_size / 2) <  WINDOW_HEIGHT / 2.0 * -1.0f))) // End of Bottom 
		m_vPos.y = -m_vPos.y;
	
	time = time / 1000.0f;

	m_pos.x = m_pos.x + m_vPos.x * time;
	m_pos.y = m_pos.y + m_vPos.y * time;
	m_pos.z = m_pos.z + m_vPos.z * time;

	m_life= m_life - 1;
	//cout << m_life << endl;
	m_lifeTime -= time;
}