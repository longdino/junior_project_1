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
	vector<int> victory = { 0,0,0,0,0 }; //number of victory of the player
	vector<int> point = { 0,0,0,0,0 }; //the list of point for each game
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

void AddFriends(int player1, int player2) {
	for (int i = 0; i < playerlist.size(); i++) {
		if (playerlist[i].id == player1) {
			playerlist[i].friends.push_back(player2);
//			cout << "ADD FRIENDS2: " << player1 << "(" << playerlist[i].name << ", " << player2 << ", " << playerlist[i].friends.size() << endl;
		}
		if (playerlist[i].id == player2) {
			playerlist[i].friends.push_back(player1);
//			cout << "ADD FRIENDS2: " << player2 << "(" << playerlist[i].name << ", " << player1 << ", " << playerlist[i].friends.size() << endl;
		}
	}
}

void WinVictory(PLAYER player, GAME game, int point, int nump, int numg, int numv) {
	cout << point << endl;
	cout << game.id << endl;
	if (game.id == 4001) {

	}
	else if (game.id == 4002) {

	}
	else if (game.id == 4003) {

	}
	else if (game.id == 4004) {

	}
	else if (game.id == 4005) {

	}
 }

void FriendswhoPlay(PLAYER player, GAME game) {
/*	for (int i = 0; i < player.friends.size(); i++) {
		for (int j = 0; j < playerlist.size(); j++) {
			if (playerlist[j].name.find(player.friends[i]) == 0) {
				cout << player.name << "'s friend " << player.friends[i] << " has played " << game.name << endl;
			}
		}
	}*/
}

void ComparePlayers(PLAYER player1, PLAYER player2, GAME game) {

}

void SummarizePlayer(PLAYER player) {

}

void SummarizeGame(GAME game) {

}

void SummarizeVictory(GAME game, VICTORY victory) {

}

void VictoryRanking() {

}

void getCommand(vector<string> input) {
//	cout << "GETCOMMAND: " << input[0] << endl;
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
		int x, y = 0;

		//given player id
		stringstream ss(input[1]);
		ss >> x;
		//given game id
		stringstream st(input[2]);
		st >> y;

		int indexp = 0;

		//to check if the leaderboard has both player id and game id
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == x) {
				for (int j = 0; j < gamelist.size(); j++) {
					if (gamelist[j].id == y) {
						Plays(input, playerlist[i], gamelist[j], indexp);
						break;
					}
				}
			}
			else
				indexp++;
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

	}
	else if (input[0].find("FriendsWhoPlay") == 0) {
/*		int x, y = 0;

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
		}*/
	}
	else if (input[0].find("ComparePlayers") == 0) {
		int x, y, z = 0;

		//given player1 id
		stringstream ss(input[1]);
		ss >> x;
		//given player2 id
		stringstream st(input[2]);
		st >> y;
		//given game id
		stringstream su(input[3]);
		su >> z;

		//to check if the leaderboard has the player ids and the game id
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == x) {
				for (int j = 0; j < playerlist.size(); j++) {
					if (playerlist[j].id == y) {
						for (int k = 0; k < gamelist.size(); k++) {
							if (gamelist[k].id == z) {
								ComparePlayers(playerlist[i], playerlist[j], gamelist[k]);
							}
						}
					}
				}
			}
		}
	}
	else if (input[0].find("SummarizePlayer") == 0) {
		int x = 0;

		//given player id
		stringstream ss(input[1]);
		ss >> x;

		//to check if the leaderboard has the player id
		for (int i = 0; i < playerlist.size(); i++) {
			if (playerlist[i].id == x) {
				SummarizePlayer(playerlist[i]);
			}
		}
	}
	else if (input[0].find("SummarizeGame") == 0) {
		int x = 0;

		//given game id
		stringstream ss(input[1]);
		ss >> x;

		//to checkc if the leaderboard has the game id
		for (int i = 0; i < gamelist.size(); i++) {
			if (gamelist[i].id == x) {
				SummarizeGame(gamelist[i]);
			}
		}
	}
	else if (input[0].find("SummarizeVictory") == 0) {
		int x, y = 0;

		//given game id
		stringstream ss(input[1]);
		ss >> x;
		//given victory id
		stringstream st(input[2]);
		st >> y;

		//to check if the leaderboard has the game id and victory id
		for (int i = 0; i < gamelist.size(); i++) {
			if (gamelist[i].id == x) {
				for (int j = 0; j < victorylist.size(); j++) {
					if (victorylist[j].victory_id == y) {
						SummarizeVictory(gamelist[i], victorylist[j]);
					}
				}
			}
		}
	}
	else if (input[0].find("VictoryRanking") == 0) {
		VictoryRanking();
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

	//test AddPlayer
/*	for (auto p : playerlist) {
		cout << p.id << endl;
		cout << p.name << endl;
	}*/	

	//test friends list for each player (AddFriends)
/*	for (int i = 0; i < playerlist[1].friends.size(); i++) {
		cout << playerlist[1].friends[i] << endl;
	}*/

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