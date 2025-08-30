# board.pyx

from engine.piece import Piece

cdef class Board:
    cdef list squares
    
    def __cinit__(self):
        self.squares = [0] * 64
        
    def saveFEN(self)->str:
        fen = ""
        for row in range(8):
            for col in range(8):
                pass
        return fen
    
    def loadDefaultFEN(self, fenStr:str):
        fen = fenStr.split("/")
        for row in range(8):
            rowFen = fen[row]
            col = 0
            for char in rowFen:
                if col > 7:
                    raise IndexError("Position impossible sur le plateau, erreur dans la création du FEN")
                pos = row*8+col
                if char.isdigit():
                    for _ in range(int(char)):
                        col += 1
                else:
                    if col > 7:
                        raise IndexError("Position impossible sur le plateau, erreur dans la création du FEN")
                    if char ==  "K":
                            piece = Piece("white_king", 0, pos, 1000, [-9, -8, -7, -1, 1, 7, 8, 9], False, False, "♔")
                    elif char == "Q": 
                            piece = Piece("white_queen", 0, pos, 9,  [-9, -8, -7, -1, 1, 7, 8, 9], True, False, "♕")
                    elif char == "R":
                            piece = Piece("white_rook", 0, pos, 5, [-8, -1, 1, 8], True, False, "♖")
                    elif char == "N":
                            piece = Piece("white_knight", 0, pos, 3, [-17, -15, -10, -6, 6, 10, 15, 17], False, False, "♘")
                    elif char == "B":
                            piece = Piece("white_bishop", 0, pos, 3, [-9, -7, 7, 9], True, False, "♗")
                    elif char == "P":
                            piece = Piece("white_pawn", 0, pos, 1, [8, 16], False, False, "♙")
                    elif char == "k":
                            piece = Piece("black_king", 1, pos, -1000, [-9, -8, -7, -1, 1, 7, 8, 9], False, False, "♚")
                    elif char == "q": 
                            piece = Piece("black_queen", 1, pos, -9,  [-9, -8, -7, -1, 1, 7, 8, 9], True, False, "♛")
                    elif char == "r":
                            piece = Piece("black_rook", 1, pos, -5, [-8, -1, 1, 8], True, False, "♜")
                    elif char == "n":
                            piece = Piece("black_knight", 1, pos, -3, [-17, -15, -10, -6, 6, 10, 15, 17], False, False, "♞")
                    elif char == "b":
                            piece = Piece("black_bishop", 1, pos, -3, [-9, -7, 7, 9], True, False, "♝")
                    elif char == "p":
                            piece = Piece("black_pawn", 1, pos, -1, [-8, -16], False, False, "♟")
                    else : 
                        raise ValueError("Caractère inconnu pour le système FEN")



                    self.squares[row*8+col] = piece
                    col += 1
    
    def display(self):
        for row in range(8):
            print("+---+---+---+---+---+---+---+---+")
            for col in range(8):
                piece = self.squares[row*8 + col]
                if piece == 0:
                    print("|   ", end="")
                else:
                    print(f"| {piece.symbol} ", end="")
            print("|")
        print("+---+---+---+---+---+---+---+---+")