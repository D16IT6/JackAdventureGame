#include <SFML/Graphics.hpp>

int main()
{
    // T?o m?t c?a s? kích thu?c 800x600 pixels
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle");

    // T?o m?t hình tròn màu d? v?i bán kính 50 pixels
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    
    // Ð?t v? trí c?a hình tròn ? gi?a c?a s?
    circle.setPosition(400.f, 300.f);

    // Vòng l?p chính
    while (window.isOpen())
    {
        // X? lý s? ki?n
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Xóa n?n c?a s? (tránh hi?n th? trùng l?p)
        window.clear();

        // V? hình tròn lên c?a s?
        window.draw(circle);

        // Hi?n th? n?i dung m?i trên c?a s?
        window.display();
    }

    return 0;
}

