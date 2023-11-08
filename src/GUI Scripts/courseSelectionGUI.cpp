#include "GUI.h"

/*note that i'll probably have to add a parameter
here that keep track of which courses they
have unlocked so far... for now i'll just 
program the default that they should only have
the first one available to them

note for sam: make a new file with a function in it that
just keeps track of all of the unlocked courses

you can call this function whenever the conditions are met
to unlock a new course when the player has finished a course
(the results screen)

the function can just contain a list or something, where
index 0 is for course 1, and so on. make it a list of bools
where true represents unlocked and false represents unlocked
*/
int courseSelection(sf::RenderWindow& window) {
	
	//load in textures and create sprites
	//load background
	sf::Texture background;
	background.loadFromFile("titleBackground.png");

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	//load title
	sf::Texture title;
	title.loadFromFile("title.png");

	sf::Sprite titleSprite;
	titleSprite.setTexture(title);
	titleSprite.setPosition(sf::Vector2f(300.f, 90.f));

	//load flag logo
	sf::Texture logo;
	logo.loadFromFile("logo.png");

	sf::Sprite logoSprite;
	logoSprite.setTexture(logo);
	logoSprite.setPosition(sf::Vector2f(1100.f, 100.f));
	
	//load level selection text
	sf::Texture levelSelection;
	levelSelection.loadFromFile("levelSelectionText.png");

	sf::Sprite levelSelectionSprite;
	levelSelectionSprite.setTexture(levelSelection);
	levelSelectionSprite.setPosition(sf::Vector2f(500.f, 1050.f));

	//load course 1 button (unlocked)
	sf::Texture course1Button;
	course1Button.loadFromFile("course1Button.png");

	sf::Sprite course1ButtonSprite;
	course1ButtonSprite.setTexture(course1Button);
	course1ButtonSprite.setPosition(sf::Vector2f(250.f, 900.f));

	//plus load the locked texture for when they hover (call it locked anyways for consistency)
	sf::Texture course1ButtonLocked;
	course1ButtonLocked.loadFromFile("course1ButtonLockedOrClicked.png");

	//load course 2 button (locked)
	sf::Texture course2ButtonLocked;
	course2ButtonLocked.loadFromFile("course2ButtonLockedOrClicked.png");

	sf::Sprite course2ButtonSprite;
	course2ButtonSprite.setTexture(course2ButtonLocked);
	course2ButtonSprite.setPosition(sf::Vector2f(650.f, 900.f));

	//load course 3 button (locked)
	sf::Texture course3ButtonLocked;
	course3ButtonLocked.loadFromFile("course3ButtonLockedOrClicked.png");

	sf::Sprite course3ButtonSprite;
	course3ButtonSprite.setTexture(course3ButtonLocked);
	course3ButtonSprite.setPosition(sf::Vector2f(1050.f, 900.f));

	//load image previews or locked indicators
	sf::Texture lockedCourse;
	lockedCourse.loadFromFile("lockedCourse.png");

	sf::Sprite course1;
	course1.setTexture(lockedCourse);
	course1.setPosition(sf::Vector2f(250.f, 600.f));

	sf::Sprite course2;
	course2.setTexture(lockedCourse);
	course2.setPosition(sf::Vector2f(650.f, 600.f));

	sf::Sprite course3;
	course3.setTexture(lockedCourse);
	course3.setPosition(sf::Vector2f(1050.f, 600.f));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (mouseHover(window, course1ButtonSprite)) {
			course1ButtonSprite.setTexture(course1ButtonLocked);
		}
		else {
			course1ButtonSprite.setTexture(course1Button);
		}

		window.clear();

		window.draw(backgroundSprite);
		window.draw(titleSprite);
		window.draw(logoSprite);
		window.draw(levelSelectionSprite);
		window.draw(course1ButtonSprite);
		window.draw(course2ButtonSprite);
		window.draw(course3ButtonSprite);
		window.draw(course1);
		window.draw(course2);
		window.draw(course3);

		window.display();
	}
	return 0;
}