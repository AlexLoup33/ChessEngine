# engine.py

from engine.board import Board

board = Board()
fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
board.loadDefaultFEN(fen)
board.display()