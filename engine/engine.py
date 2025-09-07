# engine.py

from engine.board import Board
from view.view import View

class Engine:
    def __init__(self):
        self.board = Board()
        self.view = View()

        fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

        self.board.loadFEN(fen)
        print(self.board.get_board_state())
        self.view.game.update_board(self.board.get_board_state())
        


    def start(self):
        self.view.start()