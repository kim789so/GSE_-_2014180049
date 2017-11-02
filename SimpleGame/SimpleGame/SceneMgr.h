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
	CObject** GetObj() { return m_obj; }
	int GetObjNum() { return m_objCnt; }
	void AddObject(CObject obj);

private:
	CObject* m_obj[MAX_OBJECTS_COUNT];
	DWORD m_time;
	int m_objCnt;
	Renderer* m_renderer;
};