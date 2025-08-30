from setuptools import setup, Extension
from Cython.Build import cythonize

extensions = [
    Extension("engine.piece", ["engine/piece.pyx"]),
    Extension("engine.board", ["engine/board.pyx"])
]

setup(
    name="chessEngine",
    ext_modules=cythonize(extensions, language_level=3),
    packages=["engine"],
)