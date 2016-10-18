#include <SFML/Graphics.hpp>
#include "TransformNode.h"
		 

int main(int argc, char* argv) {
	sf::RenderWindow window(sf::VideoMode(600, 600), "Taylor Calderone Lab1");

	//Shapes
	sf::RectangleShape body(sf::Vector2<float>(20.0f, 200.0f));
	sf::RectangleShape armLL(sf::Vector2<float>(75.0f, 10.0f));
	sf::RectangleShape armLU(sf::Vector2<float>(75.0f, 10.0f));
	sf::RectangleShape armRL(sf::Vector2<float>(75.0f, 10.0f));
	sf::RectangleShape armRU(sf::Vector2<float>(75.0f, 10.0f));
	sf::CircleShape head(20.0f, 16);
	sf::RectangleShape neck(sf::Vector2<float>(10.0f, 15.0f));

	//Color
	head.setFillColor(sf::Color::Red);
	neck.setFillColor(sf::Color::Red);
	body.setFillColor(sf::Color::Blue);
	armLL.setFillColor(sf::Color::Green); 
	armLU.setFillColor(sf::Color::Green); 
	armRL.setFillColor(sf::Color::Yellow); 
	armRU.setFillColor(sf::Color::Yellow); 

	TransformNode bodyNode(&body); 
	TransformNode neckNode(&neck);
	TransformNode armLNode(&armLL);
	TransformNode armRNode(&armRL);

	bodyNode.Add(&neckNode);
	bodyNode.Add(&armLNode);
	bodyNode.Add(&armRNode);
	neckNode.Add(new TransformNode(&head));
	armLNode.Add(new TransformNode(&armLU));
	armRNode.Add(new TransformNode(&armRU));

	body.setOrigin(10.0f, 200.0f);
	body.move(300.0f, 600.0f);

	//Head
	neck.setOrigin(5.0f, 15.0f);
	neck.move(10.0f, -1.0f);
	head.setOrigin(20.0f, 41.0f);
	head.move(5.0f, 0.0f);

	// Left arm
	armLL.setOrigin(76.0f, 5.0f);
	armLL.move(0.0f, 5.0f);
	armLU.setOrigin(76.0f, 5.0f);
	armLU.move(0.0f, 5.0f);

	// Right arm
	armRL.setOrigin(0.0f, 5.0f);
	armRL.move(21.0f, 5.0f);
	armRU.setOrigin(0.0f, 5.0f);
	armRU.move(76.0f, 5.0f);

	float rotate = 0.05f;

	sf::Event evt;
	while (window.isOpen()) {
		while (window.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) window.close();
		}

		armLL.rotate(0.1);
		armRL.rotate(0.1);
		armRU.rotate(0.1);
		armLU.rotate(0.1);
		neck.rotate(0.1);
		head.rotate(0.1);
		body.rotate(rotate);

		//Rotate body back and forth
		if (rotate < 0 && body.getRotation() < 315.0f && body.getRotation() > 270.0f) rotate = -rotate;
		else if (rotate > 0 && body.getRotation() > 45.0f && body.getRotation() < 90.0f) rotate = -rotate;

		window.clear();
		bodyNode.Draw(&window);
		window.display();
	}

	return 0;
}
