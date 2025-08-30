# board.pyx

from engine.piece import Piece

cdef class Board:
    cdef int[64] squares
    
    def __cinit__(self):
        for i in range(64):
            self.squares[i] = 0
        
    def saveFEN(self)->str:
        fen = ""
        empty = 0
        for row in range(8):
            for col in range(8):
                pass
        return fen
    
    def loadDefaultFEN(self, fen:str):
        fen = fen.split("/")
        for row in range(8):
            rowFen = fen[row]

            col = 0
            for char in rowFen:
                if col > 7:
                    raise IndexError("Position impossible sur le plateau, erreur dans la création du FEN")
                if char.isdigit():
                    for _ in range(int(char)):
                        self.squares[row*8+col] = 0
                        col += 1
                else:
                    match char:
                        case "K":
                            piece = Piece("white_king", 0, row*8+col, 1000, [-9, -8, -7, -1, 1, 7, 8, 9], False, False)
                        case "Q": 
                            piece = Piece("white_queen", 0, row*8+col, 9,  [-9, -8, -7, -1, 1, 7, 8, 9], True, False)
                        case "R":
                            piece = Piece("white_rook", 0, row*8+col, 5, [-8, -1, 1, 8], True, False)

                    self.squares[row*8+col] = piece