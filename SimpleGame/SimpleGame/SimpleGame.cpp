/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Define.h"



SceneMgr g_SceneMgr;

DWORD last = GetTickCount();
DWORD Time = 0;
void RenderScene(void)
{
	DWORD curr = GetTickCount();
	Time = curr - last;
	last = curr;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	g_SceneMgr.Render();

	g_SceneMgr.Update((float)Time);
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
	g_SceneMgr.Update((float)Time);
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (g_SceneMgr.GetObjNum() < MAX_CHARACTER_NUM + 1) {
			Pos pos(x, y, 0.0f);
			pos.x = x - 250.0f;
			pos.y = 250.0f - y;
			CObject obj;
			obj.Init(OBJECT_CHARACTER, pos, CHARACTER_SIZE, Color(1.0f, 1.0f, 1.0f, 1.0f));
			g_SceneMgr.AddObject(obj);
		}

	}

	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();

	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_SceneMgr.Init();

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();


    return 0;
}

