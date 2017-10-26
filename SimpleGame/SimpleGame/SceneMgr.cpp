#include "stdafx.h"
#include "Define.h"

void SceneMgr::Init()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		Pos pos;
		int k = 1;
		pos.x = rand() % (WINDOW_WIDTH / 2);
		pos.y = rand() % (WINDOW_HEIGHT / 2);
		if (rand() % 2) pos.x = pos.x * -1;
		if (rand() % 2) pos.y = pos.y * -1;
		m_obj[i] = new CObject;
		m_obj[i]->Init(pos, 4, Color(1.0f, 1.0f, 1.0f, 1.0f));
	}

	m_time = GetTickCount();
}


void SceneMgr::AddObject(CObject obj)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_obj[i] == nullptr) {
			m_obj[i] = new CObject;
			m_obj[i]->Init(obj.GetPos(), obj.GetSize(), obj.GetColor());
			return;
		}
	}
}
void SceneMgr::Update(float time)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		for (int j = 0; j < MAX_OBJECTS_COUNT; ++j) {
			if(m_obj[i] != nullptr && m_obj[j] != nullptr)
			if (i != j) m_obj[i]->CheckCollision(m_obj[j]);
		}
		
	}

	if (m_time + 500 < GetTickCount()) {
		for (int k = 0; k < MAX_OBJECTS_COUNT; ++k)
			if(m_obj[k] != nullptr)
			if (m_obj[k]->GetColor().b == 0.0f) m_obj[k]->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
		m_time = GetTickCount();
	}
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_obj[i] != nullptr) {
			if (m_obj[i]->GetLife() <= 0 || m_obj[i]->GetLifeTime() <= 0) {
				delete m_obj[i];
				m_obj[i] = nullptr;

			}
		}
		if (m_obj[i] != nullptr)
		m_obj[i]->Update(time);
	}

}
