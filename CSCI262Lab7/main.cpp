/*
 * main.cpp
 *
 * Starter code for the Circle Markers lab, CSCI 262
 */

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main() {
    int players = 0;
    int markers = 0;

    cout << "How many players will there be?" << endl;
    cin >> players;

    cout << endl;
    cout << "What is the highest numbered marker?" << endl;
    cin >> markers;

    cout << endl;

    // Keep track of player scores; players are numbered 1..n.  
    // A map would work fine here, too.
    vector<int> scores(players + 1, 0);

    // This will hold our circle of markers
    list<int> game;

    // initialize the game by putting the 0 marker
    // into the circle; create and initialize some variable 
    // to keep track of current player
    game.push_back(0);
    auto current_marker = game.begin();
    int current_player = 1;

    // Loop over all the rest of the markers
    for (int m = 1; m <= markers; m++) 
    {
	// play the marker and record any scores
        if (m % 23 == 0)
        {
            if (current_player <= players)
            {
                current_player = 1;
            }
            else
            {
                current_player++;
            }
            scores[current_player] += m;
                for (int i = 1; i <= 7; i++)
                {
                    if (current_marker == game.begin())
                    {
                        current_marker = game.end();
                        
                    }
                    else {
                        current_marker--;
                    }
                }
                scores[current_player] += *current_marker;
                auto temp_marker = current_marker++;
                game.erase(current_marker);
                current_marker = temp_marker;
                current_marker++;
            
                current_player++;
        }
        else if (m % 23 != 0)
        {
           
            if (current_marker == game.end())
            {
               current_marker = game.begin();
               ++current_marker;
               if (current_marker == game.end())
               {
                   current_marker = game.begin();
                   ++current_marker;
               }
               else
               {
                   current_marker++;
               }
            }
           else
           {
               current_marker++;
               if (current_marker == game.end())
               {
                    current_marker = game.begin();
               }
               else
               {
                   current_marker++;
               }
           }
            if (current_player <= players)
            {
                current_player = 1;
            }
            else
            {
                current_player++;
            }
           
           game.insert(current_marker, m);
        }
      
	
       
    }

    // game is over, let's see who won, with how many markers
    int high_score = 0;
    int winner = 0;
    for (int i = 0; i < players; i++)
    {
        if (scores[i] > high_score)
        {
            high_score = scores[i];
            winner = i;
        }
    }
 
    cout << "The winner is player " << winner << " with a score of " << high_score << "!" << endl;
}


