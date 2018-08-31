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
#include <string>
#include <vector>
using namespace std;

struct PLAYER {
	int id;
	string name;

	vector<int> player;
};

struct GAME {
	int id;
	string name;

	vector<int> game;
};

struct VICTORY {
	int game_id, victory_id, points;
	string name;

	vector<int> victory;
};

void AddPlayer(int id, string name) {

}

void AddGame(int id, string name) {

}

void AddVictory(int game_id, int victory_id, string name, int points) {

}

void Plays(int player_id, int game_id, string IGN) {

}

void Addfriends(int playerone, int playertwo) {

}

void WinVictory(int player_id, int game_id, int victory_id) {

}

void FriendswhoPlay(int player_id, int game_id) {

}

void ComparePlayers(int playerone, int playertwo, int game_id) {

}

void SummarizePlayer(int id) {

}

void SummarizeGame(int id) {

}

void SummarizeVictory(int game_id, int victory_id) {

}

void VictoryRanking() {

}

int main() {
	string commands;

	while (cin >> commands) {
		cout << commands << endl;
	}

	return 0;
}