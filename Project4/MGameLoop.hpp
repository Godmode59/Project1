#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "P.hpp"
#include "Kill.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		P player;
		Kill killer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{
			

		}
		void Release()
		{
		}

		void Input()
		{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{
					player.getKeyDowned();
				}
				else
				{
					player.getKeyUped();
				}

		}
		void Update()
		{

		}
		void Render()
		{
			cRenderer.Clear();
			killer.killed = false;
			
			
			cRenderer.MoveCursor(player.x, player.y);
			cRenderer.DrawString("¡à");

			cRenderer.MoveCursor(killer.x, killer.y);
			cRenderer.DrawString("¡â");

			killer.killmove();
			if (killer.x == player.x)
			{
				if (killer.y == player.y)
				{
					killer.killed = true;
				}
			}
			if (killer.x <= 0)
			{
				killer.x = 45;
				killer.killed = false;
			}
			if (killer.killed) 
			{
				cRenderer.Clear();
				cRenderer.DrawString("SuperHotSuperHotSuperHotSuperHotSuperHotSuperHot");
				while (killer.killed)
				{
					if (GetAsyncKeyState(VK_RETURN) & 0x8000 || GetAsyncKeyState(VK_RETURN) & 0x8001)
					{
						killer.killed = false;
					}
				}
				killer.x = 45; killer.y = 10;
			}

			cRenderer.MoveCursor(10, 20);


			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
		}


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
			//this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}