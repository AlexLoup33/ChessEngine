# game.py

from customtkinter import CTk, CTkFrame, CTkCanvas, CTkLabel
from pathlib import Path
from PIL import Image, ImageTk

class GameUI(CTkFrame):
    def __init__(self, master: CTk):
        super().__init__(master=master)

        self.grid(row=0, column=0, sticky="nsew")


        self.board = CTkCanvas(self, width=480, height=480, bg="black", highlightthickness=0)
        self.board.grid(row=1, column=0, columnspan=8, rowspan=8)
        self.board.grid_propagate(False)
        
        self.draw_empty_board()

        self.images = {}
    
    def draw_empty_board(self):
        for pos in range(64):
            # Transforming position of 1 dimension array into position row and column
            row, col = divmod(pos, 8)

            # Color 
            square_color = "white" if (row + col) % 2 == 0 else "gray"
            
            # Calcul of the edge of each square of the board
            x1, y1 = col * 60, row * 60
            x2, y2 = x1 + 60, y1 + 60

            # Draw of the square on the canvas
            self.board.create_rectangle(x1, y1, x2, y2, fill=square_color, outline="")

    def update_board(self, board_state: list[int]):
        # clear the images in the dictionnary for changing keys
        self.images.clear()

        for pos in range(64):
            piece = board_state[pos]

            if piece != 0: # Checking if the actual square is empty or not
                row, col = divmod(pos, 8)

                name = piece.name

                # Find and load the image of the chess piece by their name
                image_path = Path(__file__).parent.parent.joinpath(f"ressources/pieces/{name}.png")
                piece_image = Image.open(image_path)
                piece_image_tk = ImageTk.PhotoImage(piece_image)

                x, y = col * 60 + 30, row * 60 + 30

                print(f"piece {name} created at pos {x}, {y}")

                # Display the image on the canvas and storing the id of the image for the z-index
                piece_id = self.board.create_image(x, y, image=piece_image_tk, tags=("piece", ))
                
                self.board.tag_raise(piece_id)

                # Keep the draw in memory for avoiding garbage collector
                self.images[pos] = piece_image_tk
