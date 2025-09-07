from customtkinter import CTk, CTkFrame

from view.game import GameUI

class View(CTk):
    def __init__(self):
        super().__init__()

        self.title("CyChess Engine")
        self.geometry("800x600")


        self.game = GameUI(self)
        self.game.pack(fill="both", expand=True)

    def update_board(self, board: list[int]):
        self.game.update_board(board)

    def start(self):
        self.mainloop()