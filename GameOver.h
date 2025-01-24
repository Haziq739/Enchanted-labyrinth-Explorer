#include"game.h"
void GameOver()
{
	Sprite s;
	Texture t;
	t.loadFromFile("Graphics/fin.png");
	s.setScale(0.66, 0.6);
	RenderWindow win(VideoMode(1200, 650), "You Won");
	while (win.isOpen())
	{
		Event eve;
		while (win.pollEvent(eve))
		{
			if (eve.type == Event::Closed)
				win.close();
			if (eve.key.code == Keyboard::Escape)
			{
				win.close();
			}
			if (eve.key.code == Keyboard::Enter)
			{
				win.close();
			}
		}
		win.clear();
		win.draw(s);
		win.display();
	}

}