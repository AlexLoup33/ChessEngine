# piece.pyx

cdef class Piece:

    cdef str name
    cdef int color # 0 for white, 1 for black
    cdef int pos
    cdef int score
    cdef list[int] move_dir
    cdef bint long_move
    cdef bint has_move
    cdef public str symbol


    def __cinit__(self, name: str, color: int, pos: int, score: int, move: list[int], long_m: bool, has_m: bool, symbol: str):
        self.name = name
        self.color = color
        self.pos = pos
        self.score = score
        self.move_dir = move
        self.long_move = long_m
        self.has_move = has_m
        self.symbol = symbol