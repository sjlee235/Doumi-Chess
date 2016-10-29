#pragma once
#include "defs.h"
#include "move.h"
#include "board.h"
#include <Windows.h>

/*                                    CALL COUNT                               */
void moveGenCalled();







/*                                  BOARD SETUP                               */
/// <summary>
/// This function sets the given board to the initial state.
/// </summary>
/// <param name="board">The board that will be changed to initial state.</param>
void board120Setup(Board& board);
/// <summary>
/// This function sets the given board according to the FEN.
/// </summary>
/// <param name="board">The board that will be changed to initial state.</param>
/// <param name="FEN">The desired board in FEN notation.</param>
void FENboardSetup(Board& board, const std::string FEN);
/// <summary>
/// This function converts the given board to FEN notation.
/// </summary>
/// <param name="board">The board that will be converted to FEN notation.</param>
/// <returns>FEN notation of the given board.</returns>
std::string boardToFEN(const Board& board);


/// <summary>
/// This function returns the color of the given piece type
/// </summary>
/// <param name="pieceType">The piece that will be checked its color</param>
/// <returns>The color of the given piece</returns>
int checkColor(const int pieceType);
/// <summary>
/// This function returns the column character (file) of a given square.
/// </summary>
/// <param name="position">The square that the function will give its file</param>
/// <returns>The file of the given square</returns>
char numberToFile(const int position);
/// <summary>
/// This function returns the row number (rank) of a given square.
/// </summary>
/// <param name="position">The square that the function will give its rank</param>
/// <returns>The rank of the given square</returns>
int numberToRank(const int position);
/// <summary>
/// This function converts the file and rank notation to board index of a board. 
/// </summary>
/// <param name="file">The file of the square</param>
/// <param name="rank">The rank of the square</param>
/// <returns>The board index notation of the square</returns>
int filerankToNumber(const char file, const int rank);
/// <summary>
/// This function converts a position's notation from board index to file rank.
/// </summary>
/// <param name="position">The square in board index notation.</param>
/// <returns>A two-letter string with file rank notation of the given square.</returns>
std::string numberToFilerank(const int position);





/*                                   RECURSION                                */
/// <summary>
/// This function finds the number of possible move sequences for given depth and divides them into categories of first few moves given by maxDepth and prints them to console.
/// </summary>
/// <param name="depth">The current depth of the recursion.</param>
/// <param name="maxDepth">The maximum depth the moves will be divided in output</param>
/// <param name="board">The board being checked.</param>
/// <param name="showOutput">Wheter or not to show intermediate output.</param>
/// <returns>The number of possible move sequences of given depth.</returns>
uint64_t divide(const int depth, const int maxDepth, Board& board, const bool showOutput);
/// <summary>
/// This function finds the number of possible move sequences for given depth and divides them into categories of first few moves given by maxDepth amd saves them into a file.
/// </summary>
/// <param name="depth">The current depth of the recursion.</param>
/// <param name="maxDepth">The maximum depth the moves will be divided in output</param>
/// <param name="board">The board being checked.</param>
/// <param name="showOutput">Wheter or not to show intermediate output.</param>
/// <returns>The number of possible move sequences of given depth.</returns>
uint64_t divide2(const int depth, const int maxDepth, Board& board, const bool showOutput);
/// <summary>
/// This function applies the given move to the given board.
/// </summary>
/// <param name="board">The board that the move will apply to.</param>
/// <param name="move">The move to be applied to the board.</param>
/// <returns>The piece that was captured with the move</returns>
int makeMove(Board &board, const Move& move);
/// <summary>
/// This function reverts the given move on the given board.
/// </summary>
/// <param name="board">The board that the move will be reverted in</param>
/// <param name="move">The move that will be reverted</param>
/// <param name="capturedPiece">The piece that was captured by the move</param>
void undoMove(Board &board, const Move& move, const int capturedPiece);


/*                                  MISC                                      */
// TODO: Check if this can be integrated inside makeMove
/// <summary>
/// This function updates the castling rights of the given board if the given move changed it. This is called after the move was applied to the board.
/// </summary>
/// <param name="board">The board that will be checked.</param>
/// <param name="move">The move that was made that could have changed the castling rights.</param>
void updateCastling(Board& board, const Move& move);
/// <summary>
/// This function updates the en passant square of the given board if the given move changed it. This is called after the move was applied to the board.
/// </summary>
/// <param name="board">The board that will be checked.</param>
/// <param name="move">The move that was made that could have changed the en passant square.</param>
void updateEnPassant(Board& board, const Move& move);
/// <summary>
/// This function updates the half move clock of the given board if the given move changed it. This is called after the move was applied to the board.
/// </summary>
/// <param name="board">The board that will be checked.</param>
/// <param name="move">The move that was made that has changed the half move clock.</param>
void updateHalfMoveClock(Board& board, const Move& move);
/// <summary>
/// This function updates the move number of the given board if the given move changed it. This is called after the move was applied to the board.
/// </summary>
/// <param name="board">The board that will be checked.</param>
/// <param name="move">The move that was made that could have changed the move number.</param>
void updateMoveNumber(Board& board);
/// <summary>
/// This function updates the non-board components (casting, enpassant, halfmoveclock, movenumber) of the given board if the given move changed it. This is called after the move was applied to the board.
/// </summary>
/// <param name="board">The board that will be checked.</param>
/// <param name="move">The move that was made that could have changed the board properties.</param>
// TODO: UPDATE
void updateBoard(Board& board, const Move& move, const int capturedPiece);

/// <summary>
/// This function checks the game state of the given board.
/// </summary>
/// <param name="board">The board that will be checked for its game state.</param>
/// <returns>The game state of the board.</returns>
gameState checkGameState(const Board& board);
/// <summary>
/// This function checks if in the given board a fifty move rule can be declared.
/// </summary>
/// <param name="board">The board that will be checked for fifty move rule.</param>
/// <returns>True if fifty move rule is possible. False if not.</returns>
bool fiftyMoveCheck(const Board& board);
