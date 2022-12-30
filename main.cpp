#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DVD", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape logo(sf::Vector2f(306.0f, 138.0f));
    sf::Texture logoTexture;
    logoTexture.loadFromFile("DVD.png");
    logoTexture.setSmooth(true);
    logo.setTexture(&logoTexture);
    logo.setPosition(50, 50);
    float logoXoffset = 2.0f;
    float logoYoffset = 2.0f;

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == evnt.Closed) {
                window.close();
            }
        }

        int logoX = logo.getPosition().x;
        int logoY = logo.getPosition().y;

        if (logoY == WINDOW_HEIGHT - 170) {
            logoYoffset = -logoYoffset;
        }
        if (logoX == WINDOW_WIDTH - 306) {
            logoXoffset = -logoXoffset;
        }
        if (logoY == 0) {
            logoYoffset = -logoYoffset;
        }
        if (logoX == 0) {
            logoXoffset = -logoXoffset;
        }

        logo.move(logoXoffset, logoYoffset);

        window.clear();
        window.draw(logo);
        window.display();
        window.setFramerateLimit(60);
    }

    return 0;
}