#pragma once

class COBject;

#include <Windows.h>
class SceneMgr
{
public:
	void Init();
	void Update();

public:
	CObject* GetObj() { return m_obj; }


private:
	CObject m_obj[MAX_OBJECTS_COUNT];
	DWORD m_time;
};