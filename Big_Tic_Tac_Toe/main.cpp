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
    
    
     // Check for a winner
        int winner1 = 0;
        int winner2 = 0;
        int winner3 = 0;
        int winner4 = 0;
        int winner5 = 0;
        int winner6 = 0;
        int winner7 = 0;
        int winner8 = 0;
        int winner9 = 0;
        // win for subgame1
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                winner1 = board[i][0];
                break;
            }
            if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                winner1 = board[0][i];
                break;
            }
        }
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner1 = board[0][0];
        }
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner1 = board[0][2];
        }

        // If there is a winner, display the winner
        if (winner1 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner1 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        // If the board is full with no winner, it's a tie
        bool tie1 = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    tie1 = false;
                    break;
                }
            }
        }
        if (tie1)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner1=3;
        }
    
     // win for subgame2
        for (int i = 0; i < 3; i++)
        {
            if (board[i][3] != 0 && board[i][3] == board[i][4] && board[i][4] == board[i][5])
            {
                winner2 = board[i][3];
                break;
            }for (int j = 3; j < 6; j++)
            if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            {
                winner2 = board[0][j];
                break;
            }
        }
        if (board[0][3] != 0 && board[0][3] == board[1][4] && board[1][4] == board[2][5])
        {
            winner2 = board[0][3];
        }
        if (board[0][5] != 0 && board[0][5] == board[1][4] && board[1][4] == board[2][3])
        {
            winner2 = board[0][5];
        }

        // If there is a winner, display the winner
        if (winner2 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner2 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        // If the board is full with no winner
        bool tie2 = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] == 0)
                {
                    tie2 = false;
                    break;
                }
            }
        }
        if (tie2)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner2=3;
        }


}
