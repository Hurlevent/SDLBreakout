#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H


namespace Breakout
{
	// This class is a singleton that contains values related to how well the player is doing. We unfortunately didn't have enough time to implement highscore
	class PlayerStats
	{
	public:
		static PlayerStats & Instance()
		{
			static PlayerStats player_stats;
			return player_stats;
		}
		void ResetGame() { score = 0; highscore = 0; health = 3; };
		int score;
		int highscore;
		int health;
	private:
		PlayerStats() { score = 0; highscore = 0; health = 3; }
		PlayerStats(const PlayerStats&){}
		PlayerStats & operator = (const PlayerStats&){}

	};
}

#endif
