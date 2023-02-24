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

             // win for subgame3
        for (int i = 0; i < 3; i++)
        {
            if (board[i][6] != 0 && board[i][6] == board[i][7] && board[i][7] == board[i][8])
            {
                winner3 = board[i][6];
                break;
            }for (int j = 6; j < 9; j++)
            if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            {
                winner3 = board[0][j];
                break;
            }
        }
        if (board[0][6] != 0 && board[0][6] == board[1][7] && board[1][7] == board[2][8])
        {
            winner3 = board[0][6];
        }
        if (board[0][8] != 0 && board[0][8] == board[1][7] && board[1][7] == board[2][6])
        {
            winner3 = board[0][8];
        }

        // If there is a winner, display the winner
        if (winner3 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner3 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(14*50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        // If the board is full with no winner, it's a tie
        bool tie3 = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    tie3 = false;
                    break;
                }
            }
        }
        if (tie3)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(14*50, 120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner3=3;
        }

            // win for subgame4
         for (int i = 3; i < 6; i++)
        {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                winner4 = board[i][0];
                break;
            }
                for (int j = 0; j < 3; j++)
            {if (board[3][j] != 0 && board[3][j] == board[4][j] && board[4][j] == board[5][j])
            {
                winner4 = board[3][j];
                break;
            }}
        }
        if (board[3][0] != 0 && board[3][0] == board[4][1] && board[4][1] == board[5][2])
        {
            winner4 = board[3][0];
        }
        if (board[3][2] != 0 && board[3][2] == board[4][1] && board[4][1] == board[5][0])
        {
            winner4 = board[3][2];
        }

        // If there is a winner, display the winner
        if (winner4 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner4 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        // If the board is full with no winner, it's a tie
        bool tie4 = true;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    tie4 = false;
                    break;
                }
            }
        }
        if (tie4)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner4=3;
        }

              // win for subgame5
        for (int i = 3; i < 6; i++)
        {
            if (board[i][3] != 0 && board[i][3] == board[i][4] && board[i][4] == board[i][5])
            {
                winner5 = board[i][3];
                break;
            }for (int j = 3; j < 6; j++)
            if (board[3][j] != 0 && board[3][j] == board[4][j] && board[4][j] == board[5][j])
            {
                winner5 = board[3][j];
                break;
            }
        }
        if (board[3][3] != 0 && board[3][3] == board[4][4] && board[4][4] == board[5][5])
        {
            winner5 = board[3][3];
        }
        if (board[3][5] != 0 && board[3][5] == board[4][4] && board[4][4] == board[5][3])
        {
            winner5 = board[3][5];
        }

        // If there is a winner, display the winner
        if (winner5 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner5 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        bool tie5 = true;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] == 0)
                {
                    tie5 = false;
                    break;
                }
            }
        }
        if (tie5)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner5=3;
        }

    // win for subgame6
        for (int i = 3; i < 6; i++)
        {
            if (board[i][6] != 0 && board[i][6] == board[i][7] && board[i][7] == board[i][8])
            {
                winner6 = board[i][6];
                break;
            }for (int j = 6; j < 9; j++)
            if (board[3][j] != 0 && board[3][j] == board[4][j] && board[4][j] == board[5][j])
            {
                winner6 = board[3][j];
                break;
            }
        }
        if (board[3][6] != 0 && board[3][6] == board[4][7] && board[4][7] == board[5][8])
        {
            winner6 = board[3][6];
        }
        if (board[3][8] != 0 && board[3][8] == board[4][7] && board[4][7] == board[5][6])
        {
            winner6 = board[3][8];
        }

        // If there is a winner, display the winner
        if (winner6 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner6 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(14*50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);

        }

        bool tie6 = true;
        for (int i = 3; i < 6; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    tie6 = false;
                    break;
                }
            }
        }
        if (tie6)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(12*50, 3*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner6=3;

        }
        // win for subgame 7
        for (int i = 6; i < 9; i++)
        {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                winner7 = board[i][0];
                break;
            }
                for (int j = 0; j < 3; j++)
            {if (board[6][j] != 0 && board[6][j] == board[7][j] && board[7][j] == board[8][j])
            {
                winner7 = board[6][j];
                break;
            }}
        }
        if (board[6][0] != 0 && board[6][0] == board[7][1] && board[7][1] == board[8][2])
        {
            winner7 = board[6][0];
        }
        if (board[6][2] != 0 && board[6][2] == board[7][1] && board[7][1] == board[8][0])
        {
            winner7 = board[6][2];
        }

        // If there is a winner, display the winner
        if (winner7 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner7 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
        }

        // If the board is full with no winner, it's a tie
        bool tie7 = true;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    tie7 = false;
                    break;
                }
            }
        }
        if (tie7)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner7=3;
        }
         // win for subgame8
        for (int i = 6; i < 9; i++)
        {
            if (board[i][3] != 0 && board[i][3] == board[i][4] && board[i][4] == board[i][5])
            {
                winner8 = board[i][3];
                break;
            }for (int j = 3; j < 6; j++)
            if (board[6][j] != 0 && board[6][j] == board[7][j] && board[7][j] == board[8][j])
            {
                winner8 = board[6][j];
                break;
            }
        }
        if (board[6][3] != 0 && board[6][3] == board[7][4] && board[7][4] == board[8][5])
        {
            winner8 = board[6][3];
        }
        if (board[6][5] != 0 && board[6][5] == board[7][4] && board[7][4] == board[8][3])
        {
            winner8 = board[6][5];
        }

        // If there is a winner, display the winner
        if (winner8 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner8 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);

        }
        bool tie8 = true;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (board[i][j] == 0)
                {
                    tie8 = false;
                    break;
                }
            }
        }
        if (tie8)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(8*50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner8=3;

        }
          // win for subgame9
        for (int i = 6; i < 9; i++)
        {
            if (board[i][6] != 0 && board[i][6] == board[i][7] && board[i][7] == board[i][8])
            {
                winner9 = board[i][6];
                break;
            }for (int j = 6; j < 9; j++)
            if (board[6][j] != 0 && board[6][j] == board[7][j] && board[7][j] == board[8][j])
            {
                winner9 = board[6][j];
                break;
            }
        }
        if (board[6][6] != 0 && board[6][6] == board[7][7] && board[7][7] == board[8][8])
        {
            winner9 = board[6][6];
        }
        if (board[6][8] != 0 && board[6][8] == board[7][7] && board[7][7] == board[8][6])
        {
            winner9 = board[6][8];
        }

        // If there is a winner, display the winner
        if (winner9 != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner9 == 1 ? "X wins!" : "O wins!");
            text.setCharacterSize(48);
            text.setPosition(14*50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);

        }
        bool tie9 = true;
        for (int i = 6; i < 9; i++)
        {
            for (int j = 6; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    tie9 = false;
                    break;
                }
            }
        }
        if (tie9)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(12*50, 6*120);
            text.setFillColor(sf::Color::Green);
            window.draw(text);
            winner9=3;

        }

        int winner=0;
        //win for total game
        if(winner1!=0&&winner1!=3&& winner2==winner1 && winner2==winner3)
           winner = winner1;
           else if(winner4!=0&&winner4!=3&& winner4==winner5 && winner5==winner6)
            winner = winner4;
           else if(winner7!=0&&winner7!=3&& winner8==winner7 && winner8==winner9)
            winner = winner7;
            else if(winner1!=0&&winner1!=3&& winner1==winner4 && winner4==winner7)
             winner = winner1;
            else if(winner2!=0&&winner2!=3&& winner2==winner5 && winner5==winner8)
             winner = winner2;
            else if(winner3!=0&&winner3!=3&& winner3==winner6 && winner6==winner9)
             winner = winner3;
            else if(winner1!=0&&winner1!=3&& winner1==winner5 && winner5==winner9)
             winner = winner1;
            else if(winner3!=0&&winner3!=3&& winner3==winner5 && winner5==winner7)
             winner = winner3;

        // If there is a winner, display the winner and end the game
        if (winner != 0)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString(winner == 1 ? "X wins the game!" : "O wins the game!");
            text.setCharacterSize(48);
            text.setPosition(950, 200);
            text.setFillColor(sf::Color::Blue);
            window.draw(text);
            window.display();
            sf::sleep(sf::seconds(3));
            return 0;
        }

        // If the board is full with no winner, it's a tie
        bool tie;
        if(winner==0&& winner1!=0&& winner2!=0&&winner3!=0&&winner4!=0&&winner5!=0&&winner6!=0&&winner7!=0&&winner8!=0&&winner9!=0)
            tie = true ;


        if (tie)
        {
            sf::Font font;
            font.loadFromFile("Resources\\font.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("It's a tie!");
            text.setCharacterSize(48);
            text.setPosition(950, 200);
            text.setFillColor(sf::Color::Blue);
            window.draw(text);
            window.display();
            sf::sleep(sf::seconds(3));
            return 0;
        }
    // Display everything on the window
        window.display();}


}


