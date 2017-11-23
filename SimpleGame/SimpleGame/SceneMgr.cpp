#include "stdafx.h"
#include "Define.h"
#include "Renderer.h"

void SceneMgr::Init()
{
	srand((unsigned)time(NULL));

	m_renderer = new Renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!m_renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	m_createTime[TEAM_RED] = GetTickCount();
	m_createTime[TEAM_BLUE] = 0;

	m_obj[TEAM_RED][0] = new CObject;
	m_obj[TEAM_RED][0]->Init(TEAM_RED, OBJECT_BUILDING, Pos(-(WINDOW_WIDTH / 4.0f), WINDOW_HEIGHT / 3.0f, 0.0f), BUILDING_SIZE, Color(1.0f, 0.0f, 0.0f, 1.0f), LEVEL_SKY);

	m_obj[TEAM_RED][1] = new CObject;
	m_obj[TEAM_RED][1]->Init(TEAM_RED, OBJECT_BUILDING, Pos(0.0f, (WINDOW_HEIGHT / 3.0f) - CHARACTER_SIZE * 2, 0.0f), BUILDING_SIZE, Color(1.0f, 0.0f, 0.0f, 1.0f), LEVEL_SKY);

	m_obj[TEAM_RED][2] = new CObject;
	m_obj[TEAM_RED][2]->Init(TEAM_RED, OBJECT_BUILDING, Pos((WINDOW_WIDTH / 4.0f), WINDOW_HEIGHT / 3.0f, 0.0f), BUILDING_SIZE, Color(1.0f, 0.0f, 0.0f, 1.0f), LEVEL_SKY);


	m_objCnt[TEAM_RED] += 3;

	
	m_obj[TEAM_BLUE][0] = new CObject;
	m_obj[TEAM_BLUE][0]->Init(TEAM_BLUE, OBJECT_BUILDING, Pos(-(WINDOW_WIDTH / 4.0f), -(WINDOW_HEIGHT / 3.0f), 0.0f), BUILDING_SIZE, Color(0.0f, 0.0f, 1.0f, 1.0f), LEVEL_SKY);

	m_obj[TEAM_BLUE][1] = new CObject;
	m_obj[TEAM_BLUE][1]->Init(TEAM_BLUE, OBJECT_BUILDING, Pos(0.0f, -(WINDOW_HEIGHT / 3.0f) + (CHARACTER_SIZE * 2), 0.0f), BUILDING_SIZE, Color(0.0f, 0.0f, 1.0f, 1.0f), LEVEL_SKY);

	m_obj[TEAM_BLUE][2] = new CObject;
	m_obj[TEAM_BLUE][2]->Init(TEAM_BLUE, OBJECT_BUILDING, Pos((WINDOW_WIDTH / 4.0f), -(WINDOW_HEIGHT / 3.0f), 0.0f), BUILDING_SIZE, Color(0.0f, 0.0f, 1.0f, 1.0f), LEVEL_SKY);

	m_objCnt[TEAM_BLUE] += 3;
	
	m_time = GetTickCount();
	
	m_buildingImg[TEAM_RED] = m_renderer->CreatePngTexture("./Resource/Red.png");
	m_buildingImg[TEAM_BLUE] = m_renderer->CreatePngTexture("./Resource/Blue.png");
}


void SceneMgr::AddRedObject(CObject obj)
{
	
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_obj[TEAM_RED][i] == nullptr) {
			m_obj[TEAM_RED][i] = new CObject;
			m_obj[TEAM_RED][i]->Init(obj.GetTeamType(), obj.GetObjType(), obj.GetPos(), obj.GetSize(), obj.GetColor(), LEVEL_GROUND);
			m_objCnt[TEAM_RED]++;
			return;
		}
	}
}

void SceneMgr::AddBlueObject(CObject obj)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_obj[TEAM_BLUE][i] == nullptr) {
			m_obj[TEAM_BLUE][i] = new CObject;
			m_obj[TEAM_BLUE][i]->Init(obj.GetTeamType(), obj.GetObjType(), obj.GetPos(), obj.GetSize(), obj.GetColor(), LEVEL_GROUND);
			m_objCnt[TEAM_BLUE]++;
			return;
		}
	}
}

void SceneMgr::Render()
{
	for(int k = 0; k<2; ++k){
	for (int i = 0; i < m_objCnt[k]; ++i) {
		if (m_obj[k][i] != nullptr) {

			if (m_obj[k][i]->GetObjType() == OBJECT_BUILDING) {
				m_renderer->DrawTexturedRect(m_obj[k][i]->GetPos().x, m_obj[k][i]->GetPos().y, m_obj[k][i]->GetPos().z,
					m_obj[k][i]->GetSize(), m_obj[k][i]->GetColor().r, m_obj[k][i]->GetColor().g,
					m_obj[k][i]->GetColor().b, m_obj[k][i]->GetColor().a, m_buildingImg[k], m_obj[k][i]->GetLevel());

				m_renderer->DrawSolidRectGauge(m_obj[k][i]->GetPos().x, m_obj[k][i]->GetPos().y + m_obj[k][i]->GetSize() / 2.0f, m_obj[k][i]->GetPos().z,
					m_obj[k][i]->GetSize(), m_obj[k][i]->GetSize() / 8.0f, m_obj[k][i]->GetColor().r, m_obj[k][i]->GetColor().g,
					m_obj[k][i]->GetColor().b, m_obj[k][i]->GetColor().a, m_obj[k][i]->GetLife() / BUILDING_LIFE, LEVEL_GOD);

			}
			else {
				m_renderer->DrawSolidRect(m_obj[k][i]->GetPos().x, m_obj[k][i]->GetPos().y, m_obj[k][i]->GetPos().z,
					m_obj[k][i]->GetSize(), m_obj[k][i]->GetColor().r, m_obj[k][i]->GetColor().g,
					m_obj[k][i]->GetColor().b, m_obj[k][i]->GetColor().a, m_obj[k][i]->GetLevel());

				m_renderer->DrawSolidRectGauge(m_obj[k][i]->GetPos().x, m_obj[k][i]->GetPos().y + m_obj[k][i]->GetSize() , m_obj[k][i]->GetPos().z,
					m_obj[k][i]->GetSize(), m_obj[k][i]->GetSize() / 2.0f, m_obj[k][i]->GetColor().r, m_obj[k][i]->GetColor().g,
					m_obj[k][i]->GetColor().b, m_obj[k][i]->GetColor().a, m_obj[k][i]->GetLife() / CHARACTER_LIFE, LEVEL_GOD);
			}

			if (m_obj[k][i]->GetObjType() == OBJECT_BUILDING) {
				for (auto& d : m_obj[k][i]->GetBullet()) {
					m_renderer->DrawSolidRect(d->GetPos().x, d->GetPos().y, d->GetPos().z,
						d->GetSize(), d->GetColor().r, d->GetColor().g,
						d->GetColor().b, d->GetColor().a, m_obj[k][i]->GetLevel());
				}
			}

			if (m_obj[k][i]->GetObjType() == OBJECT_CHARACTER) {
				for (auto& d : m_obj[k][i]->GetArrow()) {
					m_renderer->DrawSolidRect(d->GetPos().x, d->GetPos().y, d->GetPos().z,
						d->GetSize(), d->GetColor().r, d->GetColor().g,
						d->GetColor().b, d->GetColor().a, m_obj[k][i]->GetLevel());
				}
			}

		}
	}
	}

}

bool SceneMgr::CanAddRedCharacter()
{
	if (m_createTime[TEAM_BLUE] + BLUE_CHARACTER_TIME < GetTickCount()) {
		m_createTime[TEAM_BLUE] = GetTickCount();
		return true;
	}

	return false;
}

void SceneMgr::Update(float time)
{

	if (m_createTime[TEAM_RED] + RED_CHARACTER_TIME < GetTickCount()) {
		CObject obj;
		Pos pos;

		pos.x = rand() % WINDOW_WIDTH / 4.0f;
		pos.y = rand() % WINDOW_HEIGHT / 4.0f;
		if (rand() % 2 == 1) pos.x = -pos.x;
		obj.Init(TEAM_RED, OBJECT_CHARACTER, pos, CHARACTER_SIZE, Color(1.0f, 0.0f, 0.0f, 1.0f), LEVEL_GROUND);
		AddRedObject(obj);

		m_createTime[TEAM_RED] = GetTickCount();
	}

	for(int k = 0; k < 2; ++k){
	for (int i = 0; i < m_objCnt[k]; ++i) {
		if (m_obj[k][i] != nullptr && m_obj[k][i]->GetObjType() == OBJECT_BUILDING) { 

			for (int j = 0; j < m_objCnt[(k + 1) % 2]; ++j) {
				// 건물이랑 총알 충돌
				if (m_obj[(k + 1) % 2][j] != nullptr && m_obj[(k + 1) % 2][j]->GetObjType() == OBJECT_BUILDING) {
					for (auto& d : m_obj[(k + 1) % 2][j]->GetBullet()) {
						m_obj[k][i]->CheckCollision(d);
					}
				}
				// 건물이랑 화살 충돌
				if (m_obj[(k + 1) % 2][j] != nullptr && m_obj[(k + 1) % 2][j]->GetObjType() == OBJECT_CHARACTER) {
					for (auto& d : m_obj[(k + 1) % 2][j]->GetArrow()) {
						m_obj[k][i]->CheckCollision(d);
					}

				}
			}
		}

		for (int j = 0; j < m_objCnt[k]; ++j) {
			if (m_obj[k][i] != nullptr && m_obj[k][j] != nullptr && m_obj[k][i] != m_obj[k][j]) {
				if (m_obj[k][i]->GetObjType() == OBJECT_CHARACTER && m_obj[k][j]->GetObjType() == OBJECT_CHARACTER) {
					for (auto& d : m_obj[k][i]->GetArrow()) {
						m_obj[k][j]->CheckCollision(d);
					}
				}
			}

		}
		for (int j = 0; j < m_objCnt[(k + 1) % 2]; ++j) {
			if(m_obj[k][i] != nullptr && m_obj[(k + 1) % 2][j] != nullptr)
			m_obj[k][i]->CheckCollision(m_obj[(k + 1) % 2][j]);
		}
		
	}

	// 삭제
	for (int i = 0; i < m_objCnt[k]; ++i) {
		if (m_obj[k][i] != nullptr) {
			if (m_obj[k][i]->GetLife() <= 0 || m_obj[k][i]->GetLifeTime() <= 0) {
				delete m_obj[k][i];
				m_obj[k][i] = nullptr;
				m_objCnt[k]--;
			}
		}
		if (m_obj[k][i] != nullptr)
		m_obj[k][i]->Update(time);
		
	}
	
	}
	
}
