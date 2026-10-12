#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir

#define LIGHT (Color){230, 203, 165, 255}
#define DARK (Color){179, 108, 63, 255}

#define N_ROWS 8
#define N_COLS 8

typedef enum {
  PAWN_WHITE,
  KNIGHT_WHITE,
  BISHOP_WHITE,
  ROOK_WHITE,
  QUEEN_WHITE,
  KING_WHITE,
  PAWN_BLACK,
  KNIGHT_BLACK,
  BISHOP_BLACK,
  ROOK_BLACK,
  QUEEN_BLACK,
  KING_BLACK,
  N_PIECE_TYPES
} Piece;

Texture2D pieces[N_PIECE_TYPES];
const float borderWidth = 50, borderHeight = 50, squareSide = 100;

void drawPiece(Piece type, int row, int col) {
  DrawTextureEx(pieces[type],
                (Vector2){borderWidth + col * squareSide,
                          borderHeight + row * squareSide},
                0.0f, 0.1f, WHITE);
}

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(900, 900, "Hello Raylib");

  // Utility function from resource_dir.h to find the resources folder and set
  // it as the current working directory so we can load from it
  SearchAndSetResourceDir("resources");

  pieces[PAWN_WHITE] = LoadTexture("pawn-white.png");
  pieces[KNIGHT_WHITE] = LoadTexture("knight-white.png");
  pieces[BISHOP_WHITE] = LoadTexture("bishop-white.png");
  pieces[ROOK_WHITE] = LoadTexture("rook-white.png");
  pieces[QUEEN_WHITE] = LoadTexture("queen-white.png");
  pieces[KING_WHITE] = LoadTexture("king-white.png");
  pieces[PAWN_BLACK] = LoadTexture("pawn-black.png");
  pieces[KNIGHT_BLACK] = LoadTexture("knight-black.png");
  pieces[BISHOP_BLACK] = LoadTexture("bishop-black.png");
  pieces[ROOK_BLACK] = LoadTexture("rook-black.png");
  pieces[QUEEN_BLACK] = LoadTexture("queen-black.png");
  pieces[KING_BLACK] = LoadTexture("king-black.png");

  while (!WindowShouldClose()) {
    // drawing
    BeginDrawing();

    // Setup the back buffer for drawing (clear color and depth buffers)
    ClearBackground(WHITE);

    // Draw chess board
    for (int row = 0; row < N_ROWS; ++row) {
      for (int col = 0; col < N_COLS; ++col) {
        DrawRectangleRec((Rectangle){borderWidth + row * squareSide,
                                     borderHeight + col * squareSide,
                                     squareSide, squareSide},
                         (row + col) % 2 == 0 ? LIGHT : DARK);
      }
    }

    // Draw pieces
    drawPiece(ROOK_BLACK, 0, 0);
    drawPiece(KNIGHT_BLACK, 0, 1);
    drawPiece(BISHOP_BLACK, 0, 2);
    drawPiece(QUEEN_BLACK, 0, 3);
    drawPiece(KING_BLACK, 0, 4);
    drawPiece(BISHOP_BLACK, 0, 5);
    drawPiece(KNIGHT_BLACK, 0, 6);
    drawPiece(ROOK_BLACK, 0, 7);
    for (int col = 0; col < N_COLS; ++col) {
      drawPiece(PAWN_BLACK, 1, col);
    }

    drawPiece(ROOK_WHITE, 7, 0);
    drawPiece(KNIGHT_WHITE, 7, 1);
    drawPiece(BISHOP_WHITE, 7, 2);
    drawPiece(QUEEN_WHITE, 7, 3);
    drawPiece(KING_WHITE, 7, 4);
    drawPiece(BISHOP_WHITE, 7, 5);
    drawPiece(KNIGHT_WHITE, 7, 6);
    drawPiece(ROOK_WHITE, 7, 7);
    for (int col = 0; col < N_COLS; ++col) {
      drawPiece(PAWN_WHITE, 6, col);
    }

    // end the frame and get ready for the next one  (display frame, poll input,
    // etc...)
    EndDrawing();
  }

  for (int i = 0; i < N_PIECE_TYPES; ++i) {
    UnloadTexture(pieces[i]);
  }

  // destroy the window and cleanup the OpenGL context
  CloseWindow();
  return 0;
}
