#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    // Create the main window
     sf::RenderWindow window(sf::VideoMode(1400, 900), "Big Tic Tac Toe");
    // Create the grid lines
    sf::RectangleShape horizontalLine(sf::Vector2f(900, 2));
    sf::RectangleShape verticalLine(sf::Vector2f(2, 900));
    // Draw the horizontal lines
    for (int i = 0; i <= 9; i++)
    {
        horizontalLine.setPosition(0, i * 100);
        window.draw(horizontalLine);
         horizontalLine.setFillColor(sf::Color::Black);
        if (i==2|| i==5)
            {window.draw(horizontalLine);
         horizontalLine.setFillColor(sf::Color::Red);}}
          // Draw the vertical lines
    for (int i = 0; i <= 9; i++)
    {
        verticalLine.setPosition(i * 100, 0);
        window.draw(verticalLine);
        verticalLine.setFillColor(sf::Color::Black);

          if (i==2|| i==5)
            {window.draw(verticalLine);
         verticalLine.setFillColor(sf::Color::Red);}

    }
         // Create the X and O textures
    sf::Texture xTexture;
    xTexture.loadFromFile("Resources\\cross.png");
    sf::Sprite xSprite(xTexture);
    xSprite.setScale(0.5, 0.5);
    sf::Texture oTexture;
    oTexture.loadFromFile("Resources\\circle.png");
    sf::Sprite oSprite(oTexture);
    oSprite.setScale(0.5, 0.5);

        // create the game board
    int board[9][9] = {0};

    // create a variable to keep track of whose turn it is
    int player = 1;
      // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse button press
            if (event.type == sf::Event::MouseButtonPressed)
            {
                int mouseX = sf::Mouse::getPosition(window).x;
                int mouseY = sf::Mouse::getPosition(window).y;

                // Determine which cell was clicked
                int row = -1, col = -1;
                if (mouseX < 100) col = 0;
                else if (mouseX < 200) col = 1;
                else if (mouseX < 300) col = 2;
                else if (mouseX < 400) col = 3;
                else if (mouseX < 500) col = 4;
                else if (mouseX < 600) col = 5;
                else if (mouseX < 700) col = 6;
                else if (mouseX < 800) col = 7;
                else if (mouseX < 900) col = 8;
                if (mouseY < 100) row = 0;
                else if (mouseY < 200) row = 1;
                else if (mouseY < 300) row = 2;
                else if (mouseY < 400) row = 3;
                else if (mouseY < 500) row = 4;
                else if (mouseY < 600) row = 5;
                else if (mouseY < 700) row = 6;
                else if (mouseY < 800) row = 7;
                else if (mouseY < 900) row = 8;

                // If a valid cell was clicked, place the player's symbol there
                if (row != -1 && col != -1 && board[row][col] == 0)
                {
                    board[row][col] = player;
                    player = player == 1 ? 2 : 1;
                }
            }
        }
    }
     // Clear the window
        window.clear(sf::Color::White);

        // Draw the horizontal lines
        for (int i = 0; i <= 9; i++)
        {horizontalLine.setPosition(0, i * 100);
        window.draw(horizontalLine);
         horizontalLine.setFillColor(sf::Color::Black);

            if (i==2|| i==5)
            {window.draw(horizontalLine);
         horizontalLine.setFillColor(sf::Color::Red);}
        }

        // Draw the vertical lines
        for (int i = 0; i <= 9; i++)
        {verticalLine.setPosition(i * 100, 0);
        window.draw(verticalLine);
        verticalLine.setFillColor(sf::Color::Black);

         if (i==2|| i==5)
            {window.draw(verticalLine);
         verticalLine.setFillColor(sf::Color::Red);}
        }

        // Draw the X's and O's
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 1)
                {
                    xSprite.setPosition(j * 100 + 25, i * 100 + 25);
                    window.draw(xSprite);
                }
                else if (board[i][j] == 2)
                {
                    oSprite.setPosition(j * 100 + 25, i * 100 + 25);
                    window.draw(oSprite);
                }
            }
        }
        // Display the current player's turn
        sf::Font font;
        font.loadFromFile("Resources\\font.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(player == 1 ? "X's turn" : "O's turn");
        text.setCharacterSize(40);
        text.setPosition(950, 10);
        text.setFillColor(sf::Color::Blue);
        window.draw(text);


}
