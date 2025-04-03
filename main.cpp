// library
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

// main program
int main()
{
    // keyboard
    sf::Keyboard::Scan keys[] = 
    {
        sf::Keyboard::Scan::Tab,
        sf::Keyboard::Scan::Q,
        sf::Keyboard::Scan::W,
        sf::Keyboard::Scan::E,
        sf::Keyboard::Scan::R,
        sf::Keyboard::Scan::T,
        sf::Keyboard::Scan::Y,
        sf::Keyboard::Scan::U,
        sf::Keyboard::Scan::I,
        sf::Keyboard::Scan::O,
        sf::Keyboard::Scan::P,
        sf::Keyboard::Scan::LBracket,
        sf::Keyboard::Scan::RBracket,
        sf::Keyboard::Scan::Backslash
    };

    // load sound
    sf::SoundBuffer buffer("Sounds/Music Box.mp3");

    // sound
    sf::Sound sound_D1(buffer);  sound_D1.setPitch(std::pow(2, -10/12.f));
    sf::Sound sound_E1(buffer);  sound_E1.setPitch(std::pow(2,  -8/12.f));
    sf::Sound sound_F1(buffer);  sound_F1.setPitch(std::pow(2,  -7/12.f));
    sf::Sound sound_G1(buffer);  sound_G1.setPitch(std::pow(2,  -5/12.f));
    sf::Sound sound_A1(buffer);  sound_A1.setPitch(std::pow(2,  -3/12.f));
    sf::Sound sound_B1(buffer);  sound_B1.setPitch(std::pow(2,  -1/12.f));
    sf::Sound sound_C2(buffer);
    sf::Sound sound_D2(buffer);  sound_D2.setPitch(std::pow(2,   2/12.f));
    sf::Sound sound_E2(buffer);  sound_E2.setPitch(std::pow(2,   4/12.f));
    sf::Sound sound_F2(buffer);  sound_F2.setPitch(std::pow(2,   5/12.f));
    sf::Sound sound_G2(buffer);  sound_G2.setPitch(std::pow(2,   7/12.f));
    sf::Sound sound_A2(buffer);  sound_A2.setPitch(std::pow(2,   9/12.f));
    sf::Sound sound_B2(buffer);  sound_B2.setPitch(std::pow(2,  11/12.f));
    sf::Sound sound_C3(buffer);  sound_C3.setPitch(2.f);

    // create shape of key
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(-1.f);

    // create window
    sf::RenderWindow window(sf::VideoMode({1000, 300}), "Title");

    // disable key repeat
    window.setKeyRepeatEnabled(false);

    // while window is still open
    while (window.isOpen())
    {
        // handle event
        while (std::optional event = window.pollEvent())
        {
            // when close button is release
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
        
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }
        
            // on keyboard press
            else if (auto key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->scancode == keys[0])  sound_D1.play();
                if (key->scancode == keys[1])  sound_E1.play();
                if (key->scancode == keys[2])  sound_F1.play();
                if (key->scancode == keys[3])  sound_G1.play();
                if (key->scancode == keys[4])  sound_A1.play();
                if (key->scancode == keys[5])  sound_B1.play();
                if (key->scancode == keys[6])  sound_C2.play();
                if (key->scancode == keys[7])  sound_D2.play();
                if (key->scancode == keys[8])  sound_E2.play();
                if (key->scancode == keys[9])  sound_F2.play();
                if (key->scancode == keys[10])  sound_G2.play();
                if (key->scancode == keys[11])  sound_A2.play();
                if (key->scancode == keys[12])  sound_B2.play();
                if (key->scancode == keys[13])  sound_C3.play();
            }
        }

        // size of window
        float window_w = window.getView().getSize().x;
        float window_h = window.getView().getSize().y;

        // fill window with color
        window.clear(sf::Color::Black);

        // draw piano
        int key_n = 14;
        float key_w = window_w / key_n;
        for (int i = 0;  i < key_n;  i++)
        {
            // major
            shape.setSize({key_w, window_h});
            shape.setPosition({i * key_w, 0.f});
            if (sf::Keyboard::isKeyPressed(keys[i]))
                shape.setFillColor(sf::Color(0, 170, 255));
            else
                shape.setFillColor(sf::Color::White);
            window.draw(shape);

            // minor
            if (i == 0 or i == 1 or
                i == 3 or i == 4 or i == 5 or
                i == 7 or i == 8 or
                i == 10 or i == 11 or i == 12)
            {
                shape.setSize({key_w/2, window_h*0.6f});
                shape.setPosition({(i - 0.25f) * key_w, 0.f});
                shape.setFillColor(sf::Color::Black);
                window.draw(shape);
            }
        }

        // display
        window.display();
    }

    // program end successfully
    return 0;
}