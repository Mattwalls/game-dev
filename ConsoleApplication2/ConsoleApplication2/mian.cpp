#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
int main()
{
	
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::White);
	shape.setOrigin(-80.f, -100.f);
	sf::RectangleShape square(sf::Vector2f(50.f, 10.f));
	square.setOrigin(-50.f, -50.f);
	
	
    while (window.isOpen())
    {
		
        sf::Event event;
		
		sf::FloatRect boundingBox = shape.getGlobalBounds();
		sf::FloatRect boundingBox1 = square.getGlobalBounds();
		if (boundingBox.intersects(boundingBox1))
		{
			cout << "collision";
		}
        while (window.pollEvent(event))
        {
			
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) shape.move(sf::Vector2f(0.f, -1.f));
				if (event.key.code == sf::Keyboard::Down) shape.move(sf::Vector2f(0.f, 1.f));
				if (event.key.code == sf::Keyboard::Left) shape.move(sf::Vector2f(-1.f, 0.f));
				if (event.key.code == sf::Keyboard::Right) shape.move(sf::Vector2f(1.f,0.f));	
			}
			
		}
        window.clear();
        window.draw(shape);
		window.draw(square);
        window.display();
    }

    return 0;
}



//sf::FloatRect boundingBox = entity.getGlobalBounds();

/* check collision with a point
sf::Vector2f point = ...;
if (boundingBox.contains(point))
{
	// collision!
}

// check collision with another box (like the bounding box of another entity)
sf::FloatRect otherBox = ...;
if (boundingBox.intersects(otherBox))
{
	// collision!
}*/