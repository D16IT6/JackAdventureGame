#include <SFML/Graphics.hpp>

int main()
{
    // T?o m?t c?a s? k�ch thu?c 800x600 pixels
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle");

    // T?o m?t h�nh tr�n m�u d? v?i b�n k�nh 50 pixels
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    
    // �?t v? tr� c?a h�nh tr�n ? gi?a c?a s?
    circle.setPosition(400.f, 300.f);

    // V�ng l?p ch�nh
    while (window.isOpen())
    {
        // X? l� s? ki?n
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // X�a n?n c?a s? (tr�nh hi?n th? tr�ng l?p)
        window.clear();

        // V? h�nh tr�n l�n c?a s?
        window.draw(circle);

        // Hi?n th? n?i dung m?i tr�n c?a s?
        window.display();
    }

    return 0;
}

