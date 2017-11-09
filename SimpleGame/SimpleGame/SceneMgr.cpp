#include "stdafx.h"
#include "Define.h"
#include "Renderer.h"

void SceneMgr::Init()
{
	srand((unsigned)time(NULL));


	m_obj[0] = new CObject;
	m_obj[0]->Init(OBJECT_BUILDING, Pos(0.0f, 0.0f, 0.0f), BUILDING_SIZE, Color(1.0f, 1.0f, 0.0f, 1.0f));
	m_objCnt = 1;
	m_time = GetTickCount();

	m_renderer = new Renderer(500, 500);
	if (!m_renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	m_buildingImg = m_renderer->CreatePngTexture("./Resource/Building.png");
}


void SceneMgr::AddObject(CObject obj)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_obj[i] == nullptr) {
			m_obj[i] = new CObject;
			m_obj[i]->Init(obj.GetObjType(), obj.GetPos(), obj.GetSize(), obj.GetColor());
			m_objCnt++;
			return;
		}
	}
}

void SceneMgr::Render()
{
	for (int i = 0; i < m_objCnt; ++i) {
		if (m_obj[i] != nullptr) {

			if(m_obj[i]->GetObjType() == OBJECT_BUILDING)
				m_renderer->DrawTexturedRect(m_obj[i]->GetPos().x, m_obj[i]->GetPos().y, m_obj[i]->GetPos().z,
					m_obj[i]->GetSize(), m_obj[i]->GetColor().r, m_obj[i]->GetColor().g,
					m_obj[i]->GetColor().b, m_obj[i]->GetColor().a,m_buildingImg);
			else
			m_renderer->DrawSolidRect(m_obj[i]->GetPos().x, m_obj[i]->GetPos().y, m_obj[i]->GetPos().z,
				m_obj[i]->GetSize(), m_obj[i]->GetColor().r, m_obj[i]->GetColor().g,
				m_obj[i]->GetColor().b, m_obj[i]->GetColor().a);

			if (m_obj[i]->GetObjType() == OBJECT_BUILDING) {
				for (auto& d : m_obj[i]->GetBullet()) {
					m_renderer->DrawSolidRect(d->GetPos().x, d->GetPos().y, d->GetPos().z,
						d->GetSize(), d->GetColor().r, d->GetColor().g,
						d->GetColor().b, d->GetColor().a);
				}
			}

			if (m_obj[i]->GetObjType() == OBJECT_CHARACTER) {
				for (auto& d : m_obj[i]->GetArrow()) {
					m_renderer->DrawSolidRect(d->GetPos().x, d->GetPos().y, d->GetPos().z,
						d->GetSize(), d->GetColor().r, d->GetColor().g,
						d->GetColor().b, d->GetColor().a);
				}
			}

		}
	}

}
void SceneMgr::Update(float time)
{
	for (int i = 0; i < m_objCnt; ++i) {
		if (m_obj[i] != nullptr && m_obj[i]->GetObjType() == OBJECT_BUILDING) {
			for (int j = 0; j < m_objCnt; ++j) {
				if (m_obj[j] != nullptr && m_obj[j]->GetObjType() == OBJECT_CHARACTER) {
					for (auto& d : m_obj[i]->GetBullet()) {
						m_obj[j]->CheckCollision(d);
					}
					for (auto& d : m_obj[j]->GetArrow()) {
						m_obj[i]->CheckCollision(d);
					}
				}
			}
		}

		for (int j = 0; j < m_objCnt; ++j) {
			if (m_obj[i] != nullptr && m_obj[j] != nullptr && m_obj[i] != m_obj[j]) {
				if (m_obj[i]->GetObjType() == OBJECT_CHARACTER && m_obj[j]->GetObjType() == OBJECT_CHARACTER) {
					for (auto& d : m_obj[i]->GetArrow()) {
						m_obj[j]->CheckCollision(d);
					}
				}
			}

		}
		for (int j = 0; j < m_objCnt; ++j) {
			if(m_obj[i] != nullptr && m_obj[j] != nullptr)
			if (i != j) m_obj[i]->CheckCollision(m_obj[j]);
		}
		
	}

	for (int i = 0; i < m_objCnt; ++i) {
		if (m_obj[i] != nullptr) {
			if (m_obj[i]->GetLife() <= 0 || m_obj[i]->GetLifeTime() <= 0) {
				delete m_obj[i];
				m_obj[i] = nullptr;
				m_objCnt--;
			}
		}
		if (m_obj[i] != nullptr)
		m_obj[i]->Update(time);
	}

}
