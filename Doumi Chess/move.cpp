/******************************************************************************/
/* move.cpp                                                                   */
/* Seung Jae (Ryan) Lee                                                       */
/******************************************************************************/

#include "move.h"
#include <string>

/******************************************************************************/
/* MOVE CLASS                                                                 */
/******************************************************************************/
// Constructors
Move::Move() {}
Move::Move(int i, int t, int m) {
     initialSquare = i;
     terminalSquare = t;
     moveType = m;
}

// Clone Methods
Move::Move(const Move& originalMove) {
     initialSquare = originalMove.getInitial();
     terminalSquare = originalMove.getTerminal();
     moveType = originalMove.getType();
}
Move::Move(int originalMove[3]) {
     initialSquare = originalMove[0];
     terminalSquare = originalMove[1];
     moveType = originalMove[2];
}

std::string Move::toString() const {
     std::string output = numberToFilerank(initialSquare)
          + numberToFilerank(terminalSquare);

     if (moveType == KNIGHT_PROMOTION) {
          output += "n";
     }
     else if (moveType == BISHOP_PROMOTION) {
          output += "b";
     }
     else if (moveType == ROOK_PROMOTION) {
          output += "r";
     }
     else if (moveType == QUEEN_PROMOTION) {
          output += "q";
     }

     return output;
}
/******************************************************************************/
/* MOVELIST CLASS                                                             */
/******************************************************************************/

// Constructor
MoveList::MoveList() {
     moveCounter = 0;
}

// Mutator
void MoveList::push(const Move& move) {
     movelist[moveCounter] = move;
     moveCounter++;
}
void MoveList::push(int initial, int terminal, int moveType) {
     push(Move(initial, terminal, moveType));
}
void MoveList::pushPromotion(int initial, int terminal) {
     push(initial, terminal, KNIGHT_PROMOTION);
     push(initial, terminal, BISHOP_PROMOTION);
     push(initial, terminal, ROOK_PROMOTION);
     push(initial, terminal, QUEEN_PROMOTION);
}

inline std::string numberToFilerank(const int position) {
     return char('a' + position % ROW - 1) + std::to_string((10 - position / ROW));
}
std::string printMove(const Move& move) {
     std::string output = numberToFilerank(move.getInitial())
          + numberToFilerank(move.getTerminal()) + " ";

     switch (move.getType()) {
     case NORMAL:
          output += "\n";
          break;
     case DOUBLEMOVE:
          output += "Double Move\n";
          break;
     case ENPASSANT:
          output += "En passant\n";
          break;
     case QUEENSIDE_CASTLING:
          output = "O-O-O\n";
          break;
     case KINGSIDE_CASTLING:
          output = "O-O\n";
          break;
     case KNIGHT_PROMOTION:
          output += "Promotion to Knight\n";
          break;
     case BISHOP_PROMOTION:
          output += "Promotion to Bishop\n";
          break;
     case ROOK_PROMOTION:
          output += "Promotion to Rook\n";
          break;
     case QUEEN_PROMOTION:
          output += "Promotion to Queen\n";
          break;
     case DECLARE_50:
          break;
     }

     return output;
}
