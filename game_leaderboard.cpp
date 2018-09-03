/*
	FileName: game_leaderboard.cpp
	Author: Hayoung Jeon
	UIN: 125009733
	Date: 9/2/2018
	Description: Keeps track of video game players, 
	what hames they play, their activity in those games, 
	and friendships between players.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>

using namespace std;



struct PLAYER {
	int id;
	string name;

	vector<int> friends; //game friends of the player
	vector<string> games; //games the player played
	vector<string> IGNS; //IGNs of the player for each game
	vector<int> victory = {0, 0, 0, 0, 0}; //number of victory of the player
	vector<int> point = {0, 0, 0, 0, 0}; //the list of point for each game
    vector<int> wingames;
    vector<int> victories;
};

vector<PLAYER> playerlist;

struct GAME {
	int id;
	string name;
	string IGN;
    vector<int> playerIDs;
    vector<string> playerIGNs;
};

vector<GAME> gamelist;

struct VICTORY {
	int game_id, victory_id, points;
	string name;
};

vector<VICTORY> victorylist;

void AddPlayer(vector<string> input) {
	PLAYER player;

	stringstream ss(input[1]);
	ss >> player.id;
	player.name = input[2];
	
	playerlist.push_back(player);
}

void AddGame(vector<string> input) {
	GAME game;
	
	stringstream ss(input[1]);
	ss >> game.id;
	game.name = input[2];

	gamelist.push_back(game);
}

void AddVictory(vector<string> input) {
	VICTORY victory;
	stringstream ss(input[1]);
	ss >> victory.game_id;
	stringstream st(input[2]);
	st >> victory.victory_id;
	victory.name = input[3];
	stringstream su(input[4]);
	su >> victory.points;

	victorylist.push_back(victory);
}

void Plays(vector<string> input, PLAYER player, GAME game, int nump) {
	playerlist[nump].games.push_back(game.name);
	playerlist[nump].IGNS.push_back(input[3]);
}

void AddFriends(int p1, int p2) {
    // cout << "ADD FRIENDS2: " << p1 << ", " << p2 << endl;
    for (int i=0; i < playerlist.size(); i++) {
        if (playerlist[i].id == p1) {
            playerlist[i].friends.push_back(p2);
            cout << "ADD FRIENDS2: " << p1 << "(" << playerlist[i].name << ", " << p2 << ", " << playerlist[i].friends.size() << endl;
        }
        if (playerlist[i].id == p2) {
            playerlist[i].friends.push_back(p1);
            cout << "ADD FRIENDS2: " << p2 << "(" << playerlist[i].name << ", " << p1 << ", " << playerlist[i].friends.size() << endl;
        }
    }
}

void WinVictory(PLAYER player, GAME game, int point, int nump, int numg, int numv) {
	cout << point << endl;
	switch (game.id) {
		
	case 4001 :
		
		player.victory[0] += 1;
		player.point[0] += point;
		break;
	case 4002:
		player.victory[1] += 1;
		player.point[1] += point;
	case 4003:
		player.victory[2] += 1;
		player.point[2] += point;
	case 4004:
		player.victory[3] += 1;
		player.point[3] += point;
	case 4005:
		player.victory[4] += 1;
		player.point[4] += point;
	}
}

void FriendswhoPlay(PLAYER player, GAME game) {
    /*
	for (int i = 0; i < player.friends.size(); i++) {
		for (int j = 0; j < playerlist.size(); j++) {
			if (playerlist[j].name.find(player.friends[i]) == 0) {
				cout << player.name << "'s friend " << player.friends[i] << " has played " << game.name << endl;
			}
		}
	}
    */
}

void ComparePlayers(PLAYER player1, PLAYER player2, GAME game) {

}

void SummarizePlayer(PLAYER player) {

}

void SummarizeGame(GAME game) {

}

void SummarizeVictory(GAME game, VICTORY victory) {

}

void VictoryRanking(PLAYER player, GAME game, VICTORY victory) {

}

void getCommand(vector<string> input) {
	if (input[0].find("AddPlayer") == 0) {
		AddPlayer(input);
	}
	else if (input[0].find("AddGame") == 0) {
		AddGame(input);
	}
	else if (input[0].find("AddVictory") == 0) {
		AddVictory(input);
	}
	else if (input[0].find("Plays") == 0) {
        int pid;
        int gid;

		//given player id
		stringstream ss(input[1]);
		ss >> pid;
		//given game id
		stringstream st(input[2]);
		st >> gid;

		for (int i = 0; i < gamelist.size(); i++) {
            if (gamelist[i].id == gid) {
                gamelist[i].playerIDs.push_back(pid);
                gamelist[i].playerIGNs.push_back(input[3]);
            }
        }
	}
	else if (input[0].find("AddFriends") == 0) {
		int x, y = 0;

		//given player1 id
		stringstream ss(input[1]);
		ss >> x;
		//given player2 id
		stringstream st(input[2]);
		st >> y;

        AddFriends(x, y);
	}
	else if (input[0].find("WinVictory") == 0) {
        int pid;
        int gid;
        int vid;

		stringstream ps(input[1]);
        ps >> pid;

		stringstream gs(input[2]);
        gs >> gid;

		stringstream vs(input[3]);
        vs >> vid;

        // cout << "WIN VICTORY: " << pid << ", " << gid << ", " << vid << endl;
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == pid) {
                playerlist[i].wingames.push_back(gid);
                playerlist[i].victories.push_back(vid);
			}
		}

        /*
		int x, y, z = 0;

		//given player id
		stringstream ss(input[1]);
		ss >> x;
		//given game id
		stringstream st(input[2]);
		st >> y;
		//given victory id
		stringstream su(input[3]);
		su >> z;

		int indexp, indexg, indexv = 0;

		//to check if the leaderboard has player id, game id, and victory id
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == x) {
				for (int j = 0; j < gamelist.size(); j++) {
					if (gamelist[j].id == y) {
						for (int k = 0; k < victorylist.size(); k++) {
							if (victorylist[k].victory_id == z) {
								WinVictory(playerlist[i], gamelist[j], victorylist[k].points, indexp, indexg, indexv);
							}
							indexv++;
						}
					}
					indexg++;
				}
				indexp++;
			}
		}
        */
	}
	else if (input[0].find("FriendsWhoPlay") == 0) {
        /*
		int x, y = 0;

		//given player id
		stringstream ss(input[1]);
		ss >> x;
		//given game id
		stringstream st(input[2]);
		st >> y;

		//to check if the leaderboard has both player id and game id
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == x) {
				if (playerlist[i].friends.size() == 0) {
					cout << playerlist[i].name << " does not have friends" << endl;
				}
				else {
					for (int j = 0; j < gamelist.size(); j++) {
						if (gamelist[j].id == y) {
							FriendswhoPlay(playerlist[i], gamelist[j]);
						}
					}
				}
			}
		}
        */
	}
	else if (input[0].find("ComparePlayers") == 0) {

	}
	else if (input[0].find("SummarizePlayer") == 0) {
        int pid;
		//given player id
		stringstream ss(input[1]);
		ss >> pid;
        cout << "SummarizePlayer: pid=" << pid << endl;
        for (auto p: playerlist) {
            if (p.id == pid) {
                cout << "Player: " << p.name << endl;

                // calculate total gamerscore
                int points = 0;
                for (auto vid: p.victories) {
                    for (auto v: victorylist) {
                        if (v.victory_id == vid) {
                            points += v.points;
                        }
                    }
                }
                cout << "Total Gamerscore: " << points << " pts" << endl << endl;
                cout << "   Game             Victories    Gamerscore     IGN" << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                for (int i=0; i < gamelist.size(); i++) {
                    int num_wins = 0;
                    for (int j=0; j < gamelist[i].playerIDs.size(); j++) {
                        if (gamelist[i].playerIDs[j] == pid) {
                            int gid = gamelist[i].id;
                            int points2 = 0;
                            for (int k=0; k < p.wingames.size(); k++) {
                                if (p.wingames[k] == gid) {
                                    p.victories[k];
                                    for (auto v: victorylist) {
                                        if (v.victory_id == p.victories[k]) {
                                            points2 += v.points;
                                            num_wins += 1;
                                        }
                                    }
                                }
                            }
                            cout << i+1 << ". " 
                                << gamelist[i].name << ", " 
                                << num_wins << "/ ," 
                                << points2 << " pts " 
                                << gamelist[i].playerIGNs[j] << endl;
                        }
                    }
                }
                cout << endl << "    Friend            Gamerscore" << endl;
                cout << "-------------------------------------------------" << endl;
                for (int i=0; i < p.friends.size(); i++) {
                    int fid = p.friends[i];
                    for (auto f: playerlist) {
                        if (f.id == fid) {
                            // calculate total gamerscore
                            int points = 0;
                            for (auto vid: f.victories) {
                                for (auto v: victorylist) {
                                    if (v.victory_id == vid) {
                                        points += v.points;
                                    }
                                }
                            }
                            cout << i+1 << ". " << f.name << "    " << points << " pts" << endl;
                        }
                    }
                }
            }
        }
	}
	else if (input[0].find("SummarizeGame") == 0) {

	}
	else if (input[0].find("SummarizeGame") == 0) {

	}
	else if (input[0].find("SummarizeVictory") == 0) {

	}
	else if (input[0].find("VictoryRanking") == 0) {

	}
	else {
		cout << "There is no command such like that." << endl;
	}
}

int main() {
	string line;
	string name = "";
	vector<string> words;
	while (getline(cin, line)) {
		if (line.size() < 5) continue;
		cout << line << endl;
		istringstream iss(line);
		name = "";
		for (string word; iss >> word; ) {
			if (word.front() == '\"' && word.back() == '\"') {
				word = word.substr(1, word.size() - 2);
				words.push_back(word);
			}
			else if (word.front() == '\"') {
				name += word.substr(1, word.size() - 1);
			}
			else if (word.back() == '\"') {
				word = name + " " + word.substr(0, word.size() - 1);
				name = "";
				words.push_back(word);
			}
			else {
				if (name.size() > 0) {
					name += " " + word;
				}
				else {
					words.push_back(word);
				}
			}
		}
		for (auto word : words) {
			cout << "   [" << word << "]" << endl;
		}
		getCommand(words);
		words.clear();
	}

    cout << "Games: " << endl;
    for (auto game: gamelist) {
		cout << "    " << game.id << ", " << game.name << endl;
        for (int i=0; i < game.playerIDs.size(); i++) {
            cout << "        pid=" << game.playerIDs[i] << ", IGN=" << game.playerIGNs[i] << endl;
        } 
    }
    cout << "Players: " << endl;
	for (auto p : playerlist) {
		cout << "    " << p.id << ", " << p.name << endl;
        cout << "        Friends: " << p.friends.size() << endl;
        for (auto fr: p.friends) {
            cout << "            " << fr << endl;
        }
        for (int i=0; i < p.wingames.size(); i++) {
            cout << "        game-id=" << p.wingames[i] << ", victory-id=" << p.victories[i] << endl;
        }
	}	

    cout << "Victories: " << endl;
	for (auto v : victorylist) {
		cout << "    " << v.game_id << ", " << v.victory_id << ", " << v.name << ", " << v.points << endl;
	}	

    /*
	//test friends list for each player (AddFriends)
    cout << "FRIENDS number = " << playerlist[1].friends.size() << endl;
	for (int i = 0; i < playerlist[1].friends.size(); i++) {
		cout << "    " << playerlist[1].friends[i] << endl;
	}

    for (auto p: playerlist) {
        cout << "FRIENDS number for " << p.id << ":" << p.name << " = " << p.friends.size() << endl;
        for (auto f: p.friends) {
            cout << "    " << f << endl;
        }
    }
    */

	//test games and igns for each player (Plays)
/*	for (int i = 0; i < playerlist[3].games.size(); i++) {
		cout << playerlist[3].games[i] << endl;
		cout << playerlist[3].IGNS[i] << endl;
	}*/

	//test AddGame
/*	for (auto g : gamelist) {
		cout << g.id << endl;
		cout << g.name << endl;
	}*/

	//test AddVictory
/*	for (auto v : victorylist) {
		cout << v.game_id << endl;
		cout << v.victory_id << endl;
		cout << v.name << endl;
		cout << v.points << endl;
	}*/

	//test WinVictory
	for (int i = 0; i < playerlist[0].point.size(); i++) {
		cout << playerlist[0].point[i] << endl;
 	}
	for (int i = 0; i < playerlist[0].victory.size(); i++) {
		cout << playerlist[0].victory[i] << endl;
	}

	return 0;
}
