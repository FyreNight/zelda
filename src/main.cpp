#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/glew.h>
#include <GL/glut.h>
#include "game.hpp"

void AppRender()
{
    Game::INSTANCE.Render();
}

void AppReshape(int width, int height)
{
    Game::INSTANCE.Reshape(width, height);
}

void AppKeyboard(unsigned char key, int x, int y)
{
    Game::INSTANCE.ReadKeyboard(key,x,y,true);
}

void AppKeyboardUp(unsigned char key, int x, int y)
{
    Game::INSTANCE.ReadKeyboard(key,x,y,false);
}

void AppSpecialKeys(int key, int x, int y)
{
    Game::INSTANCE.ReadKeyboard(key,x,y,true);
}

void AppSpecialKeysUp(int key, int x, int y)
{
    Game::INSTANCE.ReadKeyboard(key,x,y,false);
}

void AppMouse(int button, int state, int x, int y)
{
    Game::INSTANCE.ReadMouse(button,state,x,y);
}

void AppIdle()
{
    Game::INSTANCE.Tick();
}

int main(int argc, char** argv)
{
	int res_x,res_y,pos_x,pos_y;

	//GLUT initialization
	glutInit(&argc, argv);

	//RGBA with double buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);

	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	/*pos_x = (res_x>>1)-(Game::WINDOW_WIDTH >>1);
	pos_y = (res_y>>1)-(Game::WINDOW_HEIGHT >>1);*/
    pos_x = 200;
    pos_y = 200;

	glutInitWindowPosition(pos_x, pos_y);
	glutInitWindowSize(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT);
	glutCreateWindow("Zelda");

	GLenum err = glewInit();
	if (GLEW_OK != err)
		Game::Error("GLEW initialization failed", (const char*)glewGetErrorString(err));

	/*glutGameModeString("800x600:32");
	glutEnterGameMode();*/

	// Make the default cursor disappear
	glutSetCursor(GLUT_CURSOR_NONE);

	// Register callback functions
	glutDisplayFunc(AppRender);
    glutReshapeFunc(AppReshape);
	glutKeyboardFunc(AppKeyboard);
	glutKeyboardUpFunc(AppKeyboardUp);
	glutSpecialFunc(AppSpecialKeys);
	glutSpecialUpFunc(AppSpecialKeysUp);
	glutMouseFunc(AppMouse);
	glutIdleFunc(AppIdle);

    Game::INSTANCE.Init();

	glutMainLoop();
}
