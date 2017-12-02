#pragma once

class COBject;
class Renderer;

#include <Windows.h>
class SceneMgr
{
public:
	void Init();
	void Render();
	void Update(float time);

public:
	CObject** GetRedObj() { return m_obj[0]; }
	int GetRedObjNum() { return m_objCnt[0]; }
	void AddRedObject(CObject obj);
	bool CanAddRedCharacter();
	void AddBlueObject(CObject obj);

private:
	CObject* m_obj[2][MAX_OBJECTS_COUNT];
	DWORD m_time;
	DWORD m_createTime[2];
	int m_objCnt[2];
	Renderer* m_renderer;
	int m_buildingImg[2];
	int m_backImg;
	int m_characterImg[2];
	int m_bulletEffectImg;
};