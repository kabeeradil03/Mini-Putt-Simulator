#include "GUI.h"

/*note that i'll probably have to add a parameter
here that keep track of which courses they
have unlocked so far... for now i'll just 
program the default that they should only have
the first one available to them

scratch that, the Game Progress class will handle
most of this. they'll be dependent on each other though
*/

int courseSelection(sf::RenderWindow& window, GameProgress game) {
	
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

	//load home button
	sf::Texture homeButton;
	homeButton.loadFromFile("homeButton.png");

	sf::Texture homeButtonClicked;
	homeButtonClicked.loadFromFile("homeButtonClicked.png");

	sf::Sprite homeButtonSprite;
	homeButtonSprite.setTexture(homeButton);
	homeButtonSprite.setPosition(sf::Vector2f(20.f, 20.f));
	
	//load level selection text
	sf::Texture levelSelection;
	levelSelection.loadFromFile("levelSelectionText.png");

	sf::Sprite levelSelectionSprite;
	levelSelectionSprite.setTexture(levelSelection);
	levelSelectionSprite.setPosition(sf::Vector2f(500.f, 1050.f));


	//check the number of courses unlocked
	int numCoursesUnlocked = game.getAmtCourses();

	//load course 1 button
	sf::Texture course1Button;
	course1Button.loadFromFile("course1Button.png");

	sf::Texture course1ButtonLocked;
	course1ButtonLocked.loadFromFile("course1ButtonLockedOrClicked.png");

	sf::Sprite course1ButtonSprite;
	course1ButtonSprite.setTexture(course1Button);
	course1ButtonSprite.setPosition(sf::Vector2f(250.f, 900.f));

	//load course 2 button
	sf::Texture course2ButtonLocked;
	course2ButtonLocked.loadFromFile("course2ButtonLockedOrClicked.png");

	sf::Texture course2Button;
	course2Button.loadFromFile("course2Button.png");

	sf::Sprite course2ButtonSprite;
	course2ButtonSprite.setTexture(course2ButtonLocked);
	if (numCoursesUnlocked >= 2) {
		course2ButtonSprite.setTexture(course2Button);
	}
	course2ButtonSprite.setPosition(sf::Vector2f(650.f, 900.f));

	//load course 3 button
	sf::Texture course3ButtonLocked;
	course3ButtonLocked.loadFromFile("course3ButtonLockedOrClicked.png");

	sf::Texture course3Button;
	course3Button.loadFromFile("course3Button.png");

	sf::Sprite course3ButtonSprite;
	course3ButtonSprite.setTexture(course3ButtonLocked);
	if (numCoursesUnlocked >= 3) {
		course3ButtonSprite.setTexture(course3Button);
	}
	course3ButtonSprite.setPosition(sf::Vector2f(1050.f, 900.f));



	//load image previews or locked indicators
	sf::Texture lockedCourse;
	lockedCourse.loadFromFile("lockedCourse.png");

	sf::Texture emptyStar;
	emptyStar.loadFromFile("starUnfilled.png");

	sf::Texture fullStar;
	fullStar.loadFromFile("starFilled.png");
	
	sf::Texture lvl1Preview;
	lvl1Preview.loadFromFile("lvl1Preview.png");

	sf::Texture lvl2Preview;
	lvl2Preview.loadFromFile("lvl2Preview.png");

	sf::Texture lvl3Preview;
	lvl3Preview.loadFromFile("lvl3Preview.png");

	sf::Sprite course1Sprite;
	course1Sprite.setTexture(lvl1Preview);
	course1Sprite.setPosition(sf::Vector2f(260.f, 600.f));

	//get best score for courses
	int course1Score = game.getAmtC1();
	int course2Score = game.getAmtC2();
	int course3Score = game.getAmtC3();

	sf::Sprite star1;
	star1.setTexture(emptyStar);
	if (course1Score >= 1) {
		star1.setTexture(fullStar);
	}
	star1.setPosition(sf::Vector2f(270.f, 620.f));

	sf::Sprite star2;
	star2.setTexture(emptyStar);
	if (course1Score >= 2) {
		star2.setTexture(fullStar);
	}
	star2.setPosition(sf::Vector2f(330.f, 620.f));

	sf::Sprite star3;
	star3.setTexture(emptyStar);
	if (course1Score >= 3) {
		star3.setTexture(fullStar);
	}
	star3.setPosition(sf::Vector2f(390.f, 620.f));


	sf::Sprite course2Sprite;
	course2Sprite.setTexture(lockedCourse);
	sf::Sprite star4;
	sf::Sprite star5;
	sf::Sprite star6;

	if (numCoursesUnlocked >= 2) {

		course2Sprite.setTexture(lvl2Preview);

		//stars
		star4.setTexture(emptyStar);
		if (course2Score >= 1) {
			star4.setTexture(fullStar);
		}
		star4.setPosition(sf::Vector2f(670.f, 620.f));

		star5.setTexture(emptyStar);
		if (course2Score >= 2) {
			star5.setTexture(fullStar);
		}
		star5.setPosition(sf::Vector2f(730.f, 620.f));

		star6.setTexture(emptyStar);
		if (course2Score >= 3) {
			star6.setTexture(fullStar);
		}
		star6.setPosition(sf::Vector2f(790.f, 620.f));


	}
	course2Sprite.setPosition(sf::Vector2f(650.f, 600.f));

	sf::Sprite course3Sprite;
	course3Sprite.setTexture(lockedCourse);
	sf::Sprite star7;
	sf::Sprite star8;
	sf::Sprite star9;

	if (numCoursesUnlocked >= 3) {

		course3Sprite.setTexture(lvl3Preview);

		//stars
		star7.setTexture(emptyStar);
		if (course3Score >= 1) {
			star7.setTexture(fullStar);
		}
		star7.setPosition(sf::Vector2f(1070.f, 620.f));

		star8.setTexture(emptyStar);
		if (course3Score >= 2) {
			star8.setTexture(fullStar);
		}
		star8.setPosition(sf::Vector2f(1130.f, 620.f));

		star9.setTexture(emptyStar);
		if (course3Score >= 3) {
			star9.setTexture(fullStar);
		}
		star9.setPosition(sf::Vector2f(1190.f, 620.f));


	}
	course3Sprite.setPosition(sf::Vector2f(1050.f, 600.f));


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

			if (clickedButton(window, course1ButtonSprite)) {
				realCourse1(window, game);
			}
		}
		else {
			course1ButtonSprite.setTexture(course1Button);
		}

		//home button functionality
		if (mouseHover(window, homeButtonSprite)) {
			homeButtonSprite.setTexture(homeButtonClicked);

			if (clickedButton(window, homeButtonSprite)) {
				titleScreen(window, game);
			}
		}
		else {
			homeButtonSprite.setTexture(homeButton);
		}

		if (numCoursesUnlocked >= 2) {
			if (mouseHover(window, course2ButtonSprite)) {
				course2ButtonSprite.setTexture(course2ButtonLocked);

				if (clickedButton(window, course2ButtonSprite)) {
					realCourse2(window, game);
				}
			}
			else {
				course2ButtonSprite.setTexture(course2Button);
			}
		}

		if (numCoursesUnlocked >= 3) {
			if (mouseHover(window, course3ButtonSprite)) {
				course3ButtonSprite.setTexture(course3ButtonLocked);

				if (clickedButton(window, course3ButtonSprite)) {
					realCourse3(window, game);
				}
			}
			else {
				course3ButtonSprite.setTexture(course3Button);
			}
		}

		window.clear();

		window.draw(backgroundSprite);
		window.draw(titleSprite);
		window.draw(logoSprite);
		window.draw(levelSelectionSprite);
		window.draw(homeButtonSprite);
		window.draw(course1ButtonSprite);
		window.draw(course2ButtonSprite);
		window.draw(course3ButtonSprite);
		window.draw(course1Sprite);
		window.draw(course2Sprite);
		window.draw(course3Sprite);
		window.draw(star1);
		window.draw(star2);
		window.draw(star3);
		
		//check if you should draw stars for levels 2 and 3
		if (numCoursesUnlocked >= 2) {
			window.draw(star4);
			window.draw(star5);
			window.draw(star6);
		}
		if (numCoursesUnlocked >= 3) {
			window.draw(star7);
			window.draw(star8);
			window.draw(star9);
		}
		window.display();
	}
	return 0;
}