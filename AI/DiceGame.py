import random
class DiceGame:
    def __init__(self,num_rounds):
        self.num_rounds=num_rounds
        self.player_scores=[0,0]
    def roll_dice(self):
        return random.randint(1,6)
    def play_round(self):
        round_winner=None
        for i in range(2):
            roll=self.roll_dice()
            self.player_scores[i]+=roll
            print(f"Player{i+1} rolled: {roll}")
            if round_winner is None or roll>self.player_scores[round_winner]:
                round_winner=i
        return round_winner
    def play_game(self):
        print("Lets start the game!")
        for round_num in range(1,self.num_rounds+1):
            print(f"Round {round_num}:")
            round_winner=self.play_round()
            print(f"Round {round_num} winner:Player {round_winner+1}")
            print(f"Scores after round {round_num}:player1 - {self.player_scores[0]},player2 - {self.player_scores[1]}")
            print()
        winner = 0 if self.player_scores[0]>self.player_scores[1] else 1
        print(f"Game over! player {winner+1} wins with a score of {self.player_scores[winner]}")
game=DiceGame(5)
game.play_game()
