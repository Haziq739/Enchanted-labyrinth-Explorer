#pragma once
#include"menu.h"
#include"game.h"
#include<SFML/Audio.hpp>
#include"time.h"
#include"fstream"
class Welcome
{
private:
	Font font;
	Text wel;
	//sf::SoundBuffer sb;
	//sf::Sound background_music;

public:
	Welcome()
	{
		/*sb.loadFromFile("C:\\Users\\LEGEND\\Documents\\Fast\\4 Sem\\Data\\Project\\DS - Project\\Graphics\\Audio\\enchanted tiki 86.wav");
		background_music.setBuffer(sb);
		float speed = 1.0f;
		background_music.setPitch(speed);
		background_music.setVolume(50);
		background_music.setLoop(true);
		*/font.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
		sf::Color custom(255, 255, 255, 255);
		sf::Color outline(102, 0, 204, 250);
		wel.setFont(font);
		wel.setFillColor(custom);
		wel.setOutlineColor(outline);
		wel.setString("Press Enter");
		wel.setCharacterSize(20);
		wel.setPosition(190.f, 400.f);
	}
	void Display_Welcome()
	{

		Sprite FPng;    // Help sprite
		Texture F_texture;
		Music music;
		F_texture.loadFromFile("Graphics/Purple Neon Illustration Game Mode Mouse Pad.png");
		FPng.setTexture(F_texture);
		FPng.setScale(0.3, 0.37);

		SoundBuffer buffer;
		SoundBuffer enter;

		buffer.loadFromFile("Graphics/Audio/backgroundmusic.wav");
		enter.loadFromFile("Graphics/Audio/click.wav");

		sf::Sound sound;
		sound.setBuffer(buffer);
		sound.setVolume(30);

		Sound click;
		click.setBuffer(enter);

		click.setVolume(100);


		// Play the audio stream
		sound.play();


		RenderWindow First(VideoMode(600, 600), "Welcome");
		while (First.isOpen())
		{
			
			//background_music.play();

			Event e1;
			while (First.pollEvent(e1))
			{
				if (e1.type == Event::Closed)
					First.close();
				if (e1.key.code == Keyboard::Escape)
					First.close();
				if (e1.type == Event::KeyReleased)
				{
					if (e1.key.code == Keyboard::Enter)
					{
						//click.play();
						click.play();
						First.close();
						Menu m;
						m.display_menu();
					}
					if (e1.key.code == Keyboard::Q)
					{
						First.close();
					}
				}


			}
			First.clear();
			First.draw(FPng);
			First.draw(wel);
			First.display();
		}
		void update();
	}
	~Welcome()
	{}
};