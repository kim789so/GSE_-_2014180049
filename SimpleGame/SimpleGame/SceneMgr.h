#pragma once

class COBject;

#include <Windows.h>
class SceneMgr
{
public:
	void Init();
	void Update(float time);

public:
	CObject** GetObj() { return m_obj; }
	void AddObject(CObject obj);

private:
	CObject* m_obj[MAX_OBJECTS_COUNT];
	DWORD m_time;
};