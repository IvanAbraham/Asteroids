#include "game.h"

namespace Asteroids
{
	Music menuMusic;
	Music gameMusic;

	void ExecuteGame()
	{
		openGame = true;

		Vector2 screenSize = { 1024, 768 };
		InitAudioDevice();
		InitWindow(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), "Asteroids");
	
		InitMenuScreen(screenSize);
		InitGameScreen(screenSize);
		InitCreditsScreen(screenSize);
		InitTutorialScreen(screenSize);
		LoadButtonSound();
		LoadMusic();
		SetExitKey(KEY_NULL);

		while (openGame && !WindowShouldClose())
		{
			Update(screenSize);
			UpdateMusic();

			BeginDrawing();

			Draw(screenSize);

			EndDrawing();
		}

		UnloadMenuTextures();
		UnloadTutorialTextures();
		UnloadCreditsTextures();
		UnloadGame();
		UnloadButtonSound();
		UnloadMusic();

		CloseAudioDevice();
		CloseWindow();
	}

	void LoadMusic()
	{
		float const musicVolume = 0.5f;

		menuMusic = LoadMusicStream("res/music/arpmedia-retro-arcade-game-music-577821.mp3");
		gameMusic = LoadMusicStream("res/music/arpmedia-game-game-music-577822.mp3");

		SetMusicVolume(menuMusic, musicVolume);
		SetMusicVolume(gameMusic, musicVolume);
	}

	void UnloadMusic()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameMusic);
	}

	void UpdateMusic()
	{
		if (currentScreen == Game)
		{
			if (IsMusicStreamPlaying(menuMusic))
			{
				StopMusicStream(menuMusic);
			}

			if (!IsMusicStreamPlaying(gameMusic))
			{
				PlayMusicStream(gameMusic);
			}

			UpdateMusicStream(gameMusic);
		}
		else
		{
			if (IsMusicStreamPlaying(gameMusic))
			{
				StopMusicStream(gameMusic);
			}

			if (!IsMusicStreamPlaying(menuMusic))
			{
				PlayMusicStream(menuMusic);
			}

			UpdateMusicStream(menuMusic);
		}
	}

	void Update(Vector2 screenSize)
	{
		switch (currentScreen)
		{

			case Menu:	
			
				UpdMenuScreen(screenSize);

				break;

			case Game:

				UpdGameScreen(screenSize);

				break;

			case Credits:

				UpdateCreditsScreen();

				break;

			case Tutorial:

				UpdateTuotiralScreen();

				break;

		}
	

	}

	void Draw(Vector2 screenSize)
	{
		switch (currentScreen)
		{

			case Menu:

				DrawMenu(screenSize);

				break;

			case Game:

				DrwGameScreen(screenSize);

				break;

			case Credits:

				DrwCreditsScreen();

				break;

			case Tutorial:

				DrwTutorialScreen();

				break;
		}
	}
}